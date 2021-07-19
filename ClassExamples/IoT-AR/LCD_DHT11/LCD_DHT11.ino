#include <dht.h>
#include<LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define outPin 1  // Defines pin number to which the sensor is connected

dht DHT;      // Creates a DHT object
 
void setup(){
  lcd.begin(16,2);
  lcd.print("Temp -- Humidity ") ;
}
void loop() {
  int readData = DHT.read11(outPin);

  float t = DHT.temperature;  // Read temperature
  float h = DHT.humidity; 
  lcd.setCursor(0,1);
  lcd.print(t); 
  lcd.print("  " );
  lcd.print(h); 
  
  delay(1000);
}
