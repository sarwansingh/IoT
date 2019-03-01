#include <EEPROM.h>
int address = 0;
byte value;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);  pinMode(2,INPUT);  
  // testig the LED
//  digitalWrite(13,HIGH); delay(1000);  
//  digitalWrite(13,LOW); delay(1000); 
  value = EEPROM.read(0);
  Serial.print("value in EEPROM  : ");
  Serial.println (value) ; 
  if (value ==1)// switch on LED else off
    digitalWrite(13,HIGH);
  else 
    digitalWrite(13,LOW);
}

void loop() {
    if (digitalRead(2) ==HIGH) {
      if (value==1) value=0;
      else value=1;
      while (digitalRead(2) ==HIGH) ;
      EEPROM.write(0, value);
      Serial.print(" value Updated in EEPROM  : ");
      Serial.println (value) ; 
    }
    if (value ==1)// switch on LED else off
      digitalWrite(13,HIGH);
    else 
      digitalWrite(13,LOW); 

}
