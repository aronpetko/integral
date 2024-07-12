#ifndef SPRT_SH_CONSTANTS_H
#define SPRT_SH_CONSTANTS_H

#include "../../tuner/spsa.h"

Tunable lmr_quiet_base("lmr_quiet_base", 0.85, 0.5, 1.2, 0.05);
Tunable lmr_quiet_div("lmr_quiet_div", 2.15, 1.5, 3.0, 0.05);
Tunable lmr_tact_base("lmr_tact_base", -0.15, -0.5, 0.2, 0.05);
Tunable lmr_tact_div("lmr_tact_div", 2.57, 2.0, 3.5, 0.05);

Tunable asp_window_depth("asp_window_depth", 4, 2, 8, 1, true);
Tunable asp_window_delta("asp_window_delta", 10, 5, 20, 0.8);
Tunable asp_window_growth("asp_window_growth", 0.5, 0.25, 0.75, 0.08);

Tunable qs_fut_margin("qs_fut_margin", 100, 50, 200, 10);

Tunable rev_fut_depth("rev_fut_depth", 6, 4, 10, 1, true);
Tunable rev_fut_margin("rev_fut_margin", 75, 50, 150, 8);

Tunable null_move_rb("null_move_rb", 3, 1, 5, 0.5, true);
Tunable null_move_rf("null_move_rf", 4, 2, 8, 1, true);
Tunable null_move_re("null_move_re", 200, 100, 400, 15);

Tunable iir_depth("iir_depth", 4, 2, 8, 1, true);

Tunable improving_rate_divisor("improving_rate_divisor", 25.0, 5.0, 100.0, 15.0);

Tunable lmp_base("lmp_base", 3.0, 1.5, 5.0, 0.5);
Tunable lmp_mult("lmp_mult", 2.0, 1.0, 4.0, 0.25);

Tunable fut_prune_depth("fut_prune_depth", 8, 6, 12, 1, true);
Tunable fut_margin_base("fut_margin_base", 150, 100, 250, 20);
Tunable fut_margin_mult("fut_margin_mult", 100, 50, 200, 8);

Tunable see_prune_depth("see_prune_depth", 8, 6, 12, 1, true);
Tunable see_quiet_thresh("see_quiet_thresh", -60, -100, -20, 6);
Tunable see_noisy_thresh("see_noisy_thresh", -130, -200, -50, 8);

Tunable hist_prune_depth("hist_prune_depth", 5, 3, 8, 1, true);
Tunable hist_thresh_base("hist_thresh_base", -500, -1000, 500, 100);
Tunable hist_thresh_mult("hist_thresh_mult", -1500, -3000, -250, 100);

Tunable lmr_hist_div("lmr_hist_div", 10000, 5000, 20000, 750);

Tunable sing_ext_depth("sing_ext_depth", 8, 6, 12, 1, true);
Tunable sing_ext_margin("sing_ext_margin", 2.0, 1.0, 4.0, 0.5);
Tunable sing_double_margin("sing_double_margin", 25, 10, 40, 2);
 
#endif  // SPRT_SH_CONSTANTS_H