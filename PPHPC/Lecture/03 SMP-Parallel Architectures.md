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
- SIMD (Single instructions, Multiple data): executes the same operation on multiple data items simultaneously
- MISD (Multiple Instructions, Single data): Multiply PEs to execute different instructions on a single stream of data (not really used)
- MIMD (Multiple instructions, Multiple data): uses multiple PEs to execute differnt instructions on different data streams 
=> Flynn's taxonomy is useful to reason about instruction and data parallelism 