void setup() {
 Serial.begin(9600);
 Serial.print("DRDO Zindabad");
}

void loop() {
  int x = Serial.read();
  Serial.println(x+1);
  delay(1000);
}
