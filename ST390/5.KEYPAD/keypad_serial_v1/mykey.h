
void getKeyPress(){
  //make R1 as High and rest all rows LOW
  digitalWrite(R1,LOW); digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH); digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  valc1 = digitalRead(C1);
  valc2 = digitalRead(C2); valc3 = digitalRead(C3);
  //check for each column
  if ( valc1 == LOW) {Serial.println(keys[0][0]); delay(200);}
  if ( valc2 == LOW) {Serial.println(keys[0][1]);delay(200);}
  if ( valc3 == LOW) { Serial.println(keys[0][2]);delay(200);}
  
  digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println(keys[1][0]);delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println(keys[1][1]);delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println(keys[1][2]);delay(200);}
   
  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println(keys[2][0]);delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println(keys[2][1]);delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println(keys[2][2]);delay(200);}

  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,LOW);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println(keys[3][0]);delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println(keys[3][1]);delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println(keys[3][2]);delay(200);}
}
