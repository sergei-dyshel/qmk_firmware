#!/usr/bin/env bash

set -e

LAYOUT=qyron

make -j ergodox_ez:$LAYOUT

read -p "Press Flash button on keyboard and press ENTER..."
make -j ergodox_ez:$LAYOUT:teensy

