---
number: 7
course: Metody Numeryczne
material: Instrukcja 7
author: Ł. Łaniewski-Wołłk
title: Topologiczna optymalizacja z użyciem równań sprzeżonych
---

Na dzisiejszych zajęciach dobierzemy wektor grubości elementów $\theta=\text{thick}$, tak by ugięcie belki było jak najmniejsze. Jedynym elementem który zależy od $\theta$ jest macierz sztywności:

\[S(\theta)x = F\]

A dokładniej: macierz sztywności jest sumą macierzy elementów przemnożonych przez elementy $\theta$. Dla późniejszej poprawy zbieżności dołożymy potęgę $\gamma=3$ do tej zależności:
\[S(\theta) = \sum_i\theta_k^\gamma K^k\]

Będziemy chcieli zoptymalizować przesunięcie węzła w którym przyłożyliśmy siłę. Stwórzmy wektor wag $g$, który ma $-1$ w miejscu tego przemieszczenia, a resztę wartości ma zerową. Teraz nasza funkcja celu to $J = -\langle x, g \rangle$. Potraktujmy nasze równanie statyki jako więz i rozpiszmy funkcję celu powiększoną o mnożniki Lagrange'a:
\[L = -\sum_i x_i g_i  + \sum_j\lambda_j (\sum_iS_{ji}(\theta)x_i - F_j)\]
Optymalne rozwiązanie powinno zerować pochodne po $x$, $\lambda$ i $\theta$:
\[\begin{cases}
\sum_i S_{ji}(\theta)x_i - F_j &= 0\\
-g_i + \sum_j\lambda_j S_{ji} (\theta) &= 0\\
\sum_{ij}\lambda_j \frac{\partial}{\partial \theta_k}S_{ji}(\theta)x_i &= 0
\end{cases}\]

Pierwsze równanie to równanie statyki, opisuje ograniczenia jakie muszą być spełnione.

Drugie równanie to równanie sprzężone (adjoint):
\[S^T(\theta)\lambda = g\]
Zwróćmy uwagę, że w punkcie optymalnym kierunek gradientu funkcji celu jest równoległy do kierunku gradientu ograniczeń, $\nabla_x J || \nabla_x \lambda (S(\theta)x - F)$. Mnożniki Lagrange'a, $\lambda_j$, mogą być więc interpretowane jako *intesywność kary* zmuszającej do spełnienia $j$-tego ograniczenia.

Trzecie równanie to równanie na gradient funkcji Lagrange'a względem parametrów $\theta$:
\[\frac{d}{d\theta_k} L = \sum_{ij}\lambda_j \frac{\partial}{\partial \theta_k}S_{ji}(\theta)x_i = \gamma\theta_k^{\gamma-1}\sum_{ij}K^k_{ji}(\theta)\lambda_jx_i\]


### Zadanie 1

Wprowadź w funkcji mnożącej przez macierz sztywności `SMult` parametr $\gamma=3$ (`gamma`) podnosząc `thick` do potęgi `gamma`. Zdefiniuj zmienną `frac = 0.5` i ustaw początkowe $\theta$ (`thick`) na równe `frac`.

### Zadanie 2

Zdefiniuj wektor $g$ i rozwiąż równanie sprzężone (zauważ że $S$ jest symetryczna).

### Zadanie 3

Zdefiniuj funkcję `calc_grad(int n, double * x, double * lambda, double * grad)`. Skopiuj do niej zawartość funkcji mnożącej `SMult` i zmień:

`r[♦] += x[♠]*pow(thick[♣],gamma)*♥;`

na:

`grad[♣] += gamma*pow(thick[♣],gamma-1)*lambda[♦]*x[♠]*♥;`

Wyświetl tak policzony gradient. Pamiętaj, że gradient ma taką samą długość jak `thick`, czyli `mx*my`. Pamiętaj także by wyzerować `grad` i wyciąć część murującą stopnie swobody.

## Optymalizacja

Gradient wskazuje nam w jakim kierunku powinniśmy przesuwać nasze wartości parametrów by uzyskać lepszy wynik. Pierwszym nasuwającym się schematem postępowania byłoby:

`thick[i] += grad[i];`

### Zadanie 4

Dodaj gradient do parametrów `thick[i] += grad[i];`. Iteruj taką procedurę, oglądając wyniki.

Tak ustawiony problem optymalizacyjny jest nieograniczony. Chcemy jednak uzyskać najmniejsze ugięcie przy ustalonej ,,masie'' belki. Tzn: chcemy zachować sumę parametrów $\theta$: $\sum_i\text{thick[i]} = \text{frac*mx*my}$. Możemy łatwo nałożyć ten więz na `grad`:

### Zadanie 5

Odejmij od wektora `grad` jego sumę.

W kolejnych iteracjach grad ma różną skalę. Na początku jest duży, a później mały. Typową techniką w takich wypadkach jest normalizacja:

### Zadanie 6

Zdefiniuj zmienną `move = 0.05`. Podziel `grad` przez jego największy element i pomnóż przez `move*5`.

Na nasz projekt musimy jednak narzucić bardziej istotne warunki. Po pierwsze nigdzie grubość nie może przekroczyć $1$, i musi być powyżej $0$. Ponadto zazwyczaj chcemy, by zmiana w pojedynczej iteracji nie przekroczyła `move`. Te warunki dość trudno pogodzić z warunkiem stałej sumy elementów.

### Zadanie 7

Wynik dodania gradientu do parametrów wstaw do nowego wektora `nt[i] = thick[i] + grad[i];`. Dla danego parametru `scale` oblicz `thick[i] = scale * nt[i];`. Na tak obliczone `thick` narzuć powyżej opisane 4 warunki, obcinając za duże, bądź za małe wartości.

### Zadanie 8

Zsumuj wartości `thick` po poprzedniej procedurze. Dobierz `scale` metodą bisekcji tak by $\sum_i\text{thick[i]} = \text{frac*mx*my}$.

### Zadanie 9

Przetestuj program dla różnych obciążeń, ustawień parametru `move` i ustawień maksymalnej liczby iteracji w metodze gradientów sprzężonych.
