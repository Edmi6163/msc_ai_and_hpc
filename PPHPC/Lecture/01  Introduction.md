## Why parallel computing ? 
Parallel computing: is using multiple processorrs in parallel to solve a problem
- is not only about speedup, but also making problems feasible

Parallel computing and Distributed systems are different things

**Core capabilities**: 
- identifying and exposing parallelism in algorithms and software system
	- finding pars of a problem that can run at the same time
	- finding dependencies between different parts (like variables used in different part of the code base (desing space))
- evaluating trade-offs
	- understanding the costs,benefits and limitations of a chosen parallel approach
	- communication overhead, scalability and resource usage

## Parallel Machines
Example:
- Compute Cluster: multiple independent computers connected with one or more high-speed networks (example Leonardo HPC)
- SMP (Symmetric Multi-Processor): multiple processor chips connected to a shared memory hierarchy (smartphones example)
- CMP (Chip Multi-Processor aka Multicore): multiple compute units (called cores) packed on a single chip
These architectures lead to different programming models, where a programming models is the paradigm (like object oriented)

## Why parallel computing ? 
The main motivation was to improve performance and tackle larger problems, mainly for problems too large to be solved on single computer (like computational science or engineering for simulation)
Note: fo a long time, parallel computing was considered a niche area in computer science
Today it is now a fundamental background of any computer scientis and practitioner, it became the deafult execution model.
Today AI Revolution (especially deep learning) has amplified the demand for parallel computing (think about matrix multiplication)
Other than AI parallel computing is Big Data Analytics (very large datasets,Real time data analytics). The boundary between HPC, Big Data and Ai is increasingly blurred, due to the fact that modern AI requires the combining all three domains
Increasing interest for cloud-edge continuum and quantum computing

## From motivation to technology
recall -> Moore's law = 2x transistors/chip every 1.5 years (not about performance but refers transistors count)
Implication of Moore's law, the cost of processor chips and memories has decreased as well. With hardware improvements (smaller,improved microarchitecture, larger caches,SIMD instructions(instruction level paralleilsm))

### Limits of single chip improvements
- primary limits of single-chip performance improvement are related to packing more and more transistors into the chip
	- speed of light limit (fundamental)
		- at 3ghz signals travel onyl ~10cm per clock cycle, so chip size is becoming a limiting factor
	- power density (power was increasing over the years)

**Dennard's scaling law**: observed that power density was constant as transistors got smaller
- this was true for almost 30 years

## Power density
Patrick Gelsinger (Intel) warned that if clock speed scaling as its present pace high speed processor would have a crescent power density

## Moving to multicore
Multicore processor Intel nehalem 4 core with two QPI (quick path interlink) and private L1 and L2 and large shared L3 cache

## Movinng to CMP to reduce power 
Use explicit parallelism to reduce power consumption
$Power_{dyniamic} = \alpha * C * V^2 * F$ 

$Perf = N_{cores} * F$
where V = voltage, C = Capacitance, F = clock frequency

## CMP trend
Moore's law kept going, dennard scaling broke around 2004
- **Dark silicon**: not all transistors can be powered all together due to power constraints
- large cache units integrated within the chip

## Heterogeneous Multicore
Integrate different types of processor cores on single chip (asymettry)
- core types: CPU,GPU,NPU,DSP
- Power efficency: assing different workload to the appropriate core type to minimize power consuption
- Leveragin specific cores to maximize system performance (specialization):
	- ARM big.LITTLE for mobile and embedded devices
	- Apple M1 
- Heterogeneity is not the norm

## Supercomputers
They are large-scale parallel systems with strict energy constraints. designed to perform computations at high speeds. Current target **Exascale Computing** $O(10^{18})$ FLOPS

**Definition of FLOP**: how many operation I can do in a second.

Multiple independent CMP nodes (often with some powerful GPUs) connected with one or more high-bandwith, low-latency networks and with a dedicated network for I/O offering high-bandwith.
Supercomputers are ranked by their maximum LINPACK benchmark performance, it solve a dense linear algebra problem $A*x=b$ in terms of FLOPs. LINPACK measures peak capability, not application efficiency
Powerfullness and Sustainability have separate ranking.

## From hardware to software
Performance is now a programmer's thing, they must make their programs more parallel
### Software challenges
The transition to CMP introduced new complexities (memory consistency, cache coherence, etc etc) concurrency problems, race conditions, and thread syncronization errors, sever software programs had to be rewritten. 
Lots of HW complexities (on chip, on system level,on scale out)
Different needs in different contexts

=> Hardware perspective vs Software perspective