#ifndef __RK4_H__
#define __RK4_H__

// --------------------------------------------------------------------------
// Funkcja wykonuje, metod¹ Rungego-Kutty Iv-ego rzêdu,
// jeden krok ca³kowania skalarnego równania ro¿niczkowego zwyczajnego:
//
//  dy/dx = fun(x,y),    y(x0)=y0
//
// Parametry formalne:
// x0 - wartoœæ startowa zm. niezale¿nej
// y0 - wartoœæ startowa zm. zale¿nej
// h  - krok ca³kowania
// fun(x,y) - nazwa funkcji obliczaj¹cej prawe strony
// y1 - obliczona wartoœæ zmiennej zale¿nej w punkcie x0+h

double rk4( double x0, double y0, double h, double (*fun)(double, double));


// --------------------------------------------------------------------------
// Funkcja wykonuje, metod¹ Rungego-Kutty IV-tego rzedu,
// jeden krok ca³kowania wektorowego równania ro¿niczkowego zwyczjanego:
//
//  dY/dx = Fun(x,Y),    Y(x0)=Y0
//
// Parametry formalne:
// x0 - wartoœæ startowa zm. niezale¿nej
// y0 - wartoœæ startowa zm. zale¿nej (tablica n-elementowa)
// h  - krok ca³kowania
// n  - liczba równañ
// fun(x,y,prawastr) - nazwa funkcji obliczaj¹cej prawe strony
// y1 - obliczona wartoœæ zmiennej zale¿nej w punkcie x0+h
//      (tablica n-elementowa)

void vrk4( double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[] );

#endif