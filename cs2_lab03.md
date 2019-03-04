---
number: 3
course: Computer Science 3
material: Instruction 3
author: W. Regulski, rev. W. Gryglas, eng. T.Wacławczyk
---

# Iterative methods for solution of non-linear algebraic equations
Files for the present tutorial can be found using following links:


 - [Header file nonlin.h](http://ccfd.github.io/courses/code/info2/nonlin.h)
 - [Source file nonlin.cpp](http://ccfd.github.io/courses/code/info2/nonlin.cpp)

## 1. Introduction
During this tutorial we will learn how to use different methods for solution
of the non-linear algebraic equations. As in practice it is impossible to
find exact solution to this problem, we search for approximate solution only.
To meet this goal, three different iterative numerical techniques will be introduced, namely:
bi-section, secant and tangent methods. 
All of them require, that the function which root is
the solution of the problem is continous.



## 2. Bi-section method

In the case of bi-section method we use the fact 
that if the root of the given,
continous function `f(x)` is located
inside of the interval, say `[a,b]`,
the values of the continous function `f(x)` 
at the points `a`,`b` must then have opposite signs, hence
$f(a) \cdot f(b) < 0$. 
This observation states so called  Darboux theorem introduced by
Jean Gaston Darboux (1842-1917).
Using it we can solve 
non-linear algebraic equations,
for example:
$$cos(x) = x$$
In order to find its solution we will use function
`bisec` defined inside *nonlin.h* and *nonlin.cpp* files.
The header of this function is given below:
```c++
double bisec(double a, double b, double (*pf)(double), double eps, int *iter)
```

The function `bisec` returns approximation of the root of the algebraic equation
located in the interval $[a,b]$. To use function `bisec` the
following parameters are required:

- `a` and `b` - the ends of the interval where the solution is searched
- `(*pf)` - pointer to  the function containing algebraic equation to be solved
- `eps`   - accuracy of the solution $\varepsilon$
- `iter`  - pointer to the variable storing information about number of iterations
            required to reach solution with specified accuracy $\varepsilon$.
            If on both end of the interval $[a, b]$ the evaluated values of
            the function $f(a)$,$f(b)$ have the same signs then the pointer `iter` points
            to the value `-1` and the function returns value `0`.
            

### Exercises
1. Write a function `double eqn(double x)` which returns value if the non-linear
   algebraic equation written in the form  $f (x) = 0$
2. Read from the keyboard (initially define in the code) accuracy of the solution `eps`
   the values of the interval ends `a` and `b`. Remember $f(a) \cdot f(b) < 0$. 
3. Write on the screen the root value and the number of iterations.
4. Rewrite the program in a way it solves your non-linear algebraic equation in a loop
   where accurcy is changing  $\varepsilon = 2^{-20} , 2^{-19}, ..., 2^{-3}$.
5. Make a diagram showing how number of iterations `iter` is changing with respect
  to selected accuracy `eps` (use logharitmic scale to show how accuracy is changing).

## 3. Methods of secants and/or tangents
As mentioned above the other methods that can be used to iteratively find a solution
of non-linear algebraic equations are the method of tangents and the method of
secants. In the case of the method  of secants the following approximations of the
solution are given by the intersection of the secant (defined on the two points)
with abscisa (x- axis). In the next iteration, value of the function at point $x_i$
is used in construction of the next secant. The iterative scheme in the method of
secants has the following form:
$$ x_{i+1} = x_i - f(x_i) \frac{x_i-x_{i-1}}{f(x_i)-f(x_{i-1})} $$
In the case of the method of tangents (also called Newton's method) the next
approximation of the solution is obtained as the intersection of the tangent
(defined at one point) with abscisa (x-axis). The iterative scheme for Newton's
method, reads:
$$ x_{i+1} = x_i - \frac{f(x_i)}{f'(x_i)} $$

### Exercises
1. Find solution to the equation defined above using both tangents and secants methods.  Write on the screen exact number of iterations required to obtain solution with prescribed accuracy in: bi-section, secants and tangents methods.
2. Create the diagram showing dependence of the accuracy of the solution on the  number of iterations (for each method, use logharitmic scale to depcit accuracy)
3. Using three methods solve equation with parameter $cos(x) = w \cdot x$ using $\varepsilon = 10^{-6}$. The value of the parameter $w$ should change in a range
$w = 0.5, 0.6, ..., 15.0$.

## 4. Additional problem
Methods disscused here can also be used to find extrema of the functions. Try to find
extremum of the function:
$$ f (x) = (1 + x) \cdot arctan(x) $$
