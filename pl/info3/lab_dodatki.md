---
author: "Ł. Łaniewski-Wołłk, rev. K. Marchlewski"
course: Informatyka III
material: 'Bash: Dodatki'
number: 8
---

# BASH: skrypty

Pisanie skryptów, w uproszczeniu polega na zebraniu w pliku komend, które normalnie wpisalibyśmy w linii poleceń.
Taki plik możemy następnie oznaczyć jako wykonywalny za pomocą polecenia `chmod u+x plik`{.bash} i wykonać komendą `./plik`{.bash} .
Linia poleceń (BASH) służy do uruchamiania programów - dlatego: **każda linijka skryptu wygląda nastepująco:** `program agumenty`{.bash}.

Przeanalizuj poniższy fragment kodu:
```{.bash}
i=1
while test $i -lt 10
do
	echo $i
	cp plik plik_$i
	i=$(expr $i + 1)
done
```

Łatwo zobaczyć, że:

- nadając zmiennej wartość `i=1`{.bash} nie używamy spacji ponieważ powłoka `Bash` wie wtedy, że jest to przypisanie, a nie wywołanie programu `i` z opcjami `=` oraz `1`. 
- w wyrażeniu `expr $i + 1`{.bash}, musimy zachować spacje, żeby program `expr` dostał trzy argumenty `$i`, `+` i `1`, a nie jeden `i+1`{.bash}.
- w pętli `while`, nie możemy napisać ,,`i<10`{.bash}'', lecz musimy użyć jakiegoś programu.
Do wszelkiego rodzaju testów stworzony został program `test`{.bash}.
W tym wypadku uruchamiamy go z argumentami `$i`, `-lt` i `10`, gdzie opcja `-lt` oznacza ,,less than''.

## Przydatne programy

Jeśli już wiemy, że każdy skrypt w powłoce `Bash` to seria wywołanych programów, to potrzebne jest nam dużo małych programów, z których będziemy mogli tworzyć skrypty.

Przykładowo:

- `echo tekst`{.bash} --- Wypisuje tekst na ekran.
- `cat plik`{.bash} --- Wypisuje zawartość pliku na ekran.
- `grep tekst`{.bash} --- Czyta znaki z klawiatury i wypisuje tylko linie zawierające ,,tekst''.
- `grep tekst pliki`{.bash} --- Wyszukuje ,,tekst'' w plikach.
- `cd katalog`{.bash} --- Wchodzi do katalogu.
- `ls katalog`{.bash} --- Wypisuje zawartość katalogu na ekran.
- `cp pliki katalog`{.bash} --- Kopiuje pliki do katalogu.
- `cp plik1 plik2`{.bash} --- Kopiuje plik o nazwie ,,plik1'' do pliku o nazwie ,,plik2''.
- `mv pliki katalog`{.bash} --- Przenosi pliki do katalogu.
- `mv plik1 plik2`{.bash} --- Zmienia nazwę pliku z ,,plik1'' na ,,plik2''.
- `sed 's/tekst1/tekst2/g'`{.bash} --- Czyta z klawiatury tekst i wypisuje go zamieniając ,,tekst1'' na ,,tekst2''.
- `cut -d" " -f1`{.bash} --- Czyta z klawiatury tekst, używając znaku spacji jako separatora dzieli go na pola i wypisuje pierwsze pole.
- `seq liczba1 liczba2`{.bash} --- Wypisuje na ekran ciąg liczb od ,,liczba1'' do ,,liczba2'' co jeden (wartość domyślna).

## Przekierowanie wejścia wyjścia

Standardowo wszystkie programy czytają z klawiatury i piszą na ekran.
Można jednak zarówno wejście jak i wyjście przekierować.

- `program > plik`{.bash} --- To co program wypisałby na ekran, zostanie wpisane do pliku (plik zostanie nadpisany jeśli istnieje).
- `program >> plik`{.bash} --- To co program wypisałby na ekran, zostanie dopisane do pliku (plik zostanie utworzony jeśli nie istniał).
- `program < plik`{.bash} --- Program dostanie zawartość pliku, tak jakbyśmy ją wpisali z klawiatury.
- `program1 | program2`{.bash} --- To co ,,program1'' wypisałby na ekran, zostanie wpisane ,,z klawiatury'' do ,,program2''.
- `'program'`{.bash} lub `$(program)`{.bash} --- To co program wypisałby na ekran, zostanie wklejone w tym miejscu kodu (patrz przykłady).
Odwrócony apostrof ``` ` ``` jest na klawiszu z tyldą `~`.

### Przykłady:

- `echo Tekst > plik`{.bash} --- wypisze ,,Tekst'' do pliku (plik zostanie nadpisany jeśli istnieje)
- `echo Tekst >> plik`{.bash} --- dopisze ,,Tekst'' do pliku (plik zostanie utworzony jeśli nie istniał)
- `grep Tekst < plik`{.bash} --- wyszuka w pliku linie zwierające ,,Tekst'' i je wypisze na ekran
- `echo Tekst | sed 's/st/a/g'`{.bash} --- Zamieni w ,,Tekst'' każde wystąpienie ,,st'' na ,,a''.
Więc wypisze na ekran ,,Teka''.
- `echo $nazwa | sed 's/.txt/.dat/g'`{.bash} --- Zastąpi w zmiennej `nazwa` końcówkę `.txt` na `.dat`.
Rezultat wypisze na ekran.
- `nazwa2=$(echo $nazwa |sed 's/.txt/.dat/g')`{.bash} --- Jak poprzednio, lecz rezultat wypisze do zmiennej `nazwa2`.
- `echo $(echo $nazwa | cut -d"." -f1).dat`{.bash} --- Zastąpi w zmiennej `nazwa` końcówkę występującą po `.` na `.dat`.
Rezultat wypisze na ekran.
- `ls katalog > plik`{.bash} --- wypisze zawartość katalogu do pliku (plik zostanie nadpisany jeśli istnieje).
- `cp ls katalog`{.bash} albo `cp $(ls) katalog`{.bash} --- skopiuje pliki do `katalogu` według listy zwróconej przez `ls`.
- `cp cat plik katalog`{.bash} bądź `cp $(cat plik) katalog`{.bash} --- skopiuje pliki do `katalogu` według listy zawartej w pliku.

## Pętle i wyrażenia warunkowe

**instrucja warunkowa if**

```{.bash}
if program argumenty
then
	polecenia1
else
	polecenia2
fi
```
Jeśli wykonanie polecenia `program argumenty`{.bash} się powiedzie (program zwróci $0$), to wykonane zostaną _polecenia1_.
W przeciwnym wypadku wykonane zostaną _polecenia2_.

**pętla while **

```{.bash}
while program argumenty
do
	polecenia
done
```
Pętla, która będzie wykonywać _polecenia_ , dopóki `program argumenty`{.bash} będzie wykonywany z powodzeniem.

**pętla for **

```{.bash}
for i in lista
do
	polecenia
done
```
Pętla, która po kolei każdy element z listy wstawi do zmiennej `i`, a następnie wykona _polecenia_.

Przykładowo:
```{.bash}
for i in *.jpg
do
	mv $i IMG/a_$i
done
```
Przeniesie każdy plik o końcówce `.jpg`, do katalogu `IMG` dodając im przedrostek `a_` (np.: `obrazek.jpg` zamieni na `IMG/a_obrazek.jpg`).

# Obróbka obrazków

## Program `convert`

- `convert plik.gif plik.jpg`{.bash} -- konwertuje plik w formacie GIF na format JPG
- `convert plik1.jpg -resize 50% plik2.jpg`{.bash} -- zmniejszy obrazek dwukrotnie
- `convert plik1.jpg -resize 100 plik2.jpg`{.bash} -- zmniejszy obrazek, tak by krótszy wymiar był równy 100 pikseli
- `convert plik1.jpg -resize 100x100 plik2.jpg`{.bash} -- zmniejszy obrazek tak, by mieścił się w kwadracie 100 na 100 pikseli
- `convert plik1.jpg -resize 100x100n! plik2.jpg`{.bash} -- zmniejszy obrazek dokładnie do rozmiaru 100 na 100 pikseli
- `convert -size 320x85 canvas:none -font Bookman-DemiItalic -pointsize 72 -draw "text 25,60 'Magick'" -channel RGBA -blur 0x6 -fill darkred -stroke magenta -draw "text 20,55 'Magick'" fuzzy-magick.jpg`{.bash} -- stworzy obrazek fuzzy-magick.jpg, z naniesionym tekstem ,,Magick''

## Wszystkie opcje programu `convert`

- `-adaptive-blur geometry`{.bash} -- adaptively blur pixels; decrease effect near edges
- `-adaptive-resize geometry`{.bash} -- adaptively resize image with data dependent triangulation.
- `-adaptive-sharpen geometry`{.bash} -- adaptively sharpen pixels; increase effect near edges
- `-adjoin`{.bash} -- join images into a single multi-image file
- `-affine matrix`{.bash} -- affine transform matrix
- `-alpha`{.bash} -- on, activate, off, deactivate, set, opaque, copy, transparent, extract, background, or shape the alpha channel
- `-annotate geometry text`{.bash} -- annotate the image with text
- `-antialias`{.bash} -- remove pixel-aliasing
- `-append`{.bash} -- append an image sequence
- `-authenticate value`{.bash} -- decipher image with this password
- `-auto-gamma`{.bash} -- automagically adjust gamma level of image
- `-auto-level`{.bash} -- automagically adjust color levels of image
- `-auto-orient`{.bash} -- automagically orient image
- `-background color`{.bash} -- background color
- `-bench iterations`{.bash} -- measure performance
- `-bias value`{.bash} -- add bias when convolving an image
- `-black-threshold value`{.bash} -- force all pixels below the threshold into black
- `-blue-primary point`{.bash} -- chromaticity blue primary point
- `-blue-shift factor`{.bash} -- simulate a scene at nighttime in the moonlight
- `-blur geometry`{.bash} -- reduce image noise and reduce detail levels
- `-border geometry`{.bash} -- surround image with a border of color
- `-bordercolor color`{.bash} -- border color
- `-brightness-contrast geometry`{.bash} -- improve brightness / contrast of the image
- `-caption string`{.bash} -- assign a caption to an image
- `-cdl filename`{.bash} -- color correct with a color decision list
- `-channel type`{.bash} -- apply option to select image channels
- `-charcoal radius`{.bash} -- simulate a charcoal drawing
- `-chop geometry`{.bash} -- remove pixels from the image interior
- `-clamp`{.bash} -- restrict colors from 0 to the quantum depth
- `-clip`{.bash} -- clip along the first path from the 8BIM profile
- `-clip-mask filename`{.bash} -- associate clip mask with the image
- `-clip-path id`{.bash} -- clip along a named path from the 8BIM profile
- `-clone index`{.bash} -- clone an image
- `-clut`{.bash} -- apply a color lookup table to the image
- `-contrast-stretch geometry`{.bash} -- improve the contrast in an image by ‘stretching’ the range of intensity value
- `-coalesce`{.bash} -- merge a sequence of images
- `-colorize value`{.bash} -- colorize the image with the fill color
- `-color-matrix matrix`{.bash} -- apply color correction to the image.
- `-colors value`{.bash} -- preferred number of colors in the image
- `-colorspace type`{.bash} -- set image colorspace
- `-combine`{.bash} -- combine a sequence of images
- `-comment string`{.bash} -- annotate image with comment
- `-compose operator`{.bash} -- set image composite operator
- `-composite`{.bash} -- composite image
- `-compress type`{.bash} -- image compression type
- `-contrast`{.bash} -- enhance or reduce the image contrast
- `-convolve coefficients`{.bash} -- apply a convolution kernel to the image
- `-crop geometry`{.bash} -- crop the image
- `-cycle amount`{.bash} -- cycle the image colormap
- `-decipher filename`{.bash} -- convert cipher pixels to plain
- `-debug events`{.bash} -- display copious debugging information
- `-define format:option`{.bash} -- define one or more image format options
- `-deconstruct`{.bash} -- break down an image sequence into constituent parts
- `-delay value`{.bash} -- display the next image after pausing
- `-delete index`{.bash} -- delete the image from the image sequence
- `-density geometry`{.bash} -- horizontal and vertical density of the image
- `-depth value`{.bash} -- image depth
- `-despeckle`{.bash} -- reduce the speckles within an image
- `-direction type`{.bash} -- render text right-to-left or left-to-right
- `-display server`{.bash} -- get image or font from this X server
- `-dispose method`{.bash} -- layer disposal method
- `-distort type coefficients`{.bash} -- distort image
- `-dither method`{.bash} -- apply error diffusion to image
- `-draw string`{.bash} -- annotate the image with a graphic primitive
- `-duplicate count,indexes`{.bash} -- duplicate an image one or more times
- `-edge radius`{.bash} -- apply a filter to detect edges in the image
- `-emboss radius`{.bash} -- emboss an image
- `-encipher filename`{.bash} -- convert plain pixels to cipher pixels
- `-encoding type`{.bash} -- text encoding type
- `-endian type`{.bash} -- endianness (MSB or LSB) of the image
- `-enhance`{.bash} -- apply a digital filter to enhance a noisy image
- `-equalize`{.bash} -- perform histogram equalization to an image
- `-evaluate operator value`{.bash} -- evaluate an arithmetic, relational, or logical expression
- `-evaluate-sequence operator`{.bash} -- evaluate an arithmetic, relational, or logical expression for an image sequence
- `-extent geometry`{.bash} -- set the image size
- `-extract geometry`{.bash} -- extract area from image
- `-family name`{.bash} -- render text with this font family
- `-fft`{.bash} -- implments the discrete Fourier transform (DFT)
- `-fill color`{.bash} -- color to use when filling a graphic primitive
- `-filter type`{.bash} -- use this filter when resizing an image
- `-flatten`{.bash} -- flatten a sequence of images
- `-flip`{.bash} -- flip image in the vertical direction
- `-floodfill geometry color`{.bash} -- floodfill the image with color
- `-flop`{.bash} -- flop image in the horizontal direction
- `-font name`{.bash} -- render text with this font
- `-format string`{.bash} -- output formatted image characteristics
- `-frame geometry`{.bash} -- surround image with an ornamental border
- `-function name`{.bash} -- apply a function to the image
- `-fuzz distance`{.bash} -- colors within this distance are considered equal
- `-fx expression`{.bash} -- apply mathematical expression to an image channel(s)
- `-gamma value`{.bash} -- level of gamma correction
- `-gaussian-blur geometry`{.bash} -- reduce image noise and reduce detail levels
- `-geometry geometry`{.bash} -- preferred size or location of the image
- `-gravity type`{.bash} -- horizontal and vertical text placement
- `-green-primary point`{.bash} -- chromaticity green primary point
- `-help`{.bash} -- print program options
- `-identify`{.bash} -- identify the format and characteristics of the image
- `-ift`{.bash} -- implements the inverse discrete Fourier transform (DFT)
- `-implode amount`{.bash} -- implode image pixels about the center
- `-insert index`{.bash} -- insert last image into the image sequence
- `-intent type`{.bash} -- type of rendering intent when managing the image color
- `-interlace type`{.bash} -- type of image interlacing scheme
- `-interline-spacing value`{.bash} -- the space between two text lines
- `-interpolate method`{.bash} -- pixel color interpolation method
- `-interword-spacing value`{.bash} -- the space between two words
- `-kerning value`{.bash} -- the space between two characters
- `-label string`{.bash} -- assign a label to an image
- `-lat geometry`{.bash} -- local adaptive thresholding
- `-layers method`{.bash} -- optimize or compare image layers
- `-level value`{.bash} -- adjust the level of image contrast
- `-limit type value`{.bash} -- pixel cache resource limit
- `-linear-stretch geometry`{.bash} -- linear with saturation histogram stretch
- `-liquid-rescale geometry`{.bash} -- rescale image with seam-carving
- `-log format`{.bash} -- format of debugging information
- `-loop iterations`{.bash} -- add Netscape loop extension to your GIF animation
- `-mask filename`{.bash} -- associate a mask with the image
- `-mattecolor color`{.bash} -- frame color
- `-median radius`{.bash} -- apply a median filter to the image
- `-mode radius`{.bash} -- make each pixel the ’predominant color’ of the neighborhood
- `-modulate value`{.bash} -- vary the brightness, saturation, and hue
- `-monitor`{.bash} -- monitor progress
- `-monochrome`{.bash} -- transform image to black and white
- `-morph value`{.bash} -- morph an image sequence
- `-morphology method kernel`{.bash} -- apply a morphology method to the image
- `-motion-blur geometry`{.bash} -- simulate motion blur
- `-negate`{.bash} -- replace each pixel with its complementary color
- `-noise radius`{.bash} -- add or reduce noise in an image
- `-normalize`{.bash} -- transform image to span the full range of colors
- `-opaque color`{.bash} -- change this color to the fill color
- `-ordered-dither NxN`{.bash} -- ordered dither the image
- `-orient type`{.bash} -- image orientation
- `-page geometry`{.bash} -- size and location of an image canvas (setting)
- `-paint radius`{.bash} -- simulate an oil painting
- `-ping`{.bash} -- efficiently determine image attributes
- `-pointsize value`{.bash} -- font point size
- `-polaroid angle`{.bash} -- simulate a Polaroid picture
- `-posterize levels`{.bash} -- reduce the image to a limited number of color levels
- `-precision value`{.bash} -- set the maximum number of significant digits to be printed
- `-preview type`{.bash} -- image preview type
- `-print string`{.bash} -- interpret string and print to console
- `-process image-filter`{.bash} -- process the image with a custom image filter
- `-profile filename`{.bash} -- add, delete, or apply an image profile
- `-quality value`{.bash} -- JPEG/MIFF/PNG compression level
- `-quantize colorspace`{.bash} -- reduce image colors in this colorspace
- `-quiet`{.bash} -- suppress all warning messages
- `-radial-blur angle`{.bash} -- radial blur the image
- `-raise value`{.bash} -- lighten/darken image edges to create a 3-D effect
- `-random-threshold low,high`{.bash} -- random threshold the image
- `-red-primary point`{.bash} -- chromaticity red primary point
- `-regard-warnings`{.bash} -- pay attention to warning messages.
- `-region geometry`{.bash} -- apply options to a portion of the image
- `-remap filename`{.bash} -- transform image colors to match this set of colors
- `-render`{.bash} -- render vector graphics
- `-repage geometry`{.bash} -- size and location of an image canvas
- `-resample geometry`{.bash} -- change the resolution of an image
- `-resize geometry`{.bash} -- resize the image
- `-respect-parentheses`{.bash} -- settings remain in effect until parenthesis boundary.
- `-roll geometry`{.bash} -- roll an image vertically or horizontally
- `-rotate degrees`{.bash} -- apply Paeth rotation to the image
- `-sample geometry`{.bash} -- scale image with pixel sampling
- `-sampling-factor geometry`{.bash} -- horizontal and vertical sampling factor
- `-scale geometry`{.bash} -- scale the image
- `-scene value`{.bash} -- image scene number
- `-seed value`{.bash} -- seed a new sequence of pseudo-random numbers
- `-segment values`{.bash} -- segment an image
- `-selective-blur geometry`{.bash} -- selectively blur pixels within a contrast threshold
- `-separate`{.bash} -- separate an image channel into a grayscale image
- `-sepia-tone threshold`{.bash} -- simulate a sepia-toned photo
- `-set attribute value`{.bash} -- set an image attribute
- `-shade degrees`{.bash} -- shade the image using a distant light source
- `-shadow geometry`{.bash} -- simulate an image shadow
- `-sharpen geometry`{.bash} -- sharpen the image
- `-shave geometry`{.bash} -- shave pixels from the image edges
- `-shear geometry`{.bash} -- slide one edge of the image along the X or Y axis
- `-sigmoidal-contrast geometry`{.bash} -- increase the contrast without saturating highlights or shadows
- `-smush offset`{.bash} -- smush an image sequence together
- `-size geometry`{.bash} -- width and height of image
- `-sketch geometry`{.bash} -- simulate a pencil sketch
- `-solarize threshold`{.bash} -- negate all pixels above the threshold level
- `-splice geometry`{.bash} -- splice the background color into the image
- `-spread radius`{.bash} -- displace image pixels by a random amount
- `-statistic type geometry`{.bash} -- replace each pixel with corresponding statistic from the neighborhood
- `-strip`{.bash} -- strip image of all profiles and comments
- `-stroke color`{.bash} -- graphic primitive stroke color
- `-strokewidth value`{.bash} -- graphic primitive stroke width
- `-stretch type`{.bash} -- render text with this font stretch
- `-style type`{.bash} -- render text with this font style
- `-swap indexes`{.bash} -- swap two images in the image sequence
- `-swirl degrees`{.bash} -- swirl image pixels about the center
- `-synchronize`{.bash} -- synchronize image to storage device
- `-taint`{.bash} -- mark the image as modified
- `-texture filename`{.bash} -- name of texture to tile onto the image background
- `-threshold value`{.bash} -- threshold the image
- `-thumbnail geometry`{.bash} -- create a thumbnail of the image
- `-tile filename`{.bash} -- tile image when filling a graphic primitive
- `-tile-offset geometry`{.bash} -- set the image tile offset
- `-tint value`{.bash} -- tint the image with the fill color
- `-transform`{.bash} -- affine transform image
- `-transparent color`{.bash} -- make this color transparent within the image
- `-transparent-color color`{.bash} -- transparent color
- `-transpose`{.bash} -- flip image in the vertical direction and rotate 90 degrees
- `-transverse`{.bash} -- flop image in the horizontal direction and rotate 270 degrees
- `-treedepth value`{.bash} -- color tree depth
- `-trim`{.bash} -- trim image edges
- `-type type`{.bash} -- image type
- `-undercolor color`{.bash} -- annotation bounding box color
- `-unique-colors`{.bash} -- discard all but one of any pixel color.
- `-units type`{.bash} -- the units of image resolution
- `-unsharp geometry`{.bash} -- sharpen the image
- `-verbose`{.bash} -- print detailed information about the image
- `-version`{.bash} -- print version information
- `-view`{.bash} -- FlashPix viewing transforms
- `-vignette geometry`{.bash} -- soften the edges of the image in vignette style
- `-virtual-pixel method`{.bash} -- access method for pixels outside the boundaries of the image
- `-wave geometry`{.bash} -- alter an image along a sine wave
- `-weight type`{.bash} -- render text with this font weight
- `-white-point point`{.bash} -- chromaticity white point
- `-white-threshold value`{.bash} -- force all pixels above the threshold into white
- `-write filename`{.bash} -- write images to this file
