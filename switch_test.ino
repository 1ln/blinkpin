//Using IC Mega 2560

//Test serial using screen on host device
//screen /dev/ttyACM0 115200

//Hardware test: pin 13 blink

//list devices connected
//ls /dev

//#include <avr/io.h>
#include <Arduino.h>

input_pin = 22;

void setup() {
pinMode(input_pin,INPUT_PULLUP);
}

void loop() {
int val = digitalRead(input_pin);

if(val == LOW) {

Serial.print("on");

digitalWrite(HIGH);
delay(100);
digitalWrite(LOW);
delay(100);

}

}

int main(void) {

init();

#if defined(USBCON)
USB.attach();
#endif

setup();

for(;;) {

loop();
if(serialEventRun) serialEventRun();

}
return 0;
}

void loop() {
int val = digitalRead(input_pin);

if(val == LOW) {
Serial.print("on");
}

}
