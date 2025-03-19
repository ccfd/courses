#include "meslib.h"

static const double mlib_scale = 1.;

const double E = 100.;
const double nu = 0.3;
const double rho = 1.;
const double Md = E / (1 - nu*nu);
const double Mm = rho;

static const double elems[9] = {
  0., 1. / 2. - nu / 6., 1. / 8. + nu / 8., -1. / 4. - nu / 12., -1. / 8. + 3.*nu / 8.,
  -1. / 4. + nu / 12., -1. / 8. - nu / 8., nu / 6., 1. / 8. - 3.*nu / 8.
};

/* Macierz sztywnosci elementu */
const double K[8][8] = {
  { elems[1], elems[2], elems[3], elems[4], elems[5], elems[6], elems[7], elems[8] },
  { elems[2], elems[1], elems[8], elems[7], elems[6], elems[5], elems[4], elems[3] },
  { elems[3], elems[8], elems[1], elems[6], elems[7], elems[4], elems[5], elems[2] },
  { elems[4], elems[7], elems[6], elems[1], elems[8], elems[3], elems[2], elems[5] },
  { elems[5], elems[6], elems[7], elems[8], elems[1], elems[2], elems[3], elems[4] },
  { elems[6], elems[5], elems[4], elems[3], elems[2], elems[1], elems[8], elems[7] },
  { elems[7], elems[4], elems[5], elems[2], elems[3], elems[8], elems[1], elems[6] },
  { elems[8], elems[3], elems[2], elems[5], elems[4], elems[7], elems[6], elems[1] }
};

/* Macierz masowa elementu */
const const double M[8][8] = {
  { 4, 0, 2, 0, 1, 0, 2, 0 },
  { 0, 4, 0, 2, 0, 1, 0, 2 },
  { 2, 0, 4, 0, 2, 0, 1, 0 },
  { 0, 2, 0, 4, 0, 2, 0, 1 },
  { 1, 0, 2, 0, 4, 0, 2, 0 },
  { 0, 1, 0, 2, 0, 4, 0, 2 },
  { 2, 0, 1, 0, 2, 0, 4, 0 },
  { 0, 2, 0, 1, 0, 2, 0, 4 }
};

/* Funkcje */
int P(int id_x, int id_y, int dir) {
  return ((id_y * (MX + 1) + id_x) * 2 + dir);
}

int Q(int id_x, int id_y) {
  return (id_y * MX + id_x);
}

int DOF(int elid_x, int elid_y, int locdofid) {
  if (locdofid < 4) {
  return (2 * (elid_y * (MX + 1) + elid_x) + locdofid);
  } else if (locdofid == 4 || locdofid == 5) {
  return (2 * ((elid_y + 1) * (MX + 1) + elid_x - 1) + locdofid);
  } else if (locdofid == 6 || locdofid == 7) {
  return (2 * ((elid_y + 1) * (MX + 1) + elid_x - 3) + locdofid);
  } else {
  return (-1);
  }
}

static void quad(double *p, int x, int y) {
  double px[4], py[4];
  px[0] = mlib_scale * p[P(x, y, 0)] + x;
  py[0] = mlib_scale * p[P(x, y, 1)] + y;
  px[1] = mlib_scale * p[P(x + 1, y, 0)] + x + 1;
  py[1] = mlib_scale * p[P(x + 1, y, 1)] + y;
  px[2] = mlib_scale * p[P(x + 1, y + 1, 0)] + x + 1;
  py[2] = mlib_scale * p[P(x + 1, y + 1, 1)] + y + 1;
  px[3] = mlib_scale * p[P(x, y + 1, 0)] + x;
  py[3] = mlib_scale * p[P(x, y + 1, 1)] + y + 1;

  setcolor(0.15);
  polygon(px, py, 4);

  setgray(1);
  line(px[0], py[0], px[1], py[1]);
  line(px[1], py[1], px[2], py[2]);
  line(px[2], py[2], px[3], py[3]);
  line(px[3], py[3], px[0], py[0]);
}

static void arrow(double px, double py, double vx, double vy, double sk, double k) {
  vx *= sk;
  vy *= sk;

  setcolor(1);
  line(px, py, px + vx, py + vy);
  px += vx;
  py += vy;
  double d = sqrt(vx * vx + vy * vy);
  vx *= k;
  vy *= k;
  line(px, py, px - vx - vy / 2, py - vy + vx / 2);
  line(px, py, px - vx + vy / 2, py - vy - vx / 2);
}

void draw(double *p, double *f, int *fix) {

  for (int x = 0; x < MX; x++)
  for (int y = 0; y < MY; y++)
    quad(p, x, y);

  for (int x = 0; x < MX + 1; x++) {
  for (int y = 0; y < MY + 1; y++) {
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
    arrow(mlib_scale * p[P(x, y, 0)] + x, mlib_scale * p[P(x, y, 1)] + y, f[P(x, y, 0)], f[P(x, y, 1)], 25, 0.3);
    }
  }
  }
}

void gauss_psp(int tabsize, double **A_ext, double *b_ext, double *x) {
  double sum, coeff;
  double amax;
  int cache;
  int lmax;
  int *p;
  double *s, *b, **A, *A_row;

  if ((A = (double **) malloc(tabsize * sizeof(double *))) == NULL) {
    perror("gauss_psp (array A)");
    exit(1);
  }

  if ((A_row = (double *) malloc(tabsize * tabsize * sizeof(double))) == NULL) {
    perror("gauss_psp (array A_row)");
    free(A);
    exit(1);
  }

  for (int i = 0; i < tabsize; i++)
    A[i] = &A_row[i * tabsize];

  if ((b = (double*)malloc(tabsize * sizeof(double))) == NULL) {
    perror("gauss_psp (array b)");
    free(A);
    free(A_row);
    exit(1);
  }

  if ((p = (int*)malloc(tabsize * sizeof(int))) == NULL) {
    perror("gauss_psp (array p)");
    free(A);
    free(A_row);
    free(b);
    exit(1);
  }

  if ((s = (double*)malloc(tabsize * sizeof(double))) == NULL) {
    perror("gauss_psp (array s)");
    free(A);
    free(A_row);
    free(b);
    free(p);
    exit(1);
  }

  for (int i = 0; i < tabsize; i++) {
    for (int j = 0; j < tabsize; j++)
      A[i][j] = A_ext[i][j];
    b[i] = b_ext[i];
  }

  for (int i = 0; i < tabsize; i++)
    p[i] = i;

  for (int i = 0; i < tabsize; i++) {
    amax = fabs(A[i][0]);

    for (int j = 1; j < tabsize; j++)
      if (fabs(A[i][j]) > amax)
        amax = fabs(A[i][j]);

    s[i] = amax;
  }

  for (int i = 0; i < tabsize - 1; i++) {

    amax = fabs(A[p[i]][i]) / s[p[i]];
    lmax = i;

    for (int l = i + 1; l < tabsize; l++)
      if ((fabs(A[p[l]][i]) / s[p[i]]) > amax) {
        amax = fabs(A[p[l]][i]) / s[p[i]];
        lmax = l;
      }

    cache = p[i];
    p[i] = p[lmax];
    p[lmax] = cache;

    for (int k = i + 1; k < tabsize; k++) {
      coeff = A[p[k]][i] / A[p[i]][i];

      for (int j = i; j < tabsize; j++)
        A[p[k]][j] -= A[p[i]][j] * coeff;

      b[p[k]] -= b[p[i]] * coeff;
    }
  }

  x[p[tabsize - 1]] = b[p[tabsize - 1]] / A[p[tabsize - 1]][tabsize - 1];

  for (int i = tabsize - 1; i >= 0; i--) {
    sum = 0.;

    for (int j = i + 1; j < tabsize; j++)
      sum += A[p[i]][j] * x[j];

    x[i] = (b[p[i]] - sum) / A[p[i]][i];
  }

  free(A);
  free(A_row);
  free(b);

  free(p);
  free(s);
}

void gauss(int n, double **M, double *f, double *x) {
  int i, j, k;
  double s;
  double wsp;

  double **a;
  double *b;

  if ((b = (double *) malloc(n * sizeof(double))) == NULL) {
  perror("Gauss fun. (b table)");
  exit(1);
  }

  if ((a = (double **) malloc(n * sizeof(double*))) == NULL) {
  perror("Gauss fun. (a table)");
  exit(1);
  }

  for (int i = 0; i < n; i++)
  if ((a[i] = (double*)malloc(n * sizeof(double))) == NULL) {
    perror("Gauss fun. (a[i] table)");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    a[i][j] = M[i][j];
    }
    b[i] = f[i];
  }

  for (i = 0; i < n - 1; i++) {
    for (k = i + 1; k < n; k++) {
    wsp = a[k][i] / a[i][i];

    for (j = i + 1; j < n; j++)
      a[k][j] -= a[i][j] * wsp;

    b[k] -= b[i] * wsp;
    }
  }

  x[n - 1] = b[n - 1] / a[n - 1][n - 1];

  for (i = n - 1; i >= 0; i--) {
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
