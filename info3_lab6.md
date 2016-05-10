---
author: M. Dzikowski
---

# Wstęp

Obliczenia z wykorzystaniem komputerów są podstawą współczesnej nauki.
Natomiast podstawą obliczeń komputerowych są obliczenia równoległe. Gdy
korzystamy z 1 komputera, nawet bardzo mocnego jesteśmy ograniczeni do
(obecnie) około 32 procesorów i kilkuset Gb pamięci RAM. Co więcej czas
obliczeń spada (przynajmniej tego byśmy sobie życzyli) jak 1/(ilość procesów)
dlatego z reguły potrzebujemy i chcemy wykorzystać ich jak najwięcej.

# Obliczenia równoległe

Każdy program przygotowany do pracy równoległej oprócz podstawowego al-
gorytmu potrzebuje mechanizmu komunikacji, w naszym przypadku będzie to
standard MPI czyli Message Passing Interface. Biblioteka OpenMPI dostarcza
nam narzędzi do uruchamiania i komunikacji między poszczególnymi procesami
składającymi się na nasz ”program”

### Ćwiczenie

Przygotuj plik `program.cpp` o treści jak poniżej. Następnie skompiluj go programem
`mpic++`:

```c++
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);
  printf("Hello World! from process %d out of %d on %s\n",
    rank, numprocs, processor_name);
  MPI_Finalize();
}
```

Program ten można skompilować i uruchomić za pomocą:
```Bash
mpic++ -o program program.cpp
mpirun -np 4 program
```
gdzie `4` to liczba procesorów na której ma zostać uruchomiony program.

Przeanalizujmy teraz program. Funkcje `MPI_Init` i `MPI_Finalize` służą do odpowiednio inicjalizacji i zakonczenia komunikacji pomiedzy procesami. Powinny one być odpowiednio na początku i na końcu programu, ponieważ tylko pomiedzy nimi można wykonać jakiekolwiek wywołanie biblioteki `MPI` i komunikować się z innymi procesami w grupie. Wywołanie `MPI_Comm_size` zwroci nam liczbe procesów (np. `4`), zaś `MPI_Comm_rank` zwróci nam numer *naszego* procesu (np. `0`,`1`,`2` lub `3`). Zmienna `rank` jest wiec jedną z najważniejszych w kodzie, ponieważ odróżna nasze procesy. Jeśli jej nigdzie nie użyjemy, to wszystkie nasze procesy zrobią dokładnie to samo.

### Ćwiczenie

Rozszerz program tak, by każdy proces wylosował pewne liczby i wypisał pewne statystyki:

1. Zaalokuj tablice liczb rzeczywistych `a` o rozmiarze `n = 10000*(rank-1)`
2. Wypełnij ją liczbami losowymi z przedziału $[0,1]$
3. Wypisz komunikat o wylosowaniu
4. Policz $S_1 = \sum_i a_i$
5. Wyświetl $\frac{1}{n} S_1$
6. Policz $S_1 = \sum_i a_i^2$
7. Wyświetl $\frac{1}{n-1} S_2 - \frac{1}{n-1}\frac{1}{n} S_1^2$

Pamietaj by we wszystkich komunikatach umieszczać `rank`, tak by było wiadomo który komunikat pochodzi od którego procesu.
# Kolejka PBS

W przypadku każdego dużego systemu komputerowego potrzebny jest jakiś
mechanizm zarządzania zasobami: 2 osoby nie mogą naraz korzystać z tego
samego procesora/rdzenia. W prawdziwym systemie komputer centralny służy
do zlecania zadań, pozostałe, tzw. węzły obliczeniowe przyjmują i wykonują
zadania. Na `info3` jest tylko jeden węzeł który spełnia obie role.

### Ćwiczenia

Sprawdź co zrobi komenda `qsub -I`{.bash} (wielka litera i). To program do wysyłania zadań do wykonania. Opcja `-I` oznacza tryb interaktywny: zostaniemy zalogowani na wolny węzeł przez ssh. Wpisz teraz `qstat`, sprawdź opcje `-n` i `-f`. Zobacz ze twoje 'zadanie' jest uruchomione w kolejce. Wyloguj się teraz, bo blokujesz zasoby kolejki. Jednocześnie może być wykorzystywanych tylko 4 rdzenie. Ilością pobieranych zasobów można sterować poprzez flagę `-l`, np.:
```Bash
qsub -l nodes=1:ppn=4 -I
qsub -l nodes=1:ppn=2 -l walltime=00:00:10 -I
```

## Zadania nieinteraktywne

W większości przypadków czas trwania zadania interaktywnego jest mocno ograniczony. Bardziej użyteczne są zadania nieinteraktywne. Potrzebny jest nam plik zadania `plik.sh`:
```Bash
#!/bin/bash
cd $PBS_O_WORKDIR
mpirun --hostfile $PBS_NODEFILE --display-map ./program
```
Następnie zlecamy jego wykonanie przez
```Bash
qsub plik.sh
```
Obejrzyj zawartość katalogu, znajdź pliki o rozszerzeniu `.oXX` i `.eXX`. Czym one są? Dodaj do skryptu `plik.sh` komende `sleep 8`{.bash}, która spowoduje ze zadanie *zaśnie* na 8 sekund, tak by w liście wypisywanej przez `qstat` dało się je zobaczyć. Jako grupa możecie dodać wiele takich zadań i zobaczyć jak są po kolei realizowane przez kolejkę PBS.

### Ćwiczenie
Spróboj wykonać któryś z wcześniejszych skryptów konwerujących obrazki (np konwersje jpg na gif) jako nieinteraktywne zadanie w kolejce.
