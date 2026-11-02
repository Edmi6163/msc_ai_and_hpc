# Superscalar processors
Modern CPUs are highly parallel mixing pipelining and superscalar technologies. 
- Superscalar: CPUs are designed to execute multiple instructions from a single process/thread simultaneously to improve performance adn CPU utilization. The processor fetches multiple istructions concurrently in a single clock cycle and executes them out-of-order. The problem of is that sequential rpograms the number of instructions that are independent are small thus, the exploited parallelism is low
- To overcome such low efficiency, **SMT (Simultaneous Multi-Threading** has been added in superscalar processors to execute multiple instructions from multiple threads fo control simultaneously

# HW Multithreading 
Multithreading enables a single core to execute multiple threads concurrently: 
- A thread represents an independent sequence of instructions 
- Goal: optimize the CPU performance by efficiently handling multiple threads
There are two main types of HW multithreading: 
- **fine-grained multithreading**: interleaves instructions from different threads at the instruction level
- **coarse-grained multithreading**: switches between threads at the thread level. A switch happens only when the thread in execution causes a stall
Each thread has its own set of registers and program counter (PC) representing its state. The processor mantains the context of each thread to quicly switch between them. 

## Core/Cache topology using Isotopo
Various example (suggested to look at slides)


## Programming shared memory systems 
Parallelism created by starting threads (creating threads is a task) running concurrently on the system.
Thread creation is more lightweight and faster compared to process creation. Creating a process is from to 3 to 5 times slower than creating a thread. Exchange of data implemented by threads reading from and writing to shared locations.

## Programming shared memory systems 
- Data Race (DR) occurs when two (or more) threads access a shared variable simultaneously and: 
	- at least one access is a write operation 
	- the accesses to the shared variable are not separated by sync operation
- => DR produce non determinstic behaviour (especially in C++)
- Sync mechanism 

```
a[]: {2.1,3.4,0.1,2.2,?,-1.4,2.0,-1.9,0.4}

```
where there is "?": 
- thread 0 `a[4]= 3.1`
- thread 1 `a[4]=2.9`
- thread 2 `x=a[4`

to sync there are sync mechanisms: mutexes,condition variables, semaphores, atomic instructions

## False sharing 
Caches are organized in cache lines, where each line holds several values. The cache coherence protocol works by invalidating/updating the entire cache line and not single values within the cache line
If distinct data items (e.g variables) present in a single cache line are written by different threads, we have the false sharing effect: 
- No true sharing actually exists since threads work on different variables
The overheads introduced by the cache coherence protocol to keep the cache line consistent among all copies in the caches can be significant
- This is an indirect effect produced by the coherence 

example of false sharing: 
I have a matrix A and a vector X
Consider m=8 and a cache line size of 64 B: 
- y is stored in a single cache line
- 4 threads, one per core, each thread computing 2 elements of y
- **False sharing**: every wirte to y invalidates the cache line in the other core's cache. Most of these updates to y force main memory accesses. 
**Solutions:**
- data padding (force variable to lay in two distinct cache lines)
- use temporary variable
## More on simd
All ALUs required to execute the same instructions (sync) or idle



## SIMD with AVX2 registers
AVX -> Advanced Vector Extensions
**Instrinsics** are assembly-coded functions that can be used in C/C++ code instead of assembly instructions
Intrinsics are expanded inline eliminating funciton call overhead, `#include<immintrin.h>`

AVX2 programming: Transposed MatMult
# SIMD parallelism: AoS and SoA layouts
To exploit the power of SIMD parallelism, it is often necessary to modify the layout of the data structure used.
Two different layouts: 
- **AoS (Array of Structure)**: stores records consecutively in a single array
- **SoA (Strcture of Arrays)**: uses one array per dimension. Each array only stores the values of the associated element dimension

AoS: 
```c++
auto xyz = new float[3*n]
```
> xyz are stored inline 

SoA:
```c++
auto x = new float[n]
auto y = new float[n]
auto z = new float[n]
```
>xyz are stored by line
## Vector Normalization with AoS
Vectorization of 3D vector narmalization based on the AoS format is relatively inefficient: 
- Vector registers would not be fully occupied for 128-bit registers

It makes to cpu easier to process vector in parallel
Summing up the squares 

### From AoS to SoA using vectorized shuffling


## Auto-vectorization using compiler's options
Auto-vecto is a compiler optimization technique that trasforms scalar into vectorized code, improves performance on modern CPUs leveraging SIMD instructions
Compiler flags in GCC:
- `-O3` includes options to enable auto-vectorization (`-O2` in recent GCC version)
- `-ftree-vectorize`: enable vectorization optimizations
- `fopt-info-<option>`: enable optimization dumps from various optimization passes
- `-O3 -march=native `

### General guidelines for loop vectorization



