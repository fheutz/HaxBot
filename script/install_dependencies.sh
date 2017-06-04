#!/bin/bash

set -e
set -u


echo
echo "INFO: install needed software / dependencies ..."
apt-get -y install \
	avr-libc \
	avrdude \
	binutils \
	gcc-avr \
	git \
	wget

