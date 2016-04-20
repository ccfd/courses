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

# Python
W czasie rozwoju języka *python* wykształciły się dwie jego wersje:
- *python 2*,
- *python 3* (nowsza specyfikacja języka, choć niekoniecznie częściej używana).

Są one niekompatybilne pomiędzy sobą, w związku z czym na samym początku pracy należy się zdecydować na której wersji będziemy pracowali. Należy także pamiętać, że każdy nowo zainstalowany pakiet musi pochodzić z repozytorium właściwego dla używanej wersji.W przypadku naszego kursu zajęcia będą prowadzone w oparciu o wersję drugą i wszystkie podane informacje odnośnie instalacji i pracy z językiem będą właściwe tylko do standardu języka *python 2*. 

## Wymagane biblioteki
- wersja bazowa python-dev
- python-pip (opcjonalnie)
- scipy
- numpy
- matplotlib
- pyVTK (później)
- pyopenCV?

## Instalacja - podstawowe narzędzia
W poniższym punkcie zostaną opisane metody instalacji podstawowych i dodatkowych pakietów (zbioru narzędzi przygotowanych i upublicznionych przez innych programistów). Dokładny opis zostanie ograniczony jedynie do dystrybucji opartych na systemie Debian. W przypadku innych systemów uczestnicy powinni samodzielnie zadbać o instalację odpowiednich narzędzi.

### Linux (rodzina systemów Debian)
Większość systemów posiada domyślnie zainstalowane podstawowe pakiety języka python. Jednak, aby się upewnić, że je posiadamy możemy po prostu spróbować je zainstalować. Na początek 2 podstawowe i najważniejsze pakiety
```bash
user@host /current/path $  sudo apt-get install python-dev
user@host /current/path $ sudo apt-get install python-pip
```
Po instalacji pakietu *python-pip* uzyskujemy dostęp do managera pakietów pythona z oficjalnego repozytorium *Python Package Index* (PyPI). PyPI stanowi repozytorium dla większości znanych pakietów pythona. Z kolei instalacja za pomocą *apt-get* dostarcza tylko te pakiety które znajdują się w repozytorium wydawcy danego systemu (np. Ubuntu Repository) i na ogół są one dość ograniczone. 

|apt-get| pip |
|:--------|:----|
|`sudo apt-get install python-scipy`{.bash} | `sudo pip install scipy`{.bash}|
|`sudo apt-get install python-matplotlib`{.bash} | `sudo pip install matplotlib`{.bash}|
|`sudo apt-get install python-numpy`{.bash} | `sudo pip install numpy`{.bash}|

### Windows
Osoby zainteresowane instalacją na tym systemie odsyłamy do poniższego linku [Windows Installers](https://www.python.org/downloads/windows/) skąd można pobrać i zainstalować podstawowe narzędzia pythona (w przypadku naszego kursu należy wybrać wersję 2.x.x). 
Dodatkowe pakiety można zainstalować z poziomu linii komend. Jednak przed uczynieniem tego należy dodać ścieżkę do folderu zawierającego skrypty pythona (np. C:\Python27\Scripts) do zmiennej środowiskowej PATH (Uwaga: pod edycji zmiennej środowiskowej może być wymagane ponowne uruchomienie systemu). Następnie należy otworzyć konsolę i wywołać instalację za pomocą *pip*:
```bat
pip install <nazwa pakietu>
```



# Środowisko graficzne
 - PyCharm community edition (JetBrains company)

