#include "../chess/board.h"
#include "../chess/move_gen.h"
#include "tests.h"

namespace tests {

// clang-format off
constexpr std::array kPerftSuite = {
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ;D1 20 ;D2 400 ;D3 8902 ;D4 197281 ;D5 4865609 ;D6 119060324",
    "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ;D1 48 ;D2 2039 ;D3 97862 ;D4 4085603 ;D5 193690690",
    "4k3/8/8/8/8/8/8/4K2R w K - 0 1 ;D1 15 ;D2 66 ;D3 1197 ;D4 7059 ;D5 133987 ;D6 764643",
    "4k3/8/8/8/8/8/8/R3K3 w Q - 0 1 ;D1 16 ;D2 71 ;D3 1287 ;D4 7626 ;D5 145232 ;D6 846648",
    "4k2r/8/8/8/8/8/8/4K3 w k - 0 1 ;D1 5 ;D2 75 ;D3 459 ;D4 8290 ;D5 47635 ;D6 899442",
    "r3k3/8/8/8/8/8/8/4K3 w q - 0 1 ;D1 5 ;D2 80 ;D3 493 ;D4 8897 ;D5 52710 ;D6 1001523",
    "4k3/8/8/8/8/8/8/R3K2R w KQ - 0 1 ;D1 26 ;D2 112 ;D3 3189 ;D4 17945 ;D5 532933 ;D6 2788982",
    "r3k2r/8/8/8/8/8/8/4K3 w kq - 0 1 ;D1 5 ;D2 130 ;D3 782 ;D4 22180 ;D5 118882 ;D6 3517770",
    "8/8/8/8/8/8/6k1/4K2R w K - 0 1 ;D1 12 ;D2 38 ;D3 564 ;D4 2219 ;D5 37735 ;D6 185867",
    "8/8/8/8/8/8/1k6/R3K3 w Q - 0 1 ;D1 15 ;D2 65 ;D3 1018 ;D4 4573 ;D5 80619 ;D6 413018",
    "4k2r/6K1/8/8/8/8/8/8 w k - 0 1 ;D1 3 ;D2 32 ;D3 134 ;D4 2073 ;D5 10485 ;D6 179869",
    "r3k3/1K6/8/8/8/8/8/8 w q - 0 1 ;D1 4 ;D2 49 ;D3 243 ;D4 3991 ;D5 20780 ;D6 367724",
    "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1 ;D1 26 ;D2 568 ;D3 13744 ;D4 314346 ;D5 7594526 ;D6 179862938",
    "r3k2r/8/8/8/8/8/8/1R2K2R w Kkq - 0 1 ;D1 25 ;D2 567 ;D3 14095 ;D4 328965 ;D5 8153719 ;D6 195629489",
    "r3k2r/8/8/8/8/8/8/2R1K2R w Kkq - 0 1 ;D1 25 ;D2 548 ;D3 13502 ;D4 312835 ;D5 7736373 ;D6 184411439",
    "r3k2r/8/8/8/8/8/8/R3K1R1 w Qkq - 0 1 ;D1 25 ;D2 547 ;D3 13579 ;D4 316214 ;D5 7878456 ;D6 189224276",
    "1r2k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1 ;D1 26 ;D2 583 ;D3 14252 ;D4 334705 ;D5 8198901 ;D6 198328929",
    "2r1k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1 ;D1 25 ;D2 560 ;D3 13592 ;D4 317324 ;D5 7710115 ;D6 185959088",
    "r3k1r1/8/8/8/8/8/8/R3K2R w KQq - 0 1 ;D1 25 ;D2 560 ;D3 13607 ;D4 320792 ;D5 7848606 ;D6 190755813",
    "4k3/8/8/8/8/8/8/4K2R b K - 0 1 ;D1 5 ;D2 75 ;D3 459 ;D4 8290 ;D5 47635 ;D6 899442",
    "4k3/8/8/8/8/8/8/R3K3 b Q - 0 1 ;D1 5 ;D2 80 ;D3 493 ;D4 8897 ;D5 52710 ;D6 1001523",
    "4k2r/8/8/8/8/8/8/4K3 b k - 0 1 ;D1 15 ;D2 66 ;D3 1197 ;D4 7059 ;D5 133987 ;D6 764643",
    "r3k3/8/8/8/8/8/8/4K3 b q - 0 1 ;D1 16 ;D2 71 ;D3 1287 ;D4 7626 ;D5 145232 ;D6 846648",
    "4k3/8/8/8/8/8/8/R3K2R b KQ - 0 1 ;D1 5 ;D2 130 ;D3 782 ;D4 22180 ;D5 118882 ;D6 3517770",
    "r3k2r/8/8/8/8/8/8/4K3 b kq - 0 1 ;D1 26 ;D2 112 ;D3 3189 ;D4 17945 ;D5 532933 ;D6 2788982",
    "8/8/8/8/8/8/6k1/4K2R b K - 0 1 ;D1 3 ;D2 32 ;D3 134 ;D4 2073 ;D5 10485 ;D6 179869",
    "8/8/8/8/8/8/1k6/R3K3 b Q - 0 1 ;D1 4 ;D2 49 ;D3 243 ;D4 3991 ;D5 20780 ;D6 367724",
    "4k2r/6K1/8/8/8/8/8/8 b k - 0 1 ;D1 12 ;D2 38 ;D3 564 ;D4 2219 ;D5 37735 ;D6 185867",
    "r3k3/1K6/8/8/8/8/8/8 b q - 0 1 ;D1 15 ;D2 65 ;D3 1018 ;D4 4573 ;D5 80619 ;D6 413018",
    "r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1 ;D1 26 ;D2 568 ;D3 13744 ;D4 314346 ;D5 7594526 ;D6 179862938",
    "r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1 ;D1 26 ;D2 583 ;D3 14252 ;D4 334705 ;D5 8198901 ;D6 198328929",
    "r3k2r/8/8/8/8/8/8/2R1K2R b Kkq - 0 1 ;D1 25 ;D2 560 ;D3 13592 ;D4 317324 ;D5 7710115 ;D6 185959088",
    "r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1 ;D1 25 ;D2 560 ;D3 13607 ;D4 320792 ;D5 7848606 ;D6 190755813",
    "1r2k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1 ;D1 25 ;D2 567 ;D3 14095 ;D4 328965 ;D5 8153719 ;D6 195629489",
    "2r1k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1 ;D1 25 ;D2 548 ;D3 13502 ;D4 312835 ;D5 7736373 ;D6 184411439",
    "r3k1r1/8/8/8/8/8/8/R3K2R b KQq - 0 1 ;D1 25 ;D2 547 ;D3 13579 ;D4 316214 ;D5 7878456 ;D6 189224276",
    "8/1n4N1/2k5/8/8/5K2/1N4n1/8 w - - 0 1 ;D1 14 ;D2 195 ;D3 2760 ;D4 38675 ;D5 570726 ;D6 8107539",
    "8/1k6/8/5N2/8/4n3/8/2K5 w - - 0 1 ;D1 11 ;D2 156 ;D3 1636 ;D4 20534 ;D5 223507 ;D6 2594412",
    "8/8/4k3/3Nn3/3nN3/4K3/8/8 w - - 0 1 ;D1 19 ;D2 289 ;D3 4442 ;D4 73584 ;D5 1198299 ;D6 19870403",
    "K7/8/2n5/1n6/8/8/8/k6N w - - 0 1 ;D1 3 ;D2 51 ;D3 345 ;D4 5301 ;D5 38348 ;D6 588695",
    "k7/8/2N5/1N6/8/8/8/K6n w - - 0 1 ;D1 17 ;D2 54 ;D3 835 ;D4 5910 ;D5 92250 ;D6 688780",
    "8/1n4N1/2k5/8/8/5K2/1N4n1/8 b - - 0 1 ;D1 15 ;D2 193 ;D3 2816 ;D4 40039 ;D5 582642 ;D6 8503277",
    "8/1k6/8/5N2/8/4n3/8/2K5 b - - 0 1 ;D1 16 ;D2 180 ;D3 2290 ;D4 24640 ;D5 288141 ;D6 3147566",
    "8/8/3K4/3Nn3/3nN3/4k3/8/8 b - - 0 1 ;D1 4 ;D2 68 ;D3 1118 ;D4 16199 ;D5 281190 ;D6 4405103",
    "K7/8/2n5/1n6/8/8/8/k6N b - - 0 1 ;D1 17 ;D2 54 ;D3 835 ;D4 5910 ;D5 92250 ;D6 688780",
    "k7/8/2N5/1N6/8/8/8/K6n b - - 0 1 ;D1 3 ;D2 51 ;D3 345 ;D4 5301 ;D5 38348 ;D6 588695",
    "B6b/8/8/8/2K5/4k3/8/b6B w - - 0 1 ;D1 17 ;D2 278 ;D3 4607 ;D4 76778 ;D5 1320507 ;D6 22823890",
    "8/8/1B6/7b/7k/8/2B1b3/7K w - - 0 1 ;D1 21 ;D2 316 ;D3 5744 ;D4 93338 ;D5 1713368 ;D6 28861171",
    "k7/B7/1B6/1B6/8/8/8/K6b w - - 0 1 ;D1 21 ;D2 144 ;D3 3242 ;D4 32955 ;D5 787524 ;D6 7881673",
    "K7/b7/1b6/1b6/8/8/8/k6B w - - 0 1 ;D1 7 ;D2 143 ;D3 1416 ;D4 31787 ;D5 310862 ;D6 7382896",
    "B6b/8/8/8/2K5/5k2/8/b6B b - - 0 1 ;D1 6 ;D2 106 ;D3 1829 ;D4 31151 ;D5 530585 ;D6 9250746",
    "8/8/1B6/7b/7k/8/2B1b3/7K b - - 0 1 ;D1 17 ;D2 309 ;D3 5133 ;D4 93603 ;D5 1591064 ;D6 29027891",
    "k7/B7/1B6/1B6/8/8/8/K6b b - - 0 1 ;D1 7 ;D2 143 ;D3 1416 ;D4 31787 ;D5 310862 ;D6 7382896",
    "K7/b7/1b6/1b6/8/8/8/k6B b - - 0 1 ;D1 21 ;D2 144 ;D3 3242 ;D4 32955 ;D5 787524 ;D6 7881673",
    "7k/RR6/8/8/8/8/rr6/7K w - - 0 1 ;D1 19 ;D2 275 ;D3 5300 ;D4 104342 ;D5 2161211 ;D6 44956585",
    "R6r/8/8/2K5/5k2/8/8/r6R w - - 0 1 ;D1 36 ;D2 1027 ;D3 29215 ;D4 771461 ;D5 20506480 ;D6 525169084",
    "7k/RR6/8/8/8/8/rr6/7K b - - 0 1 ;D1 19 ;D2 275 ;D3 5300 ;D4 104342 ;D5 2161211 ;D6 44956585",
    "R6r/8/8/2K5/5k2/8/8/r6R b - - 0 1 ;D1 36 ;D2 1027 ;D3 29227 ;D4 771368 ;D5 20521342 ;D6 524966748",
    "6kq/8/8/8/8/8/8/7K w - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507",
    "6KQ/8/8/8/8/8/8/7k b - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507",
    "K7/8/8/3Q4/4q3/8/8/7k w - - 0 1 ;D1 6 ;D2 35 ;D3 495 ;D4 8349 ;D5 166741 ;D6 3370175",
    "6qk/8/8/8/8/8/8/7K b - - 0 1 ;D1 22 ;D2 43 ;D3 1015 ;D4 4167 ;D5 105749 ;D6 419369",
    "6KQ/8/8/8/8/8/8/7k b - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507",
    "K7/8/8/3Q4/4q3/8/8/7k b - - 0 1 ;D1 6 ;D2 35 ;D3 495 ;D4 8349 ;D5 166741 ;D6 3370175",
    "8/8/8/8/8/K7/P7/k7 w - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249",
    "8/8/8/8/8/7K/7P/7k w - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249",
    "K7/p7/k7/8/8/8/8/8 w - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343",
    "7K/7p/7k/8/8/8/8/8 w - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343",
    "8/2k1p3/3pP3/3P2K1/8/8/8/8 w - - 0 1 ;D1 7 ;D2 35 ;D3 210 ;D4 1091 ;D5 7028 ;D6 34834",
    "8/8/8/8/8/K7/P7/k7 b - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343",
    "8/8/8/8/8/7K/7P/7k b - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343",
    "K7/p7/k7/8/8/8/8/8 b - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249",
    "7K/7p/7k/8/8/8/8/8 b - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249",
    "8/2k1p3/3pP3/3P2K1/8/8/8/8 b - - 0 1 ;D1 5 ;D2 35 ;D3 182 ;D4 1091 ;D5 5408 ;D6 34822",
    "8/8/8/8/8/4k3/4P3/4K3 w - - 0 1 ;D1 2 ;D2 8 ;D3 44 ;D4 282 ;D5 1814 ;D6 11848",
    "4k3/4p3/4K3/8/8/8/8/8 b - - 0 1 ;D1 2 ;D2 8 ;D3 44 ;D4 282 ;D5 1814 ;D6 11848",
    "8/8/7k/7p/7P/7K/8/8 w - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724",
    "8/8/k7/p7/P7/K7/8/8 w - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724",
    "8/8/3k4/3p4/3P4/3K4/8/8 w - - 0 1 ;D1 5 ;D2 25 ;D3 180 ;D4 1294 ;D5 8296 ;D6 53138",
    "8/3k4/3p4/8/3P4/3K4/8/8 w - - 0 1 ;D1 8 ;D2 61 ;D3 483 ;D4 3213 ;D5 23599 ;D6 157093",
    "8/8/3k4/3p4/8/3P4/3K4/8 w - - 0 1 ;D1 8 ;D2 61 ;D3 411 ;D4 3213 ;D5 21637 ;D6 158065",
    "k7/8/3p4/8/3P4/8/8/7K w - - 0 1 ;D1 4 ;D2 15 ;D3 90 ;D4 534 ;D5 3450 ;D6 20960",
    "8/8/7k/7p/7P/7K/8/8 b - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724",
    "8/8/k7/p7/P7/K7/8/8 b - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724",
    "8/8/3k4/3p4/3P4/3K4/8/8 b - - 0 1 ;D1 5 ;D2 25 ;D3 180 ;D4 1294 ;D5 8296 ;D6 53138",
    "8/3k4/3p4/8/3P4/3K4/8/8 b - - 0 1 ;D1 8 ;D2 61 ;D3 411 ;D4 3213 ;D5 21637 ;D6 158065",
    "8/8/3k4/3p4/8/3P4/3K4/8 b - - 0 1 ;D1 8 ;D2 61 ;D3 483 ;D4 3213 ;D5 23599 ;D6 157093",
    "k7/8/3p4/8/3P4/8/8/7K b - - 0 1 ;D1 4 ;D2 15 ;D3 89 ;D4 537 ;D5 3309 ;D6 21104",
    "7k/3p4/8/8/3P4/8/8/K7 w - - 0 1 ;D1 4 ;D2 19 ;D3 117 ;D4 720 ;D5 4661 ;D6 32191",
    "7k/8/8/3p4/8/8/3P4/K7 w - - 0 1 ;D1 5 ;D2 19 ;D3 116 ;D4 716 ;D5 4786 ;D6 30980",
    "k7/8/8/7p/6P1/8/8/K7 w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "k7/8/7p/8/8/6P1/8/K7 w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/8/8/6p1/7P/8/8/K7 w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "k7/8/6p1/8/8/7P/8/K7 w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/8/8/3p4/4p3/8/8/7K w - - 0 1 ;D1 3 ;D2 15 ;D3 84 ;D4 573 ;D5 3013 ;D6 22886",
    "k7/8/3p4/8/8/4P3/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4271 ;D6 28662",
    "7k/3p4/8/8/3P4/8/8/K7 b - - 0 1 ;D1 5 ;D2 19 ;D3 117 ;D4 720 ;D5 5014 ;D6 32167",
    "7k/8/8/3p4/8/8/3P4/K7 b - - 0 1 ;D1 4 ;D2 19 ;D3 117 ;D4 712 ;D5 4658 ;D6 30749",
    "k7/8/8/7p/6P1/8/8/K7 b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "k7/8/7p/8/8/6P1/8/K7 b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/8/8/6p1/7P/8/8/K7 b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "k7/8/6p1/8/8/7P/8/K7 b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/8/8/3p4/4p3/8/8/7K b - - 0 1 ;D1 5 ;D2 15 ;D3 102 ;D4 569 ;D5 4337 ;D6 22579",
    "k7/8/3p4/8/8/4P3/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4271 ;D6 28662",
    "7k/8/8/p7/1P6/8/8/7K w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "7k/8/p7/8/8/1P6/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "7k/8/8/1p6/P7/8/8/7K w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "7k/8/1p6/8/8/P7/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/7p/8/8/8/8/6P1/K7 w - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338",
    "k7/6p1/8/8/8/8/7P/K7 w - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338",
    "3k4/3pp3/8/8/8/8/3PP3/3K4 w - - 0 1 ;D1 7 ;D2 49 ;D3 378 ;D4 2902 ;D5 24122 ;D6 199002",
    "7k/8/8/p7/1P6/8/8/7K b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "7k/8/p7/8/8/1P6/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "7k/8/8/1p6/P7/8/8/7K b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874",
    "7k/8/1p6/8/8/P7/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679",
    "k7/7p/8/8/8/8/6P1/K7 b - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338",
    "k7/6p1/8/8/8/8/7P/K7 b - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338",
    "3k4/3pp3/8/8/8/8/3PP3/3K4 b - - 0 1 ;D1 7 ;D2 49 ;D3 378 ;D4 2902 ;D5 24122 ;D6 199002",
    "8/Pk6/8/8/8/8/6Kp/8 w - - 0 1 ;D1 11 ;D2 97 ;D3 887 ;D4 8048 ;D5 90606 ;D6 1030499",
    "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N w - - 0 1 ;D1 24 ;D2 421 ;D3 7421 ;D4 124608 ;D5 2193768 ;D6 37665329",
    "8/PPPk4/8/8/8/8/4Kppp/8 w - - 0 1 ;D1 18 ;D2 270 ;D3 4699 ;D4 79355 ;D5 1533145 ;D6 28859283",
    "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - - 0 1 ;D1 24 ;D2 496 ;D3 9483 ;D4 182838 ;D5 3605103 ;D6 71179139",
    "8/Pk6/8/8/8/8/6Kp/8 b - - 0 1 ;D1 11 ;D2 97 ;D3 887 ;D4 8048 ;D5 90606 ;D6 1030499",
    "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N b - - 0 1 ;D1 24 ;D2 421 ;D3 7421 ;D4 124608 ;D5 2193768 ;D6 37665329",
    "8/PPPk4/8/8/8/8/4Kppp/8 b - - 0 1 ;D1 18 ;D2 270 ;D3 4699 ;D4 79355 ;D5 1533145 ;D6 28859283",
    "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1 ;D1 24 ;D2 496 ;D3 9483 ;D4 182838 ;D5 3605103 ;D6 71179139",
    "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1 ;D4 43238 ;D5 674624 ;D6 11030083",
    "rnbqkb1r/ppppp1pp/7n/4Pp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3 ;D5 11139762",
};
// clang-format on

enum class PerftType {
  kNormal,
  kSplit
};

template <PerftType type>
U64 PertInternal(Board &board, int depth, int start_depth) {
  U64 total_nodes = 0;

  auto moves = move_gen::GenerateMoves(MoveGenType::kAll, board);
  for (int i = 0; i < moves.Size(); i++) {
    const auto move = moves[i];
    if (!board.IsMoveLegal(move)) continue;

    U64 child_nodes;
    if (depth == 1) {
      // Bulk counting
      total_nodes += child_nodes = 1;
    } else {
      board.MakeMove<false>(move);
      total_nodes += child_nodes =
          PertInternal<PerftType::kNormal>(board, depth - 1, start_depth);
      board.UndoMove();
    }

    if (type == PerftType::kSplit && depth == start_depth) {
      fmt::println("{}: {}", move.ToString(), child_nodes);
    }
  }

  return total_nodes;
}

void Perft(Board &board, int depth) {
  assert(depth >= 0);

  const auto start_time = std::chrono::steady_clock::now();
  const U64 nodes = PertInternal<PerftType::kSplit>(board, depth, depth);
  const auto elapsed = duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - start_time);

  fmt::println(
      "info nodes {} time {} nps {}",
      nodes,
      elapsed.count(),
      static_cast<U64>(nodes * 1000 / std::max<U64>(elapsed.count(), 1)));
}

void PerftSuite() {
  fmt::println("starting perft test");
  const auto start_time = std::chrono::steady_clock::now();

  Board board;
  for (const auto &perft_test : kPerftSuite) {
    const auto test_data = SplitString(perft_test, ';');
    board.SetFromFen(test_data[0]);

    bool passed = true;
    for (std::size_t i = 1; i < test_data.size(); i++) {
      const auto answer_data = SplitString(test_data[i], ' ');
      const int test_depth = std::stoi(answer_data[0].substr(1));
      const U64 correct_nodes = std::stoi(answer_data[1]);

      if (PertInternal<PerftType::kNormal>(board, test_depth, test_depth) !=
          correct_nodes) {
        passed = false;
      }
    }

    fmt::println("{}\033[0m {}",
                 passed ? "\033[32mpassed" : "\033[31mfailed",
                 perft_test);
  }

  const auto elapsed = duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - start_time);
  fmt::println("test finished in {}ms", elapsed.count());
}

}  // namespace tests