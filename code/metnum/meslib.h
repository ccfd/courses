#ifndef _MESLIB_H
#define _MESLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "winbgi2.h"

/* Liczba elementow w poziomie */
extern int MX;
/* Liczba elementow w pionie */
extern int MY;
/* Calkowita liczba stopni swobody, ktora musi byc rowna 2*(MX + 1)*(MY + 1). */
extern int N;

/* Stale materialowe: modul Younga, wspolczynnik Poissona i gestosc materialu. */
extern const double E;
extern const double nu;
extern const double rho;
/* Wspolczynnik stojacy przed macierza sztywnosci a wynikajacy z E i nu */
extern const double Md;
/* Wspolczynnik stojacy przed macierza masowa */
extern const double Mm;

/* Macierz sztywnosci elementu. */
extern const double K[8][8];
/* Macierz masowa elementu. */
extern const double M[8][8];

/* Funkcja zwraca globalny indeks stopnia swobody. */
int P(int id_x, int id_y, int dir);
/* Funkcja zwraca globalny indeks elementu */
int Q(int id_x, int id_y);
/* Funkcja zwraca globalny indeks stopnia swobody */
int DOF(int elid_x, int elid_y, int locdofid);
/*
Funkcja gauss_psp znajduje rozwiazanie ukladu rownan liniowych A * x = b
metoda eliminacji Gaussa z wykorzystaniem skalowanego wyboru elementu
glownego (eng. partial scaled pivoting).
Funkcja nie modyfikuje tablic A_ext i b_ext.
*/
void gauss_psp(int tabsize, double **A_ext, double *b_ext, double *x);
/* Funkcja znajdujaca rozwiazanie ukladu podstawowa metoda eliminacji Gaussa */
void gauss(int n, double **M, double *f, double *x);
/* Funkcja rysuje uklad elementow skonczonych. */
void draw(double *p, double *f, int *fix);

#endif
