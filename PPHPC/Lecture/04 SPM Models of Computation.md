Goal: Understand the limits of parallelism and cost of communication

## Why high-level abstract models
Models help us understand what is possible before worrying about how
Separae algorithm design from machine details, also reason about scalability and fundamental limits. 

## Work span model
Also called work-depth provides more strict bounds than those offered by the Amdahlś and Gustafson's laws 
A parallel prgram can be represented as a DAG (Directed Acycling Graph) where: 
- **nodes**: are tasks
- **edges**: are data dependencies between tasks
A task is a unit of work, i.e arbitrary sequential code (a task is: input and output)
Difference between a function and task is the _input_
A task can be executed (ready) **iff** all its predecessors in the graph are completed.
**Greedy scheduling**: whenever there is a ready task (and an available processor), the task is executed immediately.
=> Parallelism is determined by the structure of the DAG

### Terminology
$T_1$ : is the total work, it measure the total computation
$T_{\infty}$: is the span (also called critical path), mesure inherent sequenatial computational 
- longest chain of dependencies wih unit task
- the path from the root to on leaf with the highest associated cost
In the example DAG (slide) we have $T_{1}$ = 54 and $T_{\infty}$: 27
Dependency in the graph make the count complex 

## Work span model: lower bounds
$T_{p}$ 


### Work-span model: speedup limits 
Speedup: $\frac{T_{s}}{T_{p}(n)}$ is the best we can do
$S(p)= \frac{T_{1}}{T_{p}} \leq \frac{T_{1}}{\frac{T_{P}}{p}}$ superlinear speed up not possible in the model (but it's possible adding caches)
$S(p) = \frac{T_{1}}{T_{P}} \leq \frac{T_{1}}{T_{\infty}}$ Maximum speedup is bounded by the available parallelism $\frac{T_{1}}{T_{\infty}}$ 

## Brent's theorem
Assume a parallel computer whose processors can perform a task in unit time with greedy scheduling of tasks 


Brent's theorem states a similar computer with fewer processors p can exeute the algorithm with the following upper limits: $$T_{p}\leq \left( \frac{T_{1}}{} \right)$$
## Implication of Brent's theorem
considering the speed up, we have that $S(P) \leq min\left( \frac{p,T_{1}}{T_{\infty}} \right)$ the speedup is bounded by both the number of processors and the available parallelism
To obtain good speedup $T_{1}$ must be significantly larger than $T_{\infty}$ 

## Limits of the Work-Span model
These bounds rely on idealized assumptions


# Parallel Random Access Memory - PRAM 
Idealized Shared-Memory modle for algorithm design
Idealized platform (no caching, no NUMA, no syncronizations overhead)

n processors are connected to a global shared memory M
Any memory location is uniformly accessible from any processor in constant time $O(1)$ 
combinded in => syncronization 
write/read + synchronization, 

n identical processors operate in lockstep (sync)
In every step each processor executes an instruction cycle in three phases (read,compute,write)
- read not affect memory 
- compute 
- write affect memory (sync problem)

Variants -> Concurrent Read Concurrent Write: 
Both simultaneous reads and writes to the same shared memory cell 

Complexity: 
- Time complexity 
- Processor complexity
