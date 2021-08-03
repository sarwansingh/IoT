int ledPin=2 ; 
void setup() {
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);  
  delay(1000);                       
  digitalWrite(ledPin, LOW);    
  delay(1000);                     
}
