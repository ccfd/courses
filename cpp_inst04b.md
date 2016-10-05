---
number: 7
course: Programowanie Obiektowe w c++
material: Instrukcja 7
author: W. Gryglas
---

#(Instruckcja poc_lab4)

## Zadanie 1
Sprawdź działanie obsługi wyjątków/błędów (exception handling) w języku C++.

* Utwórz klasę abstrakcyjną `Except`{.cpp} która ma metodę wirtualną do drukowania informacji o wyjątku (np. `PrintInfo()`{.cpp} )

* Utwórz klasę konkretną np. `Except1`{.cpp} która będzie posiadała implementację metody `PrintInfo()`{.cpp}

* W funkcji main umieść instrukcje służące do przechwytywania wyjątków:
```cpp
try {
	....
}
catch ( Except& e) {
	e.PrintInfo();
}
```

* W sekcji try wywołaj jakąś funkcję która rzuca wyjątek `Except1`{.cpp}:
```cpp
throw Except1;
```

* Spróbuj zrobić to samo dla nowej klasy `Except2`{.cpp} która będzie drukowała informacje w której linii kodu został rzucony wyjątek (użyj zmiennej preprocesora `__LINE__`{.cpp})
* Sprawdź działanie sekcji `catch(...)`{.cpp} do przechwytywania wszystkich wyjątków. Dopisz ją poniżej już istniejącej sekcji `catch`{.cpp} i spróbuj rzucić wyjątek który nie jest typu `Except`{.cpp}.

## Zadanie 2
Wykorzystanie prostych wzorców (templatów)

* Napisz wzorce (template’y) funkcji `mymin`{.cpp} i `mymax`{.cpp} liczące odpowiednio minimum i maksimum z dwóch argumentów. Sprawdź działanie tych funkcji dla różnych typów np. `int, double`{.cpp}.

* Co jest konieczne aby można było wykorzystać powyższe funkcje również do klasy np. `Wektor2D`{.cpp}?

* Przerób klasę `Wector2D`{.cpp} tak aby był to wzorzec klasy sparametryzowany typem składowych wektora:
```cpp
template< class T >
Wector2D
{
	. . .
};
```

* Sprawdź działanie takiej klasy.

* Przerób klasę `Wector2D`{.cpp} tak aby była ona również sparametryzowana ilością składowych:
```cpp
template< class T, int N >
Wector
{
	. . .
};
```

* Sprawdź działanie takiej klasy.







