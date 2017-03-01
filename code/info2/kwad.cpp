#include <math.h>

// oblicza calke metoda trapezow
float trapez( float a, float b, float (*pf)(float), int n )
{
	float h    = (b-a)/(n-1);
	float suma = 0.5 * ( pf(a) + pf(b) );
	float x    = a;

	for( int i = 1; i < n-1; i++ )
	{
		x    += h;
		suma += pf(x);
	}
	return suma * h;
}


// oblicza calke metoda simpsona
float simpson( float a, float b, float (*pf)(float), int n )
{
	float xx;
	float	x    = a;
	int		nc   = abs( (n-1)/2 + 1 ) * 2+1;  // poprawione n tak by bylo nieparzyste i >= n_old
	float	h    = (b-a)/(nc-1);
	float  h2   = h * 2;
	float	suma = pf(a) + 4.*pf(a+h) + pf(b);

	for( int i = 3; i < nc; i += 2 )
	{
		x    += h2;
		suma += 2. * pf(x) + 4. * pf( x + h );
	}
	return suma * h/3.;
}

