
/*
Funkcja gauss znajduje rozwiazanie ukladu rownan liniowych
A * x = b
metoda eliminacji Gaussa.

Argumenty:
  N - liczba rownan,
  A - wskaznik na tablice dwuwymiarowa,
  x - wskaznik na tablice przechowujaca rozwiazanie ukladu rownan,
  b - wskaznik na tablice prawych stron ukladu rownan.
*/

#include "gauss.h"

void gauss(int N, double **A, double *x, double *b) {
  double sum, wsp;

  for (int i = 0; i < N-1; i++) {

    for (int k = i+1; k < N; k++) {
      wsp = A[k][i] / A[i][i];

      for (int j = i; j < N; j++)
        A[k][j] -= A[i][j] * wsp;

      b[k] -= b[i] * wsp;
    }
  }

  x[N-1] = b[N-1] / A[N-1][N-1];
 
  for (int i = N-1; i >= 0; i--) {
    sum = 0.;

    for (int j = i+1; j < N; j++)
      sum += A[i][j] * x[j];

    x[i] = (b[i] - sum) / A[i][i];
  }
}

