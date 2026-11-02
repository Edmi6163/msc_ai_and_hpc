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


## Computation-to-Computation ratio
Let $\alpha > 0$ and $\beta > 0$ be the amount of computation and communication/synchronization needed in out parralel appplication
- $\beta$ is application dependent
$\gamma = \frac{\alpha}{\beta}$ is the computation-to-computation ratio, it measures the balance between computational workloads and the parallelization overhead

## Consideration
Speedup and parallelisation efficiency depend on both the PEs used (p) and the *computation-to-communication/synchronization* ratio ($\gamma$)
- Speedup usually increases with the number of PEs up to a local minimum, then it tends to decrease as p [?] 


## Weak Scaling with non-linear problem size


# Amdahl's Law
Address a fondamental limit on the achievable speedup when using multiple processors for a fixed problem size.
- It states that the speedup is fundamentally limited by **the fraction of sequential code** (the portion of the code that cannot be parallelised)

## Derivation of Amdahl's law 
We now assume that the best possible speedup we can achieve is linear (no super-linear speedup)
Then we derive an upper bound for achievable speedup
$T_{c}(l)=T_{ser}+T_{par}$ where: 
- $T_{ser}$ part of the program that **does not benefit** from parallelization $$T_{c}(p)\geq T_{ser} + \frac{T_{par}}{p}$$
- $T_{par}$ part of the program that **can benefit** from parallelization $$S(p)=\frac{T_{c}(l)}{T_{c}(p)} \leq  \frac{T_{ser} +T_{par}}{T_{ser}+ \frac{T_{par}}{p}}$$
## Derivation of Amdahl's law
Instead of using absolute execution time ($T_{ser}$ and $T_{par}$) we now use their relative fraction $\to$ **f** is the serail fraction whereas (1-f) is the parallelization fraction. 
Substituting f in the previously derived upper bound, the result is the Amdahl's Law

- **Amdahl's law** is: $\frac{1}{f + \frac{1-f}{p}}$ 

- The sequential fraction of code,f, is a unit-less measure between 0 and 1
- Amdahl's Law can be used to predict the performance of parallel program

### Example: 
- $95\%$ of a program's execution time occurs inside a loop that can be executed in parallel. What is the maximum speedup we should expect from a parallel version of the program executin on 6 CPUs ? 
$$S(6)=\frac{1}{0.5 + \frac{1-0.05}{6}}=4.8$$ 
## Amdahl's law defeats strong scaling
For large p (i.e $p\to \infty$) $S(p)\to \frac{1}{f}$ 
Therefore strong scaling is fundamentally limited by the serial fraction
- if $f=1\%$ then $max_{p}S(p,f)-100$
- if $f=10\%$ then $max_{p}S(p,f)=10$


## Efficiency under Amdahl's law 
The shape of the efficiency curves when varying $f$ is $$E(p)=\frac{S(p)}{p}=\frac{1}{p*f+(1-f)}$$
$E(p)$ tends to 0


Amdahl's law is too optimistic because it does not account for:
- Communication cost
- Overhead: every parallel implementation introduces overheads due to synchronization and coordination
It is not true we can arbitrarly increasee p and always improve performance

## Scaled speedup
Amdahl's law only applies in situation where the problem size is fixed and the number of processors (=> strong scaling)
However when using PEs, we often can solve larger problems (=> weak scaling) 
- Scaled speedup, incorporates such scenarios when calculating the achievable speedup

**Gustafson's law** (GsL) is a particular case of the Scaled Speedup that can be used to predict the theoretically achievable speedup using multiple processors when the parallizable part scales linearly with the problem size (Weak scaling), while the serial part remains constant

## Derivation of scaled speedup law
$$T_{\sigma \pi}(1)= \sigma \cdot T_{ser} + \pi T_{par} = \sigma \cdot f \cdot T_{c}(1) + \pi \cdot (1-f) \cdot T_{c}(1) $$

- $\sigma$: scaling function of the part of thhe program that does not benefit from parallelization with respect to the complexity of the problem size
- $\pi$: scaling function of the part of the program that may benefit from parallelization with respect to the complexity of the problem size
$\sigma$ and $\pi$ represent how the serial and parallel portions scale with the problem size

## Derivation of GsL
$\gamma = \frac{\pi}{\sigma}$ => Ratio of problem-complexity scaling between the parallelizable and non-paralleiliable parts
Using different functions for $y$ yields to the following two notable cases

## Scaled speedup example
Suppose we have a parallel program that, for a given problem size PS, is $15\%$ serial and $85\%$ linearly parallelizable.

Functional Depenency of Scaled Speedup $S_{\gamma}(p)$ parametrized with $\gamma=p^\delta$ 
The scaled speedup formula $$$S_{\gamma}(p) \leq \frac{f + \gamma \cdot (1 - f)}{f + \frac{\gamma \cdot (1 - f)}{p}}$$ depends on how $\gamma$ scales with $p$
- We can write $\gamma=p^\delta$ with $\delta \exists [0,1]$ where: 
	- f

# ISO-Efficiency
Motivating questions: 
- How much must $\delta$ increase in order to preserve parallel efficiency for increasing p? 
- How much does the parallelizable part of our problem need to grow to maintain the same efficiency with more processing ? 
**Def**: An **iso-efficiency** function describes how problem scaling $\delta$ must vary with the number of processors p to maintain a constant efficiency $E_{0}$  

it answer to : How good can I exploit the HPC

## Functional dependency
Scaled Efficiency parametrized with $\gamma=p^\delta$
