void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);              // wait for a second
  Serial.println("high");
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);              // wait for a second
  Serial.println("low");
}
