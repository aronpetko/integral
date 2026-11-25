#include "nnue.h"

#include <MantaRay/MantaRay.h>
#include <fmt/format.h>

#include <algorithm>
#include <mutex>
#include <span>
#include <vector>

#include "accumulator.h"

#ifdef _MSC_VER
#define SP_MSVC
#pragma push_macro("_MSC_VER")
#undef _MSC_VER
#endif

#include "../../../third-party/incbin/incbin.h"

#ifdef SP_MSVC
#pragma pop_macro("_MSC_VER")
#undef SP_MSVC
#endif

INCBIN(EVAL, EVALFILE);

namespace nnue {

namespace arch {

constexpr std::size_t kInputBucketCount = 16;
constexpr std::size_t kPsqtFeatureCount = kInputBucketCount * 768;
constexpr std::size_t kPawnPairFeatureCount = 4560;
constexpr std::size_t kThreatFeatureCount = 59808;
constexpr std::size_t kThreatPawnPairFeatureCount =
    kThreatFeatureCount + kPawnPairFeatureCount;
constexpr std::size_t kL1Size = 1024;
constexpr std::size_t kL2Size = 16;
constexpr std::size_t kL3Size = 32;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::size_t kHmcBucketsStart = 14;
constexpr std::size_t kHmcBucketsStep = 8;
constexpr std::size_t kHmcBucketCount =
    (100 - kHmcBucketsStart + kHmcBucketsStep - 1) / kHmcBucketsStep;

constexpr std::int32_t kFtQuantization = 255;
constexpr std::int32_t kL1Quantization = 128;
constexpr int kFtShift = 9;

constexpr std::int32_t kEvalScale = 200;

// clang-format off
constexpr MantaRay::BucketLayout kKingBuckets = MantaRay::Mirrored({
  0,  1,  2,  3,
  4,  5,  6,  7,
  8,  8,  9,  9,
  10, 10, 11, 11,
  12, 12, 13, 13,
  12, 12, 13, 13,
  14, 14, 15, 15,
  14, 14, 15, 15,
});
// clang-format on

}  // namespace arch

namespace {

using HmcBucketTable = std::array<U8, 101>;

constexpr HmcBucketTable kHmcBucketTable = [] {
  HmcBucketTable table{};
  for (std::size_t clock = 0; clock < table.size(); ++clock) {
    if (clock < arch::kHmcBucketsStart) {
      table[clock] = arch::kHmcBucketCount;
    } else {
      const std::size_t idx =
          (clock - arch::kHmcBucketsStart) / arch::kHmcBucketsStep;
      table[clock] = static_cast<U8>(std::min(idx, arch::kHmcBucketCount - 1));
    }
  }
  return table;
}();

// The half-move clock's bucket as a single input feature, which is absent
// while the clock is too low to have one. It's the same from both perspectives
// and changes without a piece moving (null moves), so rather than being
// accumulated its row is looked up when evaluating
struct HalfMoveClock {
  using Trigger = MantaRay::NoTrigger;

  static constexpr MantaRay::u32 InputSize = arch::kHmcBucketCount;
  static constexpr MantaRay::u32 MaxActive = 1;
  static constexpr MantaRay::u32 MaxChanges = 1;
  static constexpr bool Shared = true;
  static constexpr bool Cached = false;
  static constexpr bool Incremental = false;

  template <typename Board, typename Emit>
  static constexpr void Active(MantaRay::u08,
                               const Board& board,
                               Emit&& emit) noexcept {
    if (const auto bucket = board.HmcBucket(); bucket < InputSize) {
      emit(bucket);
    }
  }
};

using OutputBucket = MantaRay::MaterialCount<arch::kOutputBucketCount>;

// (768x16hm + 59808 threats + 4560 pawn pairs + hmc -> 1024)x2 -> (16 -> 32 ->
// 1)x8. The tensors are listed in the order that they're laid out in the
// network file
constexpr auto Architecture() {
  using namespace MantaRay;

  auto [psqt_stm, psqt_ntm] = Input<KingBuckets<arch::kKingBuckets>>();
  auto [pawn_pair_stm, pawn_pair_ntm] = Input<PawnPairs<>>();
  auto [threat_stm, threat_ntm] = Input<Threats<TI59808>>();
  const auto hmc_input = Input<HalfMoveClock>();

  const auto psqt = Linear(arch::kPsqtFeatureCount,
                           arch::kL1Size,
                           Weights<i16>(arch::kFtQuantization));
  const auto hmc = Linear(arch::kHmcBucketCount,
                          arch::kL1Size,
                          Weights<i16>(arch::kFtQuantization));
  // Pawn pair rows come first, followed by the threat rows
  const auto threats = Linear(arch::kThreatPawnPairFeatureCount,
                              arch::kL1Size,
                              Weights<i08>(arch::kFtQuantization));
  const auto feature_biases =
      Parameter(arch::kL1Size, Biases<i16>(arch::kFtQuantization));

  const auto l1 = Affine(arch::kL1Size,
                         arch::kOutputBucketCount * arch::kL2Size,
                         Weights<i08>(arch::kL1Quantization).RowMajor(),
                         Biases<f32>(),
                         Dequantize());
  // The reduction orders make the float layers sum in a fixed order, so that
  // the evaluation is the same on every instruction set
  const auto l2 = Affine(arch::kL2Size,
                         arch::kOutputBucketCount * arch::kL3Size,
                         Weights<f32>().RowMajor(),
                         Biases<f32>())
                      .Ordered(Reduction::BiasFirstFma);
  const auto l3 = Affine(arch::kL3Size,
                         arch::kOutputBucketCount,
                         Weights<f32>().RowMajor(),
                         Biases<f32>())
                      .Ordered(Reduction::Lanes16);

  const auto transform = [&](const auto& psqt_input,
                             const auto& pawn_pair_input,
                             const auto& threat_input) {
    const auto accumulator =
        psqt(psqt_input) +
        threats.Inputs(0, arch::kPawnPairFeatureCount)(pawn_pair_input) +
        threats.Inputs(arch::kPawnPairFeatureCount,
                       arch::kThreatPawnPairFeatureCount)(threat_input) +
        feature_biases;
    // Pairwise CReLU on the accumulator and the half-move clock row
    return Pairwise(ClippedReLU(Wrap<i16>(accumulator + hmc(hmc_input)))) >>
           arch::kFtShift;
  };

  const auto l1_output = ClippedReLU(Select<OutputBucket>(
      l1(Concat(transform(psqt_stm, pawn_pair_stm, threat_stm),
                transform(psqt_ntm, pawn_pair_ntm, threat_ntm)))));
  const auto l2_output = ClippedReLU(Select<OutputBucket>(l2(l1_output)));

  return Output(Bullet(psqt.Weights(),
                       hmc.Weights(),
                       threats.Weights(),
                       feature_biases,
                       l1.Weights(),
                       l1.Biases(),
                       l2.Weights(),
                       l2.Biases(),
                       l3.Weights(),
                       l3.Biases()),
                Head{Select<OutputBucket>(l3(l2_output)), arch::kEvalScale});
}

using Network = MantaRay::Network<Architecture>;

// The search never goes deeper than kMaxPlyFromRoot, and moves made outside of
// it (like the ones in a position command) re-root the stack when it's full
constexpr std::size_t kStackCapacity = kMaxPlyFromRoot + 64;

using AccumulatorStack =
    MantaRay::AccumulatorStack<Architecture,
                               kStackCapacity,
                               MantaRay::UpdatePolicy::Lazy,
                               MantaRay::Accumulators::Combined>;

// MantaRay's view of a board state
class BoardView {
 public:
  explicit BoardView(const BoardState& state) : state_(state) {}

  [[nodiscard]] U64 Pieces(U8 side, MantaRay::Piece piece) const {
    return (state_.piece_bbs[static_cast<int>(piece)] & state_.side_bbs[side])
        .AsU64();
  }

  [[nodiscard]] U64 Occupied() const {
    return state_.Occupied().AsU64();
  }

  [[nodiscard]] U8 King(U8 side) const {
    return state_.King(static_cast<Color>(side)).GetLsb();
  }

  // The piece on a square as color * 6 + piece type, with 12 for empty squares
  [[nodiscard]] U8 At(U8 square) const {
    return kPieceCodes[state_.mailbox[square]];
  }

  [[nodiscard]] U8 SideToMove() const {
    return state_.turn;
  }

  [[nodiscard]] U32 HmcBucket() const {
    return kHmcBucketTable[std::min<U16>(state_.fifty_moves_clock, 100)];
  }

 private:
  static constexpr auto kPieceCodes = [] {
    std::array<U8, 32> codes{};
    codes.fill(12);
    for (const auto color : {Color::kWhite, Color::kBlack}) {
      for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
        codes[BoardState::ToMailbox(static_cast<PieceType>(piece), color)] =
            color * 6 + piece;
      }
    }
    return codes;
  }();

  const BoardState& state_;
};

Network* embedded_network = nullptr;

// Per thread so each NUMA node can read its own copy of the network
thread_local Network* network = nullptr;

[[nodiscard]] Network* LoadNetwork() {
  const std::span bytes(reinterpret_cast<const std::byte*>(gEVALData),
                        gEVALSize);

  auto loaded = std::make_unique<Network>();
  if (const auto result = loaded->Load(bytes); !result) {
    fmt::println("Failed to load the embedded network ({} bytes): {}",
                 gEVALSize,
                 result.Message());
    std::abort();
  }

  return loaded.release();
}

}  // namespace

struct Accumulator::Impl {
  explicit Impl(const Network& bound_network)
      : bound_network(&bound_network), stack(bound_network) {}

  const Network* bound_network;
  AccumulatorStack stack;
};

Accumulator::Accumulator() : impl_(std::make_unique<Impl>(*network)) {}

Accumulator::~Accumulator() = default;

void Accumulator::SetFromState(const BoardState& state) {
  if (impl_->bound_network != network) {
    impl_ = std::make_unique<Impl>(*network);
  }
  impl_->stack.Reset(BoardView(state));
}

void Accumulator::PushChanges(const BoardChange& change,
                              const BoardState& state) {
  auto& stack = impl_->stack;
  if (stack.Depth() + 1 == kStackCapacity) {
    stack.Reset(BoardView(state));
    return;
  }

  MantaRay::PieceDelta delta;
  for (int i = 0; i < change.num_removed; ++i) {
    const auto& [square, piece, color] = change.removed[i];
    delta.Remove(static_cast<MantaRay::Piece>(piece), color, square);
  }
  for (int i = 0; i < change.num_added; ++i) {
    const auto& [square, piece, color] = change.added[i];
    delta.Insert(static_cast<MantaRay::Piece>(piece), color, square);
  }

  stack.Push(delta, BoardView(state));
}

void Accumulator::UndoMove(const BoardState& state) {
  auto& stack = impl_->stack;
  // The entries below a re-rooted stack are gone
  if (stack.Depth() == 0) {
    stack.Reset(BoardView(state));
  } else {
    stack.Pop();
  }
}

Score Accumulator::Evaluate(const BoardState& state) {
  return impl_->stack.Evaluate(BoardView(state));
}

void LoadFromIncBin() {
  embedded_network = LoadNetwork();
  network = embedded_network;
}

void UseNetworkForNode(std::optional<std::size_t> node) {
  if (!node) {
    network = embedded_network;
    return;
  }

  static std::mutex mutex;
  static std::vector<Network*> replicas;

  std::lock_guard lock(mutex);
  if (*node >= replicas.size()) {
    replicas.resize(*node + 1, nullptr);
  }

  auto& replica = replicas[*node];
  if (!replica) {
    // Loaded on the calling thread so that the node's memory is first touched
    // by a thread pinned to it
    replica = LoadNetwork();
  }

  network = replica;
}

Score Evaluate(Board& board) {
  return board.GetAccumulator()->Evaluate(board.GetState());
}

}  // namespace nnue
