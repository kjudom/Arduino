// the number of floating point digits is set to 2 in "DigitLedDisplay.h"
#include "DigitLedDisplay.h"

/* Arduino Pin to Display Pin
   2 to DIN,
   4 to LD,
   3 to CLK */

DigitLedDisplay ld = DigitLedDisplay(2, 4, 3);  

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
    ld.printFloat((float)i/100);
    delay(25);
  }

  /* Clear all display value */
  ld.clear();
  delay(500);

}
