#!/bin/bash

set -u
set -e 

ARDUINO_DL_FILE=arduino-1.8.2-linux64.tar.xz
ARDUINO_TAR_FILE=arduino-1.8.2-linux64.tar
ARDUINO_DIR=arduino-1.8.2



cd $CWD



echo
echo
echo "INFO: install arduino software ..."
if [ ! -d ${ARDUINO_DIR}  -a  ! -f ${ARDUINO_TAR_FILE} ]; then
	echo
	echo " -> download software ..."
	wget -c https://downloads.arduino.cc/${ARDUINO_DL_FILE}
	echo
	echo " -> extract software ..."
	xz -d ${ARDUINO_DL_FILE}
	tar xf ${ARDUINO_TAR_FILE}

	if [ -L arduino ]; then
		unlink arduino
	fi
	ln -s ${ARDUINO_DIR} arduino 

	if [ -L $AVR_GCC ]; then
		unlink arduino
	fi
	ln -s arduino/hardware/tools/avr $AVR_GCC
fi



echo
echo
echo "INFO: install libraries ..."
cd lib

if [ ! -d AccelStepper ]; then
	echo
	echo " -> AccelStepper ..."
	wget http://www.airspayce.com/mikem/arduino/AccelStepper/AccelStepper-1.57.zip
	unzip AccelStepper-1.57.zip
fi

cd ..



echo
echo
echo "INFO: pulling git submodules ..."
git submodule update --init --recursive



echo
echo
echo "INFO: run tests ..."
source "$SCRIPTS_DIR/runtests.sh"









