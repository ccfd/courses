---
number: 2
course: Informatyka I
material: Instrukcja 2 i 3
author: Ł. Łaniewski-Wołłk
---


# BASH: skrypty
Pisanie skryptów, polega na spisaniu w pliku komend, które normalnie wpisywalibyśmy w linii poleceń. Taki plik możemy następnie oznaczyć jako wykonywalny komendą `chmod +x plik`{.bash} i wykonać komendą `./plik`{.bash} . Linia poleceń (BASH) służy do uruchomiania programów - dlatego: **każda linijka skryptu wygląda nastepująco:** `program agumenty`.

Przeanalizuj fragment kodu, z zaznaczonymi `programami` i `opcjami`:
```Bash
i=1
while test $i -lt 10
do
	echo $i
	cp plik plik_$i
	i=$(expr $i + 1)
done
```

Gdy zapamiętamy tą zasadę, łatwo zobaczyć, że:

- `i=1` piszemy bez spacji ponieważ wtedy BASH wie, że to przypisanie, a nie program `i` z opcjami `=` i `1`. 
- w wyrażeniu `expr $i + 1`, musimy zachować spacje, żeby program `expr` dostał trzy argumenty `$i`, `+` i `1`, a nie jeden `i+1`.
- w pętli `while`, nie możemy wpisać ,,`i<10`'', lecz musimy użyć jakiegoś programu. Do wszelkiego rodzaju testów stwożony został program `test`. W tym wypadku podajemy mu za argumenty `$i`, `-lt` i `10`, gdzie opcja `-lt` oznacza ''less than''.

probka `mkdir`{.cpp}

probka2 `mkdir`{.sh}

probka3 `mkdir`{.bash}

## Przydatne programy
Jeśli już wiemy, że każdy skrypt w BASH to seria wywołanych programów, to potrzebne jest nam dużo małych programów, z których będziemy mogli tworzyć skrypty.

- komendą `chmod +x plik`{.bash} i wykonać  - test
- `echo tekst`{.bash} --- Wypisuje tekst na ekran.
- `cat plik`{.bash} --- Wypisuje zawartość pliku na ekran
- `grep tekst`{.bash} --- Czyta z klawiatury tekst i wypisuje tylko linie zawierające tekst
- `grep tekst pliki`{.bash} --- Wyszukuje tekst w plikach
- `cd katalog`{.bash} --- Wchodzi do katalogu
- `ls katalog`{.bash} --- Wypisuje zawartość katalogu na ekran
- `cp pliki katalog`{.bash} --- Kopiuje pliki do katalogu
- `cp plik1 plik2`{.bash} --- Kopiuje plik o nazwie plik1 do pliku o nazwie plik2
- `mv pliki katalog`{.bash} --- Przenosi pliki do katalogu
- `mvplik1 plik2`{.bash} --- Zmienia nazwę pliku z plik1 na plik2
- `sed  's/tekst1/tekst2/g'`{.bash}--- Czyta z klawiatury tekst i go wypisuje zamieniając ''tekst1'' na ''tekst2''


## Przekierowanie wejścia wyjścia
Standardowo wszystkie programy czytają z klawiatury i piszą na ekran. Można jednak zarówno pierwsze jak i drugie przekierować.

- `program > plik`{.bash} --- To co program wypisałby na ekran, zostanie wpisane do pliku (plik zostanie nadpisany jeśli istnieje)
- `program >> plik`{.bash} --- To co program wypisałby na ekran, zostanie dopisane do pliku (plik zostanie utwożony jeśli nie istniał)
- `program < plik`{.bash} --- Program dostanie zawartość pliku, tak jakbyśmy ją wpisali z klawiatury
- `program1 | program2`{.bash} --- To co program1 wypisałby na ekran, zostanie wpisane 'z klawiatury' do program2
- `program` lub `$(program)`{.bash} --- To co program wypisałby na ekran, zostanie wklejone w tym miejscu kodu (patrz przykłady). Znak '\`' jest na klawiaturze przy tyldzie '~'.

Przykłady:

- `echo Tekst > plik`{.bash} --- wypisze ,,Tekst'' do pliku (plik zostanie nadpisany jeśli istnieje)
- `echo Tekst  >> plik`{.bash} --- dopisze ,,Tekst'' do pliku (plik zostanie utwożony jeśli nie istniał)
- `grep Tekst  < plik`{.bash} --- wyszuka w pliku linie zwierające ,,Tekst'' i je wypisze na ekran
- `echo Tekst |` sed 's/st/a/g'`{.bash} --- Zamieni w ,,Tekst'' każde wystąpienie ,,st'' na ,,a''. Więc wypisze na ekran ,,Teka''.
- `echo \$nazwa |` sed 's/\.txt/.dat/g'`{.bash} --- Zastąpi w zmiennej `nazwa` końcówkę `.txt` na `.dat`. Rezultat wypisze na ekran.
- `echo \$nazwa |` sed 's/\.txt/.dat/g'`{.bash} --- Zastąpi w zmiennej `nazwa` końcówkę `.txt` na `.dat`. Rezultat wypisze na ekran.
- `nazwa2={\blue \$(`echo \$nazwa {\blue |} sed 's/\.txt/.dat/g'{\blue )}} --- Jak poprzednio, lecz \uline{rezultat wypisze do zmiennej} `nazwa2`.
- `ls katalog {\blue > plik`} --- wypisze zawartość {\green katalog}u do {\blue plik}u ({\blue plik} zostanie nadpisany jeśli istnieje)
- `cp {\blue ``ls{\blue `} katalog} albo `cp {\blue \$(`ls{\blue )} katalog} --- skopiuje pliki do `katalog`u według listy zwróconej przez `ls`.
- `cp {\blue ``cat plik{\blue `} katalog} bądz `cp {\blue \$(`cat plik{\blue )} katalog} --- skopiuje pliki do `katalog`u według listy zawartej w `plik`u.



## Pętle i wyrażenia warunkowe
- `if _program_ {\green argumenty`\\
then\\
_polecenia1_\\
else\\
_polecenia2_\\
fi}\\
Jeśli wykonanie ,,_program_ {\green argumenty}'' się powiedzie (program zwróci $0$), to wykonane zostaną _polecenia1_. W przeciwnym wypadku wykonane zostaną _polecenia2_.
- `while _program_ {\green argumenty`\\
do\\
_polecenia_\\
done}\\
Pętla, która będzie wykonywać _polecenia_, puki ,,_program_ {\green argumenty}'' będzie wykonywany z powodzeniem.
- `for i in {\green lista`\\
do\\
_polecenia_\\
done}\\
Pętla, która po kolei każdy element {\green list}y wstawi do zmiennej `i`, a następnie wykona _polecenia_.

Dla przykładu:\\
`for i in {\green *.jpg`\\
do\\
_mv_ {\green \$i IMG/a\_\$i} \\
done}\\
Przeniesie każdy plik o końcówce `.jpg`, do katalogu `IMG` dodając im przedrostek `a\_` (np.: `obrazek.jpg` zamieni na `IMG/a\_obrazek.jpg`).


## Ćwiczenia

Domyślnym edytorem na serwerze `info3 ` jest edytor `nano `, dostępny jest teś edytor `vim `. Pierwszy z nich wydaje się prostszy w obsłudze, drugi występuje na prawie każdym komputerze z UNIXem.

	- Przy pomocy pętli wypisz na ekran liczby od 0 do 10
	- Zmień skrypt, tak aby wypisywał od 0 do podanej jako argument wielkości



# Obróbka obrazków

## `convert`
Głównym programem którego będziemy używać to `convert` z biblioteki ImageMagick. Program ten służy do najróżniejszego typu konwersji i zmiany właściwości obrazów --- lecz potrafi także dodawać elementy do obrazu, a nawet tworzyć obrazy od zera. Najłatwiej zobaczyć jego użycie na przykładach:

**UWAGA: Zanim zaczniesz, skopiuj katalog ze zdjęciami do jakiegoś tymczasowego katalogu!**

- `convert plik.gif plik.jpg` --- przekonwertuje plik w formacie GIF na format JPEG
- `convert plik1.jpg -resize 50% plik2.jpg` --- zmniejszy obrazek dwukrotnie
- `convert plik1.jpg -resize 100 plik2.jpg` --- zmniejszy obrazek, tak by krótszy wymiar był 100 pikseli
- `convert plik1.jpg -resize 100x100 plik2.jpg` --- zmniejszy obrazek tak, by mieścił się w kwadracie 100 na 100 pikseli
- `convert plik1.jpg -resize 100x100\! plik2.jpg` --- zmniejszy obrazek \uline{dokładnie} do rozmiaru 100 na 100 pixeli
- `convert -size 320x85 canvas:none -font Bookman-DemiItalic -pointsize 72 -draw "text 25,60 'Magick'"{ `-channel RGBA -blur 0x6 -fill darkred -stroke magenta -draw "text 20,55 'Magick'"{ }fuzzy-magick.jpg} --- stworzy obrazek fuzzy-magick.jpg, z tekstem "Magick"
Wykonaj powyższe operacja, sprawdź efekty.



## Ćwiczenia
Napisz skrypt który:

- Zmniejszy wszystkie pliki `jpg`
- Napisz skrypt który: Zmniejszy wszystkie pliki `jpg` umieszczając je w innym katalogu
- Napisz skrypt który: Skonwertuje wszystkie pliki `jpg` na `gif`, dodając końcówkę: `plik.jpg $\rightarrow$ plik.jpg.gif`
- Napisz skrypt który: Skonwertuje wszystkie pliki `jpg` na `gif`, zamieniając końcówkę `plik.jpg $\rightarrow$ plik.gif`
- Na każde zdjęcie naniesie tekst używając `-pointsize {\green rozmiar` -draw "{}text {\green x},{\green y} '{\green Tekst}'"{}}
- Na każde zdjęcie naniesie aktualną datę (komenda `date`)
- Na każde zdjęcie naniesie datę utworzenia tego zdjęcia (można ją wyciągnąć przy pomocy `stat -c %y plik`)
- Zmniejszy wszystkie obrazki z katalogu `drop1` i połączy je w animację przy pomocy `convert *.jpg animacja.gif`


