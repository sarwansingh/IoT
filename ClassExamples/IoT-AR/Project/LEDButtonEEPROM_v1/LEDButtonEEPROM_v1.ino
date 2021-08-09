#include<EEPROM.h>
// LEDs -  10,6  . Buttons-7,8 
const int button1 = 7, button2=8 ;     // the number of the pushbutton pin
const int led1=10, led2=6;        // the number of the LED pin

int led1status=0, led2status=0;
int data=-1; 

void setup() {
  Serial.begin(9600);
  led1status = EEPROM.read(101);
  led2status = EEPROM.read(102);
  pinMode(led1, OUTPUT);  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);pinMode(button2, INPUT);
}

void loop() {
  ///////// Receive data from serial 
  if(Serial.available() > 0){
    data = Serial.read() ;
  }
  if (data=='1')led1status=1;
  if (data=='0')led1status=0;

  ///////// end .........
  
  ////////// check buttons 
  if (digitalRead(button1) == HIGH) {
    if (led1status ==1) led1status=0;
    else led1status=1 ; 
    EEPROM.write(101, led1status);
    while(digitalRead(button1) == HIGH);
  }
  if (digitalRead(button2) == HIGH) {
    if (led2status ==1) led2status=0;
    else led2status=1 ; 
    EEPROM.write(102, led2status);
    while(digitalRead(button2) == HIGH);
  }
  ////////// end check buttons 
  
  if (led1status==1 ) digitalWrite(led1, HIGH);
  else digitalWrite(led1, LOW);
  
  if (led2status==1 ) digitalWrite(led2, HIGH);
  else digitalWrite(led2, LOW);
}
