---
number: 4
course: Metody Numeryczne
material: Instrukcja 4
author: Ł. Łaniewski-Wołłk
title: Mnożenie przez macierz jako funkcja
---

# Wstęp
Na tym laboratorium nie poznamy *sensum stricte* nowych metod numerycznych. Zamiast tego przyjrzymy się, jak w optymalny sposób zaimplementować metody, które już znamy.
Wykonując poprzednie laboratorium powinniśmy byli zauważyć, że najbardziej wydajną metodą iteracyjną (przynajmniej z tych rozważanych) rozwiązania układu algebraicznego wynikającego z MES jest metoda gradientów sprzężonych z preconditionerem Jacobiego.
Wobec tego skupimy się tylko na niej, ale warto zaznaczyć, że prezentowane poniżej rozwiązania z powodzeniem można stosować również dla pozostałych metod iteracyjnych.

Macierz $N \times N$ typu `double` zajmuje w pamięci $8N^2$ byte'ów, także np. mając 16GB pamięci RAM możemy zaalokować macierz reprezentującą układ równań o ok. 45tys. niewiadomych (nawet mniej, gdy uwzględnimy pamięć zarezerwowaną na inne zmienne, system operacyjny itd.).
Implementacja z poprzednich zajęć jest wobec tego zupełnie nieadekwatna do ,,prawdziwych'' problemów inżynierskich, które potrafią mieć nawet dziesiątki milionów stopni swobody.
Szczęśliwie okazuje się, że trzymanie w pamięci całego $A$ nie jest potrzebne.
Nietrudno zauważyć, że w metodzie gradientów sprzężonych nie używamy elementów macierzy, lecz tylko możliwości mnożenia przez nią.
Innymi słowy, nie musimy wiedzieć jak wygląda $A$, wystarczy że dla danego wektora $x$ potrafimy policzyć $Ax$.
Dziś wykorzystamy to spostrzeżenie, aby przyspieszyć program i drastycznie zredukować ilość wykorzystywanej przez niego pamięci.

Dodatkowo, chętni mogą dowiedzieć się, jak wykorzystać współczesne wielordzeniowe procesory do przyspieszenia obliczeń.

# Przygotowanie
Aby nie pomylić się w następnych krokach, należy najpierw zrefaktoryzować (tzn. przeorganizować i ,,posprzątać'') kod. W tym celu upewnij się, że Twoja implementacja spełnia poniższe wymagania:

- Implementacja metody CG jest wydzielona do osobnej funkcji (dla ustalenia uwagi w tej instrukcji nazwiemy ją `Solve`)

- `Solve` przyjmuje następujące argumenty: rozmiar układu równań `N` (typ całkowity), macierz `A` (typ `double **`), wektor `b` (typ `double *`), wektor przybliżenia początkowego `x0` (typ `double *`) oraz wektor, do którego wpisane zostać ma rozwiązanie `x` (typ `double*`).

- `Solve` nie zwraca wartości lub ewentualnie zwraca kod błędu (typ `int`).

- Wewnątrz `Solve` jasno zdefiniowana jest maksymalna liczba iteracji `max_it` (typ `const int`) oraz poziom zbieżności `eps` (typ `const double`). Opcjonalnie możesz te wielkości przekazywać jako dodatkowe argumenty.

- Poszczególne elementy danej iteracji, np. liczenie residuum, mnożenie macierz-wektor, mnożenie skalarne wektorów itp. są wydzielone do osobnych funkcji.

- Bezpośrednio w `Solve` nie występują odniesienia do poszczególnych elementów `A` (są one przeniesione do odpowiednich funkcji, z których `Solve` korzysta)

- Zmienna `fix` jest globalna.

# Element po elemencie
Skopiuj funkcję do mnożenia macierz-wektor i nazwij kopię `SMult`.
W funkcji `SMult` będziemy chcieli napisać funkcję mnożącą przez globalną macierz sztywności $S$ nie używając samej tej macierzy. Chcemy wykonać operację $r=Sx$, tzn: $r_i = \sum_jS_{ij}x_j$.

Jeśli dodamy do elementu $S_{1,2}$ liczbę $4$, to do $r_1$ musimy dodać $4x_2$.

Analogicznie jeśli dodamy do elementu $S_{ij}$ liczbę $w$, to tak jak byśmy dodali do elementu $r_i$ liczbę $w\cdot x_j$.
Jako, że macierz $S$ konstruujemy właśnie przez dodawanie do kolejnych jej elementów, możemy całość mnożenia przez nią zapisać w powyższej postaci.

### Zadanie
Przekopiuj fragment kodu funkcji `main` odpowiedzialny za konstrukcję macierzy $S$. Następnie, każde wystąpienie\\
`S[i,j] += cos;`\\
zamień na:\\
`r[i] += cos * x[j];`

### Zadanie
Co z częścią, która zamieniała wybrane wiersze na wiersze macierzy diagonalnej?
Jeśli w macierzy $S$ $i$-ty wiersz zamienimy na same zera i $1$ na przekątnej, to tak jak byśmy postawili $r_i = x_i$.
Zamień pętlę wycinającą $i$ty wiersz, na `r[i]=x[i]`

### Zadanie
Przetestuj kod z `SMult` zamiast `Mult`

### Zadanie
Napisz trywialny preconditioner `IPrecond(double ** A, double * r, double * p)`, przepisujący $p=r$.

### Zadanie
Popraw kod zauważając, że ani `SMult` ani `IPrecond` nie potrzebują brać `A` za argument.

# A teraz na poważnie
Na tym etapie nigdzie w kodzie nie potrzebujemy macierzy $S$.
Możemy ją całkowicie wyeliminować.
Funkcję `Solve` będziemy chcieli jednak używać dla różnych macierzy --- dlatego jako argument, zamiast macierzy `double ** A` będziemy przekazywać funkcję mnożenia `void (*mult)(double *, double *)`.
Tzn: nagłówek funkcji `Solve` będzie następujący:\\
`void Solve(int n, void (*mult)(double *, double *), double *b, double *x0, double *x)`\\
A w miejscu mnożenia przez macierz $r=Ax$ będziemy mieli `mult(x,r);`. Teraz funkcję `Solve` będziemy wywoływać przekazując jej konkretną funkcję mnożącą: `Solve(n, SMult, F, d);`.

# Równoległość

