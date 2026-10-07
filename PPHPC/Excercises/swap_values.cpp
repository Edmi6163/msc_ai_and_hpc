#include <array>
#include <iostream>
#include <vector>

/**
* @brief Swap Two integers by reference implement swap_values(int&,int&)
 */
void swap_values(int& a, int& b){
    int tmp = a;
    a = b; 
    b = tmp; 
}



int main(){
    int a = 10;
    int b = 15; 

    std::cout << "a and b: " << a << b << '\n';
    swap_values(a,b);
    std::cout << "a and b after swap_values: " << a << b << '\n';
}