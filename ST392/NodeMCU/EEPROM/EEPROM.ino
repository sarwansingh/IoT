#include <EEPROM.h>
int ledPin = 2 ;// LED_BUILTIN ; // GPIO2 of ESP8266
int value =1;
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  pinMode(ledPin, OUTPUT);  
  value=  EEPROM.read(0);
  Serial.print("\nValue read from EEPROM  : ");
   Serial.println(value);
}
void writeEEPROM(int value){
    EEPROM.write(0, value);
    EEPROM.commit();
    Serial.print("Value wrote in EEPROM  : ");
    Serial.println(value);
}

void loop() {
//    value=1; 
    digitalWrite(ledPin, value) ;writeEEPROM(value); delay(4000); 
    // write that value in eeprom

    value = (value+1)%2;
    digitalWrite(ledPin, value) ;writeEEPROM(value); delay(4000);
     // write that value in eeprom
    
}

