#include "DigitLedDisplay.h"

/* Arduino Pin to Display Pin
   2 to DIN,
   4 to LD,
   3 to CLK */
   
#define DIN 2
#define LD 4
#define CLK 3
#define ndigits 1   // use 1 floating point digit

//DigitLedDisplay ld = DigitLedDisplay(DIN, LD, CLK);   // default with 2 floating point digits
//DigitLedDisplay ld = DigitLedDisplay(DIN, LD, CLK, ndigits);  

DigitLedDisplay ld = DigitLedDisplay(15, 22, 21, ndigits);  // test for ESP32

void setup() {

  Serial.begin(115200);
  
  /* Set the brightness min:1, max:15 */
  ld.setBright(10);

  /* Set the digit count */
  ld.setDigitLimit(5);

}

void loop() {

  /* Prints integer number to the display */
  ld.printDigit(12345);
  delay(500);
  ld.clear();
  delay(500);

  // test for float 
  for (int i = -200; i < 200; i++) {
    //float v = (float)i/1000;  // test for 3 digits
    //float v = (float)i/100;  // test for 2 digits
    float v = (float)i/10;   // test for 1 digit
    ld.printFloat(v);
    Serial.println(v, ndigits);
    delay(25);
  }

  /* Clear all display value */
  ld.clear();
  delay(500);

}
