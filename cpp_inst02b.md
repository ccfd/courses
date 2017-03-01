---
number: 2
course: Programowanie Obiektowe w c++
material: Instrukcja 2
author: W. Gryglas
---

##Zadanie 1
Sprawdź działanie operatorów `new`{.cpp} i `delete`{.cpp} dla tablicy klas z konstruktorem i destruktorem np.:
```cpp
#include <iostream.h>

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

* Dodaj do klasy `A`{.cpp} atrybut statyczny np. `static int mattr`{.cpp}.

* Sprawdź jakie wartości będą drukowane (dlaczego?) jeśli wykonasz:
    ```cpp
    for ( i=0; i<5; ++i)
        ptr[i].mattr = i+1;

    for ( i=0; i<5; ++i)
        cout << “ element “ << i << “ attr = “ << ptr[i].mattr << endl;
    ```

##Zadanie 2
Utwórz klasę bazową Pojazd opisującą pewien pojazd.

* Atrybut klasy to np. przebieg danego pojazdu (typu `int`{.cpp}) umieszczony w sekcji `private`{.cpp}

* Utwórz:
    * konstruktor defaultowy: `Pojazd()`{.cpp} – przebieg zainicjuj zerem
    * konstruktor `Pojazd(const int& n)`{.cpp} – przebieg zainicjuj argumentem n
    * destruktor `~Pojazd()`{.cpp}

* W konstruktorach i destruktorach drukuj informację o ich wykonaniu tak aby można było stwierdzić co i kiedy zostało wywołane.

* Utwórz metodę `Przebieg()`{.cpp} zwracającą wartość przebiegu.

* Sprawdź poprawność tej klasy tworząc zmienną typu Pojazd i drukując wartość metody `Przebieg()`{.cpp}

##Zadanie 3
Utwórz klasę `Autobus`{.cpp} która jest klasą pochodną klasy `Pojazd`{.cpp}.

* Atrybut klasy to np. ilość pasażerów (typu `int`{.cpp}) umieszczony w sekcji `private`{.cpp}
* Utwórz:
    * konstruktor domyślny: `Autobus()`{.cpp} – przebieg zainicjuj zerem
    * konstruktor `Autobus(const int& m)`{.cpp} – ilość pasażerów zainicjuj argumentem `m`{.cpp}
    * destruktor `~Autobus()`{.cpp}

* Podobnie jak dla klasy `Pojazd`{.cpp} w konstruktorach i destruktorach drukuj informację o ich wykonaniu.

* Utwórz metodę `IloscPasazerow()`{.cpp} zwracającą wartość atrybutu przechowującego ilość pasażerów.

* Jeśli utworzysz zmienną typu `Autobus`{.cpp} jakie konstruktory będą wywoływane? W jakiej kolejności będą wołane konstruktory i destruktory?

* Jaki przebieg ma zmienna typu `Autobus`{.cpp}?

* Dodaj nowy konstruktor do klasy `Autobus`{.cpp} który pozwoli również zainicjalizować przebieg pojazdu i sprawdź jego działanie.

* Co się stanie jeśli wykonasz poniższy kod i co zrobić aby uniknąć tego typu niejdnoznaczności?
```cpp
Autobus	 bus;
bus = 3;
```

##Zadanie 4
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp.