#ifndef __RK4_H__
#define __RK4_H__

// --------------------------------------------------------------------------
// Funkcja wykonuje, metoda Rungego-Kutty IV-ego rzedu,
// jeden krok calkowania skalarnego rownania rozniczkowego zwyczajnego:
//
//  dy/dx = fun(x,y),    y(x0)=y0
//
// Parametry formalne:
// x0 - wartosc startowa zm. niezaleznej
// y0 - wartosc startowa zm. zaleznej
// h  - krok calkowania
// fun(x,y) - nazwa funkcji obliczajacej prawe strony
// y1 - obliczona wartosc zmiennej zaleznej w punkcie x0+h

double rk4(double x0, double y0, double h, double (*fun)(double, double));


// --------------------------------------------------------------------------
// Funkcja wykonuje, metoda Rungego-Kutty IV-tego rzedu,
// jeden krok calkowania wektorowego rownania rozniczkowego zwyczjanego:
//
//  dY/dx = Fun(x,Y),    Y(x0)=Y0
//
// Parametry formalne:
// x0 - wartosc startowa zm. niezaleznej
// y0 - wartosc startowa zm. zaleznej (tablica n-elementowa)
// h  - krok calkowania
// n  - liczba rownañ
// fun(x,y,prawastr) - nazwa funkcji obliczajacej prawe strony
// y1 - obliczona wartosc zmiennej zaleznej w punkcie x0+h
//      (tablica n-elementowa)

void vrk4(double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[]);

#endif
