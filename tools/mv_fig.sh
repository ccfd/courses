#!/bin/bash

FILES=$(find pl/ en/ -name "*md" | grep '^[^_].*\.R\?md$' | grep -v '/_')
# FILES_NEW=""
# for FILE in $FILES; do
#     FILE_FILE=${FILE##*/}
#     FILE_PATH=${FILE_FILE%.*}
#     FILE_EXT=${FILE_FILE##*.}
#     PATH_PATH=${FILE%/*}
#     mkdir -p "$PATH_PATH/$FILE_PATH"
#     FILE_NEW="$PATH_PATH/$FILE_PATH/_index.$FILE_EXT"
#     git mv $FILE $FILE_NEW
#     FILES_NEW="$FILES_NEW $FILE_NEW"
# done
# git commit -m "Moving mds to folders"
FILES_NEW="$FILES"

# FILES=$(find pl/ en/ -name "*md" | grep '^[^_].*\.R\?md$' | grep -v '/_')

for FILE in $FILES_NEW; do
#FILE=pl/info1/tworzenie_projektu.md
    FILE_FILE=${FILE##*/}
    FILE_FILE_BASE=${FILE_FILE%.*}
    FILE_PATH=${FILE%/*}
    MOVE_TO="$FILE_PATH/fig"
    
    grep -o -E '\!\[[^]]*\]\(([^ \)]*)( |[^\)]*)\)' $FILE >tmp
    FIGS=$(cat tmp | sed -E 's#\!\[[^]]*\]\(([^ \)]*)( |[^\)]*)\)#\1#g' | grep '^fig' | sort | uniq)
    test -z "$FIGS" && continue
    echo "----- $FILE -----"
    # echo "Figs: $FIGS"
    FIGS_NEW=$(for FIG in $FIGS; do
        ls static/$FIG* 2>/dev/null
    done | sort | uniq)
    test -z "$FIGS_NEW" && continue
    # echo "Figs: $FIGS_NEW"
    for SRC in $FIGS_NEW; do
        if ! test -f "$SRC"; then
            echo "No such file: $SRC"
            continue
        fi
        DST="$MOVE_TO/$(basename $SRC)"
        if test -f "$DST"; then
            echo "File already exists: $DST"
            exit 1
        fi
        echo "$SRC -> $DST"
        mkdir -p "$(dirname $DST)"
        git mv $SRC $DST
        SRC_REL="$(realpath --relative-to static/ $SRC)"
        DST_REL="$(realpath --relative-to $(dirname $FILE) $DST)"
        sed -i "s|$SRC_REL|$DST_REL|g" $FILE
    done
    git add $FILE
    git commit -m "Moved figures in $FILE"
done


