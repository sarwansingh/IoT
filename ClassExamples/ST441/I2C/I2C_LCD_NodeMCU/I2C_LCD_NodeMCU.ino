#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
   
  lcd.println("Humidity and temperature\n\n");
}
void loop(){
  
}
