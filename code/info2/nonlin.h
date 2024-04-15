#ifndef __NONLIN_H__
#define __NONLIN_H__

//  rozwiazuje rownanie   pf(x)=0 metoda bisekcji
//  a,b to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  UWAGA: musi byc spelniony warunek:
//  pf(a)*pf(b) <= 0 (jesli nie jest spelniony zwracana jest wartosc 0, liczba iteracji wynosi -1)
//  jesli warunek jest spelniony
//    wartosc zwracana = liczba iteracji uzytych dla znalezienia pierwiastka
//    x  = poszukiwany pierwiastek okreslony z dokladnoscia "eps"

//  solves equation pf(x) = 0 using bisection method
//  a,b are the limits of the range in which the root is sought
//  (*pf)(double) is pointer to function of type double with a one argument
//  eps is accuracy used to stop an iteration process (eg. eps=1.e-3)
//  *i_iter pointer to a variable storing the number of iterations
//  WARNING: 
//  IF condition pf(a)*pf(b) <= 0 is satisfied the function returns 
//  the root approximation and the number of iteraions *i_iter for given eps 
//  ELSE
//  it returns 0, and the number of iterations is set to -1
//
double bisec( double a, double b, double (*pf)(double), double eps, int *i_iter);

#endif // __NONLIN_H__
