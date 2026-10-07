C++ is a general-purpose programming language evolved from C, widely used when we need high performance and control over resources. It supports several programming styles (object oriented,procedural,generic).

code example: 
```c++
#include <iostream>

int main(){
	int a = 10;
	int b = 20;
	int sum = a + b;
	std::cout << "sum" << sum << std::endl;
	
	return 0;
}
```
string differ from C 
``` c
char name[] = "alice";
```
```c++
std::string = "alice";
```

Input and output also differ
```c++
std::cin >> n //similar to scanf()
std::cout << n  //similar to printf()
```

loop and conditional are more or less the same

## How to build and run a C++ program
like C but with g++

## Reference and pointer
Pointer declare the addresses

-> reference vs pointer


## Array
```c++
#include <array>
#include <iostream>
int a[5]{};
a[0] = 10;
a[1] = 20;
a[2] = 30;
std::array<int,5> a{10,20,30,40,50}
```

## Vector
```c++
std::vector<int> values;
values.push_back[10];
values.push_back[20];
values.push_back[30];

std::cout << values.size{} == '\n';
```
vectore stores element contigusly and manage the space automatically


## Dynamic memory
c++ supports explicit dynamic allocation with ```delete``` and ```new``` 
**RAII** (Resource Acquisition Is Initialization). A vector oens is storage and release it automatically when it is destroyed.

## Struct and class
struct -> public
class -> private

## Excercises
- Swap Two integers by reference 
	- implement swap_values(int&,int&)

