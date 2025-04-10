<div align="center">
<img src="https://i.imgur.com/R7wOg9n.png" alt="Integral Chess Engine" width="150" height="150"/>
<h3>Integral</h3>
Integral is a top chess engine developed in C++. It is a personal project developed with the goal of meshing my admiration for chess with programming.
<br>
<br>
<strong>Play against Integral on <a href="https://lichess.org/@/IntegralBot">Lichess</a></strong>

</div>

## Search
Integral implements the widely adopted negamax search approach with alpha-beta pruning, and alongside it the various search heuristics that it enables. It utilizes the Lazy SMP approach for multi-threaded search, and has been proven to scale very well at higher thread counts compared to other alpha-beta chess engines.

## Evaluation
Integral utilizes an efficiently updatable neural network (NNUE) for its evaluation function.

### Architecture
Integral's neural network is a horizontally mirrored perspective network, containing 12 factorized king input buckets, an L1 of 1280 neurons, an L2 of 16 neurons, an L3 of 32 neurons, and 8 output buckets.
`(768x12 (Factorized) -> 1280)x2 -> (16 -> 32 -> 1)1x8`

### Data Generation Process
This neural network is trained on tens of millions of self-play games. Each self-play game has a unique opening of eight to nine random moves. These random moves are chosen across a probability distribution based on the piece moving, i.e. pawn, knight, and bishop moves are more likely to be played than king, queen, or rook moves. The probability distribution also slightly skews moves toward the center of the board, which hopefully encourages meaningful openings from which Integral can play from. Lastly, 5-man Syzygy endgame tablebases are used in the search. 

### Training Process
The first iteration of Integral's neural network was trained on data from version 4, which had a powerful hand-crafted evaluation (HCE). Each iteration of Integral's neural network since then has been trained on a fresh dataset using the prior network.
All networks are trained using the <a href="https://github.com/jw1912/bullet">Bullet</a> trainer, which has made my life way easier. 

## Compiling Integral
> [!NOTE]  
> Integral should be compiled with GCC >= v13 or Clang >= v10

Integral provides a Makefile for compilation, but you can use CMake as well.\
To compile Integral, enter the following commands in a terminal:
```
git clone https://github.com/aronpetko/integral
cd integral
make [native | vnni512 | avx512 | avx2_bmi2 | avx2 | sse41_popcnt]
```