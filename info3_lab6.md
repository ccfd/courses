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
```bash
mpic++ -o program program.cpp
mpirun -np 4 program
```
gdzie `4` to liczba procesorów na której ma zostać uruchomiony program.
