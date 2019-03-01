void setup() {
  Serial.begin(9600);
}
int f = 10;
void loop() {
  if (f == 10) {
    for (int i = 0; i < 256; i++) {
      analogWrite(11, i);
      x= analogRead(A0);
      Serial.println(i);
      delay(250);
    }
    f=1;
  }


}

