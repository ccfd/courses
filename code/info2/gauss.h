
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

void gauss(int N, double **A, double *x, double *b);

#endif

