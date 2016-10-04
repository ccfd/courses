#PROGRAMOWANIE OBIEKTOWE W C++
#LABORATORIUM 4

## Zadanie 1
Sprawdź działanie obsługi wyjątków/błędów (exception handling) w języku C++

* Utwórz klasę abstrakcyjną `Except`{.c++} która ma metodę wirtualną do drukowania informacji o wyjątku (np. `PrintInfo()`{.c++} ).
* Utwórz klasę konkretną np. `Except1`{.c++} która będzie posiadała implementację metody `PrintInfo()`{.c++}.
* W funkcji main umieść instrukcje służące do przechwytywania wyjątków:
```c++
	try 
	{
		....
	}
	catch ( Except& e) 
	{
		e.PrintInfo();
	}
```
* W sekcji try wywołaj jakąś funkcję która rzuca wyjątek `Except1`{.c++}:
```c++
	throw Except1;
```
* Spróbuj zrobić to samo dla nowej klasy `Except2`{.c++} która będzie drukowała informacje w której linii kodu został rzucony wyjątek (użyj zmiennej preprocesora `__LINE__`{.c++})

* Sprawdź działanie sekcji `catch(...)`{.c++} do przechwytywania wszystkich wyjątków. Dopisz ją poniżej już istniejącej sekcji `catch`{.c++} i spróbuj rzucić wyjątek który nie jest typu `Except`{.c++}.

## Zadanie 2
Wykorzystanie prostych wzorców (template)
* Napisz wzorce (template’y) funkcji `mymin`{.c++} i `mymax`{.c++} liczące odpowiednio minimum i maksimum z dwóch argumentów. Sprawdź działanie tych funkcji dla różnych typów np. `int, double`{.c++}. 
* Co jest konieczne aby można było wykorzystać powyższe funkcje również do klasy np. `Wektor2D`{.c++}?
* Przerób klasę `Wektor2D`{.c++} tak aby był to wzorzec klasy sparametryzowany typem składowych wektora:
```c++
	template< class T >
	Wector2D
	{
		. . .
	};
```
Sprawdź działanie takiej klasy.

* Przerób klasę `Wector2D`{.c++} tak aby była ona również sparametryzowana ilością składowych:
```c++
	template< class T, int N >
	Wector
	{
		. . .
	};
```
Sprawdź działanie takiej klasy.








