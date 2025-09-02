---
number: 2
course: Informatyka 2
material: Instrukcja 2
author: B. Górecki, rev. W. Gryglas
---

# Całkowanie numeryczne
Pliki do wykorzystania w poniższym ćwiczeniu można pobrać za pomocą poniższych linków:

 - [Plik nagłówkowy kwad.h](http://ccfd.github.io/courses/code/info2/kwad.h)
 - [Plik źródłowy kwad.cpp](http://ccfd.github.io/courses/code/info2/kwad.cpp)

## 1. Wstęp
Całkowanie numeryczne jest jednym z podstawowych algorytmów używanych w obliczeniach inżynierskich.
Całkowanie numeryczne zawsze dotyczy obliczania całki oznaczonej (jedno bądź wielowymiarowej).
Nigdy natomiast nie dotyczy obliczania całki nieoznaczonej.
Wynikiem jego działania jest wartość całki, a w żadnym razie wzór funkcji pierwotnej.

## 2. Algorytmy całkujące
Wśród podstawowych algorytmów, jakimi będziemy się zajmować są:

 - metoda trapezów,
 - metoda Simpsona oraz
 - kwadratury Gaussa-Legendre'a.

### Ćwiczenia
1. Napisz program, który metodą trapezów obliczy całkę oznaczoną:
$$
I = \int_a^bf(x) dx.
$$
Algorytm całkowania metodą trapezów jest zaimplementowany.
Znajdziesz go w funkcji `trapez` w pliku *kwad.cpp*.
Nagłówek funkcji `trapez` ma następującą postać:
```c++
double trapez(double a, double b, double (*fun)(double x), int n)
```
Argumenty `a`, `b` i `n` to odpowiednio dolna i górna granica całkowania oraz liczba punktów, które dzielą przedział całkowania.
Trzeci argument to wskaźnik do funkcji.
Dzięki niemu procedura `trapez` jest w stanie obliczyć całkę z dowolnej funkcji.
Nazwa funkcji, która jest jednocześnie jej adresem, informuje gdzie można znaleźć instrukcje obliczające wartości funkcji podcałkowej.
Poprawne wywołanie to np. `trapez(a, b, sin, n);` lub `trapez(1, 5, sqrt, 100);`.
Możesz też użyć tej procedury do obliczenia całki z funkcji, którą wcześniej zadeklarowałeś i zdefiniowałeś, np. `trapez(a, b, MojaFunkcja, 50);`, gdzie definicja funkcji `MojaFunkcja` ma postać:
```c++
double MojaFunkcja(double x) {
  return x * x + sin(x);
}
```
Zwróć uwagę, że funkcja **musi** mieć jeden argument typu `double` i **musi** zwracać wartość typu `double`.  
Aby zrealizować zadanie z punktu 1, wykonaj następujące czynności:

 - Napisz funkcję, która oblicza wartości $f(x)$ oraz funkcję, która oblicza całkę w sposób analityczny (całkę oblicz na papierze).
 Umieść ich prototypy przed funkcją główną oraz załącz plik nagłówkowy *kwad.h* z funkcjami całkującymi.
 - Za pomocą klawiatury podaj wartości `a`, `b` oraz `n`.
 - Oblicz wartość całki numerycznej `cn` oraz wartość całki analitycznej `ca` przez wywołanie odpowiednich funkcji.
 - Oblicz błąd $|cn - ca|$.
 - Zapisz do pliku krok całkowania oraz wartość całki obliczonej analitycznie oraz numerycznie.

2. Przetestuj ten program dla dwóch funkcji:
$$
f(x) = \frac{1}{x^2}
$$
oraz
$$
f(x) = \frac{1}{x}
$$
dla $a = 1$, $b = 5$ oraz $a = 0.1$ i $b = 5$.

3. Rozszerz program tak, aby zapisywał do pliku kolejne wiersze odpowiadające wartościom $n = 2, 4, 8, \ldots, 2^m$.
Liczbę `m` wczytaj z klawiatury.

4. Wynik przedstaw graficznie, korzystając z arkusza kalkulacyjnego.

5. Rozszerz program tak, aby dodatkowo używał metody Simpsona.
Jest ona zaimplementowana w funkcji o nagłówku `double simpson(double a, double b, double(*fun)(double x), int n)`.

6. Otrzymane wyniki przedstaw graficznie.

### Wskazówki odnośnie wskaźników do funkcji
Przeanalizuj poniższy kod ilustrujący użycie wskaźników do funkcji.
Jakie wartości przyjmują zmienne `y1` i `y2`?
```c++
// funkcja: y = 2 * x
double fun1(double x) {
  return 2 * x;
}

// funkcja: y = -x
double fun2(double x) {
  return -x;
}

// funkcja zwaraca y^2
double kwadrat(double xx, double (*pf)(double)) {
  return pf(xx) * pf(xx);
}

void main() {
  double y1 = kwadrat(2., fun1);
  double y2 = kwadrat(2., fun2);
}
```

## 3. Dla dociekliwych
Metody trapezów i Simpsona to dość elementarne procedury.
W programach obliczeniowych, które wymagają wykonywania wielokrotnych całkowań (często wiele milionów razy - o takich metodach, np. metodzie elementów skończonych stosowanej chociażby w wytrzymałości konstrukcji - będziesz się uczyć na wyższych latach) trzeba używać procedur bardziej wydajnych obliczeniowo.
Jedną klasę takich metod, które osiągają dużą dokładność przy niewielkiej liczbie punktów, w których obliczana jest funkcja podcałkowa (o tych punktach mówimy węzły kwadratury) stanowią kwadratury Gaussa.

Kwadratura Gaussa-Legendre'a jest w zdefiniowana dla następującej całki oznaczonej (zawsze w przedziale $x = [-1, 1]$).
$$
I = \int_{-1}^{1}{f(x)dx}
$$
Taką całkę w sposób przybliżony oblicza się zgodnie z następującym wzorem:
$$
\int_{-1}^{1}{f(x)dx} \approx \sum_{i=1}^{n}{w_if(x_i)}
$$
Wielkości $w_i$ to kolejne wagi kwadratury, $x_i$ to węzły kwadratury, a $n$ oznacza liczbę węzłów, w których będzie obliczana wartość funkcji podcałkowej.  
Aby obliczyć całkę tą kwadraturą, trzeba znać położenia węzłów i wartości wag.
Wielkości te można obliczyć lub skorzystać z tablic zawierających obliczone wartości $w_i$ i $n_i$ dla różnych wartości $n$ (przykładowo, można je znaleźć w Internecie[^1]).
Położenia węzłów i wartości wag dla $n = 5$ są podane w poniższej tabeli:

|             $x_i$            |            $w_i$            |
|:----------------------------:|:---------------------------:|
| -0.9061798459386639927976269 | 0.2369268850561890875142640 |
| -0.5384693101056830910363144 | 0.4786286704993664680412915 |
|              0.0             | 0.5688888888888888888888889 |
|  0.5384693101056830910363144 | 0.4786286704993664680412915 |
|  0.9061798459386639927976269 | 0.2369268850561890875142640 |

### Ćwiczenie

 - Zaimplementuj w dowolny sposób metodę całkowania za pomocą kwadratury Gaussa.
Zwróć uwagę, że kwadratura ta jest zdefiniowana dla całki w przedziale $[-1, 1]$.
Musisz najpierw przekształcić wzór tak aby można było obliczyć całkę w przedziale $[a, b]$ (skorzystaj z zamiany zmiennych).
 - Porównaj otrzymaną wartość z poprzednimi metodami.
Ilu podziałów w metodzie trapezów lub Simpsona musisz użyć, aby osiągnąć dokładność całkowania osiąganą przez kwadraturę Gaussa opartą na pięciu węzłach?

[^1]:Wystarczy do przeglądarki wpisać hasło ,,Legendre Gauss nodes and weights''. Można je także znaleźć choćby pod [adresem](http://holoborodko.com/pavel/numerical-methods/numerical-
integration/)
