#define s1 0
#define s0 2

void setup() {
  Serial.begin(9600);
  //pinMode(s1, OUTPUT);
  //pinMode(s0, OUTPUT);
  //digitalWrite(s1, 0);
  //digitalWrite(s0, 0);
}

void loop() {
  uint16_t pot=analogRead(A0);
  Serial.println(pot);
  delay(1000);
}
