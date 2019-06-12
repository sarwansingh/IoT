int ledPin = 13;   
int button = 2; 
void setup() {
  pinMode(ledPin , OUTPUT);
  pinMode(button , INPUT); 
}

void loop() {
  // make led on when button is pressed 
//  int x = digitalRead(button) ; 
//  if (x==1) {
  if (digitalRead(button) ==1) {
    digitalWrite(ledPin, HIGH);   // on
  } else  { // led off
    digitalWrite(ledPin,LOW) ;   //off
  }
}
