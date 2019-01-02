//Using IC Mega 2560

//Test serial using screen on host device
//screen /dev/ttyACM0 115200

//Hardware test: pin 13 blink

//list devices connected
//ls /dev

//convert c to .hex
//avr-gcc -g -Os -mmcu=atmega2560 -DF_CPU=16000000 blinkpin.c -o blinkpin.elf
//avr-objcopy -j .text -j .data -O ihex blinkpin.elf blinkpin.hex

//flash hex
//avrdude -v -p atmega2560 -c wiring -P /dev/ttyACM0 -b 115200 -D -U flash:w:blinkpin.hex:i

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void setup() {

//data direction register port a, pin 22 on mega2560
//1 = output, 0 = input
DDRA = 0b00000001;

}

void loop() {

PINA = 0b00000001;
_delay_ms(654);
PINA = 0b00000000;
_delay_ms(654);

}

int main(void) {

setup();

while(1) {
   
loop();

}

return 0;

}
