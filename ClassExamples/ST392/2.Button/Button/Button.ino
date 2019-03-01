
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int buttonState = 0,x=0;         // variable for reading the pushbutton status
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if(x==0) x=1; // toggle the of x whenever buttonstate is HIGH
    else x=0;
    while ( digitalRead(buttonPin)==1  )  {} //the button is pressed 
  }
  if (x==1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
