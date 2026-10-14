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
Idealized Shared-Memory model for algorithm design
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
**Exclusive Read Exclusive Write** (EREW): 
**Concurrent Read Concurrent Write** (CRCW): 
Complexity: 
- Time complexity 
- Processor complexity

## Prefix Computation
Binary associative operation, the idea is simple: As they are associative is it possible to group the element in parralel programming by associativity. 

The algorithm implementing the prefix computation is often called **scan**
- lower bound: $\Omega(n)$

Two types of scan: 
- **Exclusive**: 
- **Inclusive**: Prefix computation usually refers to the inclusive version 
The C++ STL library provides: ```
```c++
std::inclusive_scan
std::exclusive_scan
```
### Parallel Prefix '+' on a PRAM
Goal -> design a cost-optimal PRAM algorithm $C(n)=O(n)$
We use the recursive doubing algorithm using p=n processors

To reduce the cost $C(n)$ we can reduce the number of processors used

$C(n) = T(n,p)*p=O(\log n) *n =O(n *\log n)$ thus this algorithm is cost-optimal

### Sparse array compaction
Assume you have a one-dimensional array A where most entries are zero

on a PRAM:
We can use a parallel prefix approach using $p = \frac{n}{\log(n)}$ processors


## Limits of the PRAM model
- Unrealistic memory access: it assumes that all processors have uniform,instantaneous access to a single shared memory
- Perfect lockstep synchronization: in practice achieving and maintaining such global synchronization introduce significant overhead
- No communication and memory hierarchy costs
- Cost-optimal PRAM algorithms may still scale poorly on real machines processing resource

## Bulk synchronous Parallel Model
The BSP model of computation was proposed as a unified framework for the design, analysis, and programming of general purpose parallel systems. 
It can deliver both scalable performance and architecture independence. 
It's not just a theoretical model, it can also serve as a reference pradigm for parallel programming
It consists of three parts: 
- A collection of processor-memory components
- A communication network that can deliver point-to-point messages among processors 
- A facility for global synchronization (**barrier**) of all processors

Main goal: seprate the 3 paradigm (computation, .. .., ....) #TODO 

# BSP COMPUTER
n processor $P_{o},\dots,P_{n-1}$ each with its own memory (a distributed memory multiprocessor)
A processor can access its local... #TODO 

## BSP Algorithm
- it consists of a sequence of supersteps
- A superstep consists of
	- computation,communication,or computation and communication steps
		- so called mixed superstep in case both are executed 
	- a global barrier synchronization (bulk synchronization) to ensure that all computation and communication from the superstep have completed
- A computational superstep focuses on local processing tasks (e.g floating point operations)
- Communication superstep focuses on exchanging data among processes. 
### h-relation and communication cost
An h-relation is a communication superstep in which, for every processor, the number of data words sent and received is at most h

- The cost of an h-relation is $T(h) = h *g  +l$ where: 
	- g (gap) is the per word communication cost
	- l (latency) is the global synchronization time
	- Both are expressed in FLOPS [[01  Introduction#Supercomputers]]
	- Note that *g* and *l* depend on the number of processors
	- $l > 0$ includes the costs of the global synchronization plus all fixed costs for ensuring that all data have arrived at the destination, and the start-up of the communications 

## Computation superstep cost
The cost of computation superstep is $T_{comp}(w)=w+l$
where:
- $w$ is the amount of work defined as the maximum number of operations performed in the superstep by any processor
- Processor performing fewer than w operations remain idle until the barrier
The cost of a mixed superstep is $T_{min})(w)=w+h*g+l$
- The same *l* measure is used for all types of superstep 
## Cost of a BSP algorithm
The BSP algorithm cost is given by the following general expression $$C_{bsp} = a+b*g+c*l$$
The expression is obtained by adding the costs of all the algorithm's supersteps,the coefficient a,b and c collect

Example: 
$p = 4$ $g=4 FLOPS$ $l=20 FLOPS$
 (look at slide for the example)

Another example -> dot product BSP algorithm example

BSP Algorithm: GEMM
Assumption: matrices and distributed evenly over p processors
processors are organized in a logical grid of size $\sqrt{ p } * \sqrt{ p }$ 


### BSP model summary
A BPS abstract machine is a distributed memory system represented as BSP(p,r,g,l) where: 
- p is hte number of processors, r is the local computing rate expressed in FLOPS, g all the communication cost per data word (in FLOP time unit), ad l is the global synchronization cost (in FLOP time unit)


### BSP design implication
A structured approach to thinking about parallellizaton. BSP organizes program into supersteps, which improves clarity and provides a simple cost model 