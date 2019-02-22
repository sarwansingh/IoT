/* 
 *  toogle the state of LED when button is pressed
 */
 #include <EEPROM.h>
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int ledStatus=0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  ledStatus=EEPROM.read(0);
}
void loop() {
  //buttonState = digitalRead(buttonPin);
 
  if (digitalRead(buttonPin) == HIGH) {
    // toggle the status of led
    if (ledStatus ==0) {
      ledStatus=1;// high
      EEPROM.write(0, 1);// addr, value
    }
    else{
      ledStatus=0;
      EEPROM.write(0, 0);// addr, value
    }
    while(digitalRead(buttonPin)==HIGH); // wait till button is released
  }
  if (ledStatus ==1){
      digitalWrite(ledPin, HIGH);
  }else {
      digitalWrite(ledPin, LOW);
  }
}
