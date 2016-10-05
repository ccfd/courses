---
number: 4
course: Programowanie Obiektowe w c++
material: Instrukcja 4
author: W. Gryglas
---

## Zadanie 1
Sprawdź działanie polimorfizmu na przykładzie tablicy figur.

* Utwórz klasę `Point`{.cpp} przechowującą dane o współrzędnych punktu na płaszczyźnie. Klasa powinna posiadać konstruktor parametryczny i funkcję wyznaczającą odległość pomiędzy dwoma punktami. Definicje wymienionych funkcji powinny pozwolić na wykonanie następującego kodu:
```c++
Point p1(2,4), p2(2,2);
cout  << p1.Length(p2);
```

* Utwórz klasę bazową `Shape`{.cpp}. Klasa ta powinna posiadać metodę służącą do drukowania nazwy obiektu np.:
```c++
void PrintName()
{
	cout << ”class Shape\n”;
}
```

* Utwórz klasy `Circle, Rectangle, Triangle`{.cpp} będące obiektami potomnymi klasy `Shape`{.cpp}. Obiekty te powinny być opisane przez wierzchołki (wykorzystaj klasę `Point`{.cpp}) i posiadać metody do obliczania pola figury.
* Utwórz obiekty reprezentujące klasy figur i wyświetl ich powierzchnie.
* Zmodyfikuj klasę `Shape`{.cpp} przez dodanie abstrakcyjnej metody do liczenia pola figury np.:
```c++
virtual double Area() = 0;
```

* Sprawdź, czy możesz teraz utworzyć obiekt typu `Shape`{.cpp} lub np. `Circle`{.cpp}.
* Zmodyfikuj metody `Area()`{.cpp} obiektów `Circle, Rectangle, Triangle`{.cpp} tak, aby były one wirtualne oraz dodaj do nich wirtualne metody `PrintName()`{.cpp}.
* Utwórz tablicę wskaźników do obiektów typu `Shape`{.cpp} i zainicjalizuj je obiektami `Circle, Rectangle, Triangle`{.cpp} np.:
```c++
Shape	*tabp[3];
tabp[0] = new Circle(…);
tabp[1] = new Triangle(…);
tabp[2] = new Rectangle(…);
for ( int I=0; I<3; ++I)
{
    tabp[I]->PrintName();
    cout << tabp[I]->Area() << endl;
}
```

* Sprawdź co się stanie gdy usunie się modyfikator `virtual`{.cpp} przy metodach obiektów `Circle, Rectangle, Triangle`{.cpp}.
* Sprawdź działanie funkcji `dynamic_cast<T*>()`{.cpp}  np. do policzenia ile obiektów w danej kolekcji jest typu `Circle`{.cpp} (pamiętaj o włączeniu opcji kompilatora RTTI):
```c++
if( dynamic_cast<Circle*>( tabp[I] ) )
{
	++count;
}
```

* Czy wiesz dlaczego w punkcie poprzednim używaliśmy `dynamic_cast`{.cpp} a nie `static_cast`{.cpp}?

## Zadanie 2

* Dodaj do klasy `Point`{.cpp} konstruktor kopiujący:
```c++
Point::Point( const Point& p )
{
			x = p.x;
	y = p.y;
	cout << "Point: Kontruktor kopiujący"<<endl;
}
```
* Dodaj również kolejną wersję funkcji wyznaczającej odległość pomiędzy dwoma punktami. Tym razem jednak obiekt Point powinien być przekazywany do funkcji przez kopiowanie a nie przez referencje:
```c++
double Point::Length2( const Point p )
{
	return sqrt( (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y ) );
}
```
* Sprawdź czym różnią się wywołania tych funkcji:
```c++
Point pa(10, 20), pb(30, 40);
cout<<"Length()"<<endl;
cout<<pa.Length(pb)<<endl;
cout<<"Length2()"<<endl;
cout<<pa.Length2(pb)<<endl;
```
* Spróbuj zmienić wartość obiektu `p`{.cpp} wewnątrz funkcji `Length2`{.cpp} np.: `p.x = 100;`{.cpp}. Zmień na chwilę tak definicję tej funkcji aby taka operacja była możliwa. Która wersja funkcji `Length()`{.cpp} jest najbardziej optymalna?

## Zadanie 3 (Nie wiem czy jest sens z racji różnych wersji programów)
Poznaj swoje środowisko pracy.
Odnajdź i przetestuj działanie następujących ikon paska narzędziowego:
 - wstawianie i usuwanie tabulatorów.
 - wstawianie i usuwanie komentarza.
 - sterowanie zakładkami.

Dostosuj środowisko programistyczne do własnych potrzeb: poprzez menu ***Toolbox*** otwórz okno ***Customize...*** .
* Wybierz zakładkę ***Toolbars*** i dodaj lub usuń z menu dowolny pasek narzędzi (np. ***Debug***).
* Wybierz zakładkę ***Commands***. Na liście ***Categories*** zaznacz pozycję ***View***, zaś na liście ***Commands*** odszukaj pozycję ***Full Screen*** i przeciągnij ją myszką na dowolny pasek narzędzi w menu edytora. (Spróbuj go na chwilę stamtąd usunąć).
* Poprzez przycisk ***Keyboard...*** otwórz okno ***Options***. Na liście ***Show commands containing***: odszukaj skrót klawiaturowy przycisku ***Full Screen***. Sprawdź działanie tego przycisku zarówno poprzez ikonę jak i klawiaturę.

## Zadanie 4
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp.

## UWAGA
W przypadku wystąpienia ostrzeżenia:
“warning C4541: 'dynamic_cast' used on polymorphic type 'class Shape' with /GR-; unpredictable behavior may result”
należy:
- wybrać polecenie Project | Properties;
- w gałęzi C/C++ wybrać pozycję Language;
- włączyć opcję Enable Run-TimeType Info (RTTI);
