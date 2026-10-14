## Basic Performance Metrics 
Key definition for system performance: 
- **latency (*l*)**: is the time from the moment an input (request) arrives until the output is ready to be delivered
- **Completion time ($T_{c}$**): is the total time an application takes to complete all tasks
- **Service time ($T_{s}$)**: the time required by the system to process a task, excluding waiting time
- **Throughput**: It is the number of tasks completed per unit of time
- **Inter-arrival time ($T_{a}$)**: the average time between two consecutive task arrivals at the system

The term processor refers to processing element (p) like thread/processes running on cores or machines, depending on the context

## Speedup definition
**Speedup**: The speedup of a parallel program using p processors $S(p)$ is defined as the ration of the completion time of the sequential program $T_{c-seq}$ to the completion time obtained when running with p processrs $T_{c}(p)$ 
$$S(p) = \frac{T_{c-seq}}{T_{c}(p)}$$
It measures how much faster a program with more processors
The best speedup one can expect, variying the number of processors is linear speedup. In general because of the overhead introduced by the parallelisation, the speedup is sub-linear with the number ...

## Efficiency definition
The **efficiency** of a parallel program parralilized using p processors $E(p)$ is defined as the ratio between the speedup $S(p)$ and the number of porcessors used p $$E(p)=\frac{S(p)}{p}=\frac{T_{c-seq}}{T_{c}(p)*p}$$
Efficiency measures how effectively a parallel program utilizes the p resources employed
- $T_{c}(p)*p$ is also called cost of parallelization

## Scalability defintion 
**Scalability** (relative speedup): it describes how well a parallel program can utilise an increasing number of processors, indicating whether adding more processors continues to yield performance gains, it is measured as: $$S(p)=\frac{T_{c}(l)}{T_{c}(p)}$$

The scalability and the speedup are realted concepts. However there is a significant difference: 
- The scalability considers $T_{c}(l)$ as the time obtained executing the parallel implementation of the algorithm on a single processor $Scalability(p)=\frac{T_{c-par}(l)}{T_{c-par}(p)}$
- The efficiency ...

## Strong and weak scalability
Strong scaling ideal (the problem size is fixed) ideal $T_{c}(p)=\frac{T_{c}(l)}{p}$ for a fixed PS
- linear scaling is difficult to achieve due to Amdahl's law
- Perormance depends on the amount of serial work

Weak scaling: (the problem size grows with p to keep the work per processor fixed): 
- The computational work (W) is associated to the problem size (PS) remains (almost) constant per processor 

## Weak scaling efficiency
Measures how well execution time remains constant as both the number of processors and the problem size grow proportionally, keeping the workload per processor fixed $$WSE(p)=\frac{T_{c}(PS(1),1)}{T_{c}(PS(p),p)}$$
## Superlinear Speedup
Can speedup be greater than p when using p processors? Yes, it can happen, altough it is rare to see it.
Two possible reason: 
- Unfair comparison with a naive serial algorithm
	- E.g the sequential version might not be compiled with optimization flags enabled 
	- Can happen in some recursive algorithms (e.g brand&bound algorithms)
- Cache/memory effetcts
	- more processors mean more memory and larger caches, leading to fewer cache misses and page swapping


## Example and its analysis
Input: Array A of n numbers 
Output: $\sum_{i=0}^{n-1}  A[i]$  
Task: parallelize this problem by using p porcessing elements (PEs)

Assumption:
- Computation: each PE can add two numbers stored in its local memory in 1 sec
- Communication: A PE can send data from its local memory to the local memory of any other PE in 3 sec (independently of the data size)


Establish sequential runtime as a baseline $(p=1) T(1,n)=n-1 \sec$ 
We are interested in: 
- Speedup
- Efficiency
- Scalability

In $T(p,n)$ P=processors count n=problem size

Establish runtime for 2PEs $p=2$ and 1024 numbers ($n=1024$)
$(2,n)=3 \sec$ and I compute $\frac{n}{p}=\frac{1024}{2}=512$ per PE

Speedup: $\frac{T(1,1024)}{T(2,1024)}=\frac{1023}{518}=1.975$
Efficiency: $\frac{1.975}{2}=98,75 \%$ 

Example:
$T(4,1024)=3*2 + 255 + 3*2 + 2=269 \sec$
Speedup: $\frac{T(1,1024)}{T(4,1024)}=\frac{10124}{miss}$



$T(8,1024)=3*3+127+3*3+3=148 \sec$
Speedup: $\frac{T(1,1024)}{8,1024}=\frac{1023}{148}=6.91$
Efficiency: $\frac{6.91}{8}=86\%$


Timing analysis using $p=2^q$ PEs and $n=2^k$ input numbers:
- Initial data distribution $3*q$
- Local computation: $n/p-1=2^{k-q}-1$ 
- Collection of partial results: $3*q$
- Tree based reduction to combine results: $q$

## Weak scalability Analysis 
