#include <dht.h>
#include<LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define outPin 12  // Defines pin number to which the sensor is connected

dht DHT;      // Creates a DHT object
 
void setup(){
  Serial.begin(9600);
  Serial.print("Temp -- Humidity ") ;
}
void loop() {
  int readData = DHT.read11(outPin);

  float t = DHT.temperature;  // Read temperature
  float h = DHT.humidity; 
  //lcd.setCursor(0,1);
  Serial.print(t); 
  Serial.print("  " );
  Serial.print(h); 
  
  delay(1000);
}
