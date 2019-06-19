#include<EEPROM.h>
// save status of LEDpin in EEPROM

int LEDpin=13 ,st=-1; 
void setup() {
    pinMode(LEDpin ,  OUTPUT ) ; 
    st=EEPROM.read(10);
}

void loop() {
   if (st ==0){
    digitalWrite( LEDpin , LOW);
    EEPROM.write(10, 0); delay(4000);
    st=1;
   }
   if (st ==1){
      digitalWrite( LEDpin , HIGH); 
      EEPROM.write(10, 1); delay(4000);
      st=0;
   
   }
 }
