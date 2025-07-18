---
number: 9
course: Informatyka 2
material: "Raport"
---

# Raport

W ramach przedmiotu Informatyka 2 należy rozwiązać zadanie domowe (projekt).
Na rozwiązanie składa się **kod programu** oraz **raport** z przeprowadzonych obliczeń.

## Zakres raportu

Raport powinien zawierać cztery podstawowe części:

  1. **Opis zagadnienia**  
  Należy narysować układ mechaniczny będący przedmiotem zadania i zaznaczyć na rysunku wszystkie wielkości (siły, przemieszczenia, itd.), które potrzebne są do rozwiązania zadania.
  2. **Równania ruchu i energii**  
  Należy wyprowadzić równania ruchu oraz wzór na energię całkowitą dla danego zagadnienia.
  Równania ruchu należy sprowadzić do układu równań różniczkowych pierwszego rzędu.
  3. **Opis metody obliczeniowej**  
  Równania należy rozwiązać za pomocą metody Rungego-Kutty 4 rzędu.
  Wszystkie wielkości, od których zależy rozwiązanie (warunki początkowe, krok całkowania, itd.) powinny być podane a ich wartości uzasadnione.
  4. **Wyniki i ich analiza**  
  Rozdział powinien zawierać wykresy prędkości i położenia w czasie, wykres trajektorii układu w przestrzeni fazowej (jeśli układ ma więcej niż dwa stopnie swobody wykres ten należy pominąć) oraz wykres energii.
  Wyniki powinny być przeanalizowane.

## Przykładowy raport

Raport można przygotować w dowolnym edytorze.
Przykład (w różnych formatach) można pobrać za pomocą linków:

- [PDF](https://github.com/ccfd/report-template/blob/auto/pdf/info2.pdf?raw=true)
- [LaTeX](https://github.com/ccfd/report-template/archive/auto/latex.zip)
- [rmarkdown (oryginał)](https://github.com/ccfd/report-template/archive/master.zip)

System `LaTeX` pozwala na przygotowanie dokumentu wysokiej jakości przy niedużym nakładzie pracy.
Osoby zainteresowane tym językiem odsyłamy do
[Instrukcji](http://ccfd.github.io/courses/info3_lab_5.html), która zawiera krótkie wprowadzanie do `LaTeXa`.
Pracę z systemem `LaTeX` wygodnie jest zacząć od edytora dostępnego w sieci Internet, np:

- [overleaf](https://www.overleaf.com)

**Uwagi**:  
Aby uzyskać formatowanie takie jak w przykładowym raporcie w preambule pliku `raport.tex` wystarczy wpisać:
```{.tex}
\documentclass[12pt]{sprawozdanie}

\title{Tytuł}
\author{Autor nr indeksu}
\class{Nazwa przedmiotu}
\deadline{Termin oddania}
\instructor{Prowadzący}
```
oraz pobrać pliki:

- [sprawozdanie.cls](https://github.com/ccfd/report-template/blob/master/sprawozdanie.cls)
- [znak.tex](https://github.com/ccfd/report-template/blob/master/znak.tex)

i umieścić je w katalogu, w którym znajduje się plik `raport.tex`.
