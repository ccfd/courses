---
number: 4
course: HPC
material: Labs
author: S. Gepner, J. Gałecki
title: Lab 4
---


# Lab IV

Today we will get familiar with some concepts concerning concurrent processing.
We will start with some simple examples of starting and managing threads using standard C++ tools.
We will try to show some common problems and solutions when dealing with concurrent processing.

### Starting and joining
The easiest way to manually manage threads in C++ programs is to use the `std::thread` class from the `thread` header.
New threads are started by creating new `std::thread` instances, and passing a callable object (an object for which the `()` operator is defined) to be executed in the new thread.
Once the thread is started it executes independently, until it finishes.
The first problem to look at is not to leave live threads before exiting the `main` function, since this will cause running threads to terminate and is undefined behavior.
To prevent this, threads should be joined with `.join()`. C++20 introduces `std::jthread` which supports auto-joining.

Execute the following code:

```c++
#include <chrono>
#include <iostream>
#include <thread>

void work() {
  std::cout << "Hello from thread " << std::this_thread::get_id() << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
  std::jthread thread{work};
  work();
}
```

To compile it, run (assuming your source file is called `source.cpp`):

```bash
g++ -std=c++20 source.cpp -pthread
```

### Race condition

Execute the following code and discuss the results:

```c++
#include <atomic>
#include <iostream>
#include <thread>

int counter = 0;

void work() {
  for (int i = 0; i < 1000000; ++i)
    ++counter;
}

int main() {
  std::jthread thread{work};
  work();
  thread.join();
  std::cout << counter << '\n';
}
```
Are the results the same every time? Is this a problem? At least the program works, right?

What is a race condition?

Experiment with the `std::atomic` template. Is it any better now?
Modify increment of the `counter`, is there any difference between using `counter = counter + 1` or `counter += 1`?

### Mutex and the critical section
Threads working concurrently use the same memory space, and as we have seen the consequent race condition is a problem.
The region of the code our threads might interfere is the **critical section**, one that needs to be appropriately protected.
We will use the `mutex` (Mutually Exclusive Lock) mechanism. See the code below for an example. Compile and run the code.
Next, modify the previous example to use `mutex` instead of `atomic`.

```c++
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex m;
std::vector<int> ints;

void work() {
  for (int i = 0; i < 1000; ++i) {
    m.lock();
    ints.push_back(i);
    m.unlock();
  }
}

int main() {
  std::jthread thread{work};
  work();
  thread.join();

  for (int i : ints)
    std::cout << i << ' ';
  std::cout << '\n';
}
```

## TBB

Thread Building Blocks is a library designed to make parallelization relatively easy.
TBB allows us to express parallel work in an abstract fashion, without manually managing threads.
In the background, TBB manages a pool of threads, which execute the work we assign to it.

In order to use TBB, you'll first need to install it using spack:
```
spack install intel-tbb
spack load intel-tbb
```

Next, use the [starter project](http://ccfd.github.io/courses/code/hpc/lab45_starter.zip)

### Serial implementation
Examine the code in the starter project, compile and run it. It is a very simple program that computes the sine of values in a vector in place.

We would now like to perform this task in parallel.

### `parallel_for`

The for loop used to compute the sine is a great example of an embarrassingly parallel problem.
There should be no data race, and no problem with concurrent manipulation, and it should parallelize very easily.
For this task, TBB offers a simple `parallel_for`, which with little modification to the code manages starting, stopping and executing working threads.

```
tbb::parallel_for(range, kernel);
```

For `range` we will use `tbb::blocked_range<T>(T n0, T n1)`, which is a template class describing a one-dimensional iteration space from $n_0$ to $n_1-1$.
For our problem it is the same as the the range of the for `(0,y.size())`.  
`kernel` is a callable object that takes `tbb::blocked_range<T> r` as an argument and processes the chunk of the problem defined by `r`.
In our problem we will use lambda expression `[&](tbb::blocked_range<int> r){}`.

Note: Our problem is very simple, but a rule of thumb is to put frequently accessed values into local variables of the `kernel`. This should help compiler to optimize the loop better. Local variables are easier for the compiler to track.

### `parallel_reduce`

The loop initializing the data was easy to parallelize with `parallel_for`.
How about summation over all elements? In this operation elements of an array are *reduced* into a single result - the sum.
TBB offers a `parallel_reduce` function template to perform reduction operations over the range.
The simplest syntax is `parallel_reduce(range, identity_value, func, reduction)`, where:
* `range` defines a a range, to which sub-ranges `func` will be applied.
* `identity_value` is identity for the operation performed by `func` (0 for summation and 1 for multiplication).
* `func` is a callable object. Could be a lambda expression.
* `reduction` defines how sub-range reductions are joined to produce the final result. This can also be defined as a lambda expression, or we could use standard function objects. 

## A more complex problem
Examine the provided example `fem-truss` which evaluates a FEM operator for a truss. What opportunities for parallelization do you see? Discuss with the group and the instructor.
