#!/bin/bash - 

# sudo dnf install avr-gcc avr-libc dfu-programmer

# bear make KEYBOARD=ergodox_ez keymap=qyron VERBOSE=true SILENT=false
# export VERBOSE=1
# bear make KEYBOARD=ergodox_ez keymap=qyron COLOR=false
bear make ergodox_ez:qyron:teensy
STATUS=$?

compdb.py transform -v --remove '\-mmcu=atmega32u4' '\-fno-inline-small-functions' '\-funsigned-bitfields' '\-Wa,\S*' --isystem /usr/lib/gcc/avr/4.9.3/include /usr/lib/gcc/avr/4.9.3/include-fixed /usr/avr/include --prepend '\-include clang_compat.h'

# if [[ $STATUS -eq 0 ]]; then
# 	echo "Flashing firmware, push FLASH button..."
# 	teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_qyron.hex
# 	STATUS=$?
# fi

exit $STATUS


