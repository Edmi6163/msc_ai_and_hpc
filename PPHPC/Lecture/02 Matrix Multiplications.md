If I have 2 matrix (a and b, result c) to multiplicate I have to multiplicate $ROW * COLUMN$ $c_{1,1} = a_{1,1}*b_{1,1} + a_{1,2} * b_{2,1}$ 
- General formula -> $C_{ij}= \sum a_{ij}b_{jk}$ (TODO: check slides for the precise formula)
Matrix multiplication comparison with python, C and java (well...C is faster), but other than language is possiblie to change the code optimization (playing with loop's indexes). Indexes in loop are affected by cache (cache hits and cache misses, trying to maximize the cache hit (recall to _architettura degli elaboratori_ course). **Cache index not search** 
Access pattern for order i,j,k are influenced by memory layout (spatial layout). Always consider the maximum FLOPS of the machine [[01  Introduction]]. 
Row-major order is the matrix laid out in memory in C or Fortran, but each conding languages has it's own. 
## Access pattern order i,j,k
-> each matrix (a,b,c) has a different quality of spatial locality

## Other ways to optimize
- Compiler optimization flag can be used (clang in the example, with -O flag)
- Parallel loops: parallelization, separate the "i" of the for loop for each operations
	- You can parallelize all the indexes, each one will change the execution time. 
	- **Thumb Rule: parallelize outer loops rathern than innner loops**
- Data Reuse: You can splits the matrix in parts (like $64*64$ instead of $4096*4096$) to reduce memory access. Multiplying by blocks instead of multiplying by row. This is called Tiled Matrix, it's possible to tiled the matrix in different level of cache
- Vectorization: doing a number of operations between vector (need to implement a Vector ALU). Compiler can vectorize, but requires lot of manual intervention. Vectorization flags are also a things. Intel provide vector instructions (AVX). Is it very complex to use that also compiler sometimes fails in doing it
- There are many more operations (look at the slide for them)
- Intel MKL (math kernel library)

=> man gettimeofday to measure the comparison between code (TODO EXCERCISE)
