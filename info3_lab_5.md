---
author: 
  - "M. Dzikowski"
  - "Ł. Łaniewski-Wołłk"
  - "J. Gałecki"
course: Informatyka III
material: Instrukcja 5
number: 5
---

# Wstęp

Obliczenia z wykorzystaniem komputerów, takie jak symulacje fizyczne, są nieodłączną częścią współczesnej nauki i przemysłu.
Podstawą obliczeń komputerowych są obliczenia równoległe.
Gdy korzystamy z jednego komputera komputera - nawet bardzo mocnego - jesteśmy ograniczeni do kilkudziesięciu/kilkuset rdzeni procesora i kilkuset/kilku tysięcy GB pamięci RAM.
Czas obliczeń jest odwrotnie proporcjonalny do liczby rdzeni (przynajmniej w optymistycznym scenariuszu), dlatego z reguły potrzebujemy i chcemy wykorzystać ich jak najwięcej.
Na tych zajęciach zobaczymy, jak prowadzić obliczenia równoległe w modelu pamięci rozproszonej, tzn. z wykorzystaniem wielu komputerów połączonych siecią.
W tym celu potrzebujemy dwóch elementów:

- dostępu do rzeczonej sieci komputerów (klastra obliczeniowego, pot. superkomputera)
- interfejsu programistycznego, pozwalającego na komunikację pomiędzy procesami uruchomionymi na różnych komputerach

# Praca na klastrze

Przed przystąpieniem do zajęć, powinieneś/powinnaś był/a założyć konto w systemie ICM UW, pozwalające na dostęp do maszyn obliczeniowych centrum.
Resztę niniejszej instrukcji będzimy wykonywać właśnie na nich.

## Logowanie `ssh`

Do logowania na zdalne maszyny służy komenda `ssh` (od *secure shell*).
Aby połączyć się z klastrem ICM należy wykonać polecenie

```bash
ssh username@hpc.icm.edu.pl
```

Po podaniu hasła oraz kodu OTP wyświetli się wiadomość powitalna oraz prompt sugerujący, że jesteśmy na węźle dostępowym:

```
[user@login ~]$
```

## Praca z systemem kolejkowym

Jak nazwa wskazuje, węzeł loginowy nie służy do prowadzenia obliczeń.
W tym celu musimy zlecić naszą pracę na węzły obliczeniowe.
Ponieważ z klastra korzysta wielu użytkowników, musi dziać się to w sposób zorganizowany, a zasoby powinny być przydzielane sprawiedliwie.
Do rozwiązania tego problemu służą systemy kolejkowe.
Najpopularniejszy z nich, obecny na maszynach ICM, to `slurm`.
Posiada on bogatą [dokumentację](https://slurm.schedmd.com/overview.html), która może okazać się pomocna w czasie tego laboratorium.

### Stan kolejki

Zanim zlecimy pierwsze zadanie, sprawdźmy stan kolejki.
W tym celu użyj 2 poleceń:

- `sinfo` - wyświetla informacje o obciążeniu węzłów obliczeniowych (*idle* - węzły wolne, *allocated* - węzły zajęte w całości, *mixed* - węzły obciążone częściowo)
- `squeue` - wyświetla informacje o uruchomionych i oczekujących zadaniach. Przydatna jest opcja `--me`, ograniczająca output jedynie do naszych zadań (obecnie nie mamy żadnych w kolejce)

### Zlecanie zadań

Zadania obliczeniowe możemy zlecać przy pomocy `srun` i `sbatch`, podając jako argument program lub skrypt, które mają zostać wykonane.
Polecenia te przyjmują także kilka innych argumentów (pełna lista dostępna w dokumentacji):

- `-A`/`--account` (wymagane) - konto, z którego pobierany będzie budżet godzin obliczeniowych (CPUh), do odczytania z portalu ICM lub informacji wyświetlanych przy logowaniu (prowadzący/a powinien był dodać Twoje konto do odpowiedniego projektu przed zajęciami)
- `-p`/`--parititon` (wymagane) - partycja klastra, na której ma zostać uruchomione zadanie. Tutaj podaj wartość `topola` (nazwa maszyny)
- `-n`/`--ntasks` (domyślnie 1) - liczba równoległych instancji zadania (procesów), która ma zostać uruchomiona
- `-N`/`--nodes` (domyślnie 1) - min. liczba węzłów, na których ma zostać uruchomione zadanie
- `-c`/`--cpus-per-task` (domyślnie 1) - liczba rdzeni per instancja zadania
- `--mem` - ilość pamięci per węzeł na zadanie
- `-t`/`--time` - limit czasowy zadania
- `-J`/`--job-name` - nazwa zadania
- `-D`/`--chdir` - katalog roboczy dla zadania (domyślnie katalog, z którego zadanie zostało zlecone)

Zadania możemy zlecać w trybie interaktywnym lub wsadowym (batchowym).
Przyjrzyjmy się teraz jak to zrobić.

### Sesja interaktywna

Sesja interaktywna polega efektywnie na logowaniu `ssh` na węzeł obliczeniowy.
Uruchamiamy jako zadanie `srun` program `bash -l` (terminal, flaga `-l` jest potrzebna do odpowiedniej konfiguracji środowiska), podając dodatkowo opcję `--pty`.

```bash
srun -p topola -A g105-2774 --pty bash -l
```

Po wykonaniu powyższej komendy wyświetli się informacja o węźle, do którego otrzymaliśmy dostęp.
Zmieni się także prompt.

### Tryb wsadowy

Tryb interaktywny jest przydatny do krótkich eksperymentów, natomiast przeważnie chcemy zlecić większe, równoległe zadanie.
W takim wypadku nie mamy pewności, że zasoby będą dostępne od razu, a same obliczenia mogą trwać długo (np. kilka dni).
Wobec tego nie chcemy pozostawiać otwartej konsoli, tylko zlecić zadanie do kolejki i za jakiś czas sprawdzić wyniki.
Dokładnie do tego służy tryb wsadowy (komenda `sbatch`).

#### Zadanie

Napisz skrypt `printdate.sh`, który drukuje obecną datę:

```bash
#!/bin/bash -l

date
```

Następnie zleć go do kolejki: `sbatch (opcje jak wyżej) printdate.sh`.

Poczekaj aż skrypt się wykona (polecenie `squeue --me`).
Zobacz, co pojawiło się w pliku log o nazwie `slurm-(id zadania).out`.

### Tryb wsadowy - zadnie równoległe

Siła trybu wsadowego pochodzi od możliwości uruchamiania zadań w trybie równoległym.
Możemy to zrobić używając komendy `srun` wewnątrz skryptu zlecanego przez `sbatch`.

Wykonaj ponownie ostatnie zadanie, podając opcję `-n 2`.
Ile razy wyświetli się data?
Teraz podmień komendę `date` na `srun date`.
Czy teraz data wyświetli się 2 razy?

### Moduły

Na klastrze zainstalowane jest wiele różnych programów, często te same programy w różnych wersjach.
Aby uniknąć konfliktów, programy nie są dostępne od razu, tylko musimy załadować te, które potrzebujemy.
Robimy to za pomocą modułów.
Aby wyświetlić listę modułów, użyj (z węzła obliczeniowego, w sesji interaktywnej) komendy `module av`.
Moduły ładujemy za pomocą komendy `module load (moduł)`.

#### Zadanie

Rozpocznij nową sesję interaktywną.
Sprawdź wersję zainstalowanego kompilatora `gcc` komendą `gcc --version`.
Następnie załaduj moduł `common/compilers/gcc/13.2.0` i sprawdź ponownie wersję `gcc`.

# Obliczenia równoległe

Każdy program przygotowany do pracy równoległej oprócz podstawowego algorytmu, potrzebuje mechanizmu komunikacji.
W naszym przypadku będzie to standard MPI (*Message Passing Interface*).
Biblioteka OpenMPI dostarcza nam narzędzi niezbędnych do uruchamiania i komunikacji między poszczególnymi procesami składającymi się na nasz "program".

### Ćwiczenie 1

Przygotuj plik `program.cpp` o poniższej treści. Następnie skompiluj go za pomocą programu
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

Powyższy program można skompilować i uruchomić używając komend:
```Bash
mpic++ -o program program.cpp
mpirun -np 4 program
```
gdzie `4` to liczba procesorów, na których ma zostać uruchomiony program.

Przeanalizujmy teraz program. Funkcje `MPI_Init` i `MPI_Finalize` służą do odpowiednio inicjalizacji i zakonczenia komunikacji pomiedzy procesami. Powinny one być odpowiednio na początku i na końcu programu, ponieważ tylko pomiedzy nimi można wykonać jakiekolwiek wywołanie biblioteki `MPI` i komunikować się z innymi procesami w grupie. Wywołanie `MPI_Comm_size` zwroci nam liczbe procesów (np. `4`), zaś `MPI_Comm_rank` zwróci nam numer *naszego* procesu (np. `0`,`1`,`2` lub `3`). Zmienna `rank` jest wiec jedną z najważniejszych w kodzie, ponieważ odróżna nasze procesy. Jeśli jej nigdzie nie użyjemy, to wszystkie nasze procesy zrobią dokładnie to samo.

### Ćwiczenie 2

Rozszerz program tak, by każdy proces losował pewne liczby i wypisywał pewne statystyki:

1. [Zaalokuj](info1_lab07.html) tablicę liczb rzeczywistych `a` o rozmiarze `n = 10000 * (rank + 1)`
2. Wypełnij ją [liczbami losowymi](info1_lab04.html) z przedziału $[0,1]$
3. Wypisz komunikat o wylosowaniu i wypisz pierwszą liczbę `a[0]`
4. Oblicz $S_1 = \sum_i a_i$
5. Wyświetl średnią: $\mu = \frac{1}{n} S_1$
6. Oblicz $S_2 = \sum_i (a_i - \mu)^2$
7. Wyświetl wariancję: $\sigma^2 = \frac{1}{n-1} S_2$

Pamietaj aby we wszystkich komunikatach umieszczać zmienną `rank`, tak by było wiadomo, który komunikat pochodzi, od którego procesu. By mieć pewność, że komunikaty wypisywane są rzeczywiście wtedy, kiedy występują w kodzie (a nie są buforowane przez system), dodaj komendę `fflush(stdout);`{.cpp} zaraz po każdym wywołaniu `printf`{.cpp}. Intrukcja ta powoduje, że cały buforowany tekst zostanie wyświetlony na ekran od razu.

Aktualnie, losowanie jest bardzo niedoskonałe. Wszystkie procesy wylosowały ten sam ciąg losowy (można zobaczyć to już po pierwszym elemencie, który jest identyczny we wszystkich procesach. Żeby tego uniknąć przekaż np. wartość `time(NULL) + rank` jako *ziarno* do funkcji `srand`, tak aby ciąg losowy był zainicjalizowany inną liczbą na każdym procesorze.

### Ćwiczenie 3

Zaobserwuj, że różne procesy dochodzą do różnych etapów algorytmu w różnych momentach. Np. średnia dla procesu 0 może być wyznaczona przed wypełnieniem liczbami tablicy w procesie 1. Możemy wymusić aby procesy czekały na siebie nawzajem dodając instrukcję `MPI_Barrier(MPI_COMM_WORLD);`{.cpp} po wywołaniach `printf`/`fflush`. Bariera w programach wielowątkowych powoduje, że wszystkie procesy czekają w tym miejscu kodu, aż reszta procesów dojdzie do tego miejsca, a następnie wszystkie razem ruszają dalej. Zauważ, że powoduje to iż program działa tak wolno, jak jego najwolniejszy element. Przebieg programu we wszystkich procesach jest pokazany poglądowo na poniższym obrazku:

```{r, echo=FALSE}
par(mfrow=c(1,2),mar=c(2.1,2.1,0.1,0.1))
tms = c(1,0.6,0.6)
tms = rbind(0.7,outer(tms,1:4))
nms = c("alokacja","losowanie",expression("obliczenie"~S[1]),expression("obliczenie"~S[2]))
cls = 1:4
Y = max(apply(tms,2,sum))
xlim=c(-0.5,3.5)
plot (NA, ylab="Time", xlab="", xlim=xlim,ylim=c(Y,0), xaxt='n', yaxt='n')
axis(1,at=0:3,paste("rank",0:3,sep="="))
for (i in 1:ncol(tms)) {
  arrows(i-1, cumsum(tms[,i]) - tms[,i],i-1, cumsum(tms[,i]), angle = 15,length = 0.1,col=cls)
}
#text(3,cumsum(tms[,4])-tms[,4]/2,nms, adj=c(1.1,0.5))
legend("bottomleft",nms,col=cls,lty=1)
mtext("Time", 2, line = 1)
par(mar=c(2.1,2.1,0.1,0.1))
plot (NA, ylab="", xlab="", xlim=xlim,ylim=c(Y,0), xaxt='n', yaxt='n')
axis(1,at=0:3,paste("rank",0:3,sep="="))
for (i in 1:ncol(tms)) {
  arrows(i-1, cumsum(tms[,4]) - tms[,4],i-1, cumsum(tms[,4]) - tms[,4] + tms[,i], angle = 15,length = 0.1,col=cls)
}
abline(h=cumsum(tms[,4]), lty=2)
text(0.1,cumsum(tms[,4]),"Barrier", adj=c(0,-0.2))

```

### Ćwiczenie 4

Użyj funkcji wykonującej redukcję aby obliczyć średnią globalną (po wszystkich procesach) i wariancję z $a$. Redukcja w programowaniu równoległym polega na wykonaniu jakiejś operacji, np. sumowania czy wzięcia maxiumum, na danych ze wszystkich procesów. W bibliotece MPI mamy do dyspozycji funkcję:
```c++
MPI_Reduce(source, destination, count, datatype, operation, root,
           MPI_COMM_WORLD);
```
- `source` to **wskaźnik** do danych, które mamy np. zsumować.
- `destination` to wskaźnik do miejsca, gdzie ma być umieszczony wynik.
- `count` to liczba elementów danych do zsumowania. Czyli np. `1` jeśli dane to jedna liczba.
- `datatype` to typ danych, które sumujemy: `MPI_INT` lub `MPI_DOUBLE`.
- `operation` to operacja, którą wykonujemy, np: `MPI_SUM` lub `MPI_MAX`.
- `root` to numer procesu, do którego przesyłamy wynik, np: `0.`
- Ostatni argument to uchwyt komunikatora, na którym ma zostać wykonana redukcja. W naszym wypadku to domyślny komunikator `MPI_COMM_WORLD`

Użyj tej funkcji aby obliczyć globalne statystyki, a następnie wyświetl je (pamietaj, że mają one sens tylko na węźle `root`). Weź pod uwagę, że globalne `n` jest inne niż `n` lokalne.

Bliźniaczą do funkcji `MPI_Reduce` jest funkcja `MPI_Allreduce`. Przesyła ona wynik do wszystkich procesów, a nie tylko do procesu `root`.
```c++
MPI_Allreduce(source, destination, count, datatype, operation,
              MPI_COMM_WORLD);
```

### Ćwiczenie \*

Stwórz nowy program równoległy `program2.cpp`, który będzie obliczał powyższą średnią i wariancję, używając tylko jednej pętli, bez alokowania tablicy `a` (tzn., będzie liczył średnią i wariancję bez przechowywania pojedyńczych elementów). By to zrobić przekształć wzór na wariancję:

$\sigma^2 = \frac{1}{n-1}\sum_i\left(a_i - \frac{1}{n}\sum_j a_j\right)^2$

tak aby był wyrażony za pomocą $S_1$ i nowego $\hat S_2 = \sum_i a_i^2$, który da się obliczyć bez znajomości średniej $\mu$. Użyj we wszystkich procesach tego samego (bardzo wysokiego) `n`. Porównaj czas wykonania wykonując:
```Bash
time mpirun -np 1 program2
time mpirun -np 2 program2
time mpirun -np 4 program2
```



### Ćwiczenie
Spróbuj wykonać któryś z wcześniejszych skryptów konwerujących obrazki (np konwersje .jpg na .gif) jako nieinteraktywne zadanie w kolejce.
