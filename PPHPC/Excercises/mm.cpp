#include <iostream>
#include <sys/time.h>



/**
 * @brief Excercise about time performance in matrix operation swapping the for loop indexes 
 * 
 * @return int 
 */
int main(){
    int A[3][3] = {
        {1,2,3},
        {5,6,7},
        {11,12,13}
    };

    int B[3][3] = {
        {1,2,3},
        {5,6,7},
        {11,12,13}
    };

    int C[3][3] = {};
    for(int i = 0;i<3;++i){
        for(int j=0;i<3;++j){
            for(int k=0;k<3;++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    } 

}