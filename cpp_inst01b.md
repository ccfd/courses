---
number: 1
course: Programowanie Obiektowe w c++
material: Instrukcja 1
author: W. Gryglas
---

## Zadanie 1
Utwórz klasę Wektor2D będącą implementacją wektorów w przestrzeni 2D.

* atrybuty klasy to 2 zmienne typu double opisujące współrzędne wektora umieszczone w sekcji protected
* utwórz konstruktory:
    * defaultowy: Wektor2D()
    * kopiujący: Wektor2D(const Wektor2D& v)
    * Wektor2D(const double& x, const double& y)

* Utwórz metodę `Drukuj()`{.cpp} służącą do drukowania zawartości klasy na ekranie w formacie:
***wektor [ 2.345, 4.5678]***

* Utwórz operatory:
    * Jednoargumentowy  `operator +=`{.cpp}
    * Dwuargumentowy `operator +`{.cpp} (sprawdź czy możesz operować na atrybutach klasy `Wektor2D`{.cpp} bez definiowania zaprzyjaźnienia z tą klasą i co stanie się jeśli atrybuty klasy są umieszczone w sekcji `private`{.cpp})

* W funkcji `main()`{.cpp} wykorzystaj klasę `Wektor2D`{.cpp} i operatory tej klasy np.:
```cpp
Wektor2D v1(1,2);
Wektor2D v2 = v1;
Wektor2D v3;
v3 = v1 + v2;
v1.Drukuj();
v2.Drukuj();
v3.Drukuj();
```

* Sprawdź korzystając z debugera lub drukując tekst informacyjny w ciele konstruktorów które konstruktory kiedy są używane.

## Zadanie 2
Utwórz klasę Pojemnik służącą do przechowywania obiektów typu `Wektor2D`{.cpp}.

* Atrybuty tej klasy to dynamiczna tablica typu `Wektor2D *mdata`{.cpp} i rozmiar tej tablicy `int msize`{.cpp}

* Utwórz konstruktor domyślny i destruktor.

* Utwórz metodę `Dodaj(const Wektor2D& v)`{.cpp} służącą do dodawania elementów do klasy `Pojemnik`{.cpp}. Konieczne jest dynamiczne przealokowanie tablicy `mdata`{.cpp} (używaj operatorów `new`{.cpp} i `delete`{.cpp}). Wewnątrz tej metody drukuj na ekranie zawartość wektora dodawanego (przekazanego jako argument metody) korzystając z metody klasy `Wektor2D`{.cpp} – `Drukuj`{.cpp}. Co trzeba dodać do definicji metody `Drukuj`{.cpp} aby było to możliwe?

* Utwórz metodę `Suma()`{.cpp} należącą do klasy `Wektor2D`{.cpp} liczącą sumę wszystkich wektorów przechowywanych w klasie `Pojemnik`{.cpp}, korzystając z operatorów zdefiniowanych dla klasy `Wektor2D`{.cpp}

* Utwórz metodę `DrukujWszystko()`{.cpp} drukującą zawartość wszystkich obiektów `Wektor2D`{.cpp} przechowywanych w klasie `Pojemnik`{.cpp} oraz ich sumę obliczoną metodą `Suma`{.cpp}.

* Zmodyfikuj funkcję main tak aby sprawdzić działanie nowej klasy np.:
```cpp
Pojemnik poj;
poj.Dodaj( v1);
poj.Dodaj( v2);
poj.Dodaj( Wektor2D(3,2));
poj.Dodaj( Wektor2D(8,4));
poj.DrukujWszystko();
```

##Zadanie 3
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp.


