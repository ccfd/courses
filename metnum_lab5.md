---
number: 5
course: Metody Numeryczne
material: Instrukcja 5
author: Ł. Łaniewski-Wołłk
title: Równania ruchu
---

Na tych laboratoriach skupimy się na scałkowaniu równania ruchu:
\[
\mathbf{M} \ddot{\mathbf{x}} = \mathbf{f} - \mathbf{S} \mathbf{x}
\]
Gdzie $\mathbf{x}$ to odkształcenie, $\mathbf{f}$ to siła, $\mathbf{M}$ to macierz masowa, zaś $\mathbf{S}$ to macierz sztywności.

Na początek przez $\mathbf{y}$ oznaczmy prędkość odkształcenia, czyli $\mathbf{y} = \dot{\mathbf{x}}$.
Teraz mamy układ równań pierwszego rzędu:

\[
\begin{cases}
\mathbf{M} \dot{\mathbf{y}} & = \mathbf{f} - \mathbf{S} \mathbf{x} \\
\dot{\mathbf{x}} & = \mathbf{y} \\
\end{cases}
\]

Zastępując pochodną po lewej stronie przez różnicę skończoną mamy:

\[
\begin{cases}
\mathbf{M} \frac{\mathbf{y}^{n+1} - \mathbf{y}^n}{\text{dt}} & = \mathbf{f} - \mathbf{S} \mathbf{x} \\
\frac{\mathbf{x}^{n+1} - \mathbf{x}^n}{\text{dt}} & = \mathbf{y} \\
\end{cases}
\]

Po prawej stronie równania możemy użyć $\mathbf{x}$ i $\mathbf{y}$ z nowej ($n+1$), bądź starej ($n$) iteracji.
W zależności co użyjemy otrzymamy mniej lub bardziej uwikłane równanie, a schemat będzie jawny (explicit) bądź niejawny (implicit).  
**Uwaga**: aby porównać różne schematy, każdy schemat zapisz w oddzielnej funkcji, której nagłówek powinien mieć postać:
```c++
void Dynamics_schemat(int N, double *x, double *y, double *f, double t_max, double dt);
```
gdzie `x` i `y` to początkowe wartości $\mathbf{x}$ i $\mathbf{y}$, `f` to wektor sił, `t_max` to całkowity czas całkowania, a `dt` to krok czasowy.


# Schemat prawie jawny (almost explicit)

Na początek wstawmy po prawej stronie wartości ze starej iteracji.
Otrzymamy:
\[
\begin{cases}
\mathbf{M} \mathbf{y}^{n+1} & = \mathbf{M} \mathbf{y}^n + \text{dt}(\mathbf{f} - \mathbf{S} \mathbf{x}^n) \\
\mathbf{x}^{n+1} & = \mathbf{x}^n + \text{dt} \mathbf{y}^n \\
\end{cases}
\]

### Zadanie
Napisz funkcję mnożącą przez macierz masową $\mathbf{M}$.
W pliku `MesLib.h` jest ona zdefiniowana w analogiczny sposób jak macierz sztywności: przez globalną tablicę `M` i globalną stałą `Mm`.  
**Uwaga**: W mnożeniu przez macierz masową, należy także zamrozić wybrane stopnie swobody.

### Zadanie
Napisz funkcję całkującą równanie ruchu układu według następującego schematu:

- Oblicz $\mathbf{b}^n = \mathbf{M} \mathbf{y}^n + \text{dt} (\mathbf{f} - \mathbf{S} \mathbf{x}^n)$,
- Oblicz $\mathbf{x}^{n+1} = \mathbf{x}^n + \text{dt} \mathbf{y}^n$,
- Rozwiąż układ: $\mathbf{M} \mathbf{y}^{n+1} = \mathbf{b}^n$,
- Co $10$-tą iterację wyświetl belkę.


### Zadanie
Przeanalizuj dla jakich $\text{dt}$ układ jest stabilny, a dla jakich nie. 

### Zadanie
Jak wygląda wzór na całkowitą energię układu (energia potencjalna sprężystości + praca sił + energia kinetyczna)?
Zróżniczkuj ją po $t$ i pokaż, że jest stała.

### Zadanie
Wydrukuj w konsoli jak zmienia się całkowita energia układu w czasie.


# Schemat pół niejawny (semi-implicit)

Prostą modyfikacją jest użycie po prawej stronie $\mathbf{x}$ ze starej iteracji i $\mathbf{y}$ z nowej, otrzymując:
\[
\begin{cases}
\mathbf{M} \mathbf{y}^{n+1} & = \mathbf{M} \mathbf{y}^n + \text{dt}(\mathbf{f} - \mathbf{S} \mathbf{x}^n) \\
\mathbf{x}^{n+1} & = \mathbf{x}^n + \text{dt} \mathbf{y}^{n+1} \\
\end{cases}
\]

### Zadanie
Przekopiuj funkcję `Dynamics` i zmodyfikuj ją tak aby układ na $\mathbf{y}^{n+1}$ był rozwiązywany przed obliczeniem $\mathbf{x}^{n+1}$. 

### Zadanie
Przeanalizuj dla jakich $\text{dt}$ układ jest stabilny.
Wydrukuj zmienność energii. 


# Schemat niejawny (fully-implicit)

Możemy także po prawej stronie wziąć obie wartości z nowej iteracji, otrzymując:
\[
\begin{cases}
\mathbf{M} \mathbf{y}^{n+1} & = \mathbf{M} \mathbf{y}^n + \text{dt}(\mathbf{f} - \mathbf{S} \mathbf{x}^{n+1}) \\
\mathbf{x}^{n+1} & = \mathbf{x}^n + \text{dt} \mathbf{y}^{n+1} \\
\end{cases}
\]

Wstawiając drugie równanie do pierwszego otrzymujemy:
\[
\mathbf{M} \mathbf{y}^{n+1} = \mathbf{M} \mathbf{y}^n + \text{dt}(\mathbf{f} - \mathbf{S} (\mathbf{x}^n + \text{dt} \mathbf{y}^{n+1}))
\]
Po przekształceniu:
\[
(\mathbf{M} + \text{dt}^2\mathbf{S}) \mathbf{y}^{n+1} = \mathbf{M} \mathbf{y}^n + \text{dt}(\mathbf{f} - \mathbf{S} \mathbf{x}^n)
\]

### Zadanie
Napisz funkcję mnożącą przez $\mathbf{M} + \text{dt}^2 \mathbf{S}$

### Zadanie
Zmodyfikuj kod, by realizował schemat w pełni niejawny, zamieniając macierz $\mathbf{M}$ na $\mathbf{M} + \text{dt}^2 \mathbf{S}$ w obliczeniu $y$-ka.

### Zadanie
Przeanalizuj dla jakich $\text{dt}$ układ jest stabilny.
Wydrukuj zmienność energii. 


# W pół kroku (midpoint)

Ostatnia z metod, którymi się zajmiemy bierze po prawej stronie średnią z wartości w nowej i starej iteracji:
\[
\begin{cases}
\mathbf{M} \mathbf{y}^{n+1} & = \mathbf{M} \mathbf{y}^n + \text{dt} \left( \mathbf{f} - \mathbf{S} \frac{\mathbf{x}^{n+1} + \mathbf{x}^n}{2} \right) \\
\mathbf{x}^{n+1} & = \mathbf{x}^n + \text{dt} \frac{\mathbf{y}^{n+1} + \mathbf{y}^n}{2} \\
\end{cases}
\]

Po wstawieniu drugiego równania do pierwszego mamy:
\[
\mathbf{M} \mathbf{y}^{n+1} = \mathbf{M} \mathbf{y}^n + \text{dt} \left( \mathbf{f} - \mathbf{S} \frac{\mathbf{x}^n + \text{dt} \frac{\mathbf{y}^{n+1} + \mathbf{y}^n}{2} + \mathbf{x}^n}{2} \right)
\]
Po uproszczeniu:
\[
\mathbf{M} \mathbf{y}^{n+1} = \mathbf{M} \mathbf{y}^n + \text{dt} \left( \mathbf{f} - \mathbf{S} \left( \mathbf{x}^n + \text{dt} \frac{\mathbf{y}^{n+1} + \mathbf{y}^n}{4} \right) \right)
\]
Ostatecznie:
\[
\left( \mathbf{M} + \frac{\text{dt}^2}{4} \mathbf{S} \right) \mathbf{y}^{n+1} =
\mathbf{M} \mathbf{y}^n + \text{dt} \left( \mathbf{f} - \mathbf{S} \left( \mathbf{x}^n + \text{dt} \frac{\mathbf{y}^n}{4} \right) \right)
\]

### Zadanie
Napisz funkcję mnożącą przez $\mathbf{M} + \frac{\text{dt}^2}{4} \mathbf{S}$.

### Zadanie
Napisz funkcję całkującą równanie ruchu według następującego schematu (dla uproszczenia zapisu pominęliśmy number `n` iteracji):

- Oblicz $\mathbf{x} = \mathbf{x} + \frac{\text{dt}}{4} \mathbf{y}$,
- Oblicz $\mathbf{b} = \mathbf{M} \mathbf{y} + \text{dt} (\mathbf{f} - \mathbf{S} \mathbf{x})$,
- Oblicz $\mathbf{x} = \mathbf{x} + \frac{\text{dt}}{4} \mathbf{y}$,
- Rozwiąż układ: $(\mathbf{M} + \frac{\text{dt}^2}{4} \mathbf{S}) \mathbf{y} = \mathbf{b}$,
- Oblicz $\mathbf{x} = \mathbf{x} + \frac{\text{dt}}{2} \mathbf{y}$,
- Co $10$-tą iterację wyświetl belkę.

### Zadanie
Przeanalizuj dla jakich $\text{dt}$ układ jest stabilny.
Wydrukuj zmienność energii. 

### Zadanie
Udowodnij, że metoda ,,w pół kroku'' zachowuje energię układu.^[Podpowiedź: tak jak $a^2-b^2=(a+b)(a-b)$ to $x_{n+1}^TMx_{n+1} - x_{n}^TMx_{n} = (x_{n+1} - x_{n})^TM(x_{n+1} +
x_{n})$]
