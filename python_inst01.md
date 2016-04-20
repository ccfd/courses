---
number: 1
course: Python
material: Wymagania
author: W. Gryglas
---

# Wymagania

- minimalna znajomość systemów z rodziny Linux,
- podstawowa znajomość programowania (nie ma znaczenia język).

# System operacyjny
Zalecane jest korzystanie z systemów z rodziny Linux, a w szczególności opartych na Debianie. Jednak pakiety pythona są przygotowane do instalacji również na systemy z rodziny Windows (instalacja dodatkowych pakietów za pomocą *pip*, o którym w dalszej części), w związku z czym istnieje możliwość pracy na takim systemie, jednak będzie się to wiązało z ograniczonym wsparciem prowadzących kurs.

# Kontrola wersji - git i GitHub
Narzędzia kontroli wersji są praktycznie niezbędne podczas pracy nad większym kodem, a przede wszystkim w sytuacji gdy nad jednym projektem współpracuje więcej osób. Pozwalają one na:
- śledzenie kolejnych zmian w kodzie, 
- usuwanie niepotrzebnych zmian, 
- tworzenie "podprojektów" w których pracuje się tylko nad częścią kodu, 
- łączenie kodu różnych osób w obrębie nawet tego samego pliku.

Więcej informacji o tym czym właściwie jest kontrola wersji można przeczytać pod poniższym linkiem:
 [git - wprowadzenie do kontroli wersji](https://git-scm.com/book/pl/v1/Pierwsze-kroki-Wprowadzenie-do-kontroli-wersji) 

W przypadku naszego kursu do kontroli wersji będziemy stosowali narzędzie zwane *git*, które zostało opracowane przez "ojca" systemów Linux Linusa Torwaldsa. Wielu programistów obsługuje go z poziomu konsoli. My jednak skupimy się tylko na podstawowych jego funkcjach i będziemy z git'a korzystali tylko z poziomu środowiska programistycznego, o którym więcej powiemy dalej.

Na tym etapie jedyne co należy wykonać to przejść na stronę [GitHub](https://github.com/) i zarejestrować własne konto. Dzięki temu otrzymamy pewną darmową (wersja darmowa wymaga publicznego dostępu do zamieszczonego kodu) przestrzeń dyskową na której będziemy mogli przechowywać wszystkie niezbędne pliki potrzebne w naszym projekcie. Serwis GitHub sam w sobie nie jest potrzebny do działania git'a (możemy utworzyć lokalne repozytorium na własnym dysku), jednak potrzebujemy jakiegoś miejsca, najlepiej w sieci aby mieć dostęp do kodu z każdego miejsca, w którym będziemy mogli składować własne repozytorium z tworzonym kodem.

# Python
W czasie rozwoju języka *python* wykształciły się dwie jego wersje:
- *python 2*,
- *python 3* (nowsza specyfikacja języka, choć niekoniecznie częściej używana).

Są one niekompatybilne pomiędzy sobą, w związku z czym na samym początku pracy należy się zdecydować na której wersji będziemy pracowali. Należy także pamiętać, że każdy nowo zainstalowany pakiet musi pochodzić z repozytorium właściwego dla używanej wersji.W przypadku naszego kursu zajęcia będą prowadzone w oparciu o wersję drugą i wszystkie podane informacje odnośnie instalacji i pracy z językiem będą właściwe tylko dla standardu języka *python 2*. 

# Instalacja niezbędnych pakietów
W poniższym punkcie zostaną opisane metody instalacji podstawowych i dodatkowych pakietów (zbioru narzędzi przygotowanych i upublicznionych przez innych programistów). Dokładny opis zostanie ograniczony jedynie do dystrybucji opartych na systemie Debian. W przypadku innych systemów uczestnicy powinni samodzielnie zadbać o instalację odpowiednich narzędzi.

## Wymagane narzędzia
- python-dev - podstawowe narzędzie języka python
-  pip - ...TODO...
- scipy - ...TODO...
- numpy - ...TODO...
- matplotlib - ...TODO...
- pyVTK (później) - ...TODO...
- pyopenCV? - ...TODO...


## Linux (dystrybucje Debian)
### Podstawowe narzędzia
Większość systemów posiada domyślnie zainstalowane podstawowe pakiety języka python. Jednak, aby się upewnić, że je posiadamy możemy po prostu spróbować je zainstalować. Na początek 2 podstawowe i najważniejsze pakiety. Otwieramy konsolę a w niej wpisujemy następujące komendy (Uwaga komenda `sudo`{.bash} oznacza uruchomienie zadania jako administrator co będzie wymagało podania hasła):
```bash
sudo apt-get install python-dev
sudo apt-get install python-pip
```

Po dokonaniu instalacji *python-pip* uzyskujemy dostęp do managera pakietów pythona z oficjalnego repozytorium *Python Package Index* (PyPI). *PyPI* stanowi repozytorium dla większości znanych pakietów pythona. Pozwala także na instalację pakietu o żądanej wersji. Z kolei instalacja za pomocą *apt-get* dostarcza tylko te pakiety które znajdują się w repozytorium wydawcy danego systemu (np. Ubuntu Repository) i na ogół są one dość ograniczone i zawierają tylko najnowsze wersje pakietów. Ponadto pakiety dostarczane za pomocą *apt-get* są wcześniej skompilowane dzięki czemu proces instalacji jest znacznie krótszy, ale nie zawsze jest to lepsze rozwiązanie.

### Dodatkowe pakiety
Aby zainstalować dodatkowe możemy skorzystać z repozytorium *PyPI* lub z repozytorium wydawcy systemu. W obu przypadkach aby zainstalować wszystkie biblioteki możemy w linii poleceń podać więcej niż jedną nazwę pakietu. Na obecnym etapie kursu będziemy potrzebowali tylko 3 dodatkowych pakietów:

- *apt-get*
`sudo apt-get install python-scipy python-matplotlib python-numpy`{.bash}
- *pip*
`sudo pip install scipy matplotlib numpy`{.bash}

### git
W przypadku 

## Windows
### Podstawowe narzędzia
Osoby zainteresowane instalacją na tym systemie odsyłamy do poniższego linku [Windows Installers](https://www.python.org/downloads/windows/) skąd można pobrać i zainstalować podstawowe narzędzia pythona (w przypadku naszego kursu należy wybrać wersję 2.x.x). 
### Dodatkowe pakiety
Dodatkowe pakiety można zainstalować z poziomu linii komend. Jednak przed uczynieniem tego należy dodać ścieżkę do folderu zawierającego skrypty pythona (np. C:\Python27\Scripts) do zmiennej środowiskowej PATH (Uwaga: pod edycji zmiennej środowiskowej może być wymagane ponowne uruchomienie systemu). Następnie należy otworzyć konsolę i wywołać instalację za pomocą *pip*:
```bat
pip install scipy matplotlib numpy
```
### git
W przypadku systemów Windows program ten musi zostać zainstalowany oddzielnie. Będzie on 





# Środowisko graficzne
Do wygodnej pracy 
 - PyCharm community edition (JetBrains company)

