int buzzer=14,onBoardLED=2 , LED=15; 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(onBoardLED, OUTPUT);pinMode(LED, OUTPUT);pinMode(buzzer, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(onBoardLED, HIGH);   digitalWrite(LED, HIGH);digitalWrite(buzzer, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(onBoardLED, LOW);    digitalWrite(LED, LOW);digitalWrite(buzzer, LOW);
  delay(1000);                       // wait for a second
}
