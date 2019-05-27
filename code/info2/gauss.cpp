
void gauss(int n, double a[][N], double b[], double x[]) {
  int i, j, k;
  double s;
  double wsp;

  // eliminacja

  // wiersz przy pomocy ktorego eliminujemy elementy
  for (i = 0; i < n-1; i++)
  {
    // wiersz ktorego elementy eliminujemy
    for (k = i+1; k < n; k++)
    {
      wsp = a[k][i] / a[i][i];
      // odejmowanie elementow wiersza "i" od wiersza "k"
      for (j = i+1; j < n; j++)
        a[k][j] -= a[i][j] * wsp;

      // odejmowanie prawych stron
      b[k] -= b[i] * wsp;
    }
  }

  // rozwiazanie ukladu
  x[n-1] = b[n-1] / a[n-1][n-1];
 
  for (i = n-1; i >= 0; i--)
  {
    s = 0.0;
    for (j = i+1; j < n; j++)
      s += a[i][j] * x[j];

    x[i] = (b[i] - s) / a[i][i];
  }
}

