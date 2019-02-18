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
Większość procesów fizycznych w otaczającym nas świecie można zamodelować, korzystając właśnie z równań różniczkowych.
Niestety większości z wyprowadzonych przez nas równań nie da się rozwiązać w sposób analityczny (tj. podać rozwiązania w postaci jawnej).
W szczególności, największe problemy sprawiają równania zawierające człony nieliniowe.
Świat, w którym żyjemy, jest silnie nieliniowy (inaczej życie byłoby nudne), dlatego większość problemów, które przyjdzie nam rozwiązywać, nie będzie posiadać rozwiązania...
A przynajmniej rozwiązania w formie analitycznej.
Stąd płynie nasza motywacja do zagłębienia się w świat całkowania numerycznego równań różniczkowych, który pozwoli nam lepiej zrozumieć otaczającą nas rzeczywistość!
Jako pierwszą poznamy metodę pierwszego rzędu zwaną (od nazwiska odkrywcy) jawną metodą Eulera.
Jest ona jednocześnie najprostszą i (niestety) bardzo niestabilną metodą.
Drugą metodą, którą zastosujemy na dzisiejszych zajęciach, będzie metoda Rungego-Kutty 4-go rzędu.
Jest to jawna metoda wielokrokowa, która charakteryzuje się wysokim rzędem, łatwością w implementacji oraz relatywnie wysoką stabilnością.

## 2. Metoda Eulera
Metodę Eulera wykorzystamy do rozwiązania zagadnienia początkowego w postaci:
$$ \frac{dy}{dt} = f(t,y) $$
$$ y(t_0) = y_0 $$
Stosując następujący schemat iteracyjny:
$$ t_{i+1} = t_{i} + h $$
$$ y_{i+1} = y_i + h \cdot f(t_i , y_i ) $$
Gdzie: $h$ -- krok całkowania, $y_{i+1}$ -- rozwiązanie, $y_i$ -- rozwiązanie w kroku poprzednim, $f$ - funkcja obliczająca prawą stronę równania różniczkowego.

## 3. Ćwiczenia
Dane jest zagadnienie początkowe:
$$
\left\{
\begin{array}{ccc}
\frac{dy}{dt} &=& \lambda \cdot y(t) \\
y(t_0) &=& y_0 \\
\end{array}
\right.
$$
Rozwiązanie dokładne ma postać:
$$ y(t) = y_0 · e^{\lambda(t-t_0)} $$

1. Napisz program rozwiązujący dane zagadnienie, z wykorzystaniem schematu Eulera.
2. Napisz program rozwiązujący dane zagadnienie, z wykorzystaniem schematu RK4
3. Dla obu przypadków wyświetl na monitorze kolejne wartości $t$, $y$ oraz względną wartość błędu: $\varepsilon = \frac{|y-y_\text{analityczne}|}{|y_\text{analityczne}|}$.
4. Zmodyfikuj program tak aby wykonywał obliczenia jedną i druga metodą dla zadanego $t_k$ i liczby kroków: $2^0$, $2^1$, \ldots, $2^6$.
Wydrukuj do pliku: liczbę kroków, $h$, błąd metody Eulera i błąd metody RK4 dla ostatniego kroku czasowego.
5. Sporządź wykres błędu metody w funkcji $h$ i oszacuj rząd zbieżności.
