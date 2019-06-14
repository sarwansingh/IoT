/*
  LiquidCrystal Library - Hello World
 Demonstrates the use a 16x2 LCD display. (16-pin interface)

 This sketch prints "Hello World!" to the LCD and shows the time.

  The circuit:
 * LCD RS pin to digital pin 5
 * LCD Enable pin to digital pin 3
 * LCD D4 pin to digital pin 2
 * LCD D5 pin to digital pin 16
 * LCD D6 pin to digital pin 15
 * LCD D7 pin to digital pin 14
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

