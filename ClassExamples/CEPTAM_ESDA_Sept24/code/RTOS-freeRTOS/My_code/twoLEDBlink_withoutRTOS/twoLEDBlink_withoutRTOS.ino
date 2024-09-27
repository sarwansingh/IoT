int led1=13, led2=12 ; 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led1, OUTPUT);  pinMode(led2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, HIGH);    delay(1000);              
  digitalWrite(led1, LOW);     delay(1000);
  // wait for a second

  digitalWrite(led2, HIGH);     delay(3000);              
  digitalWrite(led2, LOW);     delay(3000);
}
