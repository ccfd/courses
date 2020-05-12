---
number: 6
course: Metody Numeryczne
material: Instrukcja 6
author: Ł. Łaniewski-Wołłk
title: Zagadnienie własne
---

Na poprzednich zajęciach zajmowaliśmy się równaniem ruchu postaci:
\[
\mathbf{M} \ddot{\mathbf{x}} = \mathbf{f} - \mathbf{S} \mathbf{x}
\]
Pozwalało ono na znalezienie ruchu układu pod działaniem sił.
W szczególności, jeśli przyłożyliśmy siłę do układu a następnie ją usunęliśmy dostawaliśmy drgania swobodne.
W zależności od naszego modelu, drgania te mogły być mniej lub bardziej skomplikowane.
Na dzisiejszych zajęciach zajmiemy się problemem znalezienia harmonicznych składowych drgań, które po zsumowaniu (z odpowiednimi współczynnikami) dadzą rzeczywiste drgania jakie można zaobserwować w układzie.

Znajdźmy najpierw *rozwiązanie ogólne równania jednorodnego*, tzn. zapytajmy jakie funkcje postaci $\mathbf{x} = f(t) \mathbf{w}$ spełniają równanie bez sił:
\[
\mathbf{M} \ddot{\mathbf{x}} = -\mathbf{S} \mathbf{x}
\]
Po podstawieniu dostajemy:
\[
\ddot{f}(t) \mathbf{M} \mathbf{w} = -f(t)\mathbf{S} \mathbf{w}
\]
Jeśli znajdziemy $\mathbf{w}$ takie, że:
\[
\mathbf{M} \mathbf{w} = \lambda \mathbf{S} \mathbf{w}
\]
to otrzymamy:
\[
\lambda \ddot{f}(t) = -f(t) \quad \Rightarrow \quad
f(t) = \sin\left( t\frac{1}{\sqrt{\lambda}} \right)
\]

To oznacza, że $\mathbf{x} = \sin\left( t\frac{1}{\sqrt{\lambda}} \right) \mathbf{w}$ jest oscylującym w czasie rozwiązaniem naszego równania dynamiki.
Takie rozwiązanie nazywamy **drganiem własnym** układu.
Równanie $\mathbf{M} \mathbf{w} = \lambda \mathbf{S} \mathbf{w}$ nazywamy **równaniem własnym** a $\lambda$ to **wartość własna**.

Dziś skupimy się na znalezieniu zestawu wektorów $\mathbf{w}$ i wartości $\lambda$ dla naszego układu.


# Zacznijmy od największej wartości własnej $\lambda$

Zaczniemy od największej wartości własnej $\lambda$.
Warto zauważyć, że największa wartość własna odpowiada najniższej częstotliwości.
W zastosowaniach inżynierskich, są to zazwyczaj drgania własne najmniej tłumione i niosące najwięcej energii.

Nasz wektor $\mathbf{w}$ będziemy znajdować **metodą potęgową** (iteracyjnie).
Zauważmy najpierw, że wektor $\mathbf{w}$ może być dowolnej długości.
To znaczy, jeśli wektor $\mathbf{w}$ spełnia równanie własne, to także wektor $2 \mathbf{w}$ je spełnia.
Możemy więc arbitralnie wybrać ,,skalę'' wektora $\mathbf{w}$.
Przyjmijmy więc, że $\mathbf{w}^T \mathbf{M} \mathbf{w} = 1$, tzn., że niesie on energię kinetyczną $\frac{1}{2}$.

Pomnóżmy równanie własne przez $\mathbf{S}^{-1}$.
Otrzymamy:
\[
\mathbf{w} = \frac{1}{\lambda} \mathbf{S}^{-1} \mathbf{M} \mathbf{w}
\]
Na podstawie tego wzoru możemy skonstruować prostą iterację:
\begin{align*}
\mathbf{p} &= \mathbf{S}^{-1} \mathbf{M} \mathbf{w} \\
\mathbf{w} &= \mathbf{p} \frac{1}{\sqrt{\mathbf{p}^T \mathbf{M} \mathbf{p}}}
\end{align*}

W pierwszym etapie liczymy wynik $\mathbf{S}^{-1} \mathbf{M} \mathbf{w}$, a następnie go normalizujemy tak aby $\mathbf{w}^T \mathbf{M} \mathbf{w} = 1$.
Jeśli odpowiednio długo będziemy wykonywać taką iterację, wektor własny odpowiadający największej wartości własnej zacznie dominować.
Ostatecznie $\mathbf{w}$ będzie składać się tylko z tego wektora, a $\mathbf{p}^T \mathbf{M} \mathbf{p}$ zbiegnie do największej wartości własnej $\lambda$.

### Zadanie 1
Znajdź wektor $\mathbf{w}$ odpowiadający największej wartości własnej według następującego schematu iteracji:

- Oblicz $\mathbf{b} = \mathbf{M} \mathbf{w}$,
- Rozwiąż układ $\mathbf{S} \mathbf{p} = \mathbf{b}$,
- Oblicz $\mathbf{M} \mathbf{p}$,
- Oblicz $\mathbf{w} = \frac{1}{\sqrt{\langle \mathbf{p}, \mathbf{M} \mathbf{p} \rangle}} \mathbf{p}$.

### Zadanie 2
Pokaż przemieszczenie $\mathbf{w}$ za pomocą funkcji `draw`.
Zrób animację tego przemieszczenia przemnożonego przez $\sin\left( t\frac{1}{\sqrt{\lambda}} \right)$.


# Kolejne wartości własne $\lambda$

Chcielibyśmy aby wektory własne (drgania własne) były niezależne w energii kinetycznej.
To znaczy, żeby energia kinetyczna ich sumy była równa sumie ich energii kinetycznych
\[
E_k(\mathbf{w}^0 + \mathbf{w}^1) = E_k(\mathbf{w}^0)+E_k(\mathbf{w}^1)
\]
To w połączeniu z naszą *skalą* daje nam bardzo ważny układ warunków:
\[
\begin{cases}
(\mathbf{w}^i)^T \mathbf{M} \mathbf{w}^j = 0 & \quad \text{dla} \quad i\neq j \\
(\mathbf{w}^i)^T \mathbf{M} \mathbf{w}^j = 1 & \quad \text{dla} \quad i = j \\
\end{cases}
\]

Mówiąc językiem numeryki: wektory te są do siebie ortonormalne względem macierzy $\mathbf{M}$.
Takiej ortonormalizacji możemy dokonać za pomocą znanej z Analizy Matematycznej metody Grama-Schmidta.

## Ortonormalizacja Grama-Schmidta
Załóżmy, że mamy układ $N$ liniowo niezależnych wektorów.
Aby zortonormalizować ten układ, dla każdego $j$ od $1$ do $N$:

- dla każdego $i$ od $1$ do $j-1$ należy wykonać (dla $i=1$ nie trzeba nic robić):
- oblicz $\mathbf{w}^i = \mathbf{w}^i - \mathbf{w}^j \langle \mathbf{w}^j, \mathbf{M} \mathbf{w}^i \rangle$,
- oblicz $\mathbf{w}^i = \frac{1}{\sqrt{\langle \mathbf{w}^i, \mathbf{M} \mathbf{w}^i \rangle}}\mathbf{w}^i$.

Po tej procedurze wszystkie wektory $\mathbf{w}$ są ortogonalne i długości $1$ względem macierzy $M$.

### Zadanie 3
Znajdź wektory $\mathbf{w}^i$ odpowiadające $10$-ciu największym wartościom własnym według następującego schematu iteracji:

- Oblicz $\mathbf{b} = \mathbf{M} \mathbf{w}^i$,
- Rozwiąż układ $\mathbf{S} \mathbf{p}^i = \mathbf{b}$,
- Przepisz $\mathbf{w}^i = \mathbf{p}^i$,
- Wykonaj ortonormalizację G-S wektorów $\mathbf{w}$.

### Zadanie 4
Wyznacz odpowiednie $\lambda_i$.

### Zadanie 5
Zrób animację dla kolejnych przemieszczeń $\mathbf{w}^i$ przemnożonych przez $\sin\left( t\frac{1}{\sqrt{\lambda_i}} \right)$.
