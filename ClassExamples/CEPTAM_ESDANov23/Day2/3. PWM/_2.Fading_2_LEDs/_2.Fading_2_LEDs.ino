/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.
use LED Add_on Board 
 */
int ledPin9 = 9;    // LED connected to digital pin 9
int ledPin11 = 11;    // LED connected to digital pin 11

void setup() {
  // nothing happens in setup
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin9, fadeValue);
    analogWrite(ledPin11, 255-fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin9, fadeValue);
    analogWrite(ledPin11, 255-fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}


