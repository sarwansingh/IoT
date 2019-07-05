void setup() {
 Serial.begin(9600);
 
}

void loop() {
  char ch= Serial.read();
  if (ch!=-1) Serial.print(ch);
}
