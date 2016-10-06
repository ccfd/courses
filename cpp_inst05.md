---
number: 5
course: Programowanie Obiektowe w c++
material: Instrukcja 5
author: W. Gryglas
---

## Zadanie 1
Sprawdź działanie obsługi wyjątków/błędów (exception handling) w języku C++

* Utwórz dowolną funkcję, która zwraca wyjątek w postaci:
```cpp
throw ”To jest wyjatek!”;
```

* Funkcję tę wywołaj w funkcji `main()`{.cpp} i przechwyć wyjątek:
```cpp
try
{
	....
}
catch (char* s)
{
	....
}
```

* Podejrzyj debuggerem co zawiera zmienna `s`{.cpp}, a następnie wydrukuj jej wartość na ekran w sekcji `catch`{.cpp}. Sprawdź co się stanie jeśli:
    - nie umieścisz wywołania funkcji w bloku `try - catch`{.cpp}
    - zmienisz typ wyjątku w bloku catch na inny: np. `int`{.cpp}

* Dodaj jeszcze funkcję, która zwróci jako wyjątek liczbę całkowitą. Funkcję tę wywołaj wewnątrz pierwszej funkcji. Wyjątek przechwyć wewnątrz funkcji `main()`{.cpp}.

* Utwórz klasę abstrakcyjną `Except`{.cpp} która ma metodę wirtualną do drukowania informacji o wyjątku (np. `PrintInfo()`{.cpp} )

* Utwórz klasę konkretną np. `Except1`{.cpp} która będzie posiadała implementację metody `PrintInfo()`{.cpp}

* W funkcji main umieść instrukcje służące do przechwytywania wyjątków:
```cpp
try
{
	....
}
catch ( Except& e)
{
	e.PrintInfo();
}
```

* W sekcji try wywołaj jakąś funkcję, która rzuca wyjątek `Except1`{.cpp}:
```cpp
throw Except1();
```

* Spróbuj zrobić to samo dla nowej klasy `Except2`{.cpp} która będzie drukowała informacje w której linii kodu został rzucony wyjątek (użyj zmiennej preprocesora `__LINE__`{.cpp}). (Inne popularne zmienne preprocesora to: `__FILE__`{.cpp}, `__DATE__`{.cpp}, `__TIME__`{.cpp}.)

* Sprawdź działanie sekcji `catch(...)`{.cpp} do przechwytywania wszystkich wyjątków. Dopisz ją poniżej już istniejącej sekcji `catch`{.cpp} i spróbuj rzucić wyjątek który nie dziedziczy po typie `Except`{.cpp}.

## Zadanie 2
Wykorzystanie prostych wzorców (template’ów)

* Napisz wzorce (template’y) funkcji `mymin`{.cpp} i `mymax`{.cpp} liczące odpowiednio minimum i maksimum z dwóch argumentów. Sprawdź działanie tych funkcji dla różnych typów np. `int, double`{.cpp}.

* Sprawdź działanie funkcji `mymax`{.cpp} dla następującego wywołania:
```cpp
	cout << mymax( 1., 2 );
```

* Jeśli to niezbędne popraw kod programu, aby powyższe wywołanie funkcji było poprawne.

* Co jest konieczne aby można było wykorzystać powyższe funkcje również do klasy np. `Wektor2D`{.cpp}?

* Napisz klasę `Wektor2D`{.cpp}, tak aby zadziałał następujący kod:
```cpp
Wektor2D w1(1, 3), w2(3, 5);
Wektor2D w3 = mymax(w1, w2);
```
(Wynik działania sprawdź pod debuggerem)

* Przerób klasę `Wector2D`{.cpp} tak aby był to wzorzec klasy sparametryzowany typem składowych wektora:
```cpp
template< class T >
Wector2D
{
	. . .
};
```

* Sprawdź działanie takiej klasy dla różnych typów (`int, double`{.cpp}), np.:
```cpp
Wektor2D<double> wt1(10., 20.), wt2(10.,40.);
Wektor2D<double> wt3 = mymax( wt1, wt2 );
```

* Dodaj do klasy `Wektor2D operator <<`{.cpp} pozwalający na wykonanie następującego kodu:
```cpp
Wektor2D<double> wt1(10., 20.), wt2(10.,40.);
cout << mymax( wt1, wt2 );
```

* Zapewnij aby jedynie wektory typu int miały niepowtarzalną postać wydruku. (Należy skonkretyzować `operator<<`{.cpp} dla typu `int`{.cpp}.)

* Przerób klasę `Wector2D`{.cpp} tak aby była ona również sparametryzowana liczbą składowych:
```cpp
template< class T, int N >
Wektor
{
	. . .
};
```

* W konstruktorze domyślnym zainicjalizuj każdą ze składowych wektora kolejną liczbą naturalną. Nie używaj dynamicznej alokacji pamięci (przynamniej na początku). Sprawdź działanie takiej klasy, np:
```cpp
WektorNT<int,20> wnt;
cout << wnt;
```