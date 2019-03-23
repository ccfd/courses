---
number: 3
course: Informatyka 2
material: Instrukcja 3
author: W. Regulski, rev. W. Gryglas
---

# Iteracyjne metody rozwiązywania równań nieliniowych

Pliki do wykorzystania w poniższym ćwiczeniu można pobrać za pomocą poniższych linków:

 - [Plik nagłówkowy nonlin.h](http://ccfd.github.io/courses/code/info2/nonlin.h)
 - [Plik źródłowy nonlin.cpp](http://ccfd.github.io/courses/code/info2/nonlin.cpp)

## 1. Wstęp

Celem ćwiczenia jest zapoznanie się z różnymi metodami numerycznymi służącymi do znajdowania miejsc zerowych funkcji matematycznych.
W praktyce najczęściej niemożliwe jest znalezienie dokładnej wartości pierwiastka równania, więc tak naprawdę będziemy szukać coraz dokładniejszych przybliżeń tego pierwiastka.
W tym celu posłużymy się metodą **bisekcji**, **siecznych** oraz **stycznych**.
Wszystkie metody wymagają, aby funkcja, której miejsc zerowych szukamy, była ciągła.

## 2. Metoda bisekcji

W przypadku metody bisekcji korzystamy z faktu, że jeśli na końcach pewnego przedziału liczbowego wartości funkcji są przeciwnych znaków, gdzieś na tym odcinku funkcja ma miejsce zerowe (ta trywialna obserwacja to tzw. twierdzenie Darboux, sformułowane przez francuskiego matematyka Jeana Gastona Darboux (1842-1917)).
Za pomocą tej metody rozwiążemy równanie:
$$
\cos(x) = x
$$
Posłużymy się przygotowaną wcześniej funkcją `bisec`.
W tym celu należy załączyć do projektu pliki *nonlin.h* oraz *nonlin.cpp*.
Funkcja `bisec` ma nagłówek następującej postaci:
```c++
double bisec(double a, double b, double (*pf)(double), double eps, int *iter)
```
Funkcja zwraca przybliżenie miejsca zerowego równania.
Wymagane są następujące argumenty:

- `a` i `b` - krańce przedziału, w którym szukamy rozwiązania,
- `double (*pf)(double)` - wskaźnik do funkcji utworzonej na podstawie rozwiązywanego równania,
- `eps` - dokładność rozwiązania $\varepsilon$,
- `iter` - zmienna typu wskaźnikowego, która zawiera adres, pod który zostanie zapisana liczba iteracji.
Jeśli na obu końcach przedziału $[a, b]$ funkcja przyjmuje wartości tego samego znaku to zmienna, której adres zawiera `iter` będzie zawierać wartość `-1` a funkcja zwróci wartość `0`.

### Ćwiczenia

1. Napisz funkcję `double fun(double x)`, która będzie zwracać wartość funkcji $f(x)$ uzyskaną z przekształcenia naszego równania do postaci $f(x) = 0$.
2. Wczytaj z klawiatury dokładność rozwiązania `eps` oraz krańce przedziału przeszukiwań `a` i `b`.
Pamiętaj o tym, że krańce muszą spełniać nierówność $f(a) \cdot f(b) < 0$.
3. Wykorzystaj funkcję `bisec` a następnie wypisz na ekranie znalezione miejsce zerowe oraz liczbę iteracji.
4. Zmodyfikuj program tak, aby rozwiązywał równanie w pętli, dla zmieniającej się dokładności $\varepsilon = 2^{-20} , 2^{-19}, \ldots, 2^{-3}$.
5. Utwórz wykres przedstawiający zależność liczby iteracji od dokładności (dokładność przedstaw na osi logarytmicznej).

## 3. Metoda siecznych i stycznych

Innymi metodami poszukiwania rozwiązań równań nieliniowych są metody stycznych oraz siecznych.
W przypadku metody siecznych kolejne przybliżenie miejsca zerowego wyznacza się jako miejsca przecięcia odpowiedniej siecznej wykresu funkcji z osią odciętych.
Dana sieczna przechodzi przez punkty z wykresu funkcji, których rzędne były poprzednimi przybliżeniami miejsca zerowego.
Schemat iteracyjny ma następującą postać:
$$
x_{i+1} = x_i - f(x_i) \frac{x_i-x_{i-1}}{f(x_i)-f(x_{i-1})}
$$

W przypadku metody stycznych (zwanej też metodą Newtona) kolejne przybliżenia miejsca zerowego są przecięciami stycznych do wykresu funkcji z osią odciętych.
Obliczenie kolejnych przybliżeń wymaga znajomości pochodnej funkcji.
Schemat iteracyjny przybiera następującą postać:
$$
x_{i+1} = x_i - \frac{f(x_i)}{f'(x)}
$$

### Ćwiczenia

1. Napisz procedury wyznaczające miejsce zerowe funkcji $f(x)$ metodą Newtona i metodą siecznych.
Nagłówki funkcji powinny mieć postaci:
```c++
double newton(double x, double (*pf)(double), double eps, int *iter)
```
```c++
double siecz(double x1, double x2, double (*pf)(double), double eps, int *iter)
```
2. Rozwiąż to samo równanie co poprzednio, używając obu powyższych metod.
3. Dla metody siecznych, stycznych oraz bisekcji, wypisz na ekran liczbę iteracji niezbędną do znalezienia miejsca zerowego funkcji przy dokładności $\varepsilon = 2^{-20} , 2^{-19}, \ldots, 2^{-3}$.
3. Stwórz wykres przedstawiający zależność liczby iteracji od dokładności rozwiązania (dokładność przedstaw na skali logarytmicznej).
4. Rozwiąż trzema metodami równanie z parametrem $\cos(x) = w \cdot x$.
Dokładność rozwiązania $\varepsilon = 10^{-6}$ .
Parametr $w$ przybiera wartości $w = 0.5, 0.6, \ldots, 15.0$.

## 4. Zadanie dodatkowe

Metody rozwiązywania równań nieliniowych mogą być również użyte do znajdowania ekstremów funkcji.
Spróbuj znaleźć ekstremum funkcji:
$$
f(x) = (1 + x) \cdot \arctan(x)
$$
