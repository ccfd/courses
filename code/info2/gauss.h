
#ifndef GAUSS_H
#define GAUSS_H

/*
Funkcja znajduje rozwiazanie ukladu rownan liniowych
A * x = b
metoda eliminacji Gaussa.

Argumenty:
  N - liczba rownan,
  A - wskaznik na tablice dwuwymiarowa,
  x - wskaznik na tablice przechowujaca rozwiazanie ukladu rownan,
  b - wskaznik na tablice prawych stron ukladu rownan.
*/
/*
Function solves a system of linear equations
A * x = b
using the Gauss elimination method.

Functions arguments:
  N - number of equations,
  A - pointer to two-dimensional array,
  x - pointer to an array storing solution of the system of equations,
  b - pointer to an array storing the right hand side vector b.
*/
void gauss(int N, double **A, double *x, double *b);

#endif

