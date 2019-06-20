void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
}

void loop() {
  int ch= Serial.read();
  Serial.println(ch);delay(1000);
  if (ch =='1' )   digitalWrite(13, HIGH) ;
  if (ch =='2' )  digitalWrite(13, LOW) ;

  
//  Serial.println("high");delay(1000);
//  digitalWrite(13, LOW) ;
//  Serial.println("low");delay(1000);
}
