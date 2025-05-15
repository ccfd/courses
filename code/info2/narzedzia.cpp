#include <math.h>
#include "narzedzia.h"

//==================== DEFINICJE FUNCKCJI =======================

// funkcja liczy wartosc wielomianu interpolacyjnego Lagrange'a
// tablice *x i *y zawieraja wspolrzedne wezlow interpolacji
// n liczba wezlow interpolacji
// xx wartosc dla ktorej liczy sie wielomian
double lagrange( double *x, double *y, int n, double xx )
{
	int		i, j;
	double	yint, ylag;

	yint = 0.0;
	for ( i=0; i<n; i++ )
	{
		ylag = 1.0;
		for ( j=0; j<n; j++ )
		{
			if ( i == j)
				continue;

			ylag *= (xx - x[j]) / (x[i] - x[j]);
		}

		yint += y[i]*ylag;
	}

	return yint;
}

// funkcja oblicza calkę z przekazanej funkcji "fun" w granicach
// [a,b] na "n" punktach metoda trapezow
double trapez(double a, double b, double(*fun)(double), int n)
{
    int i;
    double h=(b-a)/(n-1), calka=0, x1, x2;
    for(i=0; i<n-1; ++i)
    {
        x1 = a + i*h;
        x2 = a + (i+1)*h;
        calka += ( fun(x1) + fun(x2) )/2 * h;
    }
    return calka;
}

// funkcja oblicza calkę z przekazanej funkcji "fun" w granicach
// [a,b] na "n" punktach metoda simpsona
double simpson(double a, double b, double(*fun)(double), int n)
{
    int i;
    double h=(b-a)/(n-1), calka=0, x1, x2, x3;
    if(n%2==0)
    {
        n = n+1;
        if(n<3)
            n = 3;
    }

    for(i=0; i<n-2; i+=2)
    {
        x1 = a + i*h;
        x2 = a + (i+1)*h;
        x3 = a + (i+2)*h;
        calka += ( fun(x1) + 4*fun(x2) + fun(x3) )/3 * h;
    }
    return calka;
}

//  rozwiazuje rownanie   pf(x)=0 metoda bisekcji
//  a,b to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  UWAGA: musi byc spelniony warunek:
//  pf(a)*pf(b) <= 0 (jesli nie jest spelniony zwracana jest wartosc 0, liczba iteracji wynosi -1)
//  jesli warunek jest spelniony
//    wartosc zwracana = liczba iteracji uzytych dla znalezienia pierwiastka
//    x  = poszukiwany pierwiastek okreslony z dokladnoscia "eps"
double bisec( double xa, double xb, double (*pf)(double), double eps, int *i_iter )
{
    int	i;
    double fa, fb, xc, fc;

    fa = pf(xa);
    fb = pf(xb);

    if ( fa * fb > 0.0)
    {
        *i_iter = -1;
        return 0;
    }

    for ( i = 1; i <= 1000; i++ )
    {
        xc = ( xa + xb ) / 2.;
        fc = pf( xc );

        if( fa * fc < 0. )
        {
            xb = xc;
            fb = fc;
        }
        else
        {
            xa = xc;
            fa = fc;
        }

        if ( fabs(fc) < eps && fabs(xb-xa) < eps)
            break;
    }

    *i_iter = i;
    return xc;
}

//  rozwiazuje rownanie fun(x)=0 metoda siecznych
//  x0,x1 to granice przedzialu, w ktorym poszukuje sie pierwiastka
//  fun - funkcja okreslajaca rownanie
//  eps - dokladnosc rozwiazania
//  n_iter- wskaznik na zmienna typu int do ktorej zostanie przypisana liczba wykonanaych iteracji
double sieczna(double x0, double x1, double(*fun)(double), double eps, int *n_iter)
{
    double tmp;
    *n_iter = 0;
    while( fabs( fun(x1) ) > eps && fabs(x1-x0) > eps )
    {
        tmp = x1 - fun(x1)*(x1-x0)/(fun(x1)-fun(x0));
        x0 = x1;
        x1 = tmp;
        (*n_iter)++;
    }
    return x1;
}

//  rozwiazuje rownanie fun(x)=0 metoda stycznych
//  x0 - punkt startowy od ktorego zostanie rozpoczete poszukiwanie pierwiastka
//  fun - funkcja okreslajaca rownanie
//  poch - pochodna funkcji okreslajacej rownania
//  eps - dokladnosc rozwiazania
//  n_iter- wskaznik na zmienna typu int do ktorej zostanie przypisana liczba wykonanaych iteracji
double styczna(double x0, double(*fun)(double), double(*poch)(double), double eps, int *n_iter)
{
    double deltaX=1;
    *n_iter = 0;
    while(fabs(fun(x0)) > eps && fabs(deltaX) > eps)
    {
        deltaX = - fun(x0)/poch(x0);
        x0 = x0 + deltaX;
        (*n_iter)++;
        if(*n_iter > 1e3)
        {
            *n_iter=-1;
            return x0;
        }
    }
    return x0;
}

// wykonuje 1 krok calkowania metoda Eulera - zwarca nowa wartosc rozwiazania y=y(t+dt)
// t - wspolrzedna poprzedniego kroku rozwiazania(lub wspolrzedna poczatkowa gdy to jest pierwsza iteracja)
// y0 - wartosc rozwiazania z poprzedniego kroku(lub rozwiazanie poczatkowe gdy to jest pierwsza iteracja)
// rhsEq - funkcja obliczajaca prawa strone rownania rozniczkowego y' = f(t,y)
// dt - krok calkowania
double euler(double t, double y, double(*rhsEq)(double,double),double dt)
{
    return y + dt * rhsEq(t,y);
}

// wykonuje 1 krok calkowania metoda Rungego-Kutty 4 rzedu - zwarca nowa wartosc rozwiazania y=y(t+dt)
// t - wspolrzedna poprzedniego kroku rozwiazania(lub wspolrzedna poczatkowa gdy to jest pierwsza iteracja)
// y0 - wartosc rozwiazania z poprzedniego kroku(lub rozwiazanie poczatkowe gdy to jest pierwsza iteracja)
// rhsEq - funkcja obliczajaca prawa strone rownania rozniczkowego y' = f(t,y)
// dt - krok calkowania
double rk4(double t, double y, double(*rhsEq)(double,double),double dt)
{
    double k1,k2,k3,k4;

    k1 = dt * rhsEq(t        , y        );
    k2 = dt * rhsEq(t + dt/2., y + k1/2.);
    k3 = dt * rhsEq(t + dt/2., y + k2/2.);
    k4 = dt * rhsEq(t + dt   , y + k3   );

    return y + (k1 + 2.*k2 + 2.*k3 + k4)/6.;
}

