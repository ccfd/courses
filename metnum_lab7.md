---
number: 7
course: Metody Numeryczne
material: Instrukcja 7
author: Ł. Łaniewski-Wołłk
title: Topologiczna optymalizacja z użyciem równań sprzeżonych
---

Na dzisiejszych zajęciach dobierzemy wektor grubości elementów $\theta=\text`thick`$, tak by ugięcie belki było jak najmniejsze. Jedynym elementem który zależy od $\theta$ jest macierz sztywności:

\[S(\theta)x = F\]

A dokładniej: macierz sztywności jest sumą macierzy elementów przemnożonych przez elementy $\theta$. Dla późniejszej poprawy zbieżności dołożymy potęgę $\gamma=3$ do tej zależności:
\[S(\theta) = \sum_i\theta_k^\gamma K^k\]

Będziemy chcieli zoptymalizować przesunięcie węzła w którym przyłożyliśmy siłę. Stwórzmy wektor $g$, który ma $-1$ w miejscu tego przemieszczenia, a resztę wartości ma zerową. Teraz nasza funkcja celu to $J = -\langle x, g \rangle$. Potraktujmy nasze równanie statyki jako więz i rozpiszmy funkcję celu powiększoną o mnożniki Lagrange:
\[-\sum_i x_i g_i  + \sum_j\lambda_j (\sum_iS_{ji}(\theta)x_i - F_j)\]
Optymalne rozwiązanie powinno zerować pochodne po $x$, $\lambda$ i $\theta$:
\[\begin{cases}
-g_i + \sum_j\lambda_j S_{ji} (\theta) &= 0\\
\sum_i S_{ji}(\theta)x_i - F_j &= 0\\
\sum_{ij}\lambda_j \frac{\partial}{\partial \theta_k}S_{ji}(\theta)x_i &= 0
\end{cases}\]

Drugie równanie to nasze równanie statyki. Pierwsze równanie to równanie sprzężone (adjoint):
\[S^T(\theta)\lambda = g\]
Trzecie równanie to równanie ma gradient funkcji celu względem parametrów:
\[\frac{d}{d\theta_k}J = \sum_{ij}\lambda_j \frac{\partial}{\partial \theta_k}S_{ji}(\theta)x_i = \gamma\theta_k^{\gamma-1}\sum_{ij}K^k_{ji}(\theta)\lambda_jx_i\]


### Zadanie

Wprowadź w funkcji mnożącej przez macierz sztywności `SMult` parametr $\gamma=3$ (`gamma`) podnosząc `thick` do potęgi `gamma`. Zdefiniuj zmienną $\text`frac` = 0.5$ i ustaw początkowe $\theta$ (`thick`) na równe `frac`. 



### Zadanie

Zdefiniuj wektor $g$ i rozwiąż równanie sprzężone (zauważ że $S$ jest symetryczna).



### Zadanie

Zdefiniuj funkcję `calc\_grad(int n, double * x, double * lambda, double * grad)`. Skopiuj do niej zawartość funkcji mnożącej `SMult` i zmień:\\
`r[$\diamondsuit$] += x[$\spadesuit$]*pow(thick[$\clubsuit$],gamma)*$\heartsuit$;`\\
na:\\
`grad[$\clubsuit$] += gamma*pow(thick[$\clubsuit$],gamma-1)*lambda[$\diamondsuit$]*x[$\spadesuit$]*$\heartsuit$;`\\
Wyświetl tak policzony gradient. Pamiętaj, że gradient ma taką samą długość jak `thick`, czyli `mx*my`. Pamiętaj także by wyzerować `grad` i wyciąć część murującą stopnie swobody.




# Optymalizacja

Gradient wskazuje nam w jakim kierunku powinniśmy przesuwać nasze wartości parametrów by uzyskać lepszy wynik. Pierwszym nasuwającym się schematem postępowania byłoby:\\
`thick[i] += grad[i]; `

### Zadanie

Dodaj gradient do parametrów `thick[i] += grad[i];`. Iteruj taką procedurę, oglądając wyniki.


Tak ustawiony problem optymalizacyjny jest nieograniczony. Chcemy jednak uzyskać najmniejsze ugięcie przy ustalonej ,,masie'' belki. Tzn: chcemy zachować sumę parametrów $\theta$: $\sum_i\text`thick[i]` = \text`frac*mx*my`$. Możemy łatwo nałożyć ten więz na `grad`:


### Zadanie

Odejmij od wektora `grad` jego sumę.


W kolejnych iteracjach grad ma różną skalę. Na początku jest duży, a później mały. Typową techniką w takich wypadkach jest normalizacja:


### Zadanie

Zdefiniuj zmienną `move = 0.05`. Podziel `grad` przez jego największy element i pomnóż przez `move*5`.


Na nasz projekt musimy jednak narzucić bardziej istotne warunki. Po pierwsze nigdzie grubość nie może przekroczyć $1$, i musi być powyżej $0$. Ponadto zazwyczaj chcemy, by zmiana w pojedynczej iteracji nie przekroczyła `move`. Te warunki dość trudno pogodzić z warunkiem stałej sumy elementów. 


### Zadanie

Wynik dodania gradientu do parametrów wstaw do nowego wektora `nt[i] = thick[i] + grad[i];`. Dla danego parametru `scale` oblicz `thick[i] = scale * nt[i];`. Na tak obliczone `thick` narzuć powyżej opisane 4 warunki, obcinając za duże, bądź za małe wartości.



### Zadanie

Zsumuj wartości `thick` po poprzedniej procedurze. Dobierz `scale` metodą bisekcji tak by $\sum_i\text`thick[i]` = \text`frac*mx*my`$.



### Zadanie

Przetestuj program dla różnych obciążeń, ustawień parametru `move` i ustawień maksymalnej liczby iteracji w metodze gradientów sprzężonych.


