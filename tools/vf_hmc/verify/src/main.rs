// Independent oracle: replay with the actual crate and its actual training filter.
use std::{fs::File, io::BufReader};
use viriformat::dataformat::{Filter, Game, WDL};

fn main() {
    let args: Vec<_> = std::env::args().collect();
    let mut input = BufReader::new(File::open(&args[1]).unwrap());
    let count: usize = args[2].parse().unwrap();
    let filter = Filter { max_eval: 30000, ..Default::default() };
    let mut rng = rand::rng();
    let mut raw = [0u64; 12];
    let mut eligible = [0u64; 12];
    let mut touching = [0u64; 12];
    let mut eligible_games = [0u64; 12];
    let mut maxima = [0u64; 12];
    let mut kings = [[[0u64; 11]; 16]; 2];
    let kb = [0,1,2,3,4,5,6,7,8,8,9,9,10,10,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15];
    let mut reusable = Vec::new();
    for _ in 0..count {
        let game = Game::deserialise_from(&mut input, reusable).unwrap();
        let (mut board, _, wdl, _) = game.initial_position.unpack();
        let mut seen = [false; 12];
        let mut kept = [false; 12];
        for (mv, eval) in &game.moves {
            let h = usize::from(board.fifty_move_counter()).min(100);
            let b = if h < 14 { 0 } else { 1 + (h - 14) / 8 };
            raw[b] += 1;
            seen[b] = true;
            if !filter.should_filter(*mv, i32::from(eval.get()), &board, WDL::from_packed(wdl), &mut rng) {
                eligible[b] += 1;
                kept[b] = true;
                if b != 0 {
                    let bf = board.to_bulletformat(wdl, eval.get()).unwrap();
                    for (p, sq) in [bf.our_ksq(), bf.opp_ksq()].into_iter().enumerate() {
                        let sq = usize::from(sq);
                        kings[p][kb[sq / 8 * 4 + (sq % 8).min(7 - sq % 8)]][b-1] += 1;
                    }
                }
            }
            board.make_move_simple(*mv);
        }
        if let Some(b) = seen.iter().rposition(|&x| x) { maxima[b] += 1; }
        for b in 0..12 { touching[b] += u64::from(seen[b]); eligible_games[b] += u64::from(kept[b]); }
        reusable = game.moves;
    }
    println!("feature,positions,eligible,games_touching,eligible_games,game_maximum");
    for b in 0..12 {
        println!("{},{},{},{},{},{}", b as i32 - 1, raw[b], eligible[b], touching[b], eligible_games[b], maxima[b]);
    }
    if let Some(path) = args.get(3) {
        use std::io::Write;
        let mut out = File::create(path).unwrap();
        writeln!(out, "perspective,king_bucket,hmc_feature,input_index,eligible").unwrap();
        for p in 0..2 { for k in 0..16 { for h in 0..11 {
            writeln!(out, "{},{},{},{},{}", if p == 0 { "stm" } else { "ntm" }, k, h, k*11+h, kings[p][k][h]).unwrap();
        } } }
    }
}
