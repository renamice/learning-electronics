#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void POVDisplay(volatile uint8_t onebyte);

int main(void) {
  DDRB = 0xff;

  while (1) {
    POVDisplay(0b00001110);
    POVDisplay(0b00011000);
    POVDisplay(0b10111101);
    POVDisplay(0b01110110);
    POVDisplay(0b00111100);
    POVDisplay(0b00111100);
    POVDisplay(0b00111100);
    POVDisplay(0b01110110);
    POVDisplay(0b10111101);
    POVDisplay(0b00011000);
    POVDisplay(0b00001110);

    PORTB = 0;
    _delay_ms(10); 
  }
  return 0;
}

void POVDisplay(volatile uint8_t onebyte) {
  PORTB = onebyte;
  _delay_ms(2);
}
