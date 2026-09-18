# Viribinpack HMC distribution

Standalone C++20/OpenMP scanner for Viriformat 2.0.1 files. Defaults match
`C:/Users/Aron/Documents/bullet/examples/advanced_ti/{inputs,loader,main}.rs`
as inspected on 2026-09-18. Constants are deliberately fixed to that training
configuration; update them if the training configuration changes.

## Build and run (PowerShell, from the integral repository)

```powershell
g++ -std=c++20 -O3 -march=native -fopenmp -static -o tools/vf_hmc/vf_hmc.exe tools/vf_hmc/vf_hmc.cpp
.\tools\vf_hmc\vf_hmc.exe 'C:\Users\Aron\Documents\bullet\data\binpacks\interleaved.vf' --csv tools/vf_hmc/interleaved
```

`-static` makes the MinGW executable independent of runtime DLLs. Omit
`-march=native` when building for a different CPU. A separate CMake project is
also provided (`cmake -S tools/vf_hmc -B tools/vf_hmc/build`, then
`cmake --build tools/vf_hmc/build --config Release`). Requires a 64-bit build.
Windows and POSIX memory mapping are supported.

Options:

- `--threads N`: workers, defaults to min(16, OpenMP's available processors).
- `--max-games N`: scan a prefix for a quick check; this is not a random sample.
- `--raw-only`: skip training filters and king-feature counts for a faster scan.
- `--csv PREFIX`: write `PREFIX.buckets.csv` and, unless raw-only,
  `PREFIX.king_hmc.csv`. Parent directories must exist. Existing outputs are overwritten.

Progress goes to stderr; redirect stdout to save the text report.

## Interpretation

HMC 0–13 activates no feature (`feature=-1`). Features 0–10 cover 14–21,
22–29, ..., 86–93, 94+. The loader clamps the clock to 100. A position is
counted **before** its stored move, including the initial board when it has a
move. The final board after the last move is not a training record and is not
counted. Games without moves are counted separately.

- **Positions / Raw %**: all stored positions, before filtering.
- **Games touching / Games %**: games with at least one stored position in
  that bucket. These counts overlap across buckets.
- **Eligible / Train %**: exact deterministic training filter: absolute ply
  >=16, at least 4 pieces, abs(eval)<30000, no capture, en passant, promotion,
  or check. Castling is allowed.
- **Eligible games**: games contributing at least one eligible position in
  the bucket, before random skipping.
- **Game maximum**: exclusive distribution by highest bucket reached among
  stored positions. These counts sum to the number of nonempty games.

Training randomly drops each eligible position with probability 0.5.
The scanner reports expected retained counts (eligible / 2), not an arbitrary
random realization. Expected bucket proportions are unchanged. Game counts
are before random skipping; halving them would not give expected retained games.

The king CSV breaks eligible activations down by STM/NTM perspective, all
16 mirrored king buckets, and 11 HMC features. `input_index = king_bucket * 11
+ hmc_feature`, exactly as in the mapper. Each eligible non-fresh position
activates one STM and one NTM feature. The fresh state has no entry here.

The scanner maps the file read-only, locates complete game boundaries in
batches of 262,144 games, then replays them in parallel with per-worker
counters. It keeps no expanded position dataset. OS page caching controls
resident memory. Truncation and basic malformed headers/moves produce a
nonzero exit with a byte offset; this is not a full chess legality validator.
The source file must remain unchanged during the scan.

## Verification

```powershell
g++ -std=c++20 -O2 -fopenmp -static -o tools/vf_hmc/tests.exe tools/vf_hmc/tests.cpp
.\tools\vf_hmc\tests.exe
```

Tests cover every byte-valued HMC bucket, clock updates, captures, en passant,
all promotions, castling including Chess960 overlaps, and check detection.
`verify/` is an independent Rust oracle using the actual Viriformat crate's
board replay, filter, and Bullet conversion; it is not needed to run the utility:

```powershell
cargo run --release --offline --manifest-path tools/vf_hmc/verify/Cargo.toml -- 'C:\Users\Aron\Documents\bullet\data\binpacks\interleaved.vf' 10000 tools/vf_hmc/reference.king.csv > tools/vf_hmc/reference.csv
.\tools\vf_hmc\vf_hmc.exe 'C:\Users\Aron\Documents\bullet\data\binpacks\interleaved.vf' --max-games 10000 --csv tools/vf_hmc/check
Compare-Object (Import-Csv tools/vf_hmc/reference.csv) (Import-Csv tools/vf_hmc/check.buckets.csv) -Property feature,positions,eligible,games_touching,eligible_games,game_maximum
Compare-Object (Import-Csv tools/vf_hmc/reference.king.csv) (Import-Csv tools/vf_hmc/check.king_hmc.csv) -Property perspective,king_bucket,hmc_feature,input_index,eligible
```

No comparison output means exact agreement.
