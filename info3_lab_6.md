---
author: "J. Gałecki"
course: Informatyka III
material: Instrukcja 6
number: 6
---

# REST API

Interfejsy REST (Representational State Transfer) służą do komunikacji między klientem i serwerem przy użyciu protokołu HTTP.
Dane przeważnie (choć nie zawsze) wymieniane są w formacie [JSON](https://en.wikipedia.org/wiki/JSON#Syntax).
Na dzisiejszych zajęciach przećwiczymy interakcję z serwerem przy pomocy tej technologii.

### `curl`

Narzędziem, z którego będziemy korzystać do wysyłania zapytań do serwera będzie [`curl`](https://www.man7.org/linux/man-pages/man1/curl.1.html).
Możemy przetestować jego działanie komendą

```bash
curl 'https://example.com'
```

Powyższe zawołanie powinno wyświetlić kod HTML witryny `example.com`.
Używając przeglądarki zweryfikuj, czy kod zgadza się z wyświetlaną zawartością.

Kilka ciekawych opcji `curl`a to:

- `-I` - wyświetla jedynie nagłówek dokumentu. Przydatne do sprawdzania poprawności zapytań.
- `-v` (verbose) - drukuje kolejne etapy działania `curl`a.

#### Zadanie

Używając opcji `-v` ustal:

- Jaki adres IPv6 ma witryna `example.com`?
- Do kiedy ważny jest certyfikat tej strony?

## Czytanie prognozy pogody

Skoro wiemy już jak uzyskać połączenie z serwerem, możemy teraz spróbować pobrać z niego użyteczne dane.
W celach demonstracyjnych skorzystamy z serwisu [`open-meteo.com`](https://open-meteo.com/), który bezpłatnie (przynajmniej na potrzeby niekomercyjne) udostępnia prognozę pogodny.
Możesz otworzyć serwis w przeglądarce i "wyklikać" bieżącą prognozę.
Sama znajomość URL serwisu nie wystarczy jednak do jego integracji w ramach zautomatyzowanych skryptów, które moglibyśmy chcieć przygotować.
Skrypty oczywiście nie mogą "klikać," ale nawet użycie `curl`a nie rozwiązuje problemu.
Strona musiałaby zwracać całą zawartość bazy danych, którą musielibyśmy ręcznie przeszukiwać.
Takie rozwiązanie byłoby ekstremalnie niewydajne (nie wspominając już nawet o kwestiach bezpieczeństwa).
Wobec tego strona musi wystawiać jakiegoś rodzaju interfejs (API), pozwalający na selektywne odpytywanie w poszukiwaniu konkretnych informacji.
Tę właśnie rolę pełni REST.

Otwórz [dokumentację API serwisu](https://open-meteo.com/en/docs).
Domyślne sugerowane wyszukiwanie dotyczy godzinowej temperatury w Twojej lokalizacji:

```bash
# Uwaga na apostrofy
curl 'https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=temperature_2m'
```

Dane zwracane są w formacie JSON.
Jeżeli chcesz wyświetlić je w nieco bardziej przejrzysty sposób, możesz zpipe'ować wynik do narzędzia `jq`:

```bash
curl [...] | jq
```

Zauważ, że `v1/forecast` to ***endpoint***, wobec którego wysyłamy zapytania.
Mówiąc nieco konkretniej, przy pomocy metod HTTP skierowanych pod odpowiednio skonstruowany URL możemy czytać (a także modyfikować, o czym dalej) stan bazy danych, znajdującej się na serwerze.
Po znaku `?` możemy zadać parametry naszego zapytania (zdefiniowane w dokumentacji), łączone znakiem `&` (taka konstrukcja może wyglądać znajomo, często spotykamy tego typu URL w życiu codziennym).

#### Zadanie

Odczytaj nagłówek (`curl -I`) zwracany przez endpoint.
Co stanie się, jeżeli zrobisz literówkę w URL?
Przypomnij sobie, jakie znasz kody błędów HTTP.

#### Zadanie

Wczytaj się w dokumentację serwisu Open Meteo.
Używając API, odpowiedz na następujące pytania:

- Jaka jest obecnie prędkość wiatru w Warszawie?
- Jaka temperatura odczuwalna będzie jutro o 14:00 w Rzymie?

Jaki kod błędu zostanie zwrócony, jeżeli niepoprawnie skonstruujesz zapytanie?

#### Zadanie

Wejdź na portal `allegro.pl`.
Wyszukaj jakiś produkt (jeżeli nie masz pomysłu możesz np. poszukać doniczek).
Następnie zastosuj wybrany filtr (np. tylko czarne doniczki).
Przyjrzyj się URL, pod jakim wyświetlane jest Twoje zapytanie.
Czy wygląda ono znajomo?

## Praca z bazą danych autorów

Teraz zobaczymy, w jaki sposób można modyfikować zawartość bazy danych poprzez API REST.
W tym celu użyjemy narzędzia `json-server`.
Pozwala ono na postawienie lokalnego serwera w oparciu o jeden plik `db.json`, stanowiący jego bazę danych.
Następnie możemy rozmawiać z serwerem poprzez API REST.
`json-server` będzie modyfikował zawartość pliku `db.json`, którą możemy na bieżąco podglądać (jest to w końcu zwykły plik tekstowy).
