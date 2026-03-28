#include "avr/sfr_defs.h"
#include <avr/io.h>
#include <stdint.h>

int main(void) {
  uint16_t buttonWasPressed;
  DDRB |= (1 << PB5);  // output: PB5
  PORTB |= (1 << PB0); // input: PB0

  while (1) {
    // checking if the voltage drops to 0 when button is pressed
    if (bit_is_clear(PORTB, PB0)) {
      if (buttonWasPressed == 0) {
        PORTB ^= (1 << PB5);  // toggles output, but can do anything
        buttonWasPressed = 1; // ensures button press triggers action only once
      }
    } else {
      buttonWasPressed = 0;
    }
  }
  return 0;
}
