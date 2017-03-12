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
Robimy to za pomocą polecenia `\documentclass[opcje]{typ}`, które umożliwia nam wybranie typu dokumentu (`article`, `report`, `book`, `letter`) oraz dodatkowych opcji, np.

* rozmiaru pisma (`10pt`, `11pt`, itp.),
* rozmiaru papieru (`a4paper`, `letterpaper`),
* czy strona tytułowa ma być wygenerowana osobno (`titlepage`, `notitlepage`),
* liczby kolumn (`onecolumn`, `twocolumn`),
* czy tekst ma być przygotowany do wydruku dwustronnego (`oneside`, `twoside`), itd.

Opcje ujęte w nawiasy kwadratowe (`[` i`]`) nie są obligatoryjne -- jeśli nie zdefiniujemy żadnej zostaną użyte wartości domyślne.

W edytorze tekstu wpisz poniższy kod:
```tex
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

* `\usepackage[T1]{fontenc}` - zawiera czcionkę z polskimi znakami,
* `\usepackage[utf8]{inputenc}` - definiuje kodowanie (`utf8` - Linux, `Cp1250` - Windows) znaków w pliku źródłowym,
* `\usepackage[english, polish]{babel}`- definiuje język dokumentu,
* `\usepackage{polski}` - wymusza polskie reguły składu dokumentu. 

Pakiety, z których planujemy korzystać umieszczamy za instrukcją `\documentclass`.
Zmodyfikuj teraz kod źródłowy tak, aby polskie znaki wydrukowały się prawidłowo.

### Strona tytułowa

Ponieważ teraz tekst wygląda elegancko, warto pochwalić się swoim osiągnięciem światu.
Włącz opcję utworzenia osobnej strony tytułowej i dodaj (za instrukcjami dołączającymi pakiety) instrukcje "sterujące" jej zawartością, np.:
```tex
\author{Gall Anonim}
\title{Kroniki}
\date{1113-1116}
```
W "ciele" dokumentu (między instrukcjami `\begin{document}` i `\end{document}`) umieść instrukcję
```tex
\maketitle
```
i skompiluj ponownie tekst. Sprawdź co się stanie jeśli opcja osobnej strony tytułowej nie będzie włączona.

# Podział logiczny dokumentu

### Sekcje

Rzadko mamy do czynienia z tekstami pozbawionymi struktury logicznej.
Przemyślana kompozycja dokumentu pozwala uporządkować treść i ułatwia jej zapamiętanie.
W $\LaTeX u$ podstawowy podział dokumentu można otrzymać wykorzystując instrukcje:
```tex
\section{Nazwa}
\subsection{Nazwa}
\subsubsection{Nazwa}
```
Sprawdź jak działają wymienione polecenia.

### Listy i numeracje

Wypunktowania i numeracje uzyskuje się wykorzystując tzw. środowiska.
Charkteryzują się one instrukcjami: otwierającą `\begin{}` i zamykającą `\end{}`.
W przypadku listy nieuporządkowanej napiszemy:
```tex
\begin{itemize}
  \item A
  \item B
\end{itemize}
```
Z kolei dla listy uporządkowanej
```tex
\begin{enumerate}
  \item A
  \item B
\end{enumerate}
```
Utwórz teraz zagnieżdżoną listę:

  \begin{enumerate}
    \item A1
      \begin{enumerate}
        \item A2
        \item B2
          \begin{itemize}
            \item A3
            \item B3
          \end{itemize}
        \item C2
      \end{enumerate}
    \item B1
  \end{enumerate}

# Wzory i równania matematyczne

$$
\begin{aligned}
 AR(p): Y_i &= c + \epsilon_i + \phi_i Y_{i-1} \dots \\
 Y_{i} &= c + \phi_i Y_{i-1} \dots
\end{aligned}
$$

# Tabele

# Grafika
