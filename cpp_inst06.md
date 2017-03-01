---
number: 6
course: Programowanie Obiektowe w c++
material: Instrukcja 6
author: W. Gryglas
---

Wprowadzenie do STL (Standard Template Library)

## Zadanie 1
Korzystanie ze struktur standardowych typu `vector`{.cpp} i `list`{.cpp}.

* Utwórz tablicę służącą do przechowywania liczb całkowitych. Wykorzystaj standardową strukturę vector np.:
```cpp
#include <vector>
using namespace std;
vector<int>	tab;
```

* Wypełnij tablicę pewną ilością elementów wczytywanych z klawiatury lub generowanych losowo (funkcja `rand()`{.cpp}). Do wstawienia elementu do tablicy użyj metody `push_back`{.cpp} lub `insert`{.cpp} (sprawdź jak zmienia się rozmiar tablicy – funkcja `size`{.cpp}):
```cpp
int d;
tab.push_back( d);		lub	tab.insert( tab.end(), d);
cout << tab.size() << endl;
```

* Wydrukuj zawartość tablicy na ekran używając obiektu `iterator`{.cpp}:
```cpp
vector<int>::iterator	itr;
for ( itr=tab.begin(); itr!=tab.end(); ++itr)
cout << *itr <<endl;
```

* Wydrukuj od końca zawartość tablicy na ekran używając obiektu `reverse_iterator`{.cpp}:
```cpp
vector<int>::reverse_iterator	ritr;
for ( itr=tab.rbegin(); itr!=tab.rend(); ++ritr)
cout << *ritr <<endl;
```

* Usuń wszystkie elementu z tablicy tab przez wykorzystanie metody `clear()`{.cpp}. Sprawdź czy tablica jest rzeczywiście pusta przez sprawdzenie rozmiaru (`size()`{.cpp}) i metody `empty()`{.cpp} – zwraca wartość `bool`{.cpp} w zależności od tego czy tablica jest pusta czy też nie.

* Zmodyfikuj program tak aby zamiast kolekcji typu vector korzystać z kolekcji typu list (pamiętaj o include <list>).

##Zadanie 2
Korzystanie ze standardowych algorytmów.

* Posortuj rosnąco i wydrukuj zawartość tablicy `tab`{.cpp}. Skorzystaj z funkcji `sort`{.cpp} (pamiętaj o `#include <algorithm>`{.cpp}):
```cpp
sort( tab.begin(), tab.end() );
Posortuj malejąco i wydrukuj zawartość tablicy tab:
sort( tab.begin(), tab.end(), greater<int>() );
```

* Czy efekt z punktu poprzedniego można osiągnąć inaczej? Czy funkcja `sort`{.cpp} będzie działała dla kolekcji typu `list`{.cpp} (dlaczego)?

* Znajdź największy i najmniejszy element w tablicy `tab`{.cpp} (funkcje `max_element`{.cpp} i `min_element`{.cpp}).

* Czy możesz zastosować algorytm dla tablicy typowej dla języka C? Sprawdź działanie w programie..

* Utwórz kolekcję `vector`{.cpp} składającą się z obiektów typu `Wektor2D`{.cpp}. Współrzędne wektorów 2D generuj losowo. 

* Wydrukuj wszystkie elementy kolekcji `vector`{.cpp} posortowane rosnąco.

* Poeksperymentuj z innym algorytmami STL (opis znajdziesz w helpie pod hasłem „Standard C++ Library, algorithms”)