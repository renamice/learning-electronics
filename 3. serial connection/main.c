#include "USART.h"
#include "pinDefines.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  char serialCharacter;

  // Inits
  LED_DDR = 0xff;
  initUSART();
  printString("Hello World!\r\n");

  while (1) {
      serialCharacter = receiveByte();
      transmitByte(serialCharacter);
      LED_PORT = serialCharacter;
  }
  return 0;
}
