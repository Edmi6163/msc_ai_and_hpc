Shared memmory multiprocessor (SHMM) system: Any memory location can be accessible by any of the processors 
A *single address space* exists, meaning that each memory location is given a unique address within a single range of addresses. Generally shared memory is more convenient although it does require access to shared data to be controlled by the programmer (recall to SO course). Note that shared memory is not a physical memory (kinda see it like a vector), is a virtual space). 
Program = Algorithm + data structure. In order to move from sequential to parallel the structure must be shared. 

## Shared memory multiprocessor using a single bus 
Even if the code is parallel, bus allow to write just in a sequential way

## Alternatives for programming shmm
- Using heavy weight processes (unix system v or posix )
- Using threads (pthreads (posix threads)), threads can be create through a system call (by operating system)
- New programming langauge for parallel programming (like Ada), not a popular things

### Using heavy weight processes
FORK-JOIN construct, when creating a process the process get cloned `fork()` or `exec()` with a new PID and then created. ( #todo Look for a recall for fork and exec). 
Unix System Calls: No join routine, use exit() and wait()

## Difference between Process and Thread
- Process: completely separate program with its own variables,stack,heap, memory allocation, program count, interrupt, file descriptor
- Threads: shares the same memory space and global variables between routines 
Heap is a balanced tree, and there are objects and stuff manually allocated (dynamical allocated) by the programmer (`malloc`, `new`, `free`). In Stack instead goes variables automatically initialized (like functions, variable declaratian) (statically allocated). 
Stack is related to program counter (PC). So in threads stack is separated (one PC for each executing and) and Heap is shared.

# PThreads
```c++
phtread_create(&thread1,NULL,proc1,&arg) 
pthread_join(thread1,*status)
```
 `&thread1` because it's the value of the thread ID
 `&arg` the argument to pass

### Detached Threads


### Thread-Safe Routines
Thread safe if they can be called from multiple threads simultaneously and always produce correct results. 
> Standard I/O thread safe (prints messages without interleaving the characters)

System routines that return time may not be thread safe
Routines that access shared data may require care to be made thread safe
! Unsafe: random number generation: Requires an internal status

## Access Shared Data
Access shared data needs careful control.
Consider 2 processes each of which is to add one to a shared data item x. Necessary for the contents of the location x to be read, x +1 computed, and the result written bakc to the location
remember: `x=x+1` are 3 instructions: 
Process 1
```asm
read x 
compute x + 1
write to x
```
Process 2
```asm
read x 
compute x + 1
write to x
```

### Conflict in accessing shared variable
The way to avoid it is critical section (mutual exclusion): 
A mechanism for ensuring that only one process accesses a particular resource at a time is to establish sections of code involving the resource. 
- **Locks**: Simplest mechanism for ensuring mutual exclusion of critical sections, (busy waiting is a way).
- Pthread lock routines: Locks are implemented in Pthreads with mutually exclusive lock variables, or "mutex" variables: 
```c++
pthread_mutex_lock(&mutex1)
//critical section 
pthread_mutex_unlock(&mutex1)
```
Only the thread that locks a mutex can unlock it. 

Recall to deadlock. 