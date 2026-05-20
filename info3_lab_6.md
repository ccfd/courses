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
Możesz otworzyć serwis w przeglądarce i np. "wyklikać" bieżącą prognozę.
Sama znajomość URL serwisu nie wystarczy jednak do jego integracji w ramach zautomatyzowanych skryptów, które moglibyśmy chcieć przygotować.
Skrypty oczywiście nie mogą "klikać," ale nawet użycie `curl`a
