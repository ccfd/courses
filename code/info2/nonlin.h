#ifndef __NONLIN_H__
#define __NONLIN_H__

//  rozwiazuje rownanie   pf(x)=0 metoda bisekcji
//  a,b to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  UWAGA: musi byc spelniony warunek:
//  pf(a)*pf(b) <= 0 (jesli nie jest spelniony zwracana jest wartosc 0, liczba iteracji wynosi -1)
//  jesli warunek jest spelniony
//    wartosc zwracana = liczba iteracji uzytych dla znalezienia pierwiastka
//    x  = poszukiwany pierwiastek okreslony z dokladnoscia "eps"
double bisec( double a, double b, double (*pf)(double), double eps, int *i_iter);

#endif __NONLIN_H__