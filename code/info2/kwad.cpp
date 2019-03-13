#include <math.h>

// oblicza calke metoda trapezow
double trapez(double a, double b, double (*pf)(double), int n )
{
  double h    = (b - a) / (n - 1);
  double suma = 0.5 * (pf(a) + pf(b));
  double x    = a;

  for (int i = 1; i < n-1; i++)
  {
    x    += h;
    suma += pf(x);
  }
  return suma * h;
}


// oblicza calke metoda simpsona
double simpson( double a, double b, double (*pf)(double), int n )
{
  double  x    = a;
  int     nc   = abs((n - 2) / 2 + 1) * 2 + 1;  // poprawione n tak by bylo nieparzyste i >= n_old
  double  h    = (b - a) / (nc - 1);
  double  h2   = h * 2;
  double  suma = pf(a) + 4. *pf(a + h) + pf(b);

  for (int i = 3; i < nc; i += 2)
  {
    x    += h2;
    suma += 2. * pf(x) + 4. * pf(x + h);
  }
  return suma * h / 3.;
}

