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
Integral's neural network is a horizontally mirrored perspective network, containing 12 factorized king input buckets with threat inputs and fifty-move rule inputs, an L1 of 768 neurons, an L2 of 16 neurons, an L3 of 32 neurons, and 8 output buckets.

`[(768 + 1x11)x12hm (Factorized) + 60144hm -> 768]x2 -> (16 -> 32 -> 1)1x8`

### Data Generation Process
This neural network is trained on hundreds of millions of self-play games. Most self-play games starts with 3-4 randomly selected moves off a randomly selected opening from the **UHO_Lichess_4852_v1** book. Additionally, a majority of the data uses 5-man Syzygy endgame tablebases to guide the data generation search. 

### Training Process
The first iteration of Integral's neural network was trained on data from version 4, which had a powerful hand-crafted evaluation (HCE). All early-network data has been thrown out and a majority of Integral's data is generated using a search of 20k soft-nodes per-side. The datasets Integral trains on is publicy available through my [Huggingface repository](https://huggingface.co/aronpetkovski/integral-datasets/tree/main).
Networks are trained using the <a href="https://github.com/jw1912/bullet">Bullet</a> trainer.

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