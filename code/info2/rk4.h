#ifndef __RK4_H__
#define __RK4_H__

// --------------------------------------------------------------------------
// Funkcja wykonuje, metoda Rungego-Kutty IV-ego rzedu,
// jeden krok calkowania skalarnego rownania rozniczkowego zwyczajnego:
//
//  dy/dx = fun(x,y),    y(x0)=y0
//
// Parametry formalne:
// x0 - wartosc startowa zm. niezaleznej
// y0 - wartosc startowa zm. zaleznej
// h  - krok calkowania
// fun(x,y) - nazwa funkcji obliczajacej prawe strony
// y1 - obliczona wartosc zmiennej zaleznej w punkcie x0+h

// --------------------------------------------------------------------------
// Using IV-th order Runge-Kutta method, function performs
// one integration/time step during solution of the one first-order ODE
// (initial value problem):
//
//  dy/dx = fun(x,y),    y(x0)=y0
//
// Parameters:
// x0 - initial value of independent variable (time)
// y0 - initial value of dependent variable (unknown function y())
// h  - integration/time step size
// fun(x,y) - name of the function computing the right hand side of the equation
//
// rk4() returns y1 - value of dependent variable at point/time x0+h
//
double rk4(double x0, double y0, double h, double (*fun)(double, double));

// --------------------------------------------------------------------------
// Funkcja wykonuje, metoda Rungego-Kutty IV-tego rzedu,
// jeden krok calkowania wektorowego rownania rozniczkowego zwyczjanego:
//
//  dY/dx = Fun(x,Y),    Y(x0)=Y0
//
// Parametry formalne:
// x0 - wartosc startowa zm. niezaleznej
// y0 - wartosc startowa zm. zaleznej (tablica n-elementowa)
// h  - krok calkowania
// n  - liczba rownań
// fun(x,y,prawastr) - nazwa funkcji obliczajacej prawe strony
// y1 - obliczona wartosc zmiennej zaleznej w punkcie x0+h
//      (tablica n-elementowa)

// ------------------------------------------------------------------------------
// Using IV-th order Runge-Kutta method, function performs
// one integration/time step during solution of the set of
// the n first-order ODE's:
//
//  dY/dx = Fun(x,Y),    Y(x0)=y0[]   where Y,Fun,y0 are vectors
//
// Parameters:
// x0   - initial value of independent variable (time)
// y0[] - initial values of dependent variables (n-element array)
// h    - integration/time step size
// n    - number of the first-order ODE's (size of arrays y0[] and y1[])
//
// fun(x0,y0,k) - name of the function computing the right hand sides
//                of the set of n equations, it takes x0, y0[] and returns
//                vector k[] containing evaluated right hand sides
//
// vrk4() result is y1[] array with values of dependent variables
// at point/time x0+h
//
void vrk4(double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[]);

#endif
