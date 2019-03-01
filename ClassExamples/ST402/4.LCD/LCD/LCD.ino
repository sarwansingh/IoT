// include the library code:
#include <LiquidCrystal.h>
// A0=14 to A5=19  - 
int rs=19 , e=18, d4=17,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);// set up the LCD's number of columns and rows:
  lcd.print("Welcome st402 ");// Print a message to the LCD.
  delay(2000);  lcd.clear();
}
char str[] = "India is great country with brave people and wonderful scenic beauty. That's why we say incredible India" ;
int a=0;
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  for (int i=a ; i<a+16 ; i++)  {
    lcd.print(str[i]);  
    delay(100);
  }
  lcd.setCursor(0, 1);
  for (int i=a+16 ; i<a+32 ; i++)  {
    lcd.print(str[i]);  
    delay(100);
  }
  a=a+16;
  // check for overflow 
  delay(1000);
}

