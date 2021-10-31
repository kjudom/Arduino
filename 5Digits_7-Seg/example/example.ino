/* Arduino Nano Pin to Display Pin
   2 to DIN
   3 to CLK
   4 to LOAD
*/

#include "DigitLedDisplay.h"

DigitLedDisplay ld = DigitLedDisplay(2, 4, 3);  

void setup() {
	
  /* Set the brightness min:1, max:15 */
  ld.setBright(10);

  /* Set the digit count */
  ld.setDigitLimit(5);
}

void loop() {
	
  /* Prints data to the display */
  ld.printDigit(88888);
  delay(500);
  ld.clear();
  delay(500);
  
  ld.printDigit(12345);
  delay(500);

  // display the dot with the numbers 1 to 5
  for (int i = 1; i <= 5; i++) {	
    ld.write(i, B10000000 | pgm_read_byte_near(charTable + i));
    delay(500);
  }
  
  ld.clear();
  delay(500);

  // count from 0 to 99
  for (long i = 0; i < 100; i++) {
    ld.printDigit(i);
    delay(25);
  }

  for (int i = 0; i <= 20; i++) {
    /* Select Digit 5 and write B01100011 */
    ld.write(5, B01100011);
    delay(200);

    /* Select Digit 5 and write B00011101 */
    ld.write(5, B00011101);
    delay(200);
  }

  /* Clear all display value */
  ld.clear();
  delay(500);
}
