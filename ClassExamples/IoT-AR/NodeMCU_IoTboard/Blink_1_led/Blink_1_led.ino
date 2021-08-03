int LED = 15;
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED ON
  delay(1000);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED OFF
  delay(1000);                       // wait for a second
}
