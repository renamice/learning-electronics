MCU=atmega328p
F_CPU=16000000UL
PORT=/dev/ttyACM0

LIBDIR = ../AVR-Programming-Library

CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -I$(LIBDIR)

FILE=main

default: build

build:
	avr-gcc $(CFLAGS) -c -o $(FILE).o $(FILE).c
	avr-gcc $(CFLAGS) -o $(FILE).bin $(FILE).o
	avr-objcopy  -O ihex -R .eeprom $(FILE).bin $(FILE).hex

burn:
	sudo avrdude -F -V -c arduino -p $(MCU) -P $(PORT) -b 115200 -U flash:w:$(FILE).hex
