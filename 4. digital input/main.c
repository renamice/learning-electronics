#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  PORTD |= (1 << PD2); // initialize pullup register for input pin PD2
  DDRB = 0xff;         // for output

  while (1) {
    if ((PIND & (1 << PD2)) == 0) // or use bit_is_clear(PIND, PD2)
      PORTB = 0b00111100;
    else
      PORTB = 0b11000011;
  }

  return 0;
}
