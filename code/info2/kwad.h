#ifndef __KWAD_H__
#define __KWAD_H__


//////////////////////////////////////////////////////////////////
// oblicza metoda trapezow calke funkcji pf w przedziale <a,b> 
// w oparciu o n punktow (n >= 2)

// computes definite integral on the range <a,b> with complex
// trapezoidal rule on (n >= 1) subdomains
// (*pf)(double) is a pointer to a function with one argument
//////////////////////////////////////////////////////////////////
double trapez( double a, double b, double (*pf)(double), int n);


//////////////////////////////////////////////////////////////////
// oblicza metoda simpsona calke funkcji pf w przedziale <a,b> 
// w oparciu o n punktow (n >= 2)

// computes definite integral on the range <a,b> with complex
// Simpson rule on (n >= 1) subdomains
// (*pf)(double) is a pointer to a function with one argument
//////////////////////////////////////////////////////////////////
double simpson( double a, double b, double (*pf)(double), int n);


#endif // __KWAD_H__
