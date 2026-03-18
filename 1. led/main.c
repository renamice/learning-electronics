#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Setting pin 8 to Output
    DDRB = DDRB | (1);
    
    while(1) {
        // Setting pin 8
        PORTB = PORTB | (1);
        _delay_ms(1000);

        // Unsetting pin 8
        PORTB = PORTB & ~(1);
        _delay_ms(1000);
    }
}
