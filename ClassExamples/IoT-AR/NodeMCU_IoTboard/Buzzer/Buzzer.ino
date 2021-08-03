int Buzzer = 14;

void setup() {
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  digitalWrite(Buzzer, HIGH);   // turn the Buzzer ON
  delay(1000);                       // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the Buzzer OFF
  delay(1000);                       // wait for a second
}
