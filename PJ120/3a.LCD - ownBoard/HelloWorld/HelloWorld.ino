// include the library code:
#include <LiquidCrystal.h>
 
const int rs = 19, en = 18, d4 = 17, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("welcome Indians"); 
  delay(2000);lcd.noDisplay() ;
}
int i =0; 
void loop() {
   i++ ; 
  if (i==100)  lcd.display();
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000 ); 
  lcd.print( " secs elapsed");
}
