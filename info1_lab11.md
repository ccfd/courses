---
author: "Ł. Łaniewski-Wołłk"
course: Informatyka I
material: Instrukcja Dodatkowa I
number: 11
---

Na dzisiejszych zajęciach będziemy programować mikrokontroler.

Mikrokontroler to mały układ scalony, który (zazwyczaj) ma w sobie zintegrowane wszystkie komponenty potrzebne do wykonywania małych programów. Tzn: processor, pamięć stałą (na program), pamięć operacyjną (na dane), zegar, elementy wejścia wyjścia. Wpisanie programu do pamięci stałej mikrokontrolera nazywamy "programowaniem" mikrokontrolera i najczęściej odbywa się przez pobudzenie wybranych pinów układu scalonego w zadany sposób. Do tego używamy "programatora".

Na tych zajęciach użyjemy płytkę prototypową kompatybilną z Arduino. Urządzenia takie mają zintegrowane na jednej płytce: mikrokontroler i interfejs USB, a dodatkowo wgrany mają fabrycznie tak zwany "bootloader". Bootloader pełni rolę programatora, pozwalając wgrać programy do pamiecy stałej mikrokontrollera przez interfejs szeregowy. Bootloader Arduino stał się tak popularny, że wiele innych firm produkuje płytki z mikrokontolerami z wgranym ich bootloaderem. Pozwala to na programowanie wszelkich takich płytek przy pomocy tego samego zestawu narzędzi.

## Zaczynamy

Dziś będziemy używać narzędzia Arduino IDE.

### Przygotowanie

Programy dla Arduino mają dwa komponenty: `setup()` w której inicjalizujemy stan mikrokontrolera i wszystkie zmienne, i `loop()` która jest powtarzana w nieskończoność i wykonuje zazwyczaj zawiera gówną logikę programu. Można sobie wyobrazić, że mikrokontroler będzie wykonywał następujący program:
```c
void main() {
    setup();
    while (1) {
        loop();
    }
}
```

Na początek ustawimy stany wszystkich pinów które będziemu używać:
```c
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, OUTPUT);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, OUTPUT);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, OUTPUT);
}

void loop() {

}
```

Piny na płytce można ustawić na wiele stanów. Tu używamy `OUTPUT`, który pozwala na ustawianie wyjscia na pinie na `0` (`LOW`) i `1` (`HIGH`), i `INPUT_PULLUP`, który pozwala na sprawdzanie na pinie czy jest on podłączony (`LOW`) czy nie (`HIGH`) do zera (ground). Piny 2,4,6 i 8 podłączymy do LEDow w przyciskach, zaś 3,5,7 i 9 podłączymy do przycisków. Pin 10 użyjemy do buzzera.

### Buzzer
Pierw wybróbujemy buzzer. Buzzer to mały piezoelektryczny głosnik zaprojektowany do wydawania tonów. Możemy podłączyć jedno wyjście buzzera do zera (`GND`) a drugi do pinu 10 (`D10`). Możemy wtedy użyć komendy `tone(pin, frequency, duration)`, żeby wysłać na pinie kwadratową falę o zadanej czestotliwości, i funkcji `delay(duration)` by poczekać zadany czas.
```
void loop() {
    tone(10, 262, 500); // C4 - 261.626 Hz
    delay(1000);
}
```

Dodatkowo możemy zapalić zintegrowaną diodę LED:

```
void loop() {
    tone(10, 262, 500); // C4 - 261.626 Hz
    delay(1000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
}
```

### Przyciski
Możemy teraz podłączyć przyciski. Każdy przycisk ma 4 porty, dwa styki przełącznika i dwa styki LED. Dioda LED jest w obudowie zlutowana w opornikiem limitującym natężenie, wiec nie bedziemy potrzebować dodatkowych komponentów. **Nigdy nie należy podłączać diody LED bez rezystora**.

W każdym przycisku jeden styk przełącznika i jeden styk LED podłączymy do zera (`GND`) a pozostały styk przełącznika podłączymy do pinu w stanie `INPUT_PULLUP`, a styk LED do `OUTPUT`. Ostatecznie będziemy mieli 4x2 stykow podłączonych do pinów od `D2` do `D9`, i łańcuszek styków podłączonych do zera.

Teraz możemy obsłużyć przyciski:
```
void loop() {
    for(int i=0;i<4;i++) {
        int switch_pin = i*2+3;
        int led_pin = i*2+2;
        if (digitalRead(switch_pin) == LOW) {
            digitalWrite(led_pin,HIGH);
        } else {
            digitalWrite(led_pin,LOW);
        }
    }
}
```

Użyj funkcji `tone(pin, frequency)` i `notone(pin)` by wydać dzwięk przy naciśnięciu przycisku. Stwórz tablice częstotliwości które chcesz zagrać.

### Naduś guzik
Przy pomocy `digitalRead(switch_pin) == LOW` możemy wykryć czy dany przycisk jest wciśnięty. Zadeklaruj funkcję `keydown(k)`:
```
void keydown(int k) {
    int led_pin = k*2+2;
    digitalWrite(led_pin,HIGH);
    delay(1000);
    digitalWrite(led_pin,LOW);
}
```
Zmodyfikuj `loop` tak, by funkcja `keydown` została wywoła **raz** w momencie naciśnięcia przycisku.

## Gry
### Memory

Główne zdanie na dziś polega na napisaniu małej gry:
- Wygeneruj losową sekwencję 5 przycisków, użyjąc funkcję `random(4)`, i umieść ją w tablicy.
- Odtwórz sekwencje podświetlając odpowiednie przyciski i wydając tony
- Gra polega na tym by użytkownik powtóżył sekwencję. Gdy sie pomyli, zagraj smutną melodie, a gdy dojdzie do końca sekwencji poprawnie, zagraj fanfary.

Gdy wszystko będzie działać, zmodyfukuj kod tak, by sekwencja zaczynała od jednego elementu i zwiekszała się za każdym razem gdy użytkownik poprawnie ją wykona.

### Speed (dodatkowe)

Spróbuj napisać następującą grę, w której zapala się losowy przycisk i trzeba go nacisnąć zanim zgaśnie. Każdy następny przycisk zapala się na coraz krótrzy czas i odstępy po miedzy nimi maleją.

### Multi-speed (dodatkowe)

Zmodyfikuj powyższą grę tak, by podświetlała się dowolna kombinacja przycisków i trzeba było nacisnąć je wszystkie zanim zgasną.
