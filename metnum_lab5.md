


---
number: 5
course: Metody Numeryczne
material: Instrukcja 5
author: Ł. Łaniewski-Wołłk
---

Na tych laboratoriach skupimy się na scałkowaniu równania ruchu:
\[M\ddot{x} = F - Sx\]
Gdzie $x$ to odkształcenie, $M$ to macierz masowa, zaś $S$ to macierz sztywności.

Na początek przez $y$ oznaczmy prędkość odkształcenia, czyli $y = \dot{x}$. Teraz mamy układ równań pierwszego rzędu:

\[\begin{cases}
M\dot{y} &= F - Sx\\
\dot{x} &= y\\
\end{cases}\]

Zastępując pochodną po lewej stronie przez różnice skończoną mamy:

\[\begin{cases}
M\frac{y_{n+1}-y_n}{\text{dt} } &= F - Sx\\
\frac{x_{n+1}-x_n}{\text{dt} } &= y\\
\end{cases}\]

Po prawej stronie równania możemy użyć $x$ i $y$ z nowej ($n+1$), bądź starej ($n$) iteracji. W zależności co użyjemy otrzymamy mniej lub bardziej uwikłane równanie, a schemat będzie jawny (explicit) bądź niejawny (implicit).

Uwaga: by porównać różne schematy, każdy schemat napisz w nowej funkcji, która powinna brać następujące argumenty: `void Dynamics(int n, double * x, double * y, double T, double dt);`, gdzie `x` i `y` to początkowe wartości $x$ i $y$, `T` to całkowity czas całkowania, a `dt` to krok czasowy.



# Schemat prawie jawny (almost explicit)
Na początek wstawmy po prawej stronie wartości ze starej iteracji. Otrzymamy:

\[\begin{cases}
My_{n+1} &= My_n + \text{dt}( F - Sx_n)\\
x_{n+1} &= x_n + \text{dt} y_n\\
\end{cases}\]


### Zadanie
Napisz funkcję mnożącą przez macierz masową. W pliku `MesLib.h` jest ona zdefiniowana w analogiczny sposób jak macierz sztywności: przez macierz $M$ i stałą $Mm$. UWAGA: W mnożeniu przez macierz masową, należy także zamrozić wybrane stopnie swobody.


### Zadanie
Napisz funkcję całkującą równanie ruchu układu wg. następującego schematu:
- Oblicz $b = My + dt(F - Sx)$
- Oblicz $x = x + dt y$
- Rozwiąż układ: $My=b$
- Co $10$-tą iterację wyświetl belkę.


### Zadanie
 Przeanalizuj dla jakich $dt$ układ jest stabilny, a dla jakich nie. 

### Zadanie
 Jak wygląda wzór na całkowitą energię układu (energia potencjalna sprężystości + praca sił + energia kinetyczna)? Zróżniczkuj ją po $t$ i pokaż, że jest stała

### Zadanie
 Wydrukuj w konsoli jak zmienia się całkowita energia układu w czasie.


# Schemat pół niejawny (semi-implicit)
Prostą modyfikacją jest użycie po prawej stronie $x$ ze starej iteracji i $y$ z nowej, otrzymując:
\[\begin{cases}
My_{n+1} &= My_n + \text{dt}( F - Sx_n)\\
x_{n+1} &= x_n + \text{dt} y_{n+1}\\
\end{cases}\]


### Zadanie
 Zmodyfikuj kod rozwiązując układ na $y$ przed modyfikacją $x$-a. 

### Zadanie
 Przeanalizuj dla jakich $dt$ układ jest stabilny. Wydrukuj zmienność energii. 


# Schemat niejawny (fully-implicit)

Możemy także po prawej stronie wziąć obie wartości z nowej iteracji, otrzymując:
\[\begin{cases}
My_{n+1} &= My_n + \text{dt}( F - Sx_{n+1})\\
x_{n+1} &= x_n + \text{dt} y_{n+1}\\
\end{cases}\]

Wstawiając drugie równanie do pierwszego otrzymujemy:
\[My_{n+1} = My_n + \text{dt}( F - S(x_n + \text{dt} y_{n+1}))\]
Przekształcając:
\[(M+\text{dt}^2S)y_{n+1} = My_n + \text{dt}( F - S x_n)\]

### Zadanie
Napisz funkcję mnożącą przez $M+\text{dt}^2S$

### Zadanie
Zmodyfikuj kod, by realizował schemat w pełni niejawny, zamieniając macierz $M$ na $M+\text{dt}^2S$ w obliczeniu $y$-ka

### Zadanie
 Przeanalizuj dla jakich $dt$ układ jest stabilny. Wydrukuj zmienność energii. 


# W pół kroku (midpoint)

Ostatnia z omówionych metod bierze po prawej stronie średnią z wartości w nowej i starej iteracji:
\[\begin{cases}
My_{n+1} &= My_n + \text{dt}( F - S\frac{x_{n+1}+x_{n}}{2})\\
x_{n+1} &= x_n + \text{dt} \frac{y_{n+1}+y_{n}}{2}\\
\end{cases}\]

Po wstawieniu drugiego równania do pierwszego mamy:
\[My_{n+1} = My_n + \text{dt}( F - S\frac{x_n + \text{dt} \frac{y_{n+1}+y_{n}}{2}+x_{n}}{2})\]
Przekształcając:
\[My_{n+1} = My_n + \text{dt}( F - S(x_n + \text{dt} \frac{y_{n+1}+y_{n}}{4})\]
Ostatecznie:
\[(M + \frac{\text{dt}^2}{4}S)y_{n+1} = My_n + \text{dt}( F - S(x_n + \text{dt} \frac{y_{n}}{4})\]


### Zadanie
Napisz funkcję mnożącą przez $M+\frac{\text{dt}^2}{4}S$

### Zadanie
Napisz funkcję całkującą równanie ruchu układu wg. następującego schematu:
- Oblicz $x = x + \frac{dt}{4} y$
- Oblicz $b = My + dt(F - Sx)$
- Oblicz $x = x + \frac{dt}{4} y$
- Rozwiąż układ: $(M + \frac{\text{dt}^2}{4}S)y=b$
- Oblicz $x = x + \frac{dt}{2} y$
- Co $10$-tą iterację wyświetl belkę.

### Zadanie
 Przeanalizuj dla jakich $dt$ układ jest stabilny. Wydrukuj zmienność energii. 

### Zadanie
 Udowodnij, że metoda pół kroku zachowuje energię układu.^[Podpowiedz: tak jak $a^2-b^2=(a+b)(a-b)$ to $x_{n+1]^TMx_{n+1} - x_{n}^TMx_{n} = (x_{n+1} - x_{n})^TM(x_{n+1} +
x_{n})$}

