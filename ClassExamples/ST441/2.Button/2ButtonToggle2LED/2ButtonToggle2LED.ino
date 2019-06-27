// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 7,buttonPin2 = 8;     // the number of the pushbutton pin
const int ledPin1 =  10,ledPin2 = 6;      // the number of the LED pin
 
// variables will change:
int buttonState1 = 0,buttonState2 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);pinMode(buttonPin2, INPUT);
}
int flag1 =0,flag2 =0;
void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH) {
    // toggle value of flag whenever button is pressed.
    if (flag1==0)flag1=1 ; 
    else flag1 =0; 
    // stop here till user leaves button
    // and digitalRead(buttonPin) returns low.
    while(digitalRead(buttonPin1) == HIGH);
  }
  if (flag1 ==1){
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
  /////////second led
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH) {
    // toggle value of flag whenever button is pressed.
    if (flag2==0)flag2=1 ; 
    else flag2 =0; 
    // stop here till user leaves button
    // and digitalRead(buttonPin) returns low.
    while(digitalRead(buttonPin2) == HIGH);
  }
  if (flag2 ==1){
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }
}
