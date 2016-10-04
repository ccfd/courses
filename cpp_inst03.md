#PROGRAMOWANIE OBIEKTOWE W C++
#LABORATORIUM 3

## Zadanie 1
Sprawdź działanie polimorfizmu na przykładzie tablicy figur.

* Utwórz klasę bazową `Shape`{.c++}. Klasa ta powinna posiadać metodę służącą do drukowania nazwy obiektu np.:
```c++
	void PrintName()
	{
		cout << ”class Shape\n”;
	}
```
* Utwórz klasy `Circle, Square, Triangle`{.c++} będące obiektami potomnymi klasy `Shape`{.c++}. Obiekty te powinny być opisane przez wierzchołki (można wykorzystać klasę z zajęć poprzednich `Wector3D`{.c++}) i posiadać metody do obliczania pola figury.
* Zmodyfikuj klasę `Shape`{.c++} przez dodanie abstrakcyjnej metody do liczenia pola figury np.:
```c++
	virtual double Area() = 0;
```
* Sprawdź, czy możesz teraz utworzyć obiekt typu `Shape`{.c++} lub np. `Circle`{.c++}.
* Zmodyfikuj metody `Area()`{.c++} obiektów `Circle, Square, Triangle`{.c++} tak aby były one wirtualne oraz dodaj do nich wirtualne metody `PrintName()`{.c++}.
* Utwórz tablicę wskaźników do obiektów typu `Shape`{.c++} i zainicjalizuj je obiektami `Circle, Square, Triangle`{.c++} np.:
```c++
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
* Sprawdź co się stanie gdy usunie się modyfikator `virtual`{.c++} przy metodach obiektów `Circle, Square, Triangle`{.c++}. 
* Sprawdź działanie funkcji `dynamic_cast<T*>()`{.c++} np. do policzenia ile obiektów w danej kolekcji jest typu `Circle`{.c++} (pamiętaj o włączeniu opcji kompilatora RTTI):
```c++
	if  ( dynamic_cast<Circle*>( tabp[i] ) )  ++count;
```
* Czy wiesz dlaczego w punkcie poprzednim używaliśmy `dynamic_cast`{.c++} a nie `static_cast`{.c++}?

## Zadanie 2
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp



