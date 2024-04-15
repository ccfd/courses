#include <math.h>

// funkcja liczy wartosc wielomianu interpolacyjnego Lagrange'a
// tablice *x i *y zawieraja wspolrzedne wezlow interpolacji
// n liczba wezlow interpolacji
// xx wartosc dla ktorej liczy sie wielomian

// function computing the value of Lagrange interpolation polynomial
// arrays *x and *y contain information about interpolation nodes
// n defines number of interpolation nodes 
// xx value for which the value of polynomial is evaluated
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
