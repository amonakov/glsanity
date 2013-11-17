#!/bin/bash

pkgdir=$(dirname `readlink -ne $0`)/glsanity-bin

export CFLAGS='-O2 -Wall -s'

CC='gcc -m32' make -C src clean install instdir=$pkgdir/32
CC='gcc -m64' make -C src clean install instdir=$pkgdir/64

cp scripts/glsanity-bbee $pkgdir
cp scripts/glsanity.in $pkgdir/glsanity

sed -i -e 's#@CHECKERS32@#$(dirname `readlink -ne $0`)/32#' $pkgdir/glsanity
sed -i -e 's#@CHECKERS64@#$(dirname `readlink -ne $0`)/64#' $pkgdir/glsanity
chmod +x $pkgdir/glsanity

zip -r glsanity-bin.zip glsanity-bin
