#PROGRAMOWANIE OBIEKTOWE W C++
#LABORATORIUM 1

## Zadanie 1

Utwórz klasę `Wektor2D`{.cpp} będącą implementacją wektorów w przestrzeni 2D. Program pisz drobnymi krokami. Utwórz najpierw pustą klasę bez funkcji i bez zmiennych składowych. Utwórz obiekt tej klasy w funkcji `main()`{.c++}. Skompiluj i uruchom program. Dopiero teraz dodawaj kolejne elementy klasy kompilując program jak najczęściej. 

* atrybuty klasy to 2 zmienne typu double opisujące współrzędne wektora umieszczone w sekcji `private`{.c++}.

* utwórz konstruktory:
    * defaultowy: `Wektor2D()`{.c++}
    * parametrowy: `Wektor2D(const double& xx, const double& yy)`{.c++}
(W jednym z konstruktorów użyj listy inicjalizacyjnej.)
 
* Utwórz metodę `Drukuj()`{.c++} służącą do drukowania zawartości klasy na ekranie w formacie:   
**wektor [ 2.345, 4.5678]**

* W funkcji `main()`{.c++} wykorzystaj klasę `Wektor2D`{.c++} np.:
```c++
	int main()
	{
		Wektor2D v1(10,20);
		Wektor2D v2 = v1;
		Wektor2D v3(v1);
		Wektor2D v4;
		v1.Drukuj();
		v2.Drukuj();
		v3.Drukuj();
		v4.Drukuj();
		
		return 0;
	}
```
* Wewnątrz konstruktorów drukuj informację o rodzaju właśnie wywoływanego konstruktora i wartościach składowych klasy.

* Przy pomocy debuggera prześledź wartość składowej `x`{.c++} w poszczególnych funkcjach:
    * Postaw breakpoint na pierwszej linii kodu (*F9*).
    * Uruchom program w sesji debuggera (*F5*).
    * Po zatrzymaniu programu na "breakpoincie" wprowadź w oknie "watch" debuggera nazwę składowej klasy którą chcesz śledzić (np. `x`{.c++}).
    * Wykonaj program etapami: 
        * przechodząc do następnej linii kodu (*F10*);
        * lub wchodząc do środka funkcji (*F11*).
	
	Odpowiedz sobie na następujące pytania:
	- Ile obiektów utworzyłeś w programie?
	- Ile konstruktorów zdefiniowałeś w klasie?
	- Do ilu konstruktorów udało Ci się wejść przy pomocy debuggera?
	- Które konstruktory kompilator utworzył automatycznie?

* Dodaj do klasy konstruktor kopiujący: `Wektor2D(const Wektor2D& v)`{.c++} i powtórz doświadczenie z debuggerem.

* Dodaj do klasy destruktor. Wewnątrz destruktora umieść informacje identyfikujące obiekt który właśnie jest usuwany (np. wyświetlaj wartości składowych klasy).

## Zadanie 2
Rozszerz klasę o obsługę wybranych operatorów.

* Utwórz operatory:
     * Jednoargumentowy  `operator +=`{.c++}
     * Dwuargumentowy `operator+`{.c++} (sprawdź czy możesz operować na atrybutach klasy `Wektor2D`{.c++} bez definiowania zaprzyjaźnienia z tą klasą)

* Dodaj i przetestuj w programie głównym następujące operacje:
```c++
	v4 = v1 + v2;
	v4.Drukuj();
	v3 += v3;
	v3.Drukuj();
```
## Zadanie 3
Hermetyzacja i udostępnianie składowych klasy.

* Sprawdź czy możesz wykonać następującą operację w programie głównym:
```c++
	v4.x = 50;
```

* Dodaj do klasy funkcję `SetX(const double& xx )`{.c++} pozwalającą na zmianę składowej klasy `x`{.c++}. Ogranicz wartość tej zmiennej do `MAX_VAL = 100`{.c++}. Przekroczenie wartości `MAX_VAL`{.c++} powinno kończyć program.

* Dodaj do klasy funkcje `GetX()`{.c++} zwracającą wartość składowej `x`{.c++}.

* Dodaj analogiczne funkcje dla składowej `y`{.c++} i wykonaj następujący fragment kodu w programie głównym
```c++
	v4.SetX(50);
	v4.Drukuj();
	Wektor2D v5( v4.GetY(), v3.GetX() );
	v5.Drukuj();
```

## Zadanie 4
Zmienne statyczne klasy.
* Dodaj do klasy prywatną składową statyczną `indx`{.c++}. Zmienna ta powinna nadawać kolejne numery tworzonym obiektom. Zmienna taka musi być zainicjalizowana poza klasą w następujący sposób:
```c++
	int Wekro2D::indx = 0;
```
* Dodaj do klasy prywatną składową `nr`{.c++}. Składowa ta ma przechowywać kolejny numer obiektu (począwszy od 1). Inicjalizuj ją przy pomocy składowej `indx`{.c++} w każdym dostępnym konstruktorze jednocześnie zwiększając wartość składowej `indx`{.c++}.

* Wartość zmiennej `nr`{.c++} wyświetlaj zarówno w konstruktorach jak i w destruktorze.

* Uruchom program i przeanalizuj jeszcze raz kolejność tworzenia się i usuwania obiektów. 
     * Zwróć szczególną uwagę na moment konstrukcji i destrukcji obiektów o ***nr = 5*** i ***nr = 6***.
     * Jak zmieni się liczba tworzonych obiektów jeśli konstruktor kopiujący zmienisz na następujący: `Wektor2D(const Wektor2D v)`{.c++} (czyli bez referencji).
     * Jak wytłumaczysz, że przy destrukcji obiektów nigdzie nie pojawia się wartość ***nr = 4?*** 

* Dodaj do klasy odpowiednio zdefiniowany operator przypisania(=). Czy teraz, w trakcie usuwania obiektów, widać już wartość ***nr = 4*** ?

## Zadanie 5
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp.


