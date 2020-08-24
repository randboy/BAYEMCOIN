#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BAYEMCOIND=${BAYEMCOIND:-$SRCDIR/bayemcoind}
BAYEMCOINCLI=${BAYEMCOINCLI:-$SRCDIR/bayemcoin-cli}
BAYEMCOINTX=${BAYEMCOINTX:-$SRCDIR/bayemcoin-tx}
BAYEMCOINQT=${BAYEMCOINQT:-$SRCDIR/qt/bayemcoin-qt}

[ ! -x $BAYEMCOIND ] && echo "$BAYEMCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BYMVER=($($BAYEMCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bayemcoind if --version-string is not set,
# but has different outcomes for bayemcoin-qt and bayemcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$BAYEMCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $BAYEMCOIND $BAYEMCOINCLI $BAYEMCOINTX $BAYEMCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BYMVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BYMVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
