#include <math.h>

#define MAXN 10 // maksymalna liczba równañ

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

double rk4( double x0, double y0, double h, double (*fun)(double, double))
{
	double y1;
	double k1,k2,k3,k4;
	k1 = h*fun(x0     ,y0      );
	k2 = h*fun(x0+h/2.,y0+k1/2.);
	k3 = h*fun(x0+h/2.,y0+k2/2.);
	k4 = h*fun(x0+h   ,y0+k3   );
	y1 = y0 + (k1+2.*k2+2.*k3+k4)/6.;
	return y1;
}

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

void vrk4( double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[] )
{
	int		i;
	double	k1[MAXN], k2[MAXN], k3[MAXN], k4[MAXN];
	double	ytmp[MAXN];

	fun( x0, y0, k1);
	for ( i=0; i<n; ++i)
	{
		k1[i] *= h;
		ytmp[i] = y0[i] + k1[i]/2.0;
	}

	fun( x0+h/2.0, ytmp, k2);
	for ( i=0; i<n; ++i)
	{
		k2[i] *= h;
		ytmp[i] = y0[i] + k2[i]/2.0;
	}

	fun( x0+h/2.0, ytmp, k3);
	for ( i=0; i<n; ++i)
	{
		k3[i] *= h;
		ytmp[i] = y0[i] + k3[i];
	}

	fun( x0+h, ytmp, k4);
	for ( i=0; i<n; ++i)
		k4[i] *= h;

	for ( i=0; i<n; ++i)
		y1[i] = y0[i] + (k1[i] + 2.*k2[i] + 2.*k3[i] + k4[i])/6.;

}


