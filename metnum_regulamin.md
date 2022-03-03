---
number: 0
course: Metody Numeryczne
material: Regulamin
---

# Regulamin przedmiotu Metody Numeryczne

Przedmiot składa się z 15 h wykładów oraz 7 h spotkań laboratoryjnych (po 1,5 h). 

## Punktacja

- Kolokwium zaliczeniowe na zakończenie wykładów (60 pkt.).
- Wejściówki na 6 laboratoriach (6 x 5 pkt. = 30 pkt.).
**Uwaga:** Na pierwszych laboratoriach przeprowadzona będzie wejściówka z języka C.
- Nieobowiązkowy projekt (10 pkt.).

## Zaliczenie

Warunkiem zaliczenia jest uzyskanie >=30 punktów z kolokwium wykładowego i uzyskanie >15 punktów z laboratorium.
Suma punktów z wykładu i laboratorium musi być >50 punktów.

### Skala ocen:

    <= 50 pkt. -> 2
     > 50 pkt. -> 3
     > 60 pkt. -> 3,5
     > 70 pkt. -> 4
     > 80 pkt. -> 4,5
     > 90 pkt. -> 5

Tematy projektów będą proponowane w trakcie semestru przez prowadzących laboratoria.
Ocenie podlegać będzie zrozumienie przez studenta zagadnienia oraz kodu programu a także umiejętność jego zmodyfikowania podczas oddawania projektu.

### Wejściówka z języka C na pierwszych zajęciach:

Ważne zagadnienia podlegające sprawdzeniu podczas wejściówki to:

- składnia funkcji,
- zwracanie wyniku działania funkcji przez jej wartość,
- "zwracanie" wybranych rezultatów działania funkcji wykorzystując wskaźniki będące jej argumentami,
- dynamiczna alokacja, wypełnianie oraz zwalnianie tablic,
- składnia pętli `for`,
- zapisywanie i odczytywanie danych liczbowych z pliku.

#### Przykładowe zadanie na wejściówkę:

Napisz program, który w funkcji `main` wczyta z klawiatury liczbę typu całkowitego, zaalokuje w pamięci komputera jednowymiarową tablicę o takim rozmiarze i przekaże ją jako argument do funkcji `wypelnij`.
Funkcja `wypelnij` wypełni tablicę wyrazami ciągu arytmetycznego $(1, 4, 7, \ldots)$, iloczyn tych wyrazów zwróci przez wskaźnik do funkcji `main`, a ich sumę zwróci do funkcji `main` jako wartość zwracaną funkcji `wypelnij`.
Funkcja `main` zapisze obie wartości (obliczoną sumę i iloczyn) do pliku, zamknie plik i zwolni miejsce w pamięci zaalokowane na tablicę.
Niedozwolone jest korzystanie z jakichkolwiek notatek, urządzeń elektronicznych i podobnych materiałów.

**Czas wykonania:** 10 minut.
