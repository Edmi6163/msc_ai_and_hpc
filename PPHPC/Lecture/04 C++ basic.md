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


# C++ Essentials
In modern C++ performance and abstraction coexist. Values and objects have lifetimes. The Standard Template Library [[#The STL model]] is central, it contains different types of construct (containers, algorithm,iterators).

## Automatic type deduction (auto)
`auto` reduces verbosity, it not dynamic typing, the type is fixed at compile time. The compiler inspects the right-hand side (RHS) of the assignment and deduces the type from initialization

**decltype**: `decltype(expr)` returns the type of the expression wihtout evaluating it. Unlike `auto`, it preserves const and reference qualifier.
```c++
//returns the type deduced from the expression a+b
template <typename T,typename U>
	auto sum(T a, U b) -> decltype(a+b){
		return a+b;
		}
```

List initialization {} vs Parentheses ()
- =,{},() are not intechangeable
- brace initialization prevents narrowing

## The STL model
- **Containers**,accessed through **iterators**, and processed by **algorithms**
- std::vector as the default sequence container
### Iterators
An iterator (it) is a generalized pointer tht denotes a position in a sequence
- STL algorithms operate on half-open ranges (i.e. (first,lats)) and they are **container-agnostic** 

There are different types of Iterators:
- Output iterators - single pass, **write**
- Input Iterators - single pass, read 
- Forward Iterators - multi-pass, forward only
- etc etc 

### Common pitfalls with iterators
