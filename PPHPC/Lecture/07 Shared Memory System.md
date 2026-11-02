Shared memory architectures: 
-> Von Neumann Bottleneck: the discrepancy between CPU compute speed and main memory (DRAM) speed. CPU <-> bus <-> main memory.
-> von neumann bottleneck exaple with dot product (which is memory bound)

## Basic CPU structure with a single Cache
CPUs typically contain a hierarchy of two or three level of cache (L1,L2,L3), they have a higher bandwidth and lower compared to main memory but smaller capacity, they are faster because they are closer to the register and the technology is different (more or less the same of register 1 bit -> 6 transistors SRAM (static ram))
HBM(high bandwidth memory) modern, faster because it consists of _stacked_ dram  and HBM can directly access each column, and you reason in term of matrix rather than vector

## Cache organization
Commonly used cache organization in today CMPs
4 type of cache: 
- Shared cache
- private cache
- Multilevel cache 
- Distributed share cache 
The one we are gonna use mostly is distributed shared cached


Matrix Multiplication example

## Memory Hierarchy


## Measuring CPUtime with caches
$CPU_{time}=ClockCycles * ClockCycleTime = IC *CPI * ClockCycleTime$
where: 
- IC Instruction Count is the number of program instructions executed
- IC can be 


Impact of data of data locality on the CPU time

## Cache Algorithms 
In almost all general-purpose architectures the cache hierarchy is not exmplicity managed by the user
It is managed by a set of caching policies (cache algorithms) that detrmine which data is cached during program execution other than cache hit and miss definitionm, these are new definition: 
- Miss Penality: the time spent transferring a cache line into the first level cache and the requested data to the processor
- Hit ratio: the percentage of data requests resulting in a cache hit
- Cache line: serveral iterms of information as a single memory location to enforce spatial locality 
Instead of requesting only a single value, an entire cache line is loaded with values from neighboring addresses

Cache are organized into a number of cache lines, cache mapping strategy decides in which location in the cache a copy of a particular entry of main memory will be stored
- Direct-Mapped Cache: Each block from main memory can be stored in exactly one cache line
- n-way Set Associative Cache: Each block from main memory can be stored in one of n possible cache lines 
- Least Recently User (LRU)

## Optimizing cache accesses
Is very important to exploit locality for code performance. Is it possible to optimize cache access.
