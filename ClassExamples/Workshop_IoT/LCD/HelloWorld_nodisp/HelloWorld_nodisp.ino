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
  delay(1000);
}
unsigned int i=65530;
void loop() {
  lcd.clear();
  lcd.print(i); i++;
  delay(1000);
}

