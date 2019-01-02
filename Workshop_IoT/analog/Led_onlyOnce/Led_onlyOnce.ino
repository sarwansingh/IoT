void setup() {

}
int f = 0;
void loop() {
  if (f == 0) {
    for (int i = 0; i < 256; i++) {
      analogWrite(11, i);
      delay(50);
    }
    f=1;
  }


}

