---
number: 5
course: Informatyka 2
material: Instrukcja 5
author: W. Gryglas
---

# Całkowanie numeryczne układów równań

Pliki do wykorzystania w poniższym ćwiczenie można pobrać za pomocą poniższych linków:

 - [Plik nagłówkowy rk4.h](http://ccfd.github.io/courses/code/info2/rk4.h)
 - [Plik źródłowy rk4.cpp](http://ccfd.github.io/courses/code/info2/rk4.cpp)


## 1. Wstęp

## 2. Całkowanie układów rówań

### Ćwiczenia

## 3. Sprowadzanie równań wyższego rzędu do układów równań

### Ćwiczenia
Ruch wahadła matematycznego opisuje równanie różniczkowe z warunkami początkowymi (pomijamy
opór powietrza, nić jest nieważka i nierozciągliwa):
$$
\begin{aligned}
\frac{d^2\alpha}{dt^2} &= -\frac{g}{l}sin(\alpha) \\
\alpha(t_0) &= \alpha_0 \\
\frac{d\alpha}{dt}(t_0) &= \omega_0
\end{aligned}
$$
gdzie:

$\alpha$ - kąt wychylenia wahadła z położenia równowagi,

$g$ - przyśpieszenie ziemskie,

$l$ - długość wahadła,

$m$ - masa kuli zaczepionej na końcu wahadła.

1. Sprowadzić powyższe równanie różniczkowe rzędu drugiego do układu równań różniczkowych rzędu pierwszego.
2. Napisać program który używając metody Rungego-Kutty wyznacza zależność kąta wychylenia wahadła od czasu $\alpha(t)$ oraz prędkość kątową $\omega = \frac{d\alpha}{dt}$ dla czasu $t \in \left[0,10\right]$
3. Dodatkowo wyznaczyć zależność energii całkowitej wahadła od czasu $E(t)$, energia całkowita wahadła wyraża się wzorem:
$$E = \frac{ml^2}{2}(\frac{d\alpha}{dt})^2 + mgl(1-cos(\alpha))$$
**Uwaga**: Przy braku dyssypacji, energia mechaniczna powinna być stała.
4. Powtórzyć obliczenia dla różnych kroków czasowych.