If I have 2 matrix (a and b, result c) to multiplicate I have to multiplicate $ROW * COLUMN$ $c_{1,1} = a_{1,1}*b_{1,1} + a_{1,2} * b_{2,1}$ 
- General formula -> $C_{ij}= \sum a_{ij}b_{jk}$ (TODO: check slides for the precise formula)
Matrix multiplication comparison with python, C and java (well...C is faster), but other than language is possiblie to change the code optimization (playing with loops position). Indexes in loop are affected by cache (cache hits and cache misses (recall to _architettura degli elaboratori_ course). 
Access pattern for order i,j,k are influenced by memory layout (spatial layout)
There are other simple changes