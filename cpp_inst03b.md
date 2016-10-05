---
number: 3
course: Programowanie Obiektowe w c++
material: Instrukcja 3
author: W. Gryglas
---

## Zadanie 1
Sprawdź działanie polimorfizmu na przykładzie tablicy figur.
* Utwórz klasę bazową `Shape`{.cpp}. Klasa ta powinna posiadać metodę służącą do drukowania nazwy obiektu np.:
```cpp
void PrintName()
{
	cout << ”class Shape\n”;
}
```

* Utwórz klasy `Circle, Square, Triangle`{.cpp} będące obiektami potomnymi klasy `Shape`{.cpp}. Obiekty te powinny być opisane przez wierzchołki (można wykorzystać klasę z zajęć poprzednich `Wektor2D`{.cpp}) i posiadać metody do obliczania pola figury.

* Zmodyfikuj klasę `Shape`{.cpp} przez dodanie abstrakcyjnej metody do liczenia pola figury np.:
```cpp
virtual double Area() = 0;
```

* Sprawdź, czy możesz teraz utworzyć obiekt typu `Shape`{.cpp} lub np. `Circle`{.cpp}.

* Zmodyfikuj metody `Area()`{.cpp} obiektów `Circle, Square, Triangle`{.cpp} tak aby były one wirtualne oraz dodaj do nich wirtualne metody `PrintName()`{.cpp}.

* Utwórz tablicę wskaźników do obiektów typu `Shape`{.cpp} i zainicjalizuj je obiektami `Circle, Square, Triangle`{.cpp} np.:
```cpp
Shape	*tabp[3];
tabp[0] = new Circle(…);
tabp[1] = new Triangle(…);
tabp[2] = new Square(…);
for ( int i=0; i<3; ++i)
{
    tabp[i]->PrintName();
    cout << tabp[i]->Area() << endl;
}
```

* Sprawdź co się stanie gdy usunie się modyfikator `virtual`{.cpp} przy metodach obiektów `Circle, Square, Triangle`{.cpp}.

* Sprawdź działanie funkcji `dynamic_cast<T*>()`{.cpp}  np. do policzenia ile obiektów w danej kolekcji jest typu `Circle`{.cpp} (pamiętaj o włączeniu opcji kompilatora RTTI):
```cpp
if( dynamic_cast<Circle*>( tabp[i] ) )
{
  ++count;
}
```

* Czy wiesz dlaczego w punkcie poprzednim używaliśmy `dynamic_cast`{.cpp} a nie `static_cast`{.cpp}?

##Zadanie 2
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp