# SneakySnake: A Fast and Accurate Universal Genome Pre-Alignment Filter
The first and the only pre-alignment filtering algorithm that works on all modern high-performance computing architectures.  It works efficiently and fast on CPU, FPGA, and GPU architectures and that greatly (by more than two orders of magnitude) expedites sequence alignment calculation. Described by Alser et al. (preliminary version at https://arxiv.org/abs/1910.09020).

## The key idea 
The key idea of SneakySnake is to reduce the approximate string matching (ASM) problem to the single net routing (SNR) problem in VLSI chip layout. In the SNR problem, we are interested in only finding the optimal path that connects two terminals with the least routing cost on a special grid layout that contains obstacles.The SneakySnake algorithm quickly solves the SNR problem and uses the found optimal path to decide whether performing sequence alignment is necessary. Reducing the ASM problem into SNR also makes SneakySnake efficient to implement for all modern high-performance computing architectures (CPUs, GPUs, and FPGAs).

## Results 
SneakySnake significantly improves the accuracy of pre-alignment filtering by up to four orders of magnitude compared to the state-of-the-art pre-alignment filters, Shouji, GateKeeper, and SHD. SneakySnake accelerates Edlib (state-of-the-art implementation of Myers’s  bit-vector algorithm) and Parasail (sequence aligner with configurable scoring function), by up to 37.6× and 43.9× (>12× on average),  respectively, without requiring hardware acceleration, and by up to 413× and 689× (>400× on average), respectively, using hardware acceleration. SneakySnake also accelerates the sequence alignment of minimap2, a state-of-the-art read mapper, by 2.51× to 6.83× without requiring hardware acceleration. As SneakySnake does not replace sequence alignment, users can still configure the aligner of their  choice for different scoring functions, surpassing most existing efforts that aim to accelerate sequence alignment.

## Directory Structure:
```
SneakySnake-master
├───1. Datasets
└───2. Snake-on-Chip
    └───3. Hardware_Accelerator
├───4. Snake-on-GPU
├───5. SneakySnake
```            
1. In the "Datasets" directory, you will find four sample datasets that you can start with. You will also find details on how to obtain the datasets that we used in our evaluation, so that you can reproduce the exact same experimental results.
2. In the "Snake-on-Chip" directory, you will find the verilog design files and the host application that are needed to run SneakySnake on an FPGA board. You will find the details on how to synthesize the design and program the FPGA chip in README.md.
3. In the "Hardware_Accelerator" directory, you will find the Vivado project that is needed for the Snake-on-Chip.
4. In the "Snake-on-GPU" directory, you will find the source code of the GPU implementation of SneakySnake. Follow the instructions provided in the README.md inside the directory to compile and execute the program. We also provide an example of how the output of Snake-on-GPU looks like.
5. In the "SneakySnake" directory, you will find the source code of the CPU implementation of the SneakySnake algorithm. Follow the instructions provided in the README.md inside the directory to compile and execute the program. We also provide an example of how the output of SneakySnake looks like using both verbose mode and silent mode.

## Contact
For any issue with the code or suggestion for improvement, please contact mohammed dot alser at inf dot ethz dot ch
