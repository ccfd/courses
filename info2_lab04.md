---
number: 4
course: Informatyka 2
material: Instrukcja 4
author: P. Szałtys, rev. W. Gryglas
---

# Całkowanie numeryczne równań różniczkowych zwyczajnych

Pliki do wykorzystania w poniższym ćwiczeniu można pobrać za pomocą poniższych linków:

 - [Plik nagłówkowy rk4.h](http://ccfd.github.io/courses/code/info2/rk4.h)
 - [Plik źródłowy rk4.cpp](http://ccfd.github.io/courses/code/info2/rk4.cpp)

## 1. Wstęp
Celem dzisiejszych zajęć jest zapoznanie się z podstawowymi metodami całkowania numerycznego równań różniczkowych zwyczajnych pierwszego rzędu.
Część procesów fizycznych, które można obserwować w otaczającym nas świecie można modelować korzystając właśnie z równań różniczkowych.
Większości z nich nie da się rozwiązać w sposób analityczny (tj. podać rozwiązania w postaci jawnej).
W szczególności, największe problemy sprawiają równania zawierające człony nieliniowe.
Świat, w którym żyjemy, jest silnie nieliniowy i większość problemów, które przyjdzie nam rozwiązywać, nie będzie posiadać rozwiązania w formie analitycznej.

Jako pierwszą poznamy metodę pierwszego rzędu zwaną (od nazwiska twórcy) jawną metodą **Eulera**.
Jest ona jednocześnie najprostszą i bardzo niestabilną metodą.
Drugą metodą, którą zastosujemy na dzisiejszych zajęciach, będzie metoda **Rungego-Kutty 4-go rzędu**.
Jest to metoda jawna, która charakteryzuje się stosunkowo wysokim rzędem, łatwością implementacji oraz relatywnie wysoką stabilnością.

Obie metody wykorzystamy do rozwiązania zagadnienia początkowego w postaci:
$$
\left\{
\begin{array}{l}
\frac{dy}{dt} = f(t,y) \\
y(t_0) = y_0 \\
\end{array}
\right.
$$

## 2. Metoda Eulera

W celu rozwiązania zastosujmy następujący schemat iteracyjny:
$$
t_{i+1} = t_{i} + h
$$
$$
y_{i+1} = y_i + h \cdot f(t_i , y_i )
$$
Gdzie:

  - $h$ -- krok całkowania,
  - $y_{i+1}$ -- rozwiązanie,
  - $y_i$ -- rozwiązanie w kroku poprzednim,
  - $f$ - funkcja obliczająca prawą stronę równania różniczkowego.

## 3. Metoda Rungego-Kutty 4-ego rzędu

Metoda ta jest już zaimplementowana w pliku $\verb+rk4.cpp+$.
Nagłówek funkcji, która wykonuje jeden krok całkowania równania różniczkowego ma postać:
```c++
double rk4(double x0, double y0, double h, double (*fun)(double, double))
```
gdzie:

  - `x0` -- wartość początkowa zmiennej niezależnej,
  - `y0` -- wartość początkowa zmiennej zależnej,
  - `h` -- krok całkowania,
  - `fun` -- adres funkcji obliczającej prawe strony równania.


## 4. Ćwiczenia
Dane jest zagadnienie początkowe w postaci:
$$
\left\{
\begin{array}{l}
\frac{dy}{dt} = \lambda \cdot y(t) \\
y(t_0) = y_0 \\
\end{array}
\right.
$$
Jego rozwiązanie dokładne to:
$$ 
y(t) = y_0 \cdot \mathrm{e}^{\lambda(t-t_0)}
$$

1. Napisz program, który rozwiąże dane zagadnienie początkowe, z wykorzystaniem schematu Eulera.
Wybierz czas końcowy $t_k$ oraz liczbę kroków $N$.
2. Wykorzystaj zaimplementowany schemat RK4 i ponownie rozwiąż zagadnienie.
3. Dla obu przypadków wyświetl na monitorze kolejne wartości $t$, $y$ oraz względną wartość błędu: $\varepsilon = \frac{|y-y_\mathrm{analityczne}|}{|y_\mathrm{analityczne}|}$.
4. Zmodyfikuj program tak aby wykonywał obliczenia jedną i druga metodą dla zadanego $t_k$ i liczby kroków: $2^0$, $2^1$, $\ldots$, $2^6$.  
Wydrukuj do pliku: liczbę kroków $N$, długość kroku $h$, błąd metody Eulera i błąd metody RK4 dla ostatniego kroku czasowego.
5. Sporządź wykres błędu metody w funkcji $h$ i oszacuj rząd zbieżności.
