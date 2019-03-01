#include <LiquidCrystal.h>

//RS,E , D4,d5,d6,d7
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("INST is great!");
   lcd.setCursor(0, 1); // col, row
  lcd.print("champion of universe");
}

void loop() {
//  // set the cursor to column 0, line 1
//  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(0, 1);
//  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
}

