#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

// funkcja liczy wartosc wielomianu interpolacyjnego Lagrange'a
// tablice x[] i y[] zawieraja wspolrzedne wezlow interpolacji
// n liczba wezlow interpolacji
// xx wartosc dla ktorej liczy sie wielomian

// function computing values of Lagrange interpolation polynomial
// arrays x[] i y[] contain coordinates of predefined interpolation nodes
// n is number of interpolation nodes
// xx value of independent variable for which the value of polynomial is computed
double lagrange( double *x, double *y, int n, double xx );

#endif
