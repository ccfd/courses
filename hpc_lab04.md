---
number: 4
course: HPC
material: Labs
author: S. Gepner
title: Lab 4
---


# Lab IV

Today we will get familiar with some concepts concerning concurent processing.
We will try to solve the problems as we proceed with the material.

We will start with some simple examples of starting and managing threads using standard C++ tolls.
We will try to show some common problems and solutions whan dealing with concurent processing.

## Threads

To compile programs using `std::thread` use `g++ thread1.cpp -pthread`

### Starting and joining
The easiest way to manage threads is to add to your source `#include <thread>` and make do wiht `std::thread` objects.
New threads asre started by creating new `std::thread` instances, and passing a collable (one that has () and can be called)
object to be executed in the new thread. Once the thread is started it executes, until it finishes.
The first problem to look at is not to leave alive threads for control to go out of scope (i.e. to go out of the {} region),
since this will cause running threads to trtminate and is in general an undefined behavior.
To prevent this, threads should be joined with `.join()` (C++20 introduces a `jthread` that supports auto-joining).

See thread1.cpp, compile and run it, examine the commented out synchronization section.

### Detaching
Threads started within a scope live only within this scope, and will be terminated when it finishes.
This might be a problem for sytuations one wishes to use some form of thread caller functions.
To prevent the thread execution from being abruptly terminated we can use `detach`, which detaches execution from the thread object.  
Note: Should be used with care.

See thread2.cpp

### Race condition
Examine thread3.cpp, compile and run. What is the result of the program? Is it the same every time? Is this a problem? At least the program works, right?

Experiment with the `atomic` template. Is it any better now?  
Modify incrementation of the `thread_counter`, is there any difference in using `thread_counter = thread_counter + 1` or `thread_counter += 1`?

### Mutex and the critical section
Threads working concurrently use the same memory space, and as we have seen the consequent race condition is a problem.
The region of the code our threads might interfere is the **citical section**, one that needs to be appropriatly protected.
We will use the `mutex` (Mutually Exclusive Lock) mechanism. See thred4.cpp for an example. Compile and run the code.
Than, modify thread3.cpp to use `mutex` instead of `atomic`.

