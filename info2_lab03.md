---
number: 3
course: Informatyka 2
material: Instrukcja 3
author: B. Górecki, rev. W. Gryglas
---

# Iteracyjne metody rozwiązywania równań nieliniowych

## 1. Wstęp
Celem ćwiczenia jest zapoznanie z różnymi metodami numerycznymi służącymi do znajdowania miejsc zerowych równań algebraicznych. W praktyce najczęściej jest niemożliwe znalezienie dokładnej wartości pierwiastka równania, więc tak naprawdę będziemy szukać coraz dokładniejszych przybliżeń tego pierwiastka. W tym celu posłużymy się metodą bisekcji, siecznych oraz stycznych. Wszystkie metody wymagają, aby funkcja, której miejsc zerowych szukamy,
była ciągła.

## 2. Metoda bisekcji

W przypadu metody bisekcji korzystamy z faktu, że jeśli na końcach pewnego przedziału liczbowego wartosci funkcji są przeciwnych znaków, gdzieś na tym odcinku funkcja ma miejsce zerowe (ta trywialna obserwacja to tzw. twierdzenie Darboux, sformułowane przez francuskiego matematyka Jeana Gastona Darboux (1842-1917)). Za pomocą tej metody rozwiążemy równanie:
$$cos(x) = x$$
Posłużymy się przygotowaną wcześniej funkcją `bisec`. W tym celu należy załączyć do projektu pliki *nonlin.h* oraz *nonlin.cpp*. Funkcja `bisec` ma nagłówek następującej postaci:
```c++
double bisec(double a, double b, double (*pf)(double), double eps, int *iter)
```
Funkcja zwraca przybliżenie miejsca zerowego równania. Wymagane są następujące argumenty:
- `a` i `b` - krańce przedziału, w którym szukamy rozwiązania
- `(*pf)` - wzkaźnik do funkcji zawierającej rozwiązywane równanie
- `eps` - dokładność rozwiązania $\varepsilon$
- `iter` - wskaźnik do zmiennej, pod którą zostanie zapisana ilość iteracji. Jeśli na obu końcach przedziału $[a, b]$ funkcja przyjmuje wartości tego samego znaku to pod wskaźnik `iter` zostaje przypisana wartość `−1` a funkcja zwraca wartość `0`.

### Ćwiczenia
1. Napisz funkcję `double eqn(double x)`, która będzie zwracac wartość naszego równania sprowadzonego do postaci $f (x) = 0$.
2. Wczytać z klawiatury dokładność rozwiązania `eps` oraz krańce przedziału przeszukiwań `a` i `b`. Należy pamętać o tym, że $f (a) \cdot f (b) < 0$.
3. Wypisz na ekranie miejsce zerowe oraz liczbę iteracji.
4. Przerób program tak, aby rozwiązywał równanie w pętli, dla zmieniającej się dokładności $\varepsilon = 2^{−20} , 2^{−19}, ..., 2^{−3}$.
5. Zrób wykres przedstawiający zależność liczby iteracji od dokładności (dokładność przedstaw na osi logarytmicznej).

## 3. Metoda siecznych i stycznych
Innymi metodami poszukiwania rozwiązań równań nieliniowych są metody stycznych oraz siecznych. W przypadku metody siecznych kolejne przybliżenie miejsca zerowego wyznacza się jako miejsca przecięcia odpowiedniej siecznej wykresu funkcji z osią odciętych. Dana sieczna przechodzi przez punkty z wykresu funkcji, których rzędne były poprzednimi przybliżeniami miejsca zerowego. Schemat iteracyjny ma następującą postać:
$$ x_{i+1} = x_i - f(x_i) \frac{x_i-x_{i-1}}{f(x_i)-f(x_{i-1})} $$
W przypadku metody stycznych (zwanej też metodą Newtona) kolejne przybliżenia miejsca zerowego są przeciąciami stycznych do wykresu funkcji z osią odciętych. Policzenie kolejnych przybliżeń wymaga znajomości pochodnej funkcji. Schemat iteracyjny przybiera następującą postać:
$$ x_{i+1} = x_i - \frac{f(x_i)}{f'(x)} $$

### Ćwiczenia
1. Rozwiąż to samo równanie, co poprzednio, używajac obu powyższych metod. Wypisz na ekran dokładność, liczbę itaracji metody siecznych, stycznych oraz bisekcji.
2. Stwórz wykres przedstawiajacy zależność liczby iteracji od dokładnosci rozwiązania (dokładność przedstaw na skali logarytmicznej).
3. Rozwiąż trzema metodami równanie z parametrem $cos(x) = w \cdot x$. Dokładność $\varepsilon = 10^−6$ , Parametr $w$ przebiega w zakresie $w = 0.5, 0.6, ..., 15.0$.

## 4. Zadanie dodatkowe
Metody rozwiązywania równań nieliniowych mogą być również użyte do znajdowania ekstremów funkcji. Spróbuj znaleźć ekstremum funkcji:
$$ f (x) = (1 + x) \cdot arctan(x) $$
