//------------------------------- ELIMINACJA GAUSSA -------------------------
void Gauss(int n, double **M, double *f, double *x)
{
  int i, j, k;
  double s;
  double wsp;

  double **a;
  double *b;

  // alokacja tymczasowych tablic
  if ((b = (double *) malloc(n * sizeof(double))) == NULL) {
    perror("Gauss fun. (b table)");
    exit(1);
  }

  if ((a = (double **) malloc(n * sizeof(double *))) == NULL) {
    perror("Gauss fun. (a table)");
    exit(1);
  }

  for (int i = 0; i < n; i++)
    if ((a[i] = (double *) malloc(n * sizeof(double))) == NULL) {
      perror("Gauss fun. (a[i] table)");
      exit(1);
    }

  // przepisanie wartosci do tymczasowych tablic
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      a[i][j] = M[i][j];
    }
    b[i] = f[i];
  }

  //eliminacja

  // wiersz przy pomocy którego eliminujemy elementy
  for (i = 0; i < n - 1; i++)
  {
    // wersz którego elementy eliminujemy
    for (k = i + 1; k < n; k++)
    {
      wsp = a[k][i] / a[i][i];
      // odejmowanie elementów wiersza "i" od wiersza "k"
      for (j = i + 1; j < n; j++)
        a[k][j] -= a[i][j] * wsp;

      // odejmowanie prawych stron
      b[k] -= b[i] * wsp;
    }
  }

  //rozwiazanie ukladu
  x[n - 1] = b[n - 1] / a[n - 1][n - 1];

  for (i = n - 1; i >= 0; i--)
  {
    s = 0.0;
    for (j = i + 1; j < n; j++)
      s += a[i][j] * x[j];

    x[i] = (b[i] - s) / a[i][i];
  }

  for (int i = 0; i < n; i++)
    free(a[i]);

  free(a);
  free(b);
}
