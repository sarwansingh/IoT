#include<LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup(){
  lcd.begin(16,2);
  lcd.print("IoT champs ") ;
}
void loop() {
  
}
