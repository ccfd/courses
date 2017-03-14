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
Nie powinien zawierać żadnych elementów, które rozpraszają lub odwracają jego uwagę od tego co jest najważniejsze -- od treści.
Aby zrealizować ten cel należy wybrać: krój czcionki (szeryfowa, bezszeryfowa), ustalić liczbę wyrazów w linii (50, 66 a może 80?), dokonać podziału wyrazów niemieszczących się w linii, ustalić położenie wykresów i tabel na kartce papieru (góra, dół) oraz wiele innych.
Nie jest to proste, zwłaszcza jeśli zmienimy coś w gotowym tekście wymuszając przesunięcie rysunków i tabel.

Aby zachować wysoki poziom zasad typograficznych i jednocześnie ułatwić autorowi skupienie się na treści dokumentu stworzono program $\LaTeX$ (wł. zestaw makr i instrukcji do obsługi programu $\TeX$).
Nazwę $\LaTeX$ czytamy `la-tech`. Program rozdziela funkcję autora od zecera (osoby dokonującej składu tekstu) i zwalnia nas z odpowiedzialności za prawidłową typografię.

Pisanie w $\LaTeX u$ w pewnym stopniu przypomina pisanie w języku HTML.
"Program" składa się z właściwego tekstu i zestawu instrukcji, które mówią o tym jak nasz tekst ma wyglądać po "kompilacji".
Dzięki ogromnej liczbie pakietów i szablonów dostępnych w systemie $\LaTeX$ można tworzyć wiele różnych typów dokumentów.
Na dzisiejszych zajęciach skorzystamy z podstawowego typu `article`.

W celu poszerzenie wiedzy autorzy polecają pozycję: *Nie za krótkie wprowadzenie do systemu $\LaTeX 2_{\varepsilon}$*.

# Pierwszy dokument

Przejdziemy teraz do stworzenia pierwszego dokumentu w $\LaTeX u$.
Najpierw musimy zadeklarować klasę dokumentu.
Robimy to za pomocą polecenia `\documentclass[opcje]{typ}`{.tex}, które umożliwia nam wybranie typu dokumentu (`article`, `report`, `book`, `letter`) oraz dodatkowych opcji, np.

* rozmiaru pisma (`10pt`, `11pt`, itp.),
* rozmiaru papieru (`a4paper`, `letterpaper`),
* czy strona tytułowa ma być wygenerowana osobno (`titlepage`, `notitlepage`),
* liczby kolumn (`onecolumn`, `twocolumn`),
* czy tekst ma być przygotowany do wydruku dwustronnego (`oneside`, `twoside`), itd.

Opcje ujęte w nawiasy kwadratowe (`[` i`]`) nie są obligatoryjne -- jeśli nie zdefiniujemy żadnej zostaną użyte wartości domyślne.

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

### Pakiety

Domyślne reguły można (i często trzeba) rozszerzyć wykorzystując dodatkowe pakiety.
Przykładowo, kompletną obsługę języka polskiego włączamy za pomocą:

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
i skompiluj ponownie tekst. Sprawdź co się stanie jeśli opcja osobnej strony tytułowej nie będzie włączona.

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
W tym celu dodaj instrukcję na początku ciała dokumentu
```{.tex}
\tableofcontents
```

### Listy i numeracje

Wypunktowania i numeracje uzyskuje się wykorzystując tzw. środowiska.
Charkteryzują się one dwiema instrukcjami: otwierającą `\begin{}`{.tex} i zamykającą `\end{}`{.tex}.
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

Żaden dobry tekst naukowy nie może obyć się bez równań (chodź znaleźli by się i tacy, którzy twierdzą inaczej).
W $\LaTeX u$ istnieje kilka sposobów dodawania wyrażeń matematycznych.
Perwszy umożliwia wstawianie wyrażeń w tej samej linii co tekst (z ang. często mówi się *inline*)
```{.tex}
przereklamowany wzór $E=mc^2$ powstał \ldots
```
Kolejny sposób to dodanie środowiska, które pozwala na wyświetlenie równania w osobnym wierszu, np.
```{.tex}
dla trójkąta prostokątnego zachodzi:
\begin{displaymath}
  c ^ 2 = a ^ 2 + b ^ 2
\end{displaymath}
```
Dla utrzymania porządku czasem warto numerować równania
```{.tex}
\begin{equation}
  c ^ 2 = a ^ 2 + b ^ 2
\end{equation}
```

Przedstawimy teraz podstawowe symbole i techniki wykorzystywane przy wpisywaniu rówań matemataycznych

W celu *dezorientacji* czytającego często stosuje się greckie litery:
```{.tex}
  \[
    \alpha, \beta, \gamma, \delta, \epsilon, \varepsilon, \zeta, \eta, \theta, \vartheta, \kappa, \lambda, \mu, \nu, \xi, \pi, \rho, \varrho, \sigma, \tau, \upsilon, \phi, \varphi, \chi, \psi, \omega
  \]
```
Wielkie litery, będące odpowiednikami małych, otrzymuje się przez zamianę na dużą pierwszej litery danej nazwy (`\alpha`{.tex} -> `\Alpha`{.tex}).


Indeksy otrzymuje się przez:
```{.tex}
\[
  n^3=m^{a^2-d}
\]
\[
  \alpha_{1,2}=x_1+y_{1,2}
\]
```

Pierwiastki to
```{.tex}
\[
  R = \sqrt{x ^ 2 + y ^ 2 + z ^ 2}
\]
```

Symbol wektora
```{.tex}
\[
  \vec{z} = \vec{x} \times\vec{y}
\]
```

Podkreślenia i klamry wykorzystywane do komentowania poszczególnych części wzorów:
```{.tex}
\[
  \overline{x + i \cdot y}\cdot\underline{v - i \cdot w}
\]
\[
  \underbrace{M_{\mu \nu} + 1}_{\neq 0} \Rightarrow \overbrace{N_{\nu \mu}}^{= 0}
\]
```

Nazwy funkcji powinny być zapisane zwykłą czcionką:
```{.tex}
\[
  1 = \sin^2(x) + \cos^2(x)
\]
```
a nie pochyloną:
```{.tex}
\[
  1 = sin^2(x) + cos^2(x)
\]
```

Ułamki piętrowe uzyskujemy przez
```{.tex}
\[
  \frac{x ^ 3 + \sqrt{x^2}}{x ^ 2 + x - 1}
\]
```

Nawiasy możemy wprowadzić wprost
```{.tex}
\[
  y=((\frac{1}{1 + x})^2 - 1)
\]
```
Nie jest to jednak alagancki sposób.
W przypadku równań, które wymagają nawiasów różnej wysokości lepiej jest napisać
```{.tex}
\[
  y=\left( \left( \frac{1}{1 + x} \right)^2 - 1 \right)
\]
```

Całki zapisujemy:
```{.tex}
\[
  \Gamma(z)=\int_{0}^{\inf}x^{z-1} e^{-x} dx
\]
```
Natomiast sumy:
```{.tex}
\[
  S=\sum_{n=1}^{\inf} a \cdot q^{n-1}
\]
```

Macierze zapisujemy stosując środowisko `array`{.tex}
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

Środowisko te można także wykorzystać do zapisu warunków
```{.tex}
\[
f(x)=\left\{
\begin{array}{lr}
0 & x > 0 \\
1 & x\leq 0 \\
\end{array}
\right.
\]
```

# Tabele

# Grafika
