<div align="center">
<img src="https://i.imgur.com/R7wOg9n.png" alt="Integral Chess Engine" width="150" height="150"/>
<h3>Integral</h3>
<a href="https://www.sp-cc.de/"><img src="https://img.shields.io/badge/dynamic/regex?url=https%3A%2F%2Fwww.sp-cc.de%2F&amp;search=Program(%3F%3A%5Cs%7C%26nbsp%3B)%2BCelo%5B%5Cs%5CS%5D*%3F%5Cb(%5Cd%2B)(%3F%3A%5Cs%7C%26nbsp%3B)%2BIntegral%5Cb&amp;replace=Rank%20%23%241&amp;label=sp-cc.de&amp;color=blue&amp;cacheSeconds=86400" alt="Integral's UHO Top15 ranking"/></a>
<a href="https://lichess.org/@/IntegralBot"><img src="https://img.shields.io/badge/Play%20Integral-Lichess-brightgreen?logo=lichess&amp;logoColor=white" alt="Play Integral on Lichess"/></a>
<br>
<br>
Integral is a top chess engine developed in C++. It is a personal project developed with the goal of meshing my admiration for chess with programming.

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
The first iteration of Integral's neural network was trained on data from version 4, which had a powerful hand-crafted evaluation (HCE). All early-network data has been thrown out and a majority of Integral's data is generated using a search of 20k soft-nodes per-side. The datasets Integral trains on is publicy available through my [Hugging Face repository](https://huggingface.co/aronpetkovski/integral-datasets/tree/main).
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
