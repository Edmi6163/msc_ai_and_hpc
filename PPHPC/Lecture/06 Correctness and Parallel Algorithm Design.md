# From correctness to efficient execution
Three questions that should be answered in this order: 
- What is legal ? 
- What is parallel ?
- What is efficient ? 
Optimisazation is meaningfull only among executions that satisfies the required semantics

-> The same operations, different schedules:
$P_{1}: x = a + b$
$P_{2}: y = c + d$
$P_{3}: z = x + y$

Both inputs to P3 must have been produced
(P1)-> (P3) <-(P2)


## Berntein's conditions
- A sufficient test for order-independent execution of two computations (basically check where the process read and where the process is writing)
$R_{1}$-> locations read 
$W_{1}$ -> locations written

$W_{1} \cap R_{2} = 0$ -> no read-after-write (RAW)
$R_{1} \cap W_{2}=0$ -> no write-after-read (WAR)
$r_{1} \cap W_{2}=0$ -> no write-after-write (WAW)

All three empty => P1 and P2 can be reordered or run concurrently


# Worked example: independent producers 
Use the read/write sets to derivve the legal schedule


## Three kinds of data dependence
Arroes connect an earlier access to a later conflicting access
- RAW new value is required 
- WAR old value must be read first 
- WAW last writer matters
In case of WAR chaging the name of the variable or memory portion could be a workaround to solve data dependencies 
An ordering constraint is not necessarily a data race: sync can enforce the required order
## Loop-carried dependencies
Examine storage locations read and written by each iteration
> loop carried RAW
```
for(int i =1;i<n:++i)
	a[i] = a[i-1] + b[i]
```
Iteration *i* consumes $a[i-1]$ from iteration $i-1$  
> independent interations
```
for(int i = 1;i<n-1;++1)
	next[i] = prev[i-1] + prev[i+1]
```
Distinct $next[i]$ writes, $prevs[i]$ is read-only

## Two traps in dependence analysis 
- Syntactically different names are not guaranteed to refer to different data
Aliasing: analyse memory locations, not just identifier 
```c++
void update(double *x, double* y){
//x and y may overlap 
}
```

Shared reductions
```c++
for(int i = 0;i<n)
```


## Dependency graph, work and critical path 
The graph records precedence constraints, it does not prescribe a single schedule.
A -> B -> D -> E is the critical part


# Decomposition
Expose concurrency
Partition the problem while preserving hte dependencies that make its result meaningful

## Data versus functional decomposition
Two complementary ways to define parallel tasks
- Data/domain: Same kernel different data blocks
- Functional/pipeline: Different operations, staged execution 
	- (Read->Transform->Write)
The decomposition defines potential concurrency, The dependence graph defines when each task may execute

## Partitioning a 2D domain
Subdomains provide owenership; boundaries create communication
4 blocks: 
- Interiors -> stencil inputs belong the same block
- Boundary -> Stencil inputs may come from an adjacent block

A partition is also a data-ownership decision


## A stencil exposes the halo
One 5-point update uses north,south,east and west neighbours
- Local interior: updated without off-partition
- Halo (ghost layer, squares in border): a copy of neighbouring boundary values

Communication follows boundary size
For a square local tile with side length n (5-point stencil)
$n * n$ celss
local computation: $n^2$
Halo data: 4n
Communication/Composition = 4/n

(ignoring corners,fixed-size constants and per-message latency)

# Granularity
How much work per task ? 
-> Parallel slackness, locality,scheduling overhead and imbalance all change with grain size

## More tasks are not always better
Both extremes create different bottleneck
=> Fine grain - 16 tasks - low work/task, high scheduling frequency (fast task, but need to add computation cost)
=> Coarse grain - 4 tasks - less overhead, less available concurrecny
(less parallelism)

### Worked example: the cost of tiny tasks
Same $32768$ items. Hypotethetical taks creation overhead = $20 \mu s$ 
|16 items/task||


# Foster's PCAM
-> from decomposition to implementation
A systematic way to 

## PCAM: four design decision
Machine-independent reasoning comes first, target-specific choices come later
PARTITION->COMMUNICATION->AGGLOMERATION->MAPPING

### Partitioning
Begin with many candidate tasks; do not match the processor count yet

### Communication
Dependencies crossing task boundaries become communication edges
- Local exchanges -> nearest-neighbour halos in a stencil 
- Global communication -> reductions and collectives span many tasks 
- Design concern -> Volume,message count and ordering

### Agglomeration
Combine adjacent tasks when this reduces coordination more than useful concurrency

### Mapping
Assing tasks to workers while balancing load and preserving locality
Balance -> similar work per worker
Locality -> short communication paths 
Adapativity -> dynamic placement if uneven


# Communication Cost 
-> Latency x messages + data volume/bandwidth
The simplest performance model often explains why an otherwise correct decomposition scales poorly. Focus in parallel programming is to avoid dependencies, especially parallel activty and parallel code, less dependencies due to communication (that means overhead).

- Latency is the time to solve one of the sync or communication
- Bandwidth is the speed of data communicated to other part

## Elementary latency-bandwidth model 
For one message contianing $m$ words or bytes: 
$T_{comm}=\alpha * \beta *m$ where:
- $\alpha$ is start-up/latency fixed cost per message: unit time
- $\beta$ Incremental transfer time per word (or byte); inverse .... 

=> example: 


Bandwidth begin to dominate when affect latency
The more the latency is higher the more is required to manage the data in large byte. Could be that is needed more time in communication than do it in just one thread. 

## Strong scalining of a 2d Jacobi stencil
global $N*N$ grid distributed over P square subdomains. More P -> smaller s -> more boundary per cell     