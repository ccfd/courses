---
author: "Ł. Łaniewski-Wołłk, rev. K. Marchlewski"
course: Computer Science III
material: 'Bash: Extras'
number: 8
---

# BASH: scripts

Script writing, in simple terms, consists of gathering commands in a file that we would normally type on the command line.
We can then mark such a file as executable with the command `chmod u + x file`{.bash} and execute with the command `./file`{.bash}.
The command line (BASH) is used to run programs - therefore: ** each line of the script looks like this: ** `program agumenty`{.bash}.

Analyze the following code snippet:
```{} .bash
i = 1
while test $ i -lt 10
down
echo $ i
cp file file_ $ i
i = $ (expr $ i + 1)
done
```

It's easy to see that:

- giving the variable `i = 1`{.bash} we do not use spaces because the `Bash` shell knows then that it is an assignment, not a call to the `i` program with the `=` and `1` options.
- in the expression `expr $ i + 1`{.bash}, we must keep spaces so that the program `expr` gets three arguments `$ i`, `+ `and `1`, not one `i + 1`{. bash}.
- in the `while` loop, we cannot write" `and <10`{.bash} '', but we must use some program.
The program `test`{.bash} was created for all kinds of tests.
In this case, we run it with the arguments `$ i`, `-lt` and `10`, where the option `-lt` means 'less than'.

## Useful programs

If we already know that each script in the `Bash` shell is a series of called programs, we need a lot of small programs from which we can create scripts.

For example:

- `echo text`{.bash} --- Prints text to the screen.
- `cat file`{.bash} --- Prints the contents of the file to the screen.
- `grep text`{.bash} --- Reads characters from the keyboard and prints only lines containing "text".
- `grep text files`{.bash} --- Search for "text" in files.
- `cd directory`{.bash} --- Enters the directory.
- `ls directory`{.bash} --- Prints the contents of the directory to the screen.
- `cp files directory`{.bash} --- Copy files to the directory.
- `cp file1 file2`{.bash} --- Copy the file named "file1" to the file named "file2".
- `mv files directory`{.bash} --- Moves files to the directory.
- `mv file1 file2`{.bash} --- Changes the file name from" file1 "to" file2 ".
- `sed 's/tekst1/tekst2/g'`{.bash} --- Reads the text from the keyboard and prints it, replacing" text1 "with" text2 ".
- `cut -d" "-f1`{.bash} --- Reads text from the keyboard, using a space as the separator separates it into fields and prints the first field.
- `seq number1 number2`{.bash} --- Prints on the screen a sequence of numbers from 'number1' to 'number2' every one (default value).

## Redirection of exit input

By default, all programs read from the keyboard and write on the screen.
However, both input and output can be redirected.

- `program> file`{.bash} --- What the program would write to the screen will be written to the file (the file will be overwritten if it exists).
- `program >> file`{.bash} --- What the program would write to the screen will be added to the file (the file will be created if it did not exist).
- `program <file`{.bash} --- The program will get the contents of the file as if we entered it from the keyboard.
- `program1 | program2`{.bash} --- What 'program1' would write to the screen will be entered 'from the keyboard' into 'program2'.
- ` `program '' {.bash} or `$ (program)`{.bash} --- What the program would write to the screen will be pasted here in the code (see examples).
The inverted apostrophe ` ` ` ` ` `is on the key with the tilde `~`.

### Examples:

- `echo Text >file`{.bash} --- will write 'Text' to the file (the file will be overwritten if it exists)
- `echo Text >>file`{.bash} --- will add 'Text' to the file (the file will be created if it did not exist)
- `grep Text <file`{.bash} --- will search for lines containing 'Text' and print them on the screen
- `echo Text | sed 's/x/y/g'`{.bash} --- Replace every occurrence of 'x' with 'y' in 'Text'.
So he will write "Teyt" on the screen.
- `echo $name | sed 's/.txt/.dat/g'`{.bash} --- Replaces `.txt` with `.dat` in the variable `name`.
The result will write to the screen.
- `name2 = $(echo $name | sed 's/.txt/.dat/g')`{.bash} --- As before, but the result will be written to the variable `name2`.
- `echo $ (echo $name | cut -d". "-f1) .dat`{.bash} --- Replaces the `after` in the variable after `.` with `.dat`.
The result will write to the screen.
- `ls directory> file`{.bash} --- will write the contents of the directory to the file (the file will be overwritten if it exists).
- ``cp `ls` directory``{.bash} or `cp $(ls) directory`{.bash} --- will copy files to the `directory` according to the list returned by `ls`.
- `cp $(cat file) directory`{.bash} --- will copy files to the `directory` according to the list contained in the file.

## Loops and conditional expressions

**conditional statement if**

```{.bash}
if program arguments
then
	commands1
else
	commands2
fi
```
If the `program arguments`{.bash} command is successful (the program returns $ 0 $), _command1_ will be executed.
Otherwise _commands2_ will be executed.

**while loop**

```{.bash}
while program arguments
do
	commands
done
```
A loop that will execute _commands_ until the `program arguments`{.bash} is successfully executed.

**for loop**

```{.bash}
for i in list
do
	commands
done
```
A loop that in turn inserts each item from the list into the variable `i` and then executes _commands_.

For example:
```{.bash}
for i in *.jpg
do
	mv $i IMG/a_$i
done
```
It will transfer any file with the extension `.jpg`, adding the prefix `a_` to the `IMG` directory (e.g. `picture.jpg` will change into `IMG/a_obrazek.jpg`).

# Image processing

## Program `convert`

- `convert file.gif file.jpg`{.bash} - convert a file in GIF format to JPG
- `convert file1.jpg -resize 50% file2.jpg`{.bash} - will reduce the image twice
- `convert file1.jpg -resize 100 file2.jpg`{.bash} - will reduce the image so that the shorter dimension is 100 pixels
- `convert file1.jpg -resize 100x100 file2.jpg`{.bash} - will reduce the image to fit in a square of 100 by 100 pixels
- `convert file1.jpg -resize 100x100n! file2.jpg`{.bash} - will reduce the image to 100 by 100 pixels
- `convert -size 320x85 canvas:none -font Bookman-DemiItalic -pointsize 72 -draw "text 25,60 'Magick'" -channel RGBA -blur 0x6 -fill darkred -stroke magenta -draw" text 20.55 'Magick'" fuzzy-magick.jpg`{.bash} - will create a picture fuzzy-magick.jpg, with the text "Magick" marked

## All options for `convert`

- `-adaptive-blur geometry`{.bash} - adaptively blur pixels; decrease effect near edges
- `-adaptive-resize geometry`{.bash} - adaptively resize image with data dependent triangulation.
- `-adaptive-sharpen geometry`{.bash} - adaptively sharpen pixels; increase effect near edges
- `-adjoin`{.bash} - join images into a single multi-image file
- `-affine matrix`{.bash} - affine transform matrix
- `-alpha`{.bash} - on, activate, off, deactivate, set, opaque, copy, transparent, extract, background, or shape the alpha channel
- `-annotate geometry text`{.bash} - annotate the image with text
- `-antialias`{.bash} - remove pixel-aliasing
- `-append`{.bash} - append an image sequence
- `-authenticate value`{.bash} - decipher image with this password
- `-auto-gamma`{.bash} - automagically adjust gamma level of image
- `-auto-level`{.bash} - automagically adjust color levels of image
- `-auto-orient`{.bash} - automagically orient image
- `-background color`{.bash} - background color
- `-bench iterations`{.bash} - measure performance
- `-bias value`{.bash} - add bias when convolving an image
- `-black-threshold value`{.bash} - force all pixels below the threshold into black
- `-blue-primary point`{.bash} - chromaticity blue primary point
- `-blue-shift factor`{.bash} - simulate a scene at nighttime in the moonlight
- `-blur geometry`{.bash} - reduce image noise and reduce detail levels
- `-border geometry`{.bash} - surround image with a border of color
- `-bordercolor color`{.bash} - border color
- `-brightness-contrast geometry`{.bash} - improve brightness / contrast of the image
- `-caption string`{.bash} - assign a caption to an image
- `-cdl filename`{.bash} - color correct with a color decision list
- `-channel type`{.bash} - apply option to select image channels
- `-charcoal radius`{.bash} - simulate a charcoal drawing
- `-chop geometry`{.bash} - remove pixels from the image interior
- `-clamp`{.bash} - restrict colors from 0 to the quantum depth
- `-clip`{.bash} - clip along the first path from the 8BIM profile
- `-clip-mask filename`{.bash} - associate clip mask with the image
- `-clip-path id`{.bash} - clip along a named path from the 8BIM profile
- `-clone index`{.bash} - clone an image
- `-clut`{.bash} - apply a color lookup table to the image
- `-contrast-stretch geometry`{.bash} - improve the contrast in an image by 'stretching' the range of intensity value
- `-coalesce`{.bash} - merge a sequence of images
- `-colorize value`{.bash} - colorize the image with the fill color
- `-color-matrix matrix`{.bash} - apply color correction to the image.
- `-colors value`{.bash} - preferred number of colors in the image
- `-colorspace type`{.bash} - set image colorspace
- `-combine`{.bash} - combine a sequence of images
- `-comment string`{.bash} - annotate image with comment
- `-compose operator`{.bash} - set image composite operator
- `-composite`{.bash} - composite image
- `-compress type`{.bash} - image compression type
- `-contrast`{.bash} - enhance or reduce the image contrast
- `-convolve coefficients`{.bash} - apply a convolution kernel to the image
- `-crop geometry`{.bash} - crop the image
- `-cycle amount`{.bash} - cycle the image colormap
- `-decipher filename`{.bash} - convert cipher pixels to plain
- `-debug events`{.bash} - display copious debugging information
- `-define format:option`{.bash} - define one or more image format options
- `-deconstruct`{.bash} - break down an image sequence into constituent parts
- `-delay value`{.bash} - display the next image after pausing
- `-delete index`{.bash} - delete the image from the image sequence
- `-density geometry`{.bash} - horizontal and vertical density of the image
- `-depth value`{.bash} - image depth
- `-despeckle`{.bash} - reduce the speckles within an image
- `-direction type`{.bash} - render text right-to-left or left-to-right
- `-display server`{.bash} - get image or font from this X server
- `-dispose method`{.bash} - layer disposal method
- `-distort type coefficients`{.bash} - distort image
- `-dither method`{.bash} - apply error diffusion to image
- `-draw string`{.bash} - annotate the image with a graphic primitive
- `-duplicate count,indexes`{.bash} - duplicate an image one or more times
- `-edge radius`{.bash} - apply a filter to detect edges in the image
- `-emboss radius`{.bash} - emboss an image
- `-encipher filename`{.bash} - convert plain pixels to cipher pixels
- `-encoding type`{.bash} - text encoding type
- `-endian type`{.bash} - endianness (MSB or LSB) of the image
- `-enhance`{.bash} - apply a digital filter to enhance a noisy image
- `-equalize`{.bash} - perform histogram equalization to an image
- `-evaluate operator value`{.bash} - evaluate an arithmetic, relational, or logical expression
- `-evaluate-sequence operator`{.bash} - evaluate an arithmetic, relational, or logical expression for an image sequence
- `-extent geometry`{.bash} - set the image size
- `-extract geometry`{.bash} - extract area from image
- `-family name`{.bash} - render text with this font family
- `-fft`{.bash} - implments the discrete Fourier transform (DFT)
- `-fill color`{.bash} - color to use when filling a graphic primitive
- `-filter type`{.bash} - use this filter when resizing an image
- `-flatten`{.bash} - flatten a sequence of images
- `-flip`{.bash} - flip image in the vertical direction
- `-floodfill geometry color`{.bash} - floodfill the image with color
- `-flop`{.bash} - flop image in the horizontal direction
- `-font name`{.bash} - render text with this font
- `-format string`{.bash} - output formatted image characteristics
- `-frame geometry`{.bash} - surround image with an ornamental border
- `-function name`{.bash} - apply a function to the image
- `-fuzz distance`{.bash} - colors within this distance are considered equal
- `-fx expression`{.bash} - apply mathematical expression to an image channel (s)
- `-gamma value`{.bash} - level of gamma correction
- `-gaussian-blur geometry`{.bash} - reduce image noise and reduce detail levels
- `-geometry geometry`{.bash} - preferred size or location of the image
- `-gravity type`{.bash} - horizontal and vertical text placement
- `-green-primary point`{.bash} - chromaticity green primary point
- `-help`{.bash} - print program options
- `-identify`{.bash} - identify the format and characteristics of the image
- `-ift`{.bash} - implements the inverse discrete Fourier transform (DFT)
- `-implode amount`{.bash} - implode image pixels about the center
- `-insert index`{.bash} - insert last image into the image sequence
- `-intent type`{.bash} - type of rendering intent when managing the image color
- `-interlace type`{.bash} - type of image interlacing scheme
- `-interline-spacing value`{.bash} - the space between two text lines
- `-interpolate method`{.bash} - pixel color interpolation method
- `-interword-spacing value`{.bash} - the space between two words
- `-kerning value`{.bash} - the space between two characters
- `-label string`{.bash} - assign a label to an image
- `-lat geometry`{.bash} - local adaptive thresholding
- `-layers method`{.bash} - optimize or compare image layers
- `-level value`{.bash} - adjust the level of image contrast
- `-limit type value`{.bash} - pixel cache resource limit
- `-linear-stretch geometry`{.bash} - linear with saturation histogram stretch
- `-liquid-rescale geometry`{.bash} - rescale image with seam-carving
- `-log format`{.bash} - format of debugging information
- `-loop iterations`{.bash} - add Netscape loop extension to your GIF animation
- `-mask filename`{.bash} - associate a mask with the image
- `-mattecolor color`{.bash} - frame color
- `-median radius`{.bash} - apply a median filter to the image
- `-mode radius`{.bash} - make each pixel the 'predominant color' of the neighborhood
- `-modulate value`{.bash} - vary the brightness, saturation, and hue
- `-monitor`{.bash} - monitor progress
- `-monochrome`{.bash} - transform image to black and white
- `-morph value`{.bash} - morph an image sequence
- `-morphology method kernel`{.bash} - apply a morphology method to the image
- `-motion-blur geometry`{.bash} - simulate motion blur
- `-negate`{.bash} - replace each pixel with its complementary color
- `-noise radius`{.bash} - add or reduce noise in an image
- `-normalize`{.bash} - transform image to span the full range of colors
- `-opaque color`{.bash} - change this color to the fill color
- `-ordered-dither NxN`{.bash} - ordered dither the image
- `-orient type`{.bash} - image orientation
- `-page geometry`{.bash} - size and location of an image canvas (setting)
- `-paint radius`{.bash} - simulate an oil painting
- `-ping`{.bash} - efficiently determine image attributes
- `-pointsize value`{.bash} - font point size
- `-polaroid angle`{.bash} - simulate a Polaroid picture
- `-posterize levels`{.bash} - reduce the image to a limited number of color levels
- `-precision value`{.bash} - set the maximum number of significant digits to be printed
- `-preview type`{.bash} - image preview type
- `-print string`{.bash} - interpret string and print to console
- `-process image-filter`{.bash} - process the image with a custom image filter
- `-profile filename`{.bash} - add, delete, or apply an image profile
- `-quality value`{.bash} - JPEG/MIFF/PNG compression level
- `-quantize colorspace`{.bash} - reduce image colors in this colorspace
- `-quiet`{.bash} - suppress all warning messages
- `-radial-blur angle`{.bash} - radial blur the image
- `-raise value`{.bash} - lighten/darken image edges to create a 3-D effect
- `-random-threshold low,high`{.bash} - random threshold the image
- `-red-primary point`{.bash} - chromaticity red primary point
- `-regard-warnings`{.bash} - pay attention to warning messages.
- `-region geometry`{.bash} - apply options to a portion of the image
- `-remap filename`{.bash} - transform image colors to match this set of colors
- `-render`{.bash} - render vector graphics
- `-repage geometry`{.bash} - size and location of an image canvas
- `-resample geometry`{.bash} - change the resolution of an image
- `-resize geometry`{.bash} - resize the image
- `-respect-parentheses`{.bash} - settings remain in effect until parenthesis boundary.
- `-roll geometry`{.bash} - roll an image vertically or horizontally
- `-rotate degrees`{.bash} - apply Paeth rotation to the image
- `-sample geometry`{.bash} - scale image with pixel sampling
- `-sampling-factor geometry`{.bash} - horizontal and vertical sampling factor
- `-scale geometry`{.bash} - scale the image
- `-scene value`{.bash} - image scene number
- `-seed value`{.bash} - seed a new sequence of pseudo-random numbers
- `-segment values`{.bash} - segment an image
- `-selective-blur geometry`{.bash} - selectively blur pixels within a contrast threshold
- `-separate`{.bash} - separate an image channel into a grayscale image
- `-sepia-tone threshold`{.bash} - simulate a sepia-toned photo
- `-set attribute value`{.bash} - set an image attribute
- `-shade degrees`{.bash} - shade the image using a distant light source
- `-shadow geometry`{.bash} - simulate an image shadow
- `-sharpen geometry`{.bash} - sharpen the image
- `-shave geometry`{.bash} - shave pixels from the image edges
- `-shear geometry`{.bash} - slide one edge of the image along the X or Y axis
- `-sigmoidal-contrast geometry`{.bash} - increase the contrast without saturating highlights or shadows
- `-smush offset`{.bash} - smush an image sequence together
- `-size geometry`{.bash} - width and height of image
- `-sketch geometry`{.bash} - simulate a pencil sketch
- `-solarize threshold`{.bash} - negate all pixels above the threshold level
- `-splice geometry`{.bash} - splice the background color into the image
- `-spread radius`{.bash} - displace image pixels by a random amount
- `-statistic type geometry`{.bash} - replace each pixel with corresponding statistic from the neighborhood
- `-strip`{.bash} - strip image of all profiles and comments
- `-stroke color`{.bash} - graphic primitive stroke color
- `-strokewidth value`{.bash} - graphic primitive stroke width
- `-stretch type`{.bash} - render text with this font stretch
- `-style type`{.bash} - render text with this font style
- `-swap indexes`{.bash} - swap two images in the image sequence
- `-swirl degrees`{.bash} - swirl image pixels about the center
- `-synchronize`{.bash} - synchronize image to storage device
- `-taint`{.bash} - mark the image as modified
- `-texture filename`{.bash} - name of texture to tile onto the image background
- `-threshold value`{.bash} - threshold the image
- `-thumbnail geometry`{.bash} - create a thumbnail of the image
- `-tile filename`{.bash} - tile image when filling a graphic primitive
- `-tile-offset geometry`{.bash} - set the image tile offset
- `-tint value`{.bash} - tint the image with the fill color
- `-transform`{.bash} - affine transform image
- `-transparent color`{.bash} - make this color transparent within the image
- `-transparent-color color`{.bash} - transparent color
- `-transpose`{.bash} - flip image in the vertical direction and rotate 90 degrees
- `-transverse`{.bash} - flop image in the horizontal direction and rotate 270 degrees
- `-treedepth value`{.bash} - color tree depth
- `-trim`{.bash} - trim image edges
- `-type type`{.bash} - image type
- `-undercolor color`{.bash} - annotation bounding box color
- `-unique-colors`{.bash} - discard all but one of any pixel color.
- `-units type`{.bash} - the units of image resolution
- `-unsharp geometry`{.bash} - sharpen the image
- `-verbose`{.bash} - print detailed information about the image
- `-version`{.bash} - print version information
- `-view`{.bash} - FlashPix viewing transforms
- `-vignette geometry`{.bash} - soften the edges of the image in vignette style
- `-virtual-pixel method`{.bash} - access method for pixels outside the boundaries of the image
- `-wave geometry`{.bash} - alter an image along a sine wave
- `-weight type`{.bash} - render text with this font weight
- `-white-point point`{.bash} - chromaticity white point
- `-white-threshold value`{.bash} - force all pixels above the threshold into white
- `-write filename`{.bash} - write images to this file

