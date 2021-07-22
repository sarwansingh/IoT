#include<EEPROM.h>
int buttonState = 0;
int led = 10,button=7 ;
void setup()
{ int st = EEPROM.read(100);
  if (st==1) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  buttonState =st;
 
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{  
  if  ( digitalRead(button)==HIGH) {
    if ( buttonState==0) buttonState=1;
    else buttonState=0; 
    while(digitalRead(button)==HIGH); 
  }
  if (buttonState == 1) {
    digitalWrite(led, HIGH);
    EEPROM.write(100,1);
  } else {
    digitalWrite(led, LOW);
    EEPROM.write(100,0);
  }
  delay(10); 
}
