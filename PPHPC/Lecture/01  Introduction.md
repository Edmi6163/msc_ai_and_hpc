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
