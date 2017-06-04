#!/usr/bin/env bash

set -e
set -u


SCRIPTS_DIR=$(dirname -- $(readlink -f -- "$0"))

CWD=$(readlink -f "$SCRIPTS_DIR/..")
SRC="$CWD/src"
TEST="$CWD/test"
ARDMK="$CWD/Arduino-Makefile"

AVR_GCC="$CWD/avr-gcc"
ARDUINO="$CWD/arduino"


source "$SCRIPTS_DIR/install.sh"
