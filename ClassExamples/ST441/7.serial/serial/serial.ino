void setup() {
  Serial.begin(9600); //baud rate
  pinMode(13, OUTPUT) ; 
}

void loop() {
  char c = Serial.read();
//  c=c+1;
//  if  (c != 0){
//    Serial.println(c);
//  }
if (c==49){
  Serial.write("led on");
  digitalWrite(13, HIGH);
} 
if (c==50){
  Serial.write("led off");
  digitalWrite(13, LOW);
}
  delay(1000);
}
