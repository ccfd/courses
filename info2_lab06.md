---
number: 6
course: Informatyka 2
material: Instrukcja 6
author: B. Górecki, rev. W. Gryglas
---

# Metoda eliminacji Gaussa

Pliki do wykorzystania w poniższym ćwiczenie można pobrać za pomocą poniższych linków:

 - [Plik nagłówkowy gauss.h](http://ccfd.github.io/courses/code/info2/gauss.h)
 - [Plik źródłowy gauss.cpp](http://ccfd.github.io/courses/code/info2/gauss.cpp)


Wygeneruj układ równań $Ax = b$, gdzie:

- A jest macierzą Hilberta, tzn. $a_{ij} =\frac{1}{i+j+1}$, $i, j= 0, ..., n − 1$
- Wektor prawych stron b ma elementy równe sumie elementów macierzy $A$ w wierszu, co oznacza, że znane jest rozwiązanie analityczne tego układu równań. Ile ono wynosi?

## Ćwiczenia
1. Macierz $A$ i wektor $b$ zadeklaruj statycznie dla maksymalnie $N = 50$ elementów.
2. Napisz funkcje odpowiednio generujące macierz Hilberta, wyświetlające macierz, generujące wektor prawych stron oraz wyśtwietlające wektor. Ich nagłówki (które muszą zawierać maksymalny rozmiar macierzy) mają postać:
```c++
void HilbertMatrix(int n, double A[][N]);
void DisplayMatrix(int n, double A[][N]);
void ComputeVec(int n, double A[][N], double v[]);
void DisplayVec(int n, double v[]);.
```
3. Zastosuj funkcję realizującą metodę eliminacji Gaussa do rozwiązania powyższego układu równań. Nagłówek funkcji jest postaci `void gauss(int n, double A[][N], double b[], doublex[])`, gdzie `n` to liczba równań, `A` to macierz układu równań, `b` - wektor prawych stron, zaś `x` to wektor, w którym zostanie zapisany wynik. 
4. Przetestuj działanie programu dla różnych `n`.
5. Na podstawie funkcji gauss napisz funkcję wyznaczającą macierz trójkątną. Następnie wykorzystując tę macierz, oblicz wartość wyznacznika.
6. Przerób program tak, aby macierz i wektor były wczytywane z wcześniej utworzonych plików.
7. Zamień statyczną alokację pamięci na alokację dynamiczną.
