#include <dht.h>
#include<LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define outPin 1  // Defines pin number to which the sensor is connected
dht DHT;      // Creates a DHT object
 
void setup(){
  lcd.begin(16,2);
  lcd.print("Gas ") ;
}
void loop() {
  int gas =  digitalRead(A3);
  lcd.setCursor(0,1);
  lcd.print(gas); 
    
  delay(1000);
}
