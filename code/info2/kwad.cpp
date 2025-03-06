#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// oblicza calke metoda trapezow
// computes definite integral using complex the trapezoidal rule 
double trapez(double a, double b, double (*pf)(double), int n )
{
  double h    = (b - a) / n;
  double suma = 0.5 * (pf(a) + pf(b));
  double x    = a;

  for (int i = 0; i < n-1; i++)
  {
    x    += h;
    suma += pf(x);
  }
  return suma * h;
}

// oblicza calke metoda simpsona
// computes definite integral using complex the Simpson rule 
double simpson( double a, double b, double (*pf)(double), int n )
{
  double  x    = a;
  double  h    = (b - a) / (2*n);
  double  h2   = h * 2;
  double  x1   = a + h;

  double  suma = pf(a) + 4. *pf(x1) + pf(b);

  for (int i = 0; i < n-1; i += 1)
  {
    x    += h2;
    suma += 2. * pf(x) + 4. * pf(x + h);
  }
  return suma * h / 3.;
}

