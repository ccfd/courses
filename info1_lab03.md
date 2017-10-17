---
author: "B. Górecki"
course: Informatyka I
material: Instrukcja 3
number: 3
---

Niniejsza instrukcja poświęcona jest trzem zagadnieniom:

- Obsłudze standardowego wejścia i wyjścia,
- Wprowadzeniu do wskaźników,
- Zwracaniu wartości przez funkcje.

# Instrukcje wejścia/wyjścia

Praktyczny program powinien mieć możliwość interaktywnej komunikacji z użytkownikiem.
W celu drukowania informacji często wykorzystywane jest standardowe wyjście (ekran).

## Drukowanie tekstu

Utwórz nowy projekt pakietu MS Visual Studio i napisz program, który wydrukuje tekst *Witaj na trzecim laboratorium!*
```c++
void main() {
   printf("Witaj na trzecim laboratorium!");
}
```
Funkcja `printf()` służy do wypisywania tekstu na ekran.
Jako argument przyjmuje sformatowany strumień tekstowy.
Do formatowania tekstu służą *kody sterujące*, które pozwalają wprowadzić znak nowej linii, tabulacji itp.
Przykładowo, umieszczona wewnątrz tekstu sekwencja znaków:

- `"\n"` -- wprowadza znak nowej linii,
- `"\t"` -- wprowadza znak tabulacji.

### Ćwiczenia
Używając **pojedynczej** funkcji `printf()` oraz odpowiednich kodów sterujących, wygeneruj tekst identyczny z poniższym:
```c++
To jest pierwsze zdanie w mojej instrukcji.
To jest tuz po znaku nowej linii.      Zas ten fragment
                                       oddzielony jest znakiem
                                       tabulacji!
W ponizszej linii wszystkie liczby oddzielono tabulatorami:
5.2    3.14    -7    8
```
**Uwaga:** jeśli instrukcja jest długa, a przez to mało czytelna, warto kontunować ją w nowej linii.
W tym celu należy posłużyć się ukośnikiem wstecznym ,,\\''.
Przykładowo:
```c++
printf("Ta instrukcja kontynuowana jest \
w kolejnej linii\n);
```

Spróbuj osiągnąć ten sam efekt, co powyżej, ale tym razem użyj osobnej instrukcji `printf` dla każdego ze zdań.

W instrukcji `printf()` nie używaj polskich znaków diakrytycznych.
Można to zrobić, jednak ze względu na przenośność w prostych programach nie jest praktykowane.

## Znaki specjalne

Pewne znaki są w języku C zarezerwowane na potrzeby wykonania konkretnych operacji.
Jeśli chcemy je wydrukować na ekran, nie mogą być użyte wprost.
Dobrymi przykładami takich znaków są ,,%'' czy backslash ,,\\''.
Jeśli chcesz, aby pojawiły się na ekranie, musisz poprzedzić je dodatkowym znakiem \\.

Dopisz do swojego programu instrukcję, która wydrukuje następujący tekst:
```c++
82% dysku C:\ jest w uzyciu!
```

## Drukowane liczb

Przepisz do funkcji main następujące instrukcje:
```c++
int a = 5;
double b = 8.2, c = 7.5;

printf("a = %d, b = %lf, c = %lf\n", a, b, c);

c += b;
c -= a;
a = 1;

printf("a = %d, b = %lf, c = %lf\n", a, b, c);
```

Zauważ, że do drukowania wartości przechowywanych w zmiennych służą tzw. *specyfikatory formatu*.
Na zajęciach najczęściej będą używane:

    - %lf --- dla zmiennych typu `double`
    - %d --- dla zmiennych typu `int`
    - %f --- dla zmiennych typu `float`
    - %c --- dla zmiennych typu `char`

### Ćwiczenia

- Dodaj po linijce kodu, który wydrukuje na ekran bieżącą wartość przechowywaną w zmiennych.
Co oznaczają operatory `+=` i `-=`?
- Dla liczb zmiennoprzecinkowych o ekstremalnie małych, umiarkowanych i ogromnych wartościach użyj poniższych sekwencji i zobacz, jaki będzie efekt działania:
    - %lg, %e, %.2lf, %.4lf (dla zmiennych typu `double`),
    - %.3f (dla zmiennych typu `float`).

## Czytanie z klawiatury

Instrukcją służącą do czytania danych ze standardowego wejścia (klawiatury) jest funkcja `scanf()`.
Przykład jej użycia wygląda następująco:
```c++
int a;
scanf("%d", &a);

double c;
scanf("%lf", &c);

int b, d;
double g, h;
scanf("%lf %d %d %lf", &g, &d, &b, &h);
```
**Uwaga:**

- Zwróć szczególną uwagę na znak ,,&'' występujący przed nazwami zmiennych, do których wczytujemy wartości.
Znak ten służy do ustalenia zmiennej występującej za raz po nim.
Funkcja `scanf()` wczytuje dane z klawiatury, które musi gdzieś zapisać.
Stosując znak ,,&'' dostarczamy informacji o tym gdzie znajduje się zmienna, do której należy zapisać wczytaną wartość.
- Zauważ również, że używając pojedynczej instrukcji `scanf` możesz wczytać wiele liczb.
Należy przy tym pamiętać o podaniu specyfikatorów formatu w takiej kolejności jak zmienne na liście argumentów.
Powinno się unikać stosowania innych symboli niż spacje i specyfikatory formatu.
Inaczej należy pamiętać o podaniu liczb razem z tymi dodatkowymi symbolami. 

### Ćwiczenia
Napisz prosty kalkulator, który wczyta z klawiatury dwie liczby typu rzeczywistego i wykona na nich dodawanie, odejmowanie, mnożenie i dzielenie.
Pamiętaj, że odejmowanie i dzielenie nie jest przemienne -- policz zatem każdą z możliwych różnic i ilorazów.
Wydrukuj wszystkie wyniki na ekran.

# Wskaźniki


<--- tutaj będzie tekst o wskaźnikach --->


# Funkcje i zwracanie argumentu

Do tej pory, funkcje deklarowaliśmy i definiowaliśmy w tym samym samym miejscu (przed funkcją `main()`).
W przypadku gdy kod programu jest długi lub ma być wykorzystany przez innego użytkownika rozdziela się deklarację od definicji.
Instrukcja:
```c++
void NazwaFunkcji(int argument1, double argument2);
```
jest deklaracją (zauważ, że kończy się średnikiem).

Instrukcja:
```c++
void NazwaFunkcji(int argument1, double argument2) {
  // Tu znajduje sie cialo funkcji.
}
```
jest definicją i może być umieszczona także za funkcją `main()`.

Funkcje nie tylko grupują pewne logicznie wydzielone bloki instrukcji, których używamy wielokrotnie (jak funkcja rysująca ludzika z kółek i kresek, bądź funkcja rysująca tłum z użyciem funkcji `ludzik`).
Do tej pory ich deklaracje i definicje rozpoczynały się od słowa kluczowego `void`:
```c++
void NazwaFunkcji(int argument1, double argument2);

void NazwaFunkcji(int argument1, double argument2) {
    // Tu sie znajduje cialo funkcji
}
```

Funkcje mogą zwracać także wartość.
Typ zmiennej, jaka jest zwracana znajduje się przed nazwą funkcji.
Nie musi być zgodny z typami argumentów, których typy mogą być zupełnie inne.
Weźmy dla przykładu funkcję, która przyjmie dwie wartości (jedną typu `double`, drugą typu `float`) i zwróci liczbę całkowitą równą 5, gdy większą wartość ma pierwszy argument lub wartość 10 w przeciwnym razie.
Przeanalizujmy odpowiednio deklarację i kod takiej funkcji.
```c++
int KtoryWiekszy(double a, float b);

int KtoryWiekszy(double a, float b) {
   int Wynik;

   if(a > b) {
      Wynik = 5;
   }
   else {
      Wynik = 10;
   }
   return Wynik;
}
```
Zwróć uwagę na instrukcję `return`, która zwraca z funkcji **wartość przechowywaną w konkretnej zmiennej**.
To ważne! Funkcja nigdy nie zwraca zmiennej.
Zwraca tylko wartość, jaka była w tej zmiennej przechowywana.
Ponadto zmienna zadeklarowana w danej funkcji będzie dla programu widoczna **tylko i wyłącznie wewnątrz tej funkcji**, a nie będzie rozpoznawana w innych fragmentach kodu (np. funkcji `main`).
Prześledźmy jeszcze kod funkcji `main()`, w której występuje wywołanie naszej funkcji.
```c++
void main() {
  float c = 8.14;
  double d = -7.3814;
  int InnaZmienna = 15;
 
  KtoryWiekszy(d, c);
  InnaZmienna = KtoryWiekszy(d, c);
  InnaZmienna = KtoryWiekszy(12.5, c);
}
```
Dodaj do powyższego kodu instrukcje, które po każdym wywołaniu funkcji `KtoryWiekszy` wydrukują wartość aktualnie przechowywaną w zmiennej `InnaZmienna`.
Zastanów się, jaki będzie wynik i sprawdź, czy masz rację.

Zmodyfikuj napisany dziś kalkulator tak, aby instrukcje sumowania, odejmowania, mnożenia i dzielenia były realizowane przez osobne funkcje `Sumuj`, `Odejmij`, `Pomnoz` i `Podziel`. Funkcje te musisz napisać samodzielnie.
