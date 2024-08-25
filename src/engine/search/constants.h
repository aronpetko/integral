#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

Tunable lmr_quiet_base("lmr_quiet_base", 0.80, 0.5, 1.2, 0.05);
Tunable lmr_quiet_div("lmr_quiet_div", 2.04, 1.5, 3.0, 0.1);
Tunable lmr_tact_base("lmr_tact_base", -0.24, -0.5, 0.2, 0.05);
Tunable lmr_tact_div("lmr_tact_div", 2.60, 2.0, 3.5, 0.1);

Tunable asp_window_depth("asp_window_depth", 4, 2, 8, 1, true);
Tunable asp_window_delta("asp_window_delta", 9, 5, 20, 2);
Tunable asp_window_growth("asp_window_growth", 1.55, 0.1, 2.0, 0.05);

Tunable qs_fut_margin("qs_fut_margin", 101, 50, 200, 10);

Tunable rev_fut_depth("rev_fut_depth", 6, 4, 10, 1, true);
Tunable rev_fut_margin("rev_fut_margin", 74, 50, 150, 8);

Tunable null_move_rb("null_move_rb", 4, 1, 5, 0.5);
Tunable null_move_rf("null_move_rf", 4, 2, 8, 1, true);
Tunable null_move_re("null_move_re", 202, 100, 400, 20);

Tunable iir_depth("iir_depth", 4, 2, 8, 1);

Tunable improving_rate_divisor(
    "improving_rate_divisor", 30.0, 5.0, 100.0, 15.0);

Tunable lmp_base("lmp_base", 5.0, 1.5, 5.0, 0.5);
Tunable lmp_mult("lmp_mult", 3, 1.0, 4.0, 0.25);

Tunable fut_prune_depth("fut_prune_depth", 8, 6, 12, 1, true);
Tunable fut_margin_base("fut_margin_base", 196, 100, 250, 20);
Tunable fut_margin_mult("fut_margin_mult", 96, 50, 200, 15);

Tunable see_prune_depth("see_prune_depth", 8, 6, 12, 1, true);
Tunable see_quiet_thresh("see_quiet_thresh", -64, -100, -20, 6);
Tunable see_noisy_thresh("see_noisy_thresh", -119, -200, -50, 8);

Tunable hist_prune_depth("hist_prune_depth", 5, 3, 8, 1, true);
Tunable hist_thresh_base("hist_thresh_base", -480, -1000, 500, 100);
Tunable hist_thresh_mult("hist_thresh_mult", -1695, -3000, -250, 300);

Tunable lmr_hist_div("lmr_hist_div", 11432, 5000, 20000, 750);

Tunable sing_ext_depth("sing_ext_depth", 8, 6, 12, 1, true);
Tunable sing_ext_margin("sing_ext_margin", 2.00, 1.0, 4.0, 0.5);
Tunable sing_double_margin("sing_double_margin", 20, 10, 40, 5);

Tunable probcut_beta_delta("probcut_beta_delta", 250, 150, 350, 15);


}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H