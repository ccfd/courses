#PROGRAMOWANIE OBIEKTOWE W C++
#LABORATORIUM 2

##  Zadanie 2
Utwórz klasę Pojemnik służącą do przechowywania obiektów typu `Wektor2D`{.c++}

* Atrybuty tej klasy to dynamiczna tablica typu `Wektor2D *mdata`{.c++} i rozmiar tej tablicy `int msize`{.c++}.

* Utwórz konstruktor domyślny i destruktor.

* Utwórz metodę `Dodaj(const Wektor2D& v)`{.c++} służącą do dodawania elementów do klasy `Pojemnik`{.c++}. Konieczne jest w niej dynamiczne przealokowanie tablicy `mdata`{.c++} (używaj operatorów `new`{.c++} i `delete`{.c++}). Przealokowanie możesz wykonać według następującego schematu:
    * zadeklaruj wskaźnik do tablicy tymczasowej;
    * przydziel niezbędną pamięć;
    * przepisz dane ze starej tablicy;
    * zwolnij pamięć starej tablicy;
    * wstaw nowy element na odpowiednie miejsce w tablicy tymczasowej;
    * przypisz tablicę tymczasową do odpowiedniego wskaźnika obiektu Pojemnik.

* W programie głównym uruchom następujący fragment kodu
```c++
	Pojemnik poj;
	poj.Dodaj( v1 );
	poj.Dodaj( v2 );
	poj.Dodaj( Wektor2D(3,2) );
	poj.Dodaj( Wektor2D(8,4) );
```

* Sprawdź przy pomocy debuggera  zawartość obiektu poj. W oknie watch użyj trzech różnych wpisów:
	* `poj.mdata[0];`{.c++}
	* `poj.mdata;`{.c++}
	* `poj.mdata,4;`{.c++}

## Zadanie 2
Dodaj do klasy Pojemnik metodę `void DrukujWszystko()`{.c++} drukującą zawartość wszystkich obiektów `Wektor2D`{.c++} przechowywanych w tej klasie. Skorzystaj z metody `Drukuj()`{.c++} z klasy `Wektor2D`{.c++}. 

## Zadanie 3
Dodaj do klasy `Pojemnik`{.c++} metodę klasy `Wektor2D`{.c++} `Suma()`{.c++} liczącą sumę wszystkich wektorów przechowywanych w klasie `Pojemnik`{.c++}, korzystającą z operatorów zdefiniowanych dla klasy `Wektor2D`{.c++}. Wynik funkcji wyświetl w programie głównym.

* Spróbuj wywołać liczenie sumy i jej wyświetlanie w taki sposób aby były umieszczone w jednej instrukcji.

## Zadanie 4
Dodaj do klasy `Wektor2D operator <<`{.c++}.

* Operator powinien mieć postać: 
```c++
	void operator<<( ostream& o, const Wektor2D& w )
```
i powinien wykonywać te same operacje co funkcja `Drukuj()`{.c++} klasy `Wektor2D`{.c++}.

* Wyświetl zawartość dowolnego wektora w programie głównym:
```c++
	cout << v1;
```

* Przerób definicję operatora << tak, aby można było wykonać następującą instrukcję:
```c++
cout << v1 << v2;
```

* Dodaj do klasy Pojemnik nową wersję funkcji `DrukujWszystko()`{.c++} (np. `DrukujWszystko2()`{.c++}). Nowa funkcja powinna wykorzystywać `operator <<`{.c++} zamiast funkcji `Drukuj()`{.c++} klasy `Wektor2D`{.c++}. 

##Zadanie 5
Sprawdź na czym polega „dekorowanie nazw” przez kompilator („name mangling”).

* W oknie Solution Explorer zaznacz nazwę projektu. W menu Project powinno pojawić się na samym dole podmenu ***Properties***. 

* W drzewku okna ***Property*** wybierz folder ***linker/debug***. Teraz w polu ***Generate Map File***  wybierz ***Yes (/MAP)***, a poniżel w polu ***Map File Name*** podaj nazwę pliku ****.map***, np.: ***$(OutDir)/Test.map***.

* Przebuduj program i w katalogu ***debug*** projektu odszukaj plik ***Test.map***. 

* Przypatrz się nazwom funkcji wygenerowanym przez kompilator. Czy nawet bez dokładnej wiedzy na temat sposobu generowania tych nazw możesz określić które funkcje należą do których klas? Czy można umieszczać w dwóch różnych klasach funkcje o tych samych nazwach i takich samych parametrach? (Inaczej mówiąc czy linkerowi się one nie pomylą?)
Spróbuj odnaleźć konstruktory i destruktory klas `Wektor2D`{.c++} i `Pojemnik`{.c++}. W jaki sposób linker odróżni konstruktor domyślny (bezparametrowy) od destruktora?

* Na końcu dekorowanych nazw umieszczona jest informacja o parametrach funkcji. Czy na początku nazw metod klasy umieszczona jest informacja o typach zwracanych przez te metody (np. dla funkcji `Pojemnik::Max()`{.c++})? Czym muszą różnic się funkcje przeciążone: czyli funkcje o tych samych nazwach i należących do tej samej klasy?

* Jak myślisz, czy wśród nazw znajdujących się w pliku ****.map*** mogą wystąpić dwie identyczne nazwy funkcji?

## Zadanie 6
Dodaj do klasy Pojemnik funkcję `Max()`{.c++} zwracającą największy wektor. O tym, który wektor jest większy, a który mniejszy, powinna decydować klasa `Wektor2D`{.c++} a nie klasa `Pojemnik`{.c++}. Zatem klasa `Pojemnik`{.c++} powinna posługiwać się odpowiednimi operatorami zdefiniowanymi w klasie `Wektor2D`{.c++}. Zdefiniuj również te operatory. Funkcja `Max()`{.c++} powinna zadziałać w następujący sposób:
```c++
	cout << poj.Max();
```

## Zadanie 7
Zmodyfikuj program tak aby każda klasa była umieszczona w oddzielnym pliku .h i .cpp.

***

```c++
// -------------------------------------------------------------
// deklaracja klasy
class Wektor2D
{
public:
	Wektor2D();
	Wektor2D( const double& xx, const double& yy );
	void operator+=( Wektor2D& v );
	void Drukuj();

private:
	double x;
	double y;
};
// -------------------------------------------------------------
// konstruktor domyślny
Wektor2D::Wektor2D():x(0), y(0)
{
}
// -------------------------------------------------------------
// konstruktor parametrowy
Wektor2D::Wektor2D( const double& xx, const double& yy ):x(xx), y(yy) 
{
}
// -------------------------------------------------------------
// operator +=
void Wektor2D::operator+=( Wektor2D& v )
{
	x += v.x;
	y += v.y;
}
// ----------------------------------
// drukowanie wartości składowych klasy
void Wektor2D::Drukuj()
{
	cout.setf( ios::fixed );
	cout << "wektor: [";
	cout.precision(3);
   //   . . . 
  
  //	. . . 
  cout.width(6);
  cout << x << ",";
  cout.precision(4);
  cout.width(7);
  cout << y << "]" << endl;
}
```