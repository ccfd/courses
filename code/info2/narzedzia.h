#ifndef __NARZEDZIA_H__
#define __NARZEDZIA_H__

//==================== NAGLOWKI FUNCKCJI =======================

// funkcja liczy wartosc wielomianu interpolacyjnego Lagrange'a
// tablice x[] i y[] zawieraja wspolrzedne wezlow interpolacji
// n liczba wezlow interpolacji
// xx wartosc dla ktorej liczy sie wielomian
double lagrange( double *x, double *y, int n, double xx );

// funkcja oblicza calkę z przekazanej funkcji "fun" w granicach
// [a,b] na "n" punktach metoda trapezow
double trapez(double a, double b, double(*fun)(double), int n);

// funkcja oblicza calkę z przekazanej funkcji "fun" w granicach
// [a,b] na "n" punktach metoda simpsona
double simpson(double a, double b, double(*fun)(double), int n);

//  rozwiazuje rownanie   pf(x)=0 metoda bisekcji
//  a,b to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  UWAGA: musi byc spelniony warunek:
//  pf(a)*pf(b) <= 0 (jesli nie jest spelniony zwracana jest wartosc 0, liczba iteracji wynosi -1)
//  jesli warunek jest spelniony
//    wartosc zwracana = liczba iteracji uzytych dla znalezienia pierwiastka
//    x  = poszukiwany pierwiastek okreslony z dokladnoscia "eps"
double bisec( double a, double b, double (*pf)(double), double eps, int *i_iter);

//  rozwiazuje rownanie fun(x)=0 metoda siecznych
//  x0,x1 to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  fun - funkcja okreslajaca rownanie
//  eps - dokladnosc rozwiazania
//  n_iter- wskaznik na zmienna typu int do ktorej zostanie przypisana liczba wykonanaych iteracji
double sieczna(double x0, double x1, double(*fun)(double), double eps, int *n_iter);

//  rozwiazuje rownanie fun(x)=0 metoda stycznych
//  x0 - punkt startowy od ktorego zostanie rozpoczete poszukiwanie pierwiastka
//  fun - funkcja okreslajaca rownanie
//  poch - pochodna funkcji okreslajacej rownania
//  eps - dokladnosc rozwiazania
//  n_iter- wskaznik na zmienna typu int do ktorej zostanie przypisana liczba wykonanaych iteracji
double styczna(double x0, double(*fun)(double), double(*poch)(double), double eps, int *n_iter);

// wykonuje 1 krok calkowania metoda Eulera - zwarca nowa wartosc rozwiazania y=y(t+dt)
// t - wspolrzedna poprzedniego kroku rozwiazania(lub wspolrzedna poczatkowa gdy to jest pierwsza iteracja)
// y0 - wartosc rozwiazania z poprzedniego kroku(lub rozwiazanie poczatkowe gdy to jest pierwsza iteracja)
// rhsEq - funkcja obliczajaca prawa strone rownania rozniczkowego y' = f(t,y)
// dt - krok calkowania
double euler(double t, double y, double(*rhsEq)(double,double),double dt);

// wykonuje 1 krok calkowania metoda Rungego-Kutty 4 rzedu - zwarca nowa wartosc rozwiazania y=y(t+dt)
// t - wspolrzedna poprzedniego kroku rozwiazania(lub wspolrzedna poczatkowa gdy to jest pierwsza iteracja)
// y0 - wartosc rozwiazania z poprzedniego kroku(lub rozwiazanie poczatkowe gdy to jest pierwsza iteracja)
// rhsEq - funkcja obliczajaca prawa strone rownania rozniczkowego y' = f(t,y)
// dt - krok calkowania
double rk4(double t, double y, double(*rhsEq)(double,double),double dt);

#endif //__NARZEDZIA_H__
