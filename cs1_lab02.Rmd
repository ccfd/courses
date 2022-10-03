---
number: 2
course: Computer Science 1
material: Instruction 2
---

## 1.
Write a program using a function which prints:
```c++
#include <stdio.h>

void FunView();          // declaration of a function: line ended with semicolon!

int main()               // main function
{
    FunView();           // call the function FunView
    
    return 0;
}
                         // definition of the function FunView
void FunView()           // function header: contains return type and name
{
    printf("Hello!");    // function starting bracket
}                        // function ending bracket
```

## 2.
Modify the program by adding three new functions.
First function should increment the global variable `Number` by $5$, e.g.:
```c++
void IncNumber()
{
    Number = Number + 5; // or better: Number += 5;
}
```
Second function should decrement variable `Number` by 3.
Third function should print current value of variable `Number`.
The variable should be declared as global (e.g. after declaration of the function but before the beginning of the main function) and initialize it with $10$.
Remember about proper declaration of the functions.
Inside main function call the function according to the following pattern:

- print value of the variable `Number`;
- increment value of the `Number` by 5 and repeat it three times;
- print value of the variable `Number`;
- decrement value of the `Number` by 3; do it two times;
- increment value of the `Number` by 5;
- print value of the variable `Number`;

## 3.
Create a new program which solves the quadratic equation.
Here is a proposition of the program layout:
```c++
#include <math.h>

#include <stdio.h>
// declaration of functions
void ReadData();
void SolveQuadEq();
void PrintSolution();

// declaration of global variables
double a, b, c, delta;
double x1, x2;

// main function
int main()
{
    ReadData();
    SolveQuadEq();
    PrintSolution();
  
    return 0;
}

// definitions of other functions
void ReadData()
{
    // fill the function with proper code
}

void SolveQuadEq()
{
    // fill the function with proper code
}

void PrintSolution()
{
    // fill the function with proper code
}
```

