//------------------------------- Bardzo pomocne funkcje

int P(int x, int y, int z)
{
  return (y*(mx + 1) + x) * 2 + z;
}

int Q(int x, int y)
{
  return y*mx + x;
}

int DOF(int elidx, int elidy, int locdofid)
{
  if (locdofid < 4)
  {
    return 2 * (elidy*(mx + 1) + elidx) + locdofid;
  }
  else if (locdofid == 4 || locdofid == 5)
  {
    return 2 * ((elidy + 1)*(mx + 1) + elidx - 1) + locdofid;
  }
  else if (locdofid == 6 || locdofid == 7)
  {
    return 2 * ((elidy + 1)*(mx + 1) + elidx - 3) + locdofid;
  }
}

const double skala = 1.0;

//------------------------------- MACIERZ SZTYWNOSCI ELEMENTU --------------------------
const double E = 100.;
const double nu = 0.3;
const double elems[] = {
  0, 1. / 2. - nu / 6., 1. / 8. + nu / 8., -1. / 4. - nu / 12., -1. / 8. + 3.*nu / 8.,
  -1. / 4. + nu / 12., -1. / 8. - nu / 8., nu / 6., 1. / 8. - 3.*nu / 8.
};
const double Md = E / (1 - nu*nu);

const double K[8][8] = { { elems[1], elems[2], elems[3], elems[4], elems[5], elems[6], elems[7], elems[8] },
{ elems[2], elems[1], elems[8], elems[7], elems[6], elems[5], elems[4], elems[3] },
{ elems[3], elems[8], elems[1], elems[6], elems[7], elems[4], elems[5], elems[2] },
{ elems[4], elems[7], elems[6], elems[1], elems[8], elems[3], elems[2], elems[5] },
{ elems[5], elems[6], elems[7], elems[8], elems[1], elems[2], elems[3], elems[4] },
{ elems[6], elems[5], elems[4], elems[3], elems[2], elems[1], elems[8], elems[7] },
{ elems[7], elems[4], elems[5], elems[2], elems[3], elems[8], elems[1], elems[6] },
{ elems[8], elems[3], elems[2], elems[5], elems[4], elems[7], elems[6], elems[1] } };

//------------------------------- MACIERZ MASOWA ELEMENTU --------------------------
const double rho = 1;
const double Mm = rho;

const double M[8][8] = { { 4, 0, 2, 0, 1, 0, 2, 0 },
{ 0, 4, 0, 2, 0, 1, 0, 2 },
{ 2, 0, 4, 0, 2, 0, 1, 0 },
{ 0, 2, 0, 4, 0, 2, 0, 1 },
{ 1, 0, 2, 0, 4, 0, 2, 0 },
{ 0, 1, 0, 2, 0, 4, 0, 2 },
{ 2, 0, 1, 0, 2, 0, 4, 0 },
{ 0, 2, 0, 1, 0, 2, 0, 4 } };

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

void quad(double * p, int x, int y){
  double px[4], py[4];
  px[0] = skala*p[P(x, y, 0)] + x;
  py[0] = skala*p[P(x, y, 1)] + y;
  px[1] = skala*p[P(x + 1, y, 0)] + x + 1;
  py[1] = skala*p[P(x + 1, y, 1)] + y;
  px[2] = skala*p[P(x + 1, y + 1, 0)] + x + 1;
  py[2] = skala*p[P(x + 1, y + 1, 1)] + y + 1;
  px[3] = skala*p[P(x, y + 1, 0)] + x;
  py[3] = skala*p[P(x, y + 1, 1)] + y + 1;
  setcolor(0.15);
  polygon(px, py, 4);
  setgray(1);
  line(px[0], py[0], px[1], py[1]);
  line(px[1], py[1], px[2], py[2]);
  line(px[2], py[2], px[3], py[3]);
  line(px[3], py[3], px[0], py[0]);
}

//------------------------------- Rysowanie strzalki
void strzalka(double px, double py, double vx, double vy, double sk, double k) {
  vx *= sk;
  vy *= sk;
  setcolor(1);
  line(px, py, px + vx, py + vy);
  px += vx;
  py += vy;
  double d = sqrt(vx*vx + vy*vy);
  vx *= k; // d;
  vy *= k; // d;
  line(px, py, px - vx - vy / 2, py - vy + vx / 2);
  line(px, py, px - vx + vy / 2, py - vy - vx / 2);
}

//------------------------------- Rysowanie calego ukladu
void draw(double * p, double * f) {
  double px, py, vx, vy;
  for (int x = 0; x<mx; x++){
    for (int y = 0; y<my; y++){
      quad(p, x, y);
    }
  }
  for (int x = 0; x<mx + 1; x++){
    for (int y = 0; y<my + 1; y++){
      if (fix[P(x, y, 1)]) {
        line(x, y, x + 0.2, y - 0.4);
        line(x, y, x - 0.2, y - 0.4);
        line(x + 0.2, y - 0.4, x - 0.2, y - 0.4);
      }
      if (fix[P(x, y, 0)]) {
        line(x, y, x - 0.4, y + 0.2);
        line(x, y, x - 0.4, y - 0.2);
        line(x - 0.4, y - 0.2, x - 0.4, y + 0.2);
      }
      if ((f[P(x, y, 0)] != 0) || (f[P(x, y, 1)] != 0)) {
        strzalka(skala*p[P(x, y, 0)] + x, skala*p[P(x, y, 1)] + y, f[P(x, y, 0)], f[P(x, y, 1)], 25, 0.3);
      }
    }
  }
}
