---
number: 3
course: Programowanie Obiektowe w c++
material: Instrukcja 3
author: W. Gryglas
---

## Zadanie 1
Sprawdź działanie operatorów new i delete dla tablicy klas z konstruktorem i destruktorem np.:
```c++
#include <iostream>
using namespace std;

class A
{
public:
	A()	{ cout << "konstruktor A\n";}
	~A()	{ cout << "destruktor A\n";}
};

int main()
{
	A	*ptr;
	ptr = new A[5];
	delete [] ptr; // co będzie gdy usunie się nawiasy [] ?
	return 0;
}
```

* Dodaj do klasy A atrybut statyczny np. `static int mattr`{.cpp}:
* Sprawdź jakie wartości będą drukowane (dlaczego?) jeśli wykonasz:
    ```c++
    for ( i=0; i<5; ++i)
        ptr[i].mattr = i+1;

    for ( i=0; i<5; ++i)
        cout << " element " << i << " attr = " << ptr[i].mattr << endl;
    ```

## Zadanie 2
Utwórz klasę bazową `Pojazd`{.cpp} opisującą pewien pojazd

* Atrybut klasy to np. przebieg danego pojazdu (typu int) umieszczony w sekcji `private`{.cpp}
* Utwórz:
    * konstruktor defaultowy: `Pojazd()`{.cpp} – przebieg zainicjuj zerem
    * konstruktor `Pojazd(const int& n)`{.cpp} – przebieg zainicjuj argumentem n
    * destruktor `~Pojazd()`{.cpp}
* W konstruktorach i destruktorach drukuj informację o ich wykonaniu tak aby można było stwierdzić co i kiedy zostało wywołane.
* Utwórz metodę `GetPrzebieg()`{.cpp} zwracającą wartość przebiegu
* Sprawdź poprawność tej klasy tworząc zmienną typu `Pojazd`{.cpp} i drukując wartość metody `GetPrzebieg()`{.cpp}

## Zadanie 3
Utwórz klasę `Autobus`{.cpp} która jest klasą pochodną klasy `Pojazd`{.cpp}
* Atrybut klasy to np. liczba pasażerów (typu int) umieszczony w sekcji `private`{.cpp}
* Utwórz:
    * konstruktor domyślny: `Autobus()`{.cpp} – liczbę pasażerów zainicjuj zerem
    * konstruktor `Autobus(const int& m)`{.cpp} – liczbę pasażerów zainicjuj argumentem `m`{.cpp}
    * destruktor `~Autobus()`{.cpp}
* Podobnie jak dla klasy `Pojazd`{.cpp} w konstruktorach i destruktorach drukuj informację o ich wykonaniu.
* Utwórz metodę `GetLiPasazerow()`{.cpp} zwracającą wartość atrybutu przechowującego liczbę pasażerów.
* Jeśli utworzysz zmienną typu `Autobus`{.cpp} jakie konstruktory będą wywoływane? W jakiej kolejności będą wołane konstruktory i destruktory?
* Jaki przebieg ma zmienna typu `Autobus`{.cpp}?
* Dodaj nowy konstruktor do klasy `Autobus`{.cpp}, który pozwoli również zainicjalizować przebieg pojazdu i sprawdź jego działanie.
* Co się stanie jeśli wykonasz poniższy kod i co zrobić aby uniknąć tego typu niejednoznaczności?
```c++
Autobus	 bus;
bus = 3;
```

## Zadanie 4
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp
