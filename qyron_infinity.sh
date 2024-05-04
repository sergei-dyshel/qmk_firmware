#!/usr/bin/env bash

set -e

while getopts "nd" opt; do
    case "$opt" in
    r)
        date=1
        ;;
    l)
        dry=1
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        print_usage
        exit 1
        ;;
    esac
done
shift "$((OPTIND - 1))"

src=$1
dst=$2



LAYOUT=qyron

make -j input_club/ergodox_infinity:$LAYOUT
mv input_club_ergodox_infinity_$LAYOUT.bin input_club_ergodox_infinity_${LAYOUT}_left.bin

make -j input_club/ergodox_infinity:$LAYOUT MASTER=right
mv input_club_ergodox_infinity_$LAYOUT.bin input_club_ergodox_infinity_${LAYOUT}_right.bin

read -p "Connect LEFT keyboard and press ENTER..."

set +e
dfu-util -w -D input_club_ergodox_infinity_${LAYOUT}_left.bin
ret=$?
if [[ $ret -ne 0 ]] && [[ $ret -ne 74 ]]; then
    echo "dfa-util failed with code $ret"
    exit $ret
fi

echo
echo
read -p "Connect RIGHT keyboard and press ENTER..."
dfu-util -w -D input_club_ergodox_infinity_${LAYOUT}_right.bin
ret=$?
if [[ $ret -ne 0 ]] && [[ $ret -ne 74 ]]; then
    echo "dfa-util failed with code $ret"
    exit $ret
fi
exit 0
