#ifndef INTEGRAL_REPORTER_H
#define INTEGRAL_REPORTER_H

#include <fmt/color.h>
#include <fmt/core.h>

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "../evaluation/evaluation.h"

namespace uci::reporter {

// Global flag indicating whether UCI mode is enabled
inline bool using_uci = false;

class ReportInfo {
 public:
  virtual ~ReportInfo() = default;

  virtual void Print(int depth,
                     int sel_depth,
                     bool is_mate,
                     int score,
                     int64_t nodes_searched,
                     int64_t time_elapsed,
                     int64_t nps,
                     int hash_full,
                     bool syzygy_enabled,
                     int64_t tb_hits,
                     const std::string& pv) const = 0;

 protected:
  virtual std::string FormatScore(bool is_mate, int score) const = 0;

  static std::string FormatNumber(int64_t number) {
    // Define a custom numpunct facet to specify the thousands separator
    struct comma_numpunct : std::numpunct<char> {
     protected:
      char do_thousands_sep() const override {
        return ',';
      }  // Use comma as separator
      std::string do_grouping() const override {
        return "\3";
      }  // Group digits in threes
    };

    std::stringstream ss;
    // Imbue the stringstream with the custom locale
    ss.imbue(std::locale(std::locale::classic(), new comma_numpunct));
    ss << std::fixed << std::setprecision(0) << number;
    return ss.str();
  }

  static fmt::rgb GetScoreColor(int score) {
    constexpr fmt::rgb kLosingColor(242, 119, 119);  // Negative score color
    constexpr fmt::rgb kWinningColor(124, 230, 147);   // Positive score color
    constexpr fmt::rgb kDrawColor(237, 228, 133);     // Draw score color

    // Return the appropriate color based on the score
    if (score > 10) {
      // Positive score: use green
      return kWinningColor;
    } else if (score < -10) {
      // Negative score: use red
      return kLosingColor;
    } else {
      // Near zero: considered a draw, use yellowish color
      return kDrawColor;
    }
  }

  static fmt::rgb GetPVMoveColor(size_t index, size_t total) {
    // Gradient from white to pastel blue and back
    float progress = static_cast<float>(index) / std::max(total - 1, size_t(1));
    float hue = 174.0f;  // Light blue
    float saturation = (progress < 0.5f ? progress : (1.0f - progress)) * 1.2f;
    float value = 0.8f;

    return HSVtoRGB(hue, saturation, value);
  }

 private:
  static fmt::rgb HSVtoRGB(float hue, float saturation, float value) {
    float c = value * saturation;
    float x = c * (1.0f - std::fabs(std::fmod(hue / 60.0f, 2) - 1.0f));
    float m = value - c;

    float r = 0, g = 0, b = 0;
    if (0 <= hue && hue < 60) {
      r = c, g = x, b = 0;
    } else if (60 <= hue && hue < 120) {
      r = x, g = c, b = 0;
    } else if (120 <= hue && hue < 180) {
      r = 0, g = c, b = x;
    } else if (180 <= hue && hue < 240) {
      r = 0, g = x, b = c;
    } else if (240 <= hue && hue < 300) {
      r = x, g = 0, b = c;
    } else if (300 <= hue && hue < 360) {
      r = c, g = 0, b = x;
    }

    return fmt::rgb(static_cast<uint8_t>((r + m) * 255),
                    static_cast<uint8_t>((g + m) * 255),
                    static_cast<uint8_t>((b + m) * 255));
  }
};

class UCIReportInfo : public ReportInfo {
 public:
  void Print(int depth,
             int sel_depth,
             bool is_mate,
             int score,
             int64_t nodes_searched,
             int64_t time_elapsed,
             int64_t nps,
             int hash_full,
             bool syzygy_enabled,
             int64_t tb_hits,
             const std::string& pv) const override {
    fmt::print(
        "info depth {} seldepth {} score {} nodes {} time {} nps {} "
        "hashfull {}{}{} pv {}\n",
        depth,
        sel_depth,
        FormatScore(is_mate, score),
        nodes_searched,
        time_elapsed,
        nps,
        hash_full,
        syzygy_enabled ? " tbhits " : "",
        syzygy_enabled ? std::to_string(tb_hits) : "",
        pv);
  }

 protected:
  std::string FormatScore(bool is_mate, int score) const override {
    return is_mate ? fmt::format("mate {}", eval::MateIn(score))
                   : fmt::format("cp {}", score);
  }
};

class PrettyReportInfo : public ReportInfo {
 public:
  void Print(int depth,
             int sel_depth,
             bool is_mate,
             int score,
             int64_t nodes_searched,
             int64_t time_elapsed,
             int64_t nps,
             int hash_full,
             bool syzygy_enabled,
             int64_t tb_hits,
             const std::string& pv) const override {
    // Define color constants
    const auto dark_gray = fmt::rgb(143, 143, 143);
    const auto light_gray = fmt::rgb(184, 184, 184);
    const auto grayish_white = fmt::rgb(220, 220, 220);

    // Depth and Selective Depth
    fmt::print(fg(dark_gray), "depth: ");
    fmt::print(
        fg(light_gray), "{:>6}  ", fmt::format("{}/{}", depth, sel_depth));

    // Time
    fmt::print(fg(dark_gray), "time: ");
    fmt::print(fg(grayish_white), "{:6d} ", time_elapsed);
    fmt::print(fg(light_gray), "ms  ");

    // Nodes
    fmt::print(fg(dark_gray), "nodes: ");
    fmt::print(fg(grayish_white), "{:>12s}", FormatNumber(nodes_searched));
    fmt::print(fg(light_gray), "  ");

    // NPS (Nodes Per Second)
    fmt::print(fg(dark_gray), "nps: ");
    fmt::print(
        fg(grayish_white), "{:5.2f}", static_cast<double>(nps) / 1'000'000);
    fmt::print(fg(light_gray), " mil  ");

    // Hash Fullness
    fmt::print(fg(dark_gray), "hash: ");
    fmt::print(fg(grayish_white), "{:3d}", hash_full / 10);
    fmt::print(fg(light_gray), "%  ");

    // Score
    fmt::print(fg(GetScoreColor(score)) | fmt::emphasis::bold,
               "{}  ",
               FormatScore(is_mate, score));

    // Principal Variation (PV)
    const auto moves = SplitString(pv, ' ');
    for (size_t i = 0; i < moves.size(); ++i) {
      fmt::print(fg(GetPVMoveColor(i, moves.size())), "{} ", moves[i]);
    }

    fmt::print("\n");
  }

 protected:
  std::string FormatScore(bool is_mate, int score) const override {
    if (is_mate) {
      return fmt::format("#{}", eval::MateIn(score));
    } else {
      // Convert centipawns to pawns and format with sign and two decimal places
      return fmt::format("{}{:.2f}",
                         score > 0 ? "+" : "",
                         static_cast<float>(score) / 100.0f);
    }
  }
};

}  // namespace uci::reporter

#endif  // INTEGRAL_REPORTER_H
