#!/usr/bin/env bash

set -e

LAYOUT=qyron

make -j ergodox_infinity:$LAYOUT
mv ergodox_infinity_$LAYOUT.bin ergodox_infinity_${LAYOUT}_left.bin

make -j ergodox_infinity:$LAYOUT MASTER=right
mv ergodox_infinity_$LAYOUT.bin ergodox_infinity_${LAYOUT}_right.bin

read -p "Connect LEFT keyboard and press ENTER..."
dfu-util -D ergodox_infinity_${LAYOUT}_left.bin

echo
echo
read -p "Connect RIGHT keyboard and press ENTER..."
dfu-util -D ergodox_infinity_${LAYOUT}_right.bin
