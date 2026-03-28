MCU=atmega328p
F_CPU=16000000UL
PORT=/dev/ttyACM0

LIBDIR = ../AVR-Programming-Library

CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -I$(LIBDIR)

default: build

build:
	avr-gcc $(CFLAGS) -c -o main.o main.c
	avr-gcc $(CFLAGS) -o main.bin main.o

burn:
	avr-objcopy  -O ihex -R .eeprom main.bin main.hex
	sudo avrdude -F -V -c arduino -p $(MCU) -P $(PORT) -b 115200 -U flash:w:main.hex
