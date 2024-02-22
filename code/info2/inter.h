#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

// funkcja liczy wartosc wielomianu interpolacyjnego Lagrange'a
// tablice x[] i y[] zawieraja wspolrzedne wezlow interpolacji
// n liczba wezlow interpolacji
// xx wartosc dla ktorej liczy sie wielomian
double lagrange( double *x, double *y, int n, double xx );

#endif
