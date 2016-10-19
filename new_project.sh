#!/bin/bash

NAME="test"
CPU_F="16000000"
MMCU="atmega328p"
PROJECT="Test"

echo "************ Making a makefile ************"
echo ""
echo "Project name: (default=$PROJECT) "
read
if [ ! -z $REPLY]; then
	PROJECT=$REPLY
fi
REPLY=""

echo "Program name: (default=$NAME) "
read 
if [ ! -z $REPLY ]; then
	NAME=$REPLY
fi
REPLY=""

echo "CPU Clock: (default=$CPU_F) "
read
if [ ! -z $REPLY ]; then
	CPU_F=$REPLY 
fi
REPLY=""

echo "MMCU: (default=$MMCU) "
read
if [ ! -z $REPLY ]; then
	MMCU=$REPLY
fi
REPLY=""


mkdir $PROJECT
cd $PROJECT

cat > Makefile << EOF 

NAME=$NAME
CPU_F=$CPU_F 
MMCU=$MMCU

all: hex

hex: exe
	avr-objcopy -O ihex -R .eeprom \$(NAME) \$(NAME).hex
exe: obj
	avr-gcc -mmcu=\$(MMCU) \$(NAME).o -o \$(NAME)
obj: \$(NAME).c
	avr-gcc -Os -DF_CPU=\$(CPU_F) -mmcu=\$(MMCU) -c -o \$(NAME).o \$(NAME).c

clear:
	rm \$(NAME)
	rm \$(NAME).o
	rm \$(NAME).hex

upload: hex
	sudo chmod 777 /dev/ttyACM0
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:\$(NAME).hex
EOF
