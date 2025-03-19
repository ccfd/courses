---
author: "K. Marchlewski"
course: Informatyka III
material: Regulamin
number: 0
---

# Informacje ogólne

1. Jednostka: Zakład Aerodynamiki
2. Numer katalogowy: NK469
3. Liczba punktów ECTS: 2
4. Godziny dydaktyczne: 15 W, 15 L
5. Koordynator: Łukasz Łaniewski-Wołłk

# Regulamin przedmiotu, zasady zaliczenia

1. Wykład odbywa się przez pół semestru w pt. 8:15-10:00
2. Ćwiczenia odbywają się co dwa tygodnie w terminach:

    - wt. 8:15-10:00,
    - wt. 10:15-12:00,
    - pt. 10:15-12:00.
    
3. Zaliczenie przedmiotu składa się z dwóch części:

    - kolokwium wykładowe (warunek konieczny niewystarczający)
    - kolokwium na ćwiczeniach.

# Program

1. Zapoznanie z systemem UNIX/Linux
2. Programowanie w powłoce (Bash)
3. Relacyjne bazy danych - MySQL
4. Tworzenie dokumentów tekstowych w $\LaTeX u$
5. Programowanie równoległe
6. Sieci i protokoły internetowe

# Przykładowe kolokwium z ćwiczeń

Czas trwania: 60 min

Ocena: 2 zadania: dst., 3 zadania: db. 4 zadania: bdb.

1. Wyświetl tabelę zawierającą nazwy europejskich krajów i liczbę języków jakimi mówią ich mieszkańcy.
2. Napisz skrypt tworzący listę plików znajdujących się w każdym z katalogów podrzędnych (jeden poziom) względem katalogu, w którym znajduje się skrypt. Przykładowy wynik działania programu:  
*katalogA:*  
*plik.txt* *plik.dat*  
*katalogB:*  
*plik1.txt* *plik2.txt* *plik.dat*  
                  
3. Napisz skrypt wyświetlający nazwę pliku o największym rozmiarze. Skrypt powinien sprawdzać wyłącznie pliki znajdujące się w tym samym katalogu co on.  
**Podpowiedź:** skorzystaj z wyniku polecenia *du -b plik*

4. Utwórz plik *.pdf* zawierający równanie zapisane w systemie $\LaTeX$.
$$
1-|\mu_0|^2=\frac{(\mathfrak{R} f_0)^2+(\mathfrak{B}f_0-kR_x)^2-(\mathfrak{R}f_0)^2-(\mathfrak{B}f_0-kR_x)^2}{(\mathfrak{R}f_0)^2-(\mathfrak{B}f_0-kR_x)^2}
$$  
**Podpowiedź:** w celu zmiany czcionki skorzystaj z pakietu *amsfonts* i polecenia *\\mathfrak*.
