---
author:
- M. Dzikowski
- rev. K. Marchlewski
- rev. J. Gałecki
course: Informatyka III
material: Instrukcja 1
number: 1
---

# Podstawy pracy z systemem UNIX

Większość współczesnych komputerów (i podobnych urządzeń np. tabletów i telefonów) wyposażonych jest w system operacyjny oraz towarzyszące mu oprogramowanie.
Z całą pewnością korzystałeś/aś z systemów operacyjnych firmy Microsoft -- rodziny Windows.
Mogłeś/aś też zetknąć się z systemem Android (czyli odmianą Uniksa) od Google czy iOS od Apple.
W większości przypadków system posiada tzw. interfejs graficzny, czyli GUI (Graphical User Interface).
Systemy te są zasadniczo podobne i np. uruchomienie przeglądarki internetowej czy przeglądanie plików nie jest dla nikogo wyzwaniem.

Jednak nie każdy komputer posiada GUI, dotyczy to np. rozbudowanych komputerów wykorzystywanych w obliczeniach numerycznych (np. wyznaczanie właściwości aerodynamicznych samochodu z użyciem programu Fluent).
W takim przypadku nie ma możliwości skorzystania z myszki i obejrzenia czegoś na ekranie, ponieważ komputer znajduje się w serwerowni, czasami w innym kraju.
Aby korzystać z takiego zdalnego komputera musimy połączyć się z nim za pomocą specjalnego programu, który pozwoli nam na wydawanie mu polecenia w trybie tekstowym.
Tryb tekstowy posiada m.in. następujące zalety:

- pozwala na automatyzację poprzez pisanie skryptów
- pozawala na szybszą pracę (przynajmniej po osiągnięciu pewnego poziomu biegłości)
- jest dużo bardziej ustandaryzowany - przesiadając się na inną odmianę systemu operacyjnego nie musimy uczyć się od nowa położeń menu, konfiguracji ustawień, etc.

# Ćwiczenia

Uruchom komputer wybierając system operacyjny Linux (Ubuntu).
Jeśli pracujesz na własnym komputerze z systemem Windows, możesz zainstalować Linux jako podsystem, patrz [https://learn.microsoft.com/en-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install).
Następnie uruchom terminal nawigując z menu głównego lub poprzez skrót klawiszowy `Ctrl + Alt + T` (`T` jak terminal).
Zobaczysz linijkę podobną do:
```
stud@lab:~$
```

Jest to tzw. znak zachęty i oznacza, że jako użytkownik `stud` jesteśmy zalogowani na komputer `lab`.
Między znakami `:` i `$` znajduje się katalog, w którym się aktualnie znajdujemy.
W tym przypadku jesteśmy katalogu domowym.
Znak `~` to skrót, którego rozwinięcie to `/home/stud`.

## Pierwsze starcie

Wpisz w konsoli polecenie `date` i wciśnij enter.
Komputer wyświetli aktualną (jego zdaniem) datę i godzinę.
Poniżej ponownie wyświetli się linijka kończącą się na `$`, oznaczającą, że komputer czeka na nowe polecenia.
Używając strzałek `góra` i `dół` możesz przeglądać historię poleceń.
Wciśnięcie klawiszy `Ctrl + R` uruchomi opcję wyszukiwania poleceń w historii.
Klasyczny znak zachęty zostanie zastąpiony przez
```bash
(reverse-i-search)`':
```

Wyszukujemy przez wpisywanie kolejnych znaków z szukanego polecenia, a po dwukropku system pokaże podpowiedź.
Kolejne wciśnięcie `Ctrl + R` pokaże nastęþną sugestię.
Innym ułatwieniem jest dopełnianie nazw.
Jeśli wpiszesz `dat` i naciśniesz 2x klawisz `Tab`, wyświetlona zostanie lista poleceń zaczynających się na `dat`.
Jeśli jest tylko jedno takie polecenie, nazwa zostanie dokończona.
Pamiętaj o tych trikach -- znacznie ułatwiają pracę w trybie tekstowym.

## Poruszanie się po katalogach

Pracując w trybie tekstowym, zawsze pracujemy w jakimś katalogu, tzw. katalogu bieżącym.
Jeśli uruchomimy jakiś program, np. prosty program czytający dane z pliku z Informatyki I, będzie on odczytywał pliki znajdujące się w tym katalogu.
Każdy program, którego będziesz używać, a który potrzebuje nazwy pliku lub katalogu (np. do kopiowania), może ją otrzymać w dwóch postaciach.
Pierwsza to tzw. ścieżka bezwzględna, zaczynająca się od znaku `/` np:
```
/home/students/stud01
/usr/bin/bash
/etc
```

Sprawdź, w jakim katalogu się znajdujesz przez wpisanie polecenia `pwd` (od *print working directory*).

Aby zmienić katalog, wykorzystuje się polecenie `cd` (od *change directory*), np.
```
stud01@eto:~$ cd /tmp
stud01@eto:/tmp$ pwd
/tmp
stud01@eto:~$
```

Teraz przejdź do katalogu `/home` i sprawdź czy się udało, z użyciem polecenia `pwd`.
Aby powrócić do katalogu domowego wpisz
```
stud01@eto:~$ cd ~
```
Znak $\sim$ zawsze oznacza katalog domowy użytkownika.

Dodatkowo, oprócz ścieżki bezwzględnej, można podać ścieżkę względną:

- `../` oznacza katalog nadrzędny,
- `/` oznacza katalog główny (początek każdej ścieżki bezwzględnej),
- `.` i `./` oznaczają katalog bieżący (ten zwracany przez polecenie `pwd`).

Poeksperymentuj teraz z poruszaniem się po katalogach.
Jeśli wpisywanie ścieżek Cię znudzi wypróbuj program `mc`.
Pozwala on m. in. na graficzne poruszanie się po drzewie katalogów.
Z programu wychodzimy przez wciśnięcie klawisza `F10` lub wpisanie `exit`.

## Tworzenie i usuwanie katalogów

Do tworzenia katalogów służy polecenie `mkdir` (od *make directory*) np.
```bash
$ mkdir nazwa_katalogu
```

Do sprawdzenia zawartości aktualnego katalogu polecenie `ls` (od *list*).
Stwórz teraz katalogi A, B, C i D, każdy wewnątrz poprzedniego.
Aby to zrobić będziesz musiał stworzyć katalog A, przejść do niego, następnie stworzyć B, itd.
Do usuwania katalogów służy polecenie `rmdir` (od *remove directory*).
Usuń teraz stworzone katalogi.

Za pomocą `rmdir` nie można usunąć katalogu posiadającego zawartość.
W tym celu należy wykorzystać polecenie `rm -r`.
Znaki `-r` po nazwie programu `rm` są argumentem programu i oznaczają, że katalog ma być usuwany rekurencyjne.
Podobne argumenty posiada większość poleceń, np. `ls -l` pokazuje zawartość danego katalogu w postaci listy zawierającej różne informacje o pliku.

# Podstawowe operacja na plikach i katalogach
Komenda `echo` wypisuje na ekran ciąg znaków, który podany jest jako jej argument.
Można to wykorzystać do stworzenia pierwszego pliku (o znaczeniu symbolu `>` powiemy więcej na kolejnych zajęciach)
```bash
$ echo pierwszy plik > plik.txt
```

Aby wyświetlić zawartość pliku na ekranie używamy polecenia `cat`
```bash
$ cat plik.txt
```

## Kopiowanie i przenoszenie

Do kopiowania służy komenda `cp [SKĄD] [DOKĄD]`.
Stwórz teraz katalog i skopiuj do niego Twój plik.
Powinno to wyglądać tak:
```bash
$ cp plik.txt katalog
```

Aby przenieść/zmienić nazwę pliku lub katalogu używamy polecenia `mv [SKĄD] [DOKĄD]`.
Przejdź do nowego katalogu i zmień nazwę pliku.
Następnie usuń plik poleceniem `rm`.

Nie zawsze trzeba podawać pełną nazwę pliku/katalogu, który chcemy wykorzystać jako argument programu.
Wciśnięcie klawisza `Tab` dokończy wpisywaną nazwę.
Jeśli podpowiedź nie jest jednoznaczna, po dwukrotnym naciśnięciu klawisza `Tab` w konsoli zostaną wyświetlone nazwy wszystkich plików/katalogów zaczynające się od wpisanych znaków.

# Pomoc

Znakomita większość komend trybu tekstowego posiada porządną dokumentację dostępną od ręki, np.:
```bash
$ man rm
$ rm --help
```
W przypadku komendy `man` dostajemy obszerniejszą dokumentację.
Tekst przewija się za pomocą strzałek.
Aby zakończyć przeglądanie należy wcisnąć `Q`.
Sprawdź instrukcje dla poleceń `who`, `whoami`, `head` i `date`.
Sprawdź jak działają.

# Program `tar`

Program `tar` służy do pakowania i rozpakowywania drzewa katalogów i plików w jeden plik (archiwum).
Plik wynikowy niekoniecznie musi być mniejszy niż oryginalne pliki.
Dopiero użycie kompresji zmniejszy rozmiar.
Przygotuj najpierw kilka plików do spakowania:
```bash
$ mkdir a
$ cd a
$ mkdir b
$ echo asdasd > ./b/c
$ cat ./b/c
asdasd
```

Teraz spakuj je, a następnie obejrzyj zawartość archiwum za pomocą programu `mc`.
```bash
$ tar -cf test.tar b
$ ls
b  test.tar
$ mc
```

Sprawdź zawartość spakowanego katalogu, następnie usuń go i rozpakuj archiwum.
```bash
$ ls
b  test.tar
$ rm -r b
$ ls
test.tar
$ tar -xf test.tar
$ ls
b  test.tar
```

Sprawdź poleceniem `ls -lah` objętość utworzonego archiwum.
Następnie spakuj te same pliki z dodatkową flagą `z`.
Dodanie tego parametru uruchamia kompresję programem `gzip`.
Zmień rozszerzenie archiwum na `tar.gz`.
Sprawdź czy plik wynikowy jest mniejszy.

# Proste skrypty

Najważniejszym aspektem pracy w trybie tekstowym jest możliwość tworzenia skryptów, czyli zapisanych w pliku kolejnych komend wykonywanych tak, jakbyśmy wpisywali je z klawiatury.
Więcej o zaawansowanych skryptach dowiesz się na następnych laboratoriach, pierwszy napiszesz dzisiaj.

Prostymi i dość wygodnymi edytorami tekstu są `nano` i `vim`.
Uruchom program `nano` komendą `nano skrypt.sh` i zapisz do niego pierwszy skrypt:
```bash
#!/bin/bash
echo 1
echo 2
```

Następnie zmień uprawnienia, aby pozwolić na uruchomienie naszego skryptu: 
```bash
$ chmod u+x skrypt.sh
$ ./skrypt.sh
```

Polecenie `chmod` służy do zmiany uprawnień pliku.
`u` oznacza użytkownika (czyli Ciebie), któremu chcemy nadać (`+`) prawo uruchamiania (`x`, od *execute*) skryptów/programów.

## Zmienne

Bash obsługuje zmienne, tak jak każdy język programowania
Nie występuje tu jednak typowanie.
Aby stworzyć zmienną zawierającą tekst piszemy:
```bash
zmienna="Tekst"
```

Natomiast wynik działania jakiegoś programu (tzn. wydrukowany przez niego tekst) możemy zapisać do zmiennej w następujący sposób:
```bash
zmienna=$( pwd )
```

Aby odczytać zmienną piszemy:
```bash
echo $zmienna
```

## Drugi skrypt

Przygotuj strukturę katalogów:

 - AA
   - BB
     - plik.txt
   - CC
     - DD
     - plik.txt

zawierając niezbędne komendy w skrypcie. Plik `plik.txt` ma zawierać datę zwracaną przez polecenie `date`.

Zmodyfikuj skrypt tak, aby nazwa każdego katalogu zaczynała się przedrostkiem przekazanym do skryptu przy jego uruchomieniu.

 - przed_AA
   - przed_BB
     - plik.txt
   - przed_CC
     - przed_DD
     - plik.txt

Abu uruchomić skrypt wraz z dwoma argumentami `arg1` i `arg2` należy wpisać
```bash
./skrypt.sh arg1 arg2
```

Do argumentów `arg1` i `arg2` mamy dostęp z wewnątrz skryptu dzięki tzw. zmiennym programowym.
Jest ich dziewięć `$1` -- `$9`, w tym przypadku będą to zmienne `$1` i `$2`.

## Pętle

Przygotuj skrypt zawierający:
```bash
#!/bin/bash

for i in *.txt
do
  cp $i $1_$i
done
```

i uruchom go w katalogu zawierającym pliki z rozszerzeniem `.txt`.
W jaki sposób działa?
Pamiętaj o argumencie skryptu!

Napisz skrypt, który tworzy katalog o nazwie podanej jako pierwszy argument skryptu `$1` i kopiuje do niego wszystkie pliki `.txt` dodając do ich nazwy przedrostek podany jako drugi argument `$2`.
Co się stanie jeśli nie podasz argumentów do skryptu?

# Na deser: piszemy własne narzędzie

Narzędzia, które wykorzystalywaliśmy powyżej nie są w żaden sposób "magiczne", możemy napisać własne.
W tym celu zademonstrujemy jak skompilować i uruchomić proste programy w języku C.

**Uwaga:** jeśli chcesz korzystać z C++, nie C, w poniższych poleceniach zamień `gcc` na `g++` (możesz też zmienić rozszerzenia plików na `.cpp`, ale na Linuxie rozszerzenia nie mają znaczenia).

## `Hello, World!` z konsoli

Utwórz plik źródłowy `helloworld.cc` o zawartości
```c++
#include <stdio.h>
int main() {
  printf("Hello, World!\n");
}
```

Następnie skompiluj go używając kompilatora `gcc`:
```bash
gcc -o helloworld.x helloworld.cc
```

Zauważ, że w bieżącym katalogu pojawił się plik `helloworld.x` (gdybyśmy nie podali opcji `-o`, domyślna nazwa to `a.out`).
Uruchom go wołając `./helloworld.x`.

## Przyjmujemy argumenty

Naturalnie nasuwa się pytanie, skąd program wie, jakie argumenty zostały do niego podane?
W językach C i C++ funkcja `main` może przyjmować 2 argumenty:

- pierwszy typu `int`, zawierający liczbę podanych argumentów plus 1, zwyczajowo nazywany `argc`, od *argument count*
- drugi typu `char**`, zawierający tablicę stringów reprezentujących argumenty, zwyczajowo nazywany `argv`, od *argument values*. Pierwszy element tablicy zawiera nazwę wywołanego programu (stąd `argc` jest o jeden większe)

Przykładowo, program drukujący argumenty może wyglądać następująco:
```c++
#include <stdio.h>
int main(int argc, char** argv) {
  for(int i = 1; i != argc; ++i)
    printf("%s\n", argv[i]);
}
```

Skompiluj powyższy program i zobacz co wydrukuje, gdy podasz do niego argumenty, np. `-a -b -c`.
Porównaj co stanie się, gdy umieścisz argumenty w cudzysłowie.
