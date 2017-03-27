---
author: "K. Marchlewski"
course: Informatyka III
material: Instrukcja 5
number: 5
---

# Wstęp

Statystyczny użytkownik myszki komputerowej żyje w przekonaniu, iż stworzenie dokumentu tekstowego wysokiej jakości jest stosunkowo proste.
Jest prawdopodobne, że przekonanie to zostało mu zaszczepione przez edytory typu WYSWIG (What You See is What You Get).
Klasycznym przykładem takiego programu jest MS Word.
Umożliwia on m. in. modyfikację kroju czcionki oraz rozmiaru marginesów w taki sposób aby dokument był przyjemny dla oka.
Czy wizualna atrakcyjność dokumentu oznacza jednak, że dokument jest wysokiej jakości?
Ciężko powiedzieć... nie napisaliśmy jeszcze co to znaczy "dokument wysokiej jakości".

Otóż, dokument powinien być tak sformatowany, aby umożliwić czytelnikowi całkowite skupienie się na tekście.
Nie powinien zawierać elementów, które rozpraszają lub odwracają jego uwagę od tego co jest najważniejsze -- od treści.
Aby zrealizować ten cel należy wybrać: krój czcionki (szeryfowa, bezszeryfowa), ustalić liczbę wyrazów w linii (50, 66 a może 80?), dokonać podziału wyrazów, które nie mieszczą się w linii, ustalić położenie wykresów i tabel na kartce papieru (góra, dół) oraz wiele innych.
Nie jest to proste, zwłaszcza jeśli zmienimy coś w gotowym tekście wymuszając przesunięcie rysunków i tabel na kartce.

Aby zachować wysoki poziom zasad typograficznych i jednocześnie ułatwić autorowi skupienie się na treści dokumentu stworzono program $\LaTeX$ (wł. zestaw makr i instrukcji do obsługi programu $\TeX$).
Nazwę $\LaTeX$ czytamy `la-tech`. Program rozdziela funkcję autora od zecera (osoby dokonującej składu tekstu) i zwalnia nas z odpowiedzialności za prawidłową typografię.

Pisanie w $\LaTeX u$ w pewnym stopniu przypomina pisanie w języku HTML.
"Program" składa się z właściwego tekstu i zestawu instrukcji, które mówią o tym jak nasz tekst ma wyglądać po "kompilacji".
Dzięki ogromnej liczbie pakietów i szablonów dostępnych w systemie $\LaTeX$ można tworzyć wiele różnych typów dokumentów.
Na dzisiejszych zajęciach skorzystamy z podstawowego typu `article`.

W celu poszerzenia wiedzy, autorzy polecają pozycję: *Nie za krótkie wprowadzenie do systemu $\LaTeX 2_{\varepsilon}$*.

# Pierwszy dokument

Przejdziemy teraz do stworzenia pierwszego dokumentu w $\LaTeX u$.
Najpierw musimy zadeklarować klasę dokumentu.
Robimy to za pomocą polecenia `\documentclass[opcje]{typ}`{.tex}, które umożliwia nam wybranie typu dokumentu (`article`, `report`, `book`, `letter`) oraz dodatkowych opcji, np.

* rozmiaru pisma (`10pt`, `11pt`, itp.),
* rozmiaru papieru (`a4paper`, `letterpaper`),
* czy strona tytułowa ma być wygenerowana osobno (`titlepage`, `notitlepage`),
* liczby kolumn (`onecolumn`, `twocolumn`),
* czy tekst ma być przygotowany do wydruku dwustronnego (`oneside`, `twoside`), itd.

Opcje ujęte w nawiasy kwadratowe (`[` i`]`) nie są obligatoryjne -- jeśli nie zdefiniujemy żadnej, zostaną użyte wartości domyślne.

W edytorze tekstu wpisz poniższy kod:
```{.tex}
\documentclass[11pt, a4paper, twoside]{article}

\begin{document}
  Stół z powyłamywanymi nogami!
\end{document}
```
zapisz go w pliku z rozszerzeniem `.tex`, np. `dokument.tex` i skompiluj za pomocą polecenia
```bash
pdflatex dokument.tex
```
Kompilator utworzy kilka plików, m. in. plik `dokument.pdf`, który zawiera nasz tekst.

Otwórz plik `dokument.pdf` i naciesz oczy wynikiem swojej pracy.
Ale co to?
Okazuje się, że brakuje kilku liter!
Podstawowe możliwości $\LaTeX a$ nie sięgają bowiem języka polskiego.

Istnieje wiele nakładek graficznych do środowiska $\LaTeX $.
Popularnością cieszy się Texmaker, dostępny zarówno pod Windowsa jak i Linuxa.
Do łatwej obsługi pakietów warto zainstalować managera pakietów, np MikTex.

### Pakiety

Domyślne reguły można (i często trzeba) rozszerzyć wykorzystując dodatkowe pakiety.
Przykładowo, kompletną obsługę języka polskiego włączamy dodając pakiety:

* `\usepackage[T1]{fontenc}`{.tex} - zawiera czcionkę z polskimi znakami,
* `\usepackage[utf8]{inputenc}`{.tex} - definiuje kodowanie (`utf8` - Linux, `Cp1250` - Windows) znaków w pliku źródłowym,
* `\usepackage[english, polish]{babel}`{.tex} - definiuje język dokumentu,
* `\usepackage{polski}`{.tex} - wymusza polskie reguły składu dokumentu. 

Pakiety, z których planujemy korzystać umieszczamy za instrukcją `\documentclass`.
Zmodyfikuj teraz kod źródłowy tak, aby polskie znaki wydrukowały się prawidłowo.

### Strona tytułowa

Ponieważ teraz tekst wygląda elegancko, warto pochwalić się swoim osiągnięciem światu.
Włącz opcję utworzenia osobnej strony tytułowej i dodaj (za instrukcjami dołączającymi pakiety) instrukcje "sterujące" jej zawartością, np.:
```{.tex}
\author{Gall Anonim}
\title{Kroniki}
\date{1113-1116}
```
W "ciele" dokumentu (między instrukcjami `\begin{document}`{.tex} i `\end{document}`{.tex}) umieść instrukcję
```{.tex}
\maketitle
```
i skompiluj ponownie tekst.
Sprawdź co się stanie jeśli opcja osobnej strony tytułowej nie będzie włączona.

# Podział logiczny dokumentu

### Sekcje

Rzadko mamy do czynienia z tekstami pozbawionymi struktury logicznej.
Przemyślana kompozycja dokumentu pozwala uporządkować treść i ułatwia jej zapamiętanie.
W $\LaTeX u$ podstawowy podział dokumentu można otrzymać wykorzystując instrukcje:
```{.tex}
\section{Nazwa}
\subsection{Nazwa}
\subsubsection{Nazwa}
\paragraph{Nazwa}
\subparagraph{Nazwa}
```
Podziel wybrany fragment tekstu za pomocą wymienionych poleceń i sprawdź jak działają.
Zbuduj teraz spis treści odpowiadający utworzonym rozdziałom.
W tym celu dodaj instrukcję
```{.tex}
\tableofcontents
```
na początku ciała dokumentu.

### Listy i numeracje

Wypunktowania i numeracje uzyskuje się wykorzystując tzw. otoczenia.
Charakteryzują się one dwiema instrukcjami: otwierającą `\begin{}`{.tex} i zamykającą `\end{}`{.tex}.
W przypadku listy nieuporządkowanej napiszemy:
```{.tex}
\begin{itemize}
  \item A
  \item B
\end{itemize}
```
Z kolei dla listy uporządkowanej
```{.tex}
\begin{enumerate}
  \item A
  \item B
\end{enumerate}
```
Utwórz teraz zagnieżdżoną listę:

1. A1
2. B1
    - A2
    - B2
        - A3
        - B3
    - C2
3. C1
    1. D2
    2. E2
4. D1

# Wzory i równania matematyczne

Dobry tekst naukowy nie może obyć się bez równań i wzorów (chodź znaleźli by się i tacy, którzy twierdzą inaczej).
W $\LaTeX u$ istnieje kilka sposobów dodawania wyrażeń matematycznych.
Podstawowy z nich umożliwia wstawianie wyrażeń w tej samej linii co tekst (z ang. często mówi się *inline*)
```{.tex}
  wzór $E=mc^2$ powstał \ldots
```
Kolejny sposób to wykorzystanie otoczenia, które pozwala na wyświetlenie równania w osobnym wierszu, np.
```{.tex}
dla trójkąta prostokątnego zachodzi:
\[
  c ^ 2 = a ^ 2 + b ^ 2
\]
```
Dla utrzymania porządku często warto numerować równania
```{.tex}
\begin{equation}
  c ^ 2 = a ^ 2 + b ^ 2
\end{equation}
```

Aby sprawnie posługiwać się jakimś językiem trzeba znać jego składnię.
Przedstawimy teraz podstawowe symbole i techniki wykorzystywane w $\LaTeX u$ przy wpisywaniu równań matematycznych.

Greckie litery są jednym z podstawowych elementów.
Są dość łatwe do zapamiętania ze względu na zapis fonetyczny:
```{.tex}
  \[
    \alpha, \beta, \gamma, \delta, \epsilon, \varepsilon, \zeta, \eta, \theta, \vartheta, \kappa, \lambda, \mu, \nu, \xi, \pi, \rho, \varrho, \sigma, \tau, \upsilon, \phi, \varphi, \chi, \psi, \omega
  \]
```
Wielkie litery, będące odpowiednikami małych, otrzymuje się przez zamianę na dużą pierwszej litery danej nazwy (np. `\alpha`{.tex} -> `\Alpha`{.tex}).

Indeksy górne i dolne otrzymuje się przez użycie symboli `^` i `_`:
```{.tex}
\[ n^3=m^{a^2-d} \]
\[ \alpha_{1,2}=x_1+y_{1,2} \]
```

Zapis pierwiastków wymaga z kolei instrukcji `\sqrt{}`{.tex} 
```{.tex}
\[ R = \sqrt{x ^ 2 + y ^ 2 + z ^ 2} \]
```

Symbol wektora uzyskuje się przez
```{.tex}
\[ \vec{z} = \vec{x} \times \vec{y} \]
```

Podkreślenia i klamry wykorzystywane do komentowania poszczególnych części wzorów:
```{.tex}
\[ \overline{x + i \cdot y}\cdot\underline{v - i \cdot w} \]
\[ \underbrace{M_{\mu \nu} + 1}_{\neq 0} \Rightarrow \overbrace{N_{\nu \mu}}^{= 0} \]
```

Nazwy funkcji powinny być zapisane zwykłą czcionką:
```{.tex}
\[ 1 = \sin^2(x) + \cos^2(x) \]
```
a nie pochyloną:
```{.tex}
\[ 1 = sin^2(x) + cos^2(x) \]
```

Ułamki piętrowe uzyskujemy przez
```{.tex}
\[ \frac{x ^ 3 + \sqrt{x^2}}{x ^ 2 + x - 1} \]
```

Nawiasy możemy wprowadzić wprost
```{.tex}
\[ y=((\frac{1}{1 + x})^2 - 1) \]
```
Nie jest to jednak elegancki sposób.
W przypadku równań, które wymagają nawiasów różnej wysokości lepiej jest napisać
```{.tex}
\[ y=\left( \left( \frac{1}{1 + x} \right)^2 - 1 \right) \]
```

Całki zapisujemy:
```{.tex}
\[ \Gamma(z)=\int_{0}^{\inf}x^{z-1} e^{-x} dx \]
```
Natomiast sumy:
```{.tex}
\[ S=\sum_{n=1}^{\inf} a \cdot q^{n-1} \]
```

Macierze zapisujemy stosując otoczenie `array`{.tex}
```{.tex}
\[
  \left|
    \begin{array}{ccc}
      a_{11} & a_{12} & a_{13} \\
      a_{21} & a_{22} & a_{23} \\
      a_{31} & a_{32} & a_{33} \\
    \end{array}
  \right|
\]
```

Otoczenie te można także wykorzystać do zapisu warunków
```{.tex}
\[
  \delta(x)=\left\{
    \begin{array}{lr}
      0 & x \ne 0 \\
      +\infty & x = 0 \\
    \end{array}
  \right.
\]
```

## Ćwiczenia

Zapisz poniższe równania wykorzystując system $\LaTeX$.
Niektóre symbole, których należy użyć, nie były wprowadzone wcześniej.
W sieci Internet można znaleźć listy dostępnych symboli.
W naszej pracowni można skorzystać ze strony: https://www.sharelatex.com/learn/Mathematical_expressions

$$
  i\hbar\frac{\partial}{\partial t}\Psi(\vec{r},t)=-\frac{\hbar^2}{2m}\nabla^2 \Psi(\vec{r},t) + V(\vec{r}) \Psi(\vec{r},t)
$$

$$
  \frac{\partial \mathbf{u}}{\partial t} + \mathbf{u} \cdot \nabla\mathbf{u} =
  -\frac{1}{\rho}\nabla p+\nu \nabla^{2}\mathbf{u} + \frac{1}{3}\nu \nabla (\nabla \cdot \mathbf{u}) + \mathbf{g}
$$

$$
  \oint_{\partial \Sigma}\mathbf{B} \cdot \mathrm{dl} =
  \mu_0 \iint_{\Sigma} \mathbf{J} \cdot \mathrm{d} \mathbf{S} +
  \mu_0 \varepsilon_0 \frac{\mathrm{d}}{\mathrm{dt}} \iint_{\Sigma} \mathbf{E} \cdot \mathrm{d} \mathbf{S} 
$$

$$
\mathrm{Var} \left(\hat{Z}(x_0)-Z(x_0)\right) =
\underbrace{c(x_0,x_0)}_{\mathrm{Var}(Z(x_0))}-
\underbrace{
\left(
\begin{array}{c}
c(x_1,x_0) \\
\vdots \\
c(x_n,x_0) \\
\end{array}
\right)
\left(
\begin{array}{ccc}
c(x_1,x_1) & \cdots & c(x_1,x_n)  \\
\vdots & \ddots & \vdots  \\
c(x_n,x_1) & \cdots & c(x_n,x_n)
\end{array}
\right)^{-1}
\left(
\begin{array}{c}
c(x_1,x_0) \\
\vdots \\
c(x_n,x_0)
\end{array}
\right)}_{\mathrm{Var}(\hat{Z}(x_0))}
$$

# Tabele

Istnieje wiele bibliotek rozszerzających możliwości tworzenia tabel w systemie $\LaTeX$.
Pokarzemy najprostszy przykład z wykorzystaniem otoczenia `tabular`.
Otoczenie to tworzy tabelę w sposób automatyczny, tzn. szerokości i wysokości poszczególnych komórek są dobierane do ich zawartości.
Jedyne parametry na jakie mamy wpływ to liczba kolumn i sposób ich justowania.
Przeanalizuj poniższy kod:
```{.tex}
  \begin{tabular}{c||c|c|c}
     & symb. & symb. & symb. \\ \hline \hline
    symb. & X & O & O \\ \hline
    symb. & O & X & X \\ \hline
    symb. & X & O & X \\
  \end{tabular}
```
Jaki wpływ na wygląd tabeli mają parametry `{c||c|c|c}`{.tex}?

Otoczenie `tabular` pozwala także na tworzenie wielokolumnowych rubryk.
Służy do tego polecenie `\multicolumn{l_kolumn}{justowanie}{tekst}`{.tex}.
```{.tex}
  \begin{tabular}{c|c|c}
    \multicolumn{3}{c}{symb.} \\ \hline \hline
    X & O & O \\ \hline
    O & X & X \\ \hline
    X & O & X \\
  \end{tabular}
```

Użycie powyższej konstrukcji ma pewną wadę.
Tabele dodane do dokumentu za pomocą otoczenia `tabular` nie zawsze znajdą się tam gdzie byśmy tego chcieli.
Aby mieć kontrolę nad położeniem tabeli należy użyć otoczenia `table`, które ma jeden argument opcjonalny mówiący o tym gdzie na stronie ma się znaleźć wstawka z tabelą.
Dodatkowo, otoczenie to pozwala na dodanie podpisu do naszej tabeli.
Służy do tego instrukcja `\caption{podpis}`{.tex}.
Przykładowo, jeśli chcemy aby tabela znalazła się dokładnie w miejscu użycia, napiszemy:
```{.tex}
\begin{table}[h]
  \begin{tabular}{c|c|c}
    X & O & O \\ \hline
    O & X & X \\ \hline
    X & O & X \\
  \end{tabular}
  \caption{Kółko i krzyżyk.}
\end{table}
```
Pozostałe parametry to:

- `t` -- umieść wstawkę na górze strony,
- `b` -- umieść wstawkę na dole strony,
- `p` -- umieść wstawkę na oddzielnej stronie ze wstawkami.

## Ćwiczenia

Wykonaj poniższą tabelę:

![](figures/info3_lab_5_table.png "Tabela")

# Grafika

Wstawienie grafiki w $LaTeX u$ ogranicza się do użycia instrukcji `\includegraphics[parametry]{sciezka_do_grafiki}`{.tex}.
Przykładowo, jeśli chcemy wstawić obrazek, którego szerokość będzie równa `95%` szerokości tekstu napiszemy:
```{.tex}
\includegraphics[width=.95\textwidth]{rysunek.pdf}
```

Podobnie jak to było w przypadku tabel, kontrolę nad położeniem rysunku i możliwość dodawania podpisów otrzymamy po zastosowaniu specjalnego otoczenia.
W przypadku grafiki będzie to otoczenie `figure`:
```{.tex}
\begin{figure}[!h]
    \includegraphics[width=.95\textwidth]{rysunek.pdf}
    \caption{Rysunek.}
\end{figure}
```


# Na pewno się przyda...

Do tworzenia profesjonalnych prezentacji w $\LaTeX u$ wykorzystuje się template - 'beamer'.
Innym przydatnym narzędziem jest serwis https://www.overleaf.com/ pozwalający na tworzenie dokomentów on-line przez wielu użytkowników jednocześnie.
