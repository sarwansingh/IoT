#include <LiquidCrystal.h>

const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Champs of ST441");
  lcd.setCursor(0, 1); // column, row
  lcd.print("NAGA Zindabad");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0); // column, row
  lcd.print("Mohan");
}
int cnt=1;
void loop() {
  lcd.autoscroll();
  lcd.print("Khusbhoo");
  lcd.scrollDisplayLeft();
//  lcd.setCursor(0, 1); // column, row
//  lcd.print(cnt); 
//  cnt++; 
  delay(1000);  
  
}
