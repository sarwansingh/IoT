void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available())
    Serial.println(Serial.read());
  delay(1000);
}
