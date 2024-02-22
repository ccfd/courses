#include <math.h>

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