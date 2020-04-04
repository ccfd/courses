---
number: 4
course: Metody Numeryczne
material: Instrukcja 4
author: Ł. Łaniewski-Wołłk
title: Mnożenie przez macierz jako funkcja
---

Można zauważyć, że w metodzie gradientów sprzężonych nie wykorzystujemy elementów macierzy $\mathbf{A}$ jako takich.
Używamy jedynie wektorów będących wynikami mnożenia przez $\mathbf{A}$.
Tymi wektorami są $\mathbf{A} \mathbf{x}^k$, $\mathbf{A} \mathbf{p}^k$ oraz $\mathbf{A} \mathbf{r}^k$.
Nie musimy więc wiedzieć jak wygląda macierz $\mathbf{A}$, wystarczy że dla danego wektora $\mathbf{v}$ wiemy jak wygląda (potrafimy obliczyć) $\mathbf{A}\mathbf{v}$.  
Na tych laboratoriach wykorzystamy tą wiedzę i przyspieszymy działanie programu oraz zmniejszymy zużycie pamięci.

# Przygotowanie

Aby nie pomylić się w kolejnych krokach, należy najpierw dobrze **uporządkować** dotychczasowych kod.
W tym celu zrealizuj poniższe zadania:

### Zadanie 1
Rozdziel wszystkie elementy iteracji metodą gradientów sprzężonych tak aby mnożenie przez macierz $\mathbf{A}$ było realizowane przez oddzielny fragment kodu.
Przykładowo, jeśli residuum było obliczane za pomocą funkcji
```c++
void res(int N, double **A, double *x, double *b, double *r)
```
to za miast niej należy użyć dwóch oddzielnych fragmentów kodu realizujących mnożenie $\mathbf{r} = \mathbf{A} \mathbf{x}$ oraz odejmowanie $\mathbf{r} = \mathbf{b} - \mathbf{r}$.

### Zadanie 2
Wydziel z funkcji `Solve` część odpowiedzialną za mnożenie przez macierz $\mathbf{A}$: `Mult(int N, double **A, double *x, double *r)` i preconditioner diagonalny: `Precond(int N, double **A, double *r, double *p)`.  
Zauważ, że mnożenie przez macierz $\mathbf{A}$ występuje co najmniej dwa razy w iteracji.

Na tym etapie w funkcji `Solve` nigdzie nie powinny występować elementy macierzy $\mathbf{A}$.

### Zadanie 3
Przenieś zmienną `thick` oznaczającą grubość elementów skończonych do zmiennych globalnych

### Zadanie 4
Skopiuj funkcję `Mult` i nadaj jej nazwę `Mult_A`.

# Mnożenie przez $\mathbf{A}$ bez $\mathbf{A}$ 

Chcielibyśmy aby funkcja `Mult_A` wykonywała mnożenie pewnego wektora $\mathbf{v}$ przez globalną macierz sztywności nie używając samej macierzy $\mathbf{A}$.
To znaczy, że chcemy wykonać operację $\mathbf{t} = \mathbf{A} \mathbf{v}$ czyli:
$$
t_i = \sum_{j=1}^N A_{ij} v_j, \; (i=1\ldots N)
$$
Przypomnijmy, że globalną macierz sztywności $\mathbf{A}$ tworzy się przez sumowanie elementów macierzy lokalnych.
Zastanówmy się więc co się dzieje z wynikiem mnożenia $\mathbf{t}$ jeśli do macierzy $\mathbf{A}$ dodamy coś.

Jeśli do elementu $A_{1,2}$ dodamy liczbę $4$, to do $t_1$ musimy dodać $4 v_2$.

Analogicznie jeśli do elementu $A_{ij}$ dodamy liczbę $w$, to tak jak byśmy do elementu $t_i$ dodali liczbę $w \cdot v_j$.

### Zadanie 5
Przekopiuj fragment kodu odpowiedzialny za konstrukcję globalnej macierzy sztywności $A$.
Następnie, każde wystąpienie:
```c++
A[i,j] += cos;
```
zamień na:
```c++
r[i] += cos * x[j];
```

Co z częścią, która uwzględniała odebrane stopnie swobody i zamieniała wybrane wiersze na wiersze macierzy diagonalnej?
Jeśli w macierzy $\mathbf{A}$ $i$-ty wiersz zamienimy na same zera i $1$ na przekątnej, to tak jak byśmy podstawili $t_i = v_i$.

### Zadanie 6
Zamień pętlę modyfikującą $i$-ty wiersz, na `t[i] = v[i]`.

### Zadanie 7
Przetestuj kod z funkcją `Mult_A` zamiast funkcji `Mult`.

### Zadanie 8
Jeśli nie zrobiłeś tego w poprzednim ćwiczeniu, napisz trywialny preconditioner `Precond_I(int N, double **A, double *r, double *p)` przepisujący tablicę reszt wskazywaną przez `r` na tablicę poprawek wskazywaną przez `p`.

### Zadanie 9
Popraw kod zauważając, że ani `Mult_A`, ani `Precond_I` nie potrzebują wskaźnika na `A` jako argumentu.

# A teraz na poważnie

Na tym etapie nie potrzebujemy w ogóle macierzy $\mathbf{A}$ zapisanej gdziekolwiek w pamięci.
Możemy ją całkowicie wyeliminować.
Funkcję `Solve` będziemy jednak chcieli używać dla różnych macierzy --- dlatego jako argument, zamiast wskaźnika na macierz `double **A` będziemy przekazywać funkcję mnożenia
```c++
void (*mult)(int N, double *, double *)
```
Nagłówek funkcji `Solve` będzie miał wtedy postać:
```c++
void Solve(int N, void (*mult)(int N, double *, double *), double *b, double *x)
```
W miejscu mnożenia przez macierz $\mathbf{b} = \mathbf{A}\mathbf{x}$ będziemy wywoływali `mult(N, x, b);`.
Teraz funkcję `Solve` będziemy wywoływać przekazując jej konkretną funkcję mnożącą
```c++
Solve(N, Mult_A, F, d);
```
