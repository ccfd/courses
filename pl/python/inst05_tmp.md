---
number: 5
course: Python
material: Instrukcja 5
author: W. Gryglas
---
# Wprowadzenie

## Tworzenie własnych klas

## Uruchamianie zewnętrznych procesów

## Konsola "ipython"

## Tworzenie własnych generatorów

## Tworzenie własnych modułów

# Instalacja OpenFOAM i ParaView

Do rozwiązania poniższego zadania będzie wymagane zainstalowanie aplikacji OpenFOAM. OpenFOAM jest zbiorem różnych solverów opensource, które pozwalają na rozwiązywanie zagadnień obliczeniowej mechaniki płynów. W przypadku naszego zadania będzie on zastosowany do tworzenia siatki i wykonania obliczeń przepływu 2D, których wynik będzie następnie przez nas wykorzystany do utworzenia optymalizacji. Instalacja OpenFOAM z pakietów jest bardzo prosta. Opis instalacji można znaleźć pod [tym](http://openfoam.org/download/3-0-1-ubuntu/) linkiem. Poniżej opisujemy dokładnie te same kroki:

 - Należy na początek dodać repozytorium OpenFOAM do system, tak aby nasz system wiedział skąd ma pobrać aplikację. W tym celu w konsoli wpisujemy:
```bash
$ sudo add-apt-repository http://www.openfoam.org/download/ubuntu
```

- Oprócz dodania repozytorium musimy odświeżyć nasz manager pakietów:
```bash
$ sudo apt-get update
```

- Na koniec możemy już zainstalować samego OpenFOAMa
```bash
$ sudo apt-get install openfoam30
```

OpenFOAM domyślnie powinien zostać zainstalowany w lokalizacji "/opt/openfoam30".

Oprócz samego OpenFOAMa potrzebujemy także narzędzia do wykonywania postprocessingu. Świetnie nadaje się do tego narzędzie ParaView które domyślnie wspiera wczytywanie siatki i danych wygenerowanych przez OpenFOAMa.  Aplikację tą można zainstalować na dwa sposoby: 
Z repozytorium OpenFOAM (posiada dodatkowe wsparcie do danych OpenFOAMa):
```bash
$ sudo apt-get install paraviewopenfoam44
```

Drugim sposobem jest pobranie ParaView z [oficjalnego repozytorium](http://www.paraview.org/download/) - tutaj wystarczy pobrać archiwum i następnie je rozpakować. Zaletą tego podejścia jest pobranie najnowszej dostępnej wersji tego oprogramowania.  

# Zadanie

Dokonaj optymalizacji kształtu poniższej geometrii tak aby otrzymany profil kanału zapewniał najmniejszą stratę energii przepływu. Optymalizacji powinny podlegać jednie kolanka kanału, nie wlot i wylot.

![kanal](figures/python_inst05/tube.png "Kanał do optymalizacji")

Stratę przepływu można wyznaczyć jako różnicę ciśnienia całkowitego pomiędzy wlotem i wylotem. Twoim zadaniem jest napisanie skryptu w języku Python który będzie służył do modyfikacji siatki obliczeniowej, wczytywania wyników oraz uruchamiania kolejnych symulacji w pętli optymalizacyjnej. 

Kod powinien realizować następujący zadania:

1. Utworzyć bazową siatkę obliczeniową.
2. Wczytywać i zapisywać współrzędne węzłów siatki obliczeniowej z formatu OpenFOAM
3. Wczytywać wyniki z pliku zawierającego obliczone całki z ciśnienia całkowitego na wlocie i wylocie domeny.
4. Uruchamiać symulację
5. Uruchamiać narzędzie *minimize* z biblioteki scipy.optimize w celu 

 Symulacje powinny zostać prowadzone przy użyciu aplikacji OpenFOAM zwanej "simpleFoam", która implementuje solver przepływów nieściśliwych. Gotowa symulacja zawierająca wszystkie ustawienia znajduje się 

Bazowa siatka wraz z ustawieniami 


## przypadek a)



Optymalizacji możesz dokonać posługując się jedną z funkcji znajdujących się w pakiecie ***scipy.optimize***. Aby wyznaczyć straty przepływu skorzystaj z  "channel_optimization"




![optymalizacja dwu parametryczna](figures/python_inst05/optimization_iteration.png "Optymalizacja dwu parametryczna, wartość funkcji celu w kolejnych iteracjach")

![optymalizacja dwu parametryczna - prędkość](figures/python_inst05/opt_velocity.gif "Optymalizacja dwu parametryczna, pole prędkości") ![optymalizacja dwu parametryczna, ciśnienie całkowite](figures/python_inst05/opt_totalpressure.gif "Optymalizacja dwu parametryczna, pole ciśnienia całkowitego")

![optymalizacja 4-parometrowa](figures/python_inst05/optimization_iteration_4params.png "Optymalizacja 4-parometrowa, wartość funkcji celu w kolejnych iteracjach")

![optymalizacja 4-parometrowa - prędkość](figures/python_inst05/opt_velocity.gif "Optymalizacja 4-parometrowa, pole prędkości") ![optymalizacja 4-parometrowa, ciśnienie całkowite](figures/python_inst05/opt_totalpressure_4params.gif "Optymalizacja 4-parometrowa, pole ciśnienia całkowitego")
