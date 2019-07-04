int ledPin = 9, led2= 10;    // LED connected to digital pin 9

void setup() {
  // nothing happens in setup
}

void loop() {
 analogWrite(ledPin , 60);
 analogWrite(led2 , 254);

 delay(1000); 
}
