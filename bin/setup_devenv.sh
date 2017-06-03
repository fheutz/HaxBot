#!/bin/bash

set -u
set -e 

ARDUINO_DL_FILE=arduino-1.8.2-linux64.tar.xz
ARDUINO_TAR_FILE=arduino-1.8.2-linux64.tar
ARDUINO_DIR=arduino-1.8.2-linux64
HEXBOT_REPO="https://github.com/fheutz/HaxBot.git"


echo
echo "INFO: install arduino software ..."
mkdir -p HaxBot-Arduino
cd HaxBot-Arduino

if [ ! -d ${ARDUINO_DIR}  -a  ! -f ${ARDUINO_TAR_FILE} ]; then
	echo " -> download software ..."
	wget -c https://downloads.arduino.cc/${ARDUINO_DL_FILE}
	echo " -> extract software ..."
	xz -d ${ARDUINO_DL_FILE}
	tar xf ${ARDUINO_TAR_FILE}
fi
if [ -L arduino ]; then
	unlink arduino
fi
ln -s ${ARDUINO_DIR} arduino 


echo 
echo "INFO: retrieving git repositories ..."
if [ -d HaxBot ]; then
	cd HaxBot
	git pull
else 
	git clone ${HEXBOT_REPO}
fi

echo
echo "INFO: pulling git submodules ..."
git submodule update --init --recursive





