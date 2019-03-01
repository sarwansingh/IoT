#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11); // RX,TX magnetic card connect to 10
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("welcome software Serial");
}
void loop() {
  if (mySerial.available()){
    Serial.print((char)mySerial.read());
  }
}
