int R1=2,R2=3,R3=4,R4=5;
int C1=6,C2=7,C3=8 ;
void setup() {
  pinMode(R1,OUTPUT) ; pinMode(R2,OUTPUT) ; 
  pinMode(R3,OUTPUT) ; pinMode(R4,OUTPUT) ; 
  pinMode(C1,INPUT) ; pinMode(C2,INPUT) ; 
  pinMode(C3,INPUT) ;
  Serial.begin(9600);
  Serial.println("Welcome to Keypad");
//  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
//  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
}
int valc1, valc2, valc3;
void loop() {
  //make R1 as High and rest all rows LOW
  digitalWrite(R1,LOW); digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH); digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  valc1 = digitalRead(C1);
  valc2 = digitalRead(C2); valc3 = digitalRead(C3);
  //check for each column
  if ( valc1 == LOW) {
    lcd.print ("1"); delay(200);
  
  }
  if ( valc2 == LOW) {lcd.print ("2");delay(200);}
  if ( valc3 == LOW) {lcd.print ("3");delay(200);}
  
  digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println("4");delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println("5");delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println("6");delay(200);}
   
  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println("7");delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println("8");delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println("9");delay(200);}

  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,LOW);
  //check for each column
  if (digitalRead(C1) == LOW) { Serial.println("*");delay(200);}
  if (digitalRead(C2) == LOW) { Serial.println("0");delay(200);}
  if (digitalRead(C3) == LOW) { Serial.println("#");delay(200);}
}
