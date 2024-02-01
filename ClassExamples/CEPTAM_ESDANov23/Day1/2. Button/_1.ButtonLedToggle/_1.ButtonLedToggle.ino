/*  Button
 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.
 */

// constants won't change. set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin

// variables will change:
int LedState = 0;         // variable for storing LED status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // if the button is pressed or ButtonPin is HIGH 
  // check the LedState and reverse the state
  if ( digitalRead(buttonPin) == HIGH ){
      if (LedState == HIGH )LedState = LOW;
      else LedState = HIGH;
  }
  
  // write the current state of LED using digitalWrite 
     digitalWrite(ledPin, LedState);
}
