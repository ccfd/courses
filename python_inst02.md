---
number: 2
course: Python
material: Wymagania
author: W. Gryglas
---
# Git - aktualizacja kopii repozytorium

# Wprowadzenie

## Komentarze

Jednym z najczęściej używanych elementów każdego języka są komentarze, które pozwalają na chwilowe wyłączenie kodu bądź dodanie notatki na temat danej instrukcji. W języku python w odróżnieniu od C/C++ komentować można tylko linię za pomocą znaku ***#***

```python
# To jest komnentarz, a poniżej zwykły kod
a = 5
```

Jeśli chcemy dodać komentarz do kilku linii tekstu to niestety należy znak ***#*** umieścić na początku każdej z linii:
```python
# linia 1 komentarza
# linia 2 komentarza
a = 5
```
Może być to mało wygodne, jednak w praktyce, gdy korzystamy ze środowiska graficznego PyCharm wystarczy posłużyć się odpowiednim skrótem klawiszowym. Na przykład, gdy chcemy zamienić linijkę w której znajduje się nasz kursor to wystarczy wcisnąć na klawiaturze kombinację  ***CTRL + /***

![komentarz_linia]( resources/python_inst02/comment_line.png "Komentowanie 1  linii w PyCharm") 

Z kolei jeśli chcemy zamienić blok kodu na komentarz to należy go zaznaczyć a następnie ponownie skorzystać z kombinacji ***CTRL + /***

![komentarz_blok]( resources/python_inst02/comment_block.png "Komentowanie bloku tekstu w PyCharm") 

Oprócz zwykłych komentarzy specyfikacja języka python przewiduje dodatkowy rodzaj komentarza, który jest automatycznie uznawany za dokumentację. Tekst dokumentacji powinien znaleźć się w pomiędzy znacznikami początku i końca. Jako znaczniki stosuje się trzykrotny znak cudzysłowu.  Dokumentacja powinna znaleźć się tuż pod deklaracją dokumentowanego narzędzia, np. funkcji:

```python
def funkcja(arg1, arg2):
	"""
	To jest funkcja, sluzy ona do robienia czegos 
	dziwnego z przekazanymi argumentami
	"""
	# kod zawierajacy cialo funkcji
	pass
```

Środowisko PyCharm w przypadku dokumentacji jest także bardzo pomocne. Jeśli chcemy dodać taki rodzaj dokumentacji funkcji, wystarczy tuż pod jej nazwą dodać trzy znaki cudzysłowu i nacisnąć klawisz ***Enter*** a program automatycznie wygeneruje ciało dokumentacji w następującej postaci

![komentarz_dok](resources/python_inst02/doc_comment.png "Szablon dokumentacji funkcji w PyCharm")

Jak widać na powyższym rysunku PyCharm wygenerował dodatkowe elementy które wypada umieścić w dokumentacji. Tuż za znakami cudzysłowów została pozostawiona wolna linia w której należy umieścić opis funkcji, tzn. do czego służy i ewentualnie jaki algorytm implementuje. Oprócz tego PyCharm umieścił informację o argumentach funkcji:

- ***param: argument1:***  należy dopisać informację jaki obiekt powinien być przekazane jako pierwszy argument
- ***param: argument1:***  należy dopisać informację jaki obiekt powinien być przekazane jako drugi argument
- ***return:***  należy dodać informację jaki obiekt jest zwracany z funkcji. W przypadku gdy funkcja nie powinna zwracać argumentów zwyczajowo podaje się  "None" które oznacza, że funkcja nic nie zwraca. 

Czasami programiści umieszczają pod argumentami dodatkowo przykład zastosowania funkcji.

Dokumentacja kodu w języku python jest szczególnie ważna z uwagi na brak typów obiektów. Jeśli chcemy aby argument przekazany do funkcji był liczbą całkowitą, to nie możemy tego powiedzieć użytkownikowi za pomocą deklaracji funkcji (deklaracja zawiera tylko nazwy przekazanych zmiennych, nie ma typu) i musimy to zrobić za pośrednictwem dokumentacji. 

## Polskie znaki diakrytyczne
W sytuacji gdy w komentarzach zostaną umieszczone polskie znaki diakrytyczne kod znajdujący się w danym pliku może nie uda się uruchomić. Wynika to z tego, że python używa domyślnego kodowania ASCII nieobsługującego tego typu znaków. Jeśli jednak chcemy używać polskich znaków, to na początku pliku należy wstawić następujący komentarz
```python
# coding=utf-8
```
Ta linijka wymusi na interpreterze skorzystanie z innego dekodera.

## Listy
### Tworzenie i uzupełnianie

## Pętla "for", słowo "in" i generator "range"

### Metody należące do klasy list
- append - metoda dodaje element na koniec list, np.:
```python
a = [1,2]
a.append(5)
print a # wyswietli sie [1, 2, 5]
```
- insert - metoda wstawia element w dokładnej pozycji

### Wycinki list

### Tablice wielowymiarowe

### Zaawansowana inicjalizacja

### Rozwijanie list

### Zadania - uzupełnij ciała funkcji:
```python
#Remove duplicated elements
def remove_adjacent_duplication(listObject):
    # your code
    pass

print remove_adjacent_duplication([1, 2, 3, 3, 5, 68, 68, 24])
```

```python
# Mereg 2 lists
def merge_lists(list1, list2):
    # your code
    pass

print merge_lists([1,2,45,19,2],[12,-12,'c',3,'5'])
```


## Tuple
##### Zadania - uzupełnij ciała funkcji:
```python
# Order list of tuples by last element
def order_tuples(listTuples):
    # your code
    pass

print "is order ok?"+ str( order_tuples([(1, 3), (3, 2), (2, 1)]) == [(2, 1), (3, 2), (1, 3)])
```

## Instrukcja warunkowa if

## Wykorzystywanie i tworzenie bibliotek


## Numpy array zamiast list

### Tworzenie tablic

### Dostęp do elementów tablicy wielowymiarowej

### Wycinki tablic za pomocą indeksów i masek

### Operacje matematyczne na całych tablicach

## String

### String jako tablica

### Konwersja typów 

### Operator % 

## instrukcja if 

## Operacje na plikach

## Podstawowe narzędzie obsługi systemu

## Rysowanie wykresów - podstawy biblioteki matplotlib


# Zadanie 1
W folderze ***resources/lab1/files*** zlokalizowanym się w repozytorium znajduje się szereg plików o losowych nazwach. W każdym z plików znajduje się tylko jeden wiersz o postaci: *location: [nazwa folderu]*, gdzie [nazwa folderu] może różnić się pomiędzy plikami. Należy skopiować poszczególne pliki zawarte w podanej lokalizacji do folderów, których nazwy są takie same jak ta podana wewnątrz pliku. 

![Pliki w folderach](figures/python_inst02/1.png "Przykład przetworzenia") 

Nowo utworzone foldery mogą zostać umieszczone w dowolnej lokalizacji. 

# Zadanie 2
Należy utworzyć funkcję która będzie potrafiła przeskalować macierz z większego rozmiaru na mniejszy. W tym celu:

1. Utwórz nowy plik pythona o nazwie matrix. 
2. Wewnątrz tego pliku przygotuj funkcję "reduce" która jako argumenty będzie przyjmowała obiekt reprezentujący listę/tablicę dwuwymiarową oraz rozmiar wynikowej macierzy (parametr określający rozmiar powinien obsługiwać sytuację gdy przekazano 1 liczbę lub parę)
3. Uzupełnij ciało funkcji wykorzystując algorytm opisany poniższym rysunkiem
![algorytm](figures/python_inst02/2.png "Algorytm skalowania") 
Na powyższym rysunku oznaczono jak poszukiwać referencyjnych elementów w tablicy większej w zależności od indeksu elementu w tablicy mniejszej. Wartość kolejnych elementów w tablicy mniejszej powinna być obliczona jako średnia z zaznaczonych sąsiadów i referencyjnego elementu z tablicy większej. 

4. Zwróć wynikową tablicę/listę dwuwymiarową.


# Zadanie 3
Należy napisać skrypt który będzie wczytywał plik graficzny ***resources/lab1/meil.png***. 

![logo](https://github.com/ccfd/python_course/blob/master/resources/lab1/meil.png?raw=true "Obraz do przetworzenia") 

Ponadto skrypt ten powinien przeskalować obraz do rozmiaru 20x20 (wykorzystaj funkcję z poprzedniego zadania) i wyświetlić w jednym oknie obraz wczytany i przeskalowany obok siebie.

### Podpowiedzi
- Obraz można wczytać za pomocą funkcji ***imread*** znajdującej się w bibliotece ***matplotlib.image***. Wczytany obraz będzie w postaci tablicy 3 wymiarowej, gdzie pierwsze 2 wymiary określają indeks pojedynczego punktu, a ostatni określa kanał (red, green, blue i opcjonalnie alpha)
- Aby utworzyć 2 wykresy/obrazki w jednym oknie zamiast funkcji ***figure*** (z biblioteki matplotlib.pyplot) należy skorzystać z funkcji ***subplot*** gdzie argumentami jest para określająca liczbę wykresów w wierszach i  kolumnach:

```python
import matplotlib.pyplot as plt
# kod wyznaczający tablice x, y ....
_, axes =  plt.subplot(1,2)
axes[0].plot(x, y)
axes[1].plot(y, x)
plt.show()
```

- Obraz zapisany w postaci macierzy kolorów RGB (lub RGBA) można wyświetlić za pomocą funkcji ***imshow*** znajdującej się w bibliotece ***matplotlib.pyplot*** (w przypadku rysowania w jednym oknie należy skorzystać z metody ***imshow*** należącej do obiektów typu Axes, zwracanych z funkcji subplot)

# Zadanie 4
Uzupełnij skrypt z poprzedniego zadania tak, aby na podstawie jasności obrazka w danym punkcie generował obraz w pliku tekstowym za pomocą wybranych znaków. Obraz tekstowy powinien zostać utworzony na bazie przeskalowanego, mniejszego obrazka oraz powinien używać co najmniej 2 różnych znaków do określenia 2 różnych jasności (np. "||" dla czarnego koloru i "--" dla szarego). Poniżej zamieszczono przykładowy rezultat.  
```python
                  - - -                 
            - - - - - - - - -           
        ||  - -           - - -         
      ||||        - ||        - - -     
    ||||||      ||||||  ||||    - -     
    ||||  ||||  ||      ||||||    - -   
  ||||    ||    ||      ||    ||    - - 
  ||||  ||      ||      ||    ||||  - - 
  ||    ||      ||      ||      ||  - - 
||||  - ||      ||      ||      ||    - 
||||  - ||    ||||||||  ||      ||    - 
||||    ||      ||      ||      ||    - 
  ||-   ||      ||      ||      ||  - - 
  ||||  ||||    ||      ||    ||||  - - 
  ||||    ||-   ||      ||  ||||    -   
    ||||    ||  ||      ||||||    - -   
    - ||||      ||      ||||    - -     
      ||||||                    -       
          ||||||||      ||||||          
            ||||||||||||||||-           
```
### Podpowiedzi
W celu określenia jasności obrazka w danym punkcie skorzystaj z definicji kolorów HSV zamiast RGB. Kolory HSV, podobnie jak RGB są przechowywane w macierzy o 3 kanałach. Definicja każdego z kanałów można zobaczyć na poniższym rysunku:

![SkalaHSV](https://upload.wikimedia.org/wikipedia/commons/0/0d/HSV_color_solid_cylinder_alpha_lowgamma.png "Skala HSV, źródło wikipedia") 

Konwrsji koloru z macierzy RGB na macierz HSV można dokonać za pomocą funkcji ***rgb_to_hsv*** znajdującej się w bibliotece ***matplotlib.colors***. Kanał  ***Value*** dla macierzy HSV jest określony jako trzeci(ostatni).
