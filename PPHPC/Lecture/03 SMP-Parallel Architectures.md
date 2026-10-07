Parallel architectures differ primarly in memory organization and interconnection, and these choices termine: 
- scalibility limits 
- performance behaviour
- programming models

## Why parallel architectures (PA)
- Scalabilty: enable scale-out by adding nodes while keeping efficiency acceptable
- Energy efficiency: PA enable higher performance per watt by scaling out with many low-frequency cores and specialized accelerators
- Fault tolerance: to ensure reliability, if one or more nodes fail, other can still be used
- Parallelism applies at all levels of system design: from microarchitecutres, memory systems, interconnection, I/O

## Classifying PA
- system architecture of the single node
- the interconnection network connecting multiple nodes forming parallel systems 

Common classification criteria: 
- Flynn taxonomy: yet useful to understand basic paralllel concepts
- Memory organization
- System scale and Processing organization
- INterconnection networks

## Flynn taxonomy
Classifcation based on the number of instructions and data streams:
- SISD (Single instructions, single data): traditional Von Neumann architecture 
Single stream of instructions executed serially

- SIMD (Single instructions, Multiple data): executes the same operation on multiple data items simultaneously
SIMD systems reliate to data parallelism, it operate on different data stream and each PE has an associated data memory module, operations are synchronusly. GPUs implement SIMD-like execution withing Streaming Multiprocessors, example image processing (each processing unit have different block of pixel with the same operation all over). 

- MISD (Multiple Instructions, Single data): Multiply PEs to execute different instructions on a single stream of data (not really used)
All PEs execute a different instruction sequence on single data stream, rarely used in general-purpose computing, found in system-critical systems for fault tolerant reasons (shuttle, avionics,nuclear plant control)
- MIMD (Multiple instructions, Multiple data): uses multiple PEs to execute differnt instructions on different data streams 
=> Flynn's taxonomy is useful to reason about instruction and data parallelism
Most interesting for us, Is the dominant model for general-purpose parallel computing, each processor has its own control unit and can independently execute any instruction in its instruction set.

## Memory based classification
Here we implicity refer to MIMD. 2 ways of memory system: 
- [[#Shared memory]] (aka multiprocessors)
- [[#Distributed memory]] (aka multicomputers)
The way of code change a lot between the two type of memory system

### Shared memory
Could be: 
- Uniform (SMP Symmetric Multiprocessors): 
All processors/cores have (kinda) equal access time to memory (ignoring cache effects), this organization is called Uniform Memory Access (UMA)
=> example: single socket intel xeon based system, where all cores share one mmemory controller
- Non Uniform (NUMA Non Uniform Memory Access)
Each processor/core has its local memory, non uniform memory access time, the memory access time is asymetric depending on which memory is accessed. In NUMA multiprocessors, the memory is still shared among PEs, but it is physically distributed, example AMD EPYC (chip composed of multiple chiplets)

### Numa multicores
Numa organization is a hardware reality, not a programming model.
- A NUMA node corresponds to an entire CPU (socket) or a chiplet with its local memory and set of cores
- Accessing remote memory has higher latency and lower bandwidth than local memory
- Each socket has its memory controller and local memory
- The nodes are connected by a high-speed interconnect (Network-on-chip plus soceket links in multi-socket systems)
- Each socket has a shared Last Level Cache (LLC), usually L3


## Distributed memory
DM systems inherently have Non Uniform Memory Accessm however the term NUMA is mostly used for shared memory NUMA, not in distributed memory systems. Each processor has its private memory, it can be SPM or NUMA multiprocessor. 
The address space of distrinct nodes is disjoint

## Classification based on system scale
Considering the number of cores in general-purpose MIMD machines. The core count is a rought estimation of peak compute performance:
- $O(10^1 - 10^2)$ cores, for a single multiprocessors chip (example AMD EPYC CPU has 64 cores)
- $O(10^2 - 10^3)$ cores, for a shared memory tightly-coupled multiprocessor (example HPE Superdome Flex series, large ccNUMA multiprocessor)
- $O(10^3 - 10^4)$ for Distributed-Memory loosely-coupled systems, from small to large compute clusters (example small medium cluster with 16-128 nodes up to large cluster where nodes have one or more GPUs)
- $O(10^3 - 10^7)$ Top supercomputers (Leonardo, Fugaky, El Capitan)
Often the core count includes both CPU and GPU

## Core count of Leonardo
Hosted by CINECA in Bolo. It's composed by: 

- A Data-Centric Module composed of 1536 nodes each with 2x Intel Sapphire Rapids (56 cores @2.0GHz) -> **RPeak**: $1536 nodes *2 sockets *2 *10^9 Hz * 56 cores * \frac{32FLOPS}{10}$ = 11.010 PFLOPS
- A Booster Module composed of 3456 nodes, each with one Intel Xeon plus 4 nvidia A100, more than 1.8M cores in total, **Rpeak** more than 306 PFLOPS

## Parallel systems goals & challenges 
- Shared-memory systems: 
	- key focus: primarly on the memory organization (memory hierarchy,processor-memory,interconnections)
	- goals: reduce commmunication costs
	- challenges: cache-coherence, memory consistency, thread synchronizations
- Distributed memory sytems:
	- key focus: primarily on the interconnection network topology
	- goals: reduce communication costs
	- challenges: fast messaging protocols/libraries, message routing, and flow control
The challenges have a direct impact on the programming models


## Programming model
Is an abstraction that defines how concurrency and communication are expressed in a program, including how work is decomposed, how data is shared or moved, and  what synchronization mechanism are used (MPI,OpenMPI,CUDA)

## DM Systems
Each node is a complete computer system, usally an SMP or NUMA multiprocessor. Communication is explicit and unavoidable
Processes on different nodes communicatate explictly by sending messages across a network -> reference library in HPC: **MPI**
High performance network topologies: Mesh, Torus, Fat-Tree, Dragonfly

Example: 
- Stencil computation: distributed memory partitioning of a $N*N$ matrix onto $N$  processess running on $M$ nodes
## SHM systems
They comprise a relatively low number of CPU cores $O(10^1 - 10^2)$
all with direct hardware access to a shared memory space:
- Communication is implicit through memory, synchronization is explicit
Even in UMA systems, each core has a small local memory (like L1-cache) to mitigate expensive accesses to main memory.
Refenence programming models: Pthreads, C++ threads, OpenMP.