## <p align="center"><img src="https://i.imgur.com/Py8am6G.png" alt="Integral Chess Engine" width="30%" height="30%"/></p>

Integral is a top chess engine developed in C++. It is a personal project developed with the goal of meshing my admiration for chess with programming. \
\
**Play against Integral on [Lichess](https://lichess.org/@/IntegralBot)**

## Search
Integral implements the widely adopted negamax search approach with alpha-beta pruning, and alongside it the various search heuristics that it enables. It utilizes the Lazy SMP approach for multi-threaded search, and has been proven to scale very well at higher thread counts compared to other alpha-beta chess engines.

## Evaluation
Integral utilizes an efficiently updatable neural network (NNUE) for its evaluation function.

### Architecture
Integral's neural network is a horizontally mirrored perspective network, containing four king input buckets, eight output buckets, and a hidden layer of 1280 neurons.
`(768x4 -> 1280)x2 -> 1x8`

### Data Generation Process
This neural network is trained on millions of self-play games. Each self-play game has a unique opening of six to nine random moves. These random moves are chosen across a probability distribution based on the piece moving, i.e. pawn, knight, and bishop moves are more likely to be played than king, queen, or rook moves. Additionally, all moves that lose material are eliminated. This approach intuitively leaves the openings to be entirely positional in nature and thus, hopefully makes Integral's neural network able to learn more positional knowledge. Lastly, 5-man Syzygy endgame tables are used in both the search and for game adjudication. 

### Training Process
The first iteration of Integral's neural network was trained on data from version 4, which had a powerful hand-crafted evaluation (HCE). Each iteration of Integral's neural network since then has been generated on a fresh dataset using the prior network.

## Compiling Integral
> [!NOTE]  
> Integral should be compiled with GCC v13 (or higher)

Integral provides a Makefile for compilation, but you can use CMake as well.\
To compile Integral, enter the following commands in a terminal:
```
git clone https://github.com/aronpetko/integral
cd integral
make <native|x86_64_bmi2|x86_64_modern|x86_64>
```