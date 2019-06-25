
void setup() {
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  digitalWrite(10 , HIGH); digitalWrite(6 , LOW);
  digitalWrite(9 , LOW); digitalWrite(11 , LOW); 
  delay(500);
  digitalWrite(10 ,LOW ); digitalWrite(6 , HIGH);
  digitalWrite(9 , LOW); digitalWrite(11 , LOW); 
  delay(500);
  digitalWrite(10 , LOW); digitalWrite(6 , LOW);
  digitalWrite(9 , HIGH); digitalWrite(11 , LOW); 
  delay(500);
  digitalWrite(10 , LOW); digitalWrite(6 , LOW);
  digitalWrite(9 , LOW); digitalWrite(11 , HIGH); 
  delay(500) ;

}
