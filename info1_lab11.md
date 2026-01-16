---
author: "Ł. Łaniewski-Wołłk"
course: Podst. Prog.
material: Instrukcja Dodatkowa I
number: 11
---

Na dzisiejszych zajęciach będziemy programować mikrokontroler.

Mikrokontroler to mały układ scalony, który (zazwyczaj) ma w sobie zintegrowane wszystkie komponenty potrzebne do wykonywania małych programów. Tzn: processor, pamięć stałą (na program), pamięć operacyjną (na dane), zegar, elementy wejścia wyjścia. Wpisanie programu do pamięci stałej mikrokontrolera nazywamy "programowaniem" mikrokontrolera i najczęściej odbywa się przez pobudzenie wybranych pinów układu scalonego w zadany sposób. Do tego używamy "programatora".

Na tych zajęciach użyjemy płytkę prototypową kompatybilną z Arduino. Urządzenia takie mają zintegrowane na jednej płytce: mikrokontroler i interfejs USB, a dodatkowo wgrany mają fabrycznie tak zwany "bootloader". Bootloader pełni rolę programatora, pozwalając wgrać programy do pamiecy stałej mikrokontrollera przez interfejs szeregowy. Bootloader Arduino stał się tak popularny, że wiele innych firm produkuje płytki z mikrokontolerami z wgranym ich bootloaderem. Pozwala to na programowanie wszelkich takich płytek przy pomocy tego samego zestawu narzędzi.

## Zaczynamy

Dziś będziemy używać narzędzia Arduino IDE.

Programy dla Arduino mają dwa komponenty: `setup()` w której inicjalizujemy stan mikrokontrolera i wszystkie zmienne, i `loop()` która jest powtarzana w nieskończoność i wykonuje zazwyczaj zawiera gówną logikę programu. Można sobie wyobrazić, że mikrokontroler będzie wykonywał następujący program:
```c
//some stuff
setup();
while (1) {
    loop();
    //some stuff
}
```

### `Piny`

Nasza płytka ma piny typu General Purpose Input Output (GPIO). Oznacza to, że możemy ustawić je w różne stany służące do odczytu danych (input) i wysyłania danych (output). Do ustawiania stanu służy funkcja `pinMode(pin, typ)`. Dziś użyjemy dwóch typów:

#### `OUTPUT`
`OUTPUT` pozwala na ustawianie wyjscia na pinie na logiczne `0` (`LOW`) i `1` (`HIGH`). Zero to samo co uziemienie (ground), a jedyna to napięcie operacyjne układu (u nas 3V). Jesli podlaczymy taki pin (np. 2) do lampki (jak na rysunku), bedziemy mogli ja zapalac i gasic ustawiajac pin za pomoca `digitalWrite(2,HIGH);` i `digitalWrite(2,LOW);`.

![](figures/info1/micro/led.png)

Jesli zas do takiego pinu (np 10) podlaczymy buzzer (jak na rysunku) i uzyjemy komendy `tone(10,freq)`, uklad zacznie na zmiane podawac 0 i 1 z czestotliwoscia `freq`, wydajac dzwiek.

![](figures/info1/micro/buzzer.png)

#### `INPUT_PULLUP`
`INPUT_PULLUP` pozwala na sprawdzanie na pinie czy jest on podłączony (`LOW`) czy nie (`HIGH`) do zera (ground). Jesli do takiego pina (np 3) podlaczymy przelacznik, a jego drugi styk podlaczymy do ziemi, bedziemy mogli wykryc czy przelacznik jest nacisniety sprawdzajac czy `digitalRead(3) == LOW`.

![](figures/info1/micro/button.png)

### Buzzer
Pierw wybróbujemy buzzer. Buzzer to mały piezoelektryczny głosnik zaprojektowany do wydawania tonów. Możemy podłączyć jedno wyjście buzzera do zera (`GND`) a drugi do pinu 4 (`D4`). Możemy wtedy użyć komendy `tone(pin, frequency, duration)`, żeby wysłać na pinie kwadratową falę o zadanej czestotliwości, i funkcji `delay(duration)` by poczekać zadany czas.
```
void setup() {
    pinMode(4, OUTPUT);
}

void loop() {
    tone(4, 262, 500); // C4 - 261.626 Hz
    delay(1000);
}
```

Dodatkowo możemy zapalić zintegrowaną diodę LED przy pomocy `digiralWrite(...)`:
```
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop() {
    tone(4, 262, 500); // C4 - 261.626 Hz
    delay(1000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
}
```


## Nasz uklad

Możemy teraz podłączyć przyciski. Każdy przycisk ma 4 porty, dwa styki przełącznika i dwa styki LED. Dioda LED jest w obudowie zlutowana w opornikiem limitującym natężenie, wiec nie bedziemy potrzebować dodatkowych komponentów. **Nigdy nie należy podłączać diody LED bez rezystora**.

![](figures/info1/micro/button_led.png)


W każdym przycisku jeden styk przełącznika i jeden styk LED podłączymy do zera (`GND`) a pozostały styk przełącznika podłączymy do pinu w stanie `INPUT_PULLUP`, a styk LED do `OUTPUT`. Ostatecznie będziemy mieli 4x2 stykow podłączonych do pinów od `D10` do `A3`, i łańcuszek styków podłączonych do zera. Piny 10,12,14(A0) i 16(A2) podłączymy do LEDow w przyciskach, zaś 11,13,15 i 17(A3) podłączymy do przycisków. Pin 4, jak wczesniej, użyjemy do buzzera.

![](figures/info1/micro/complete.png)

Na początek ustawimy stany wszystkich pinów które będziemu używać:
```c
void setup() {
    pinMode(10, OUTPUT);       // D10 - LED 1
    pinMode(11, INPUT_PULLUP); // D11 - Switch 1
    pinMode(12, OUTPUT);       // D12 - LED 2
    pinMode(13, INPUT_PULLUP); // D13 - Switch 2
    pinMode(14, OUTPUT);       // A0  - LED 3
    pinMode(15, INPUT_PULLUP); // A1  - Switch 3
    pinMode(16, OUTPUT);       // A2  - LED 4
    pinMode(17, INPUT_PULLUP); // A3  - Switch 4
    pinMode(4, OUTPUT);        // D4  - Buzzer
}

void loop() {

}
```

### Przyciski
Teraz możemy obsłużyć przyciski:
```
void loop() {
    for(int i=0;i<4;i++) {
        int switch_pin = i*2+11;
        int led_pin = i*2+10;
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
    int led_pin = k*2+10;
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
