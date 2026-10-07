#include <iostream>


/**
 * @brief Read exactly 10 integers from standard input. Without storing the numbers in an
array or vector, calculate and print the sum of the even numbers 
 * 
 * @return int 
 */
int main(){
    int n;
    int sum = 0;

    for(int i = 0;i<10;++i){
        std::cin >> n;
        if(n % 2 == 0){
            sum += n;
        }
    }

    std::cout << sum << "\n";
    return 0;
}