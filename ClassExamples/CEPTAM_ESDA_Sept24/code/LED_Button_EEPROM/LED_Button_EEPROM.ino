#include<EEPROM.h>
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin
int ledAddr=10;
// variables will change:
int LedState = 0;         // variable for storing LED status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  LedState = EEPROM.read(ledAddr);
}

void loop() {
  // if the button is pressed or ButtonPin is HIGH 
//  // check the LedState and reverse the state
  if ( digitalRead(buttonPin) == HIGH ){
      if (LedState == 1 )LedState = 0;
      else LedState = 1;
      while(digitalRead(buttonPin)==HIGH){}// till the button is release wait here;
      EEPROM.write(ledAddr, LedState);
  }
//  
//  // write the current state of LED using digitalWrite 
     if (LedState==0)digitalWrite(ledPin, LOW);
     if (LedState==1)digitalWrite(ledPin, HIGH);
}
