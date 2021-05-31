/*

Neopixel!

*/

// check this lib sources at https://github.com/outofambit/easy-neopixels
#include <EasyNeoPixels.h>

#define PIN 6		    // pin for led's data 
#define LEN 10		  // how much Led's in strip
#define TAIL 3		  // for visual effect, this represent how much leds keep alive behind actual led on  
#define DELAY 50 	  // time in millisecounds

enum RGB {
    RED 	  = 250,	// betewn 0-255
    GREEN 	= 0,	  // betewn 0-255
    BLUE	  = 0	    // betewn 0-255
};


void setup() {
    setupEasyNeoPixels(PIN, LEN);
}

void come_go(){
  int i = 0;
  int f = 0;

  while ( 1 ) {
    for (i = 0; i < LEN; i++) {
      for (f = 0; f < TAIL; f++){
          writeEasyNeoPixel(i - f, RED, GREEN, BLUE); // turn on
        }
        writeEasyNeoPixel(i - f, LOW); // turn off last 
      delay(DELAY); // Waiting time
    }
    for (i = LEN; i > 0; i--) {
      for (f = TAIL; f > 0; f--){
          writeEasyNeoPixel(i - f, RED, GREEN, BLUE); // turn on
        }
        writeEasyNeoPixel(i - f, LOW); // turn off last 
      delay(DELAY); //Waiting time
    }
  }
 }

void loop() {
  come_go();
}
