#include<EEPROM.h>
// save status of LEDpin in EEPROM

int LEDpin=10  ; 
int button=7;  int butState = 0;
void setup() {
    pinMode(LEDpin ,  OUTPUT ) ; 
    pinMode(button ,  INPUT ) ; 
    butState  = EEPROM.read(10);
}

void loop() {
    
   if (digitalRead(button)==HIGH) {
     butState = !butState;
      //if (butState==0)  butState =1; 
      //else  butState =0; 
      while(digitalRead(button)==HIGH) ; 
   }
   if (butState ){
      digitalWrite( LEDpin , HIGH);    
      EEPROM.write(10,1);
   }else {
      digitalWrite( LEDpin , LOW);  
      EEPROM.write(10,0);
   }
 }
