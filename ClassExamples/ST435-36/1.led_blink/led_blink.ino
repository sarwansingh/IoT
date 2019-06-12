int ledPin = 13;   
void setup() {
  pinMode(ledPin , OUTPUT); 
}

void loop() {
  // make led blink 
    digitalWrite(ledPin, HIGH); delay(1000);
    digitalWrite(ledPin,LOW) ;  delay(500); 
}
