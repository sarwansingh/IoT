int R1=5,R2=6,R3=7,R4=8,C1=2,C2=3,C3=4;
void setup() {
 Serial.begin(9600);
 Serial.println("Welcome Serial");
 // all rows OUTPUT and cols INPUT
 pinMode(R1,OUTPUT);pinMode(R2,OUTPUT);pinMode(R3,OUTPUT);pinMode(R4,OUTPUT);
 pinMode(C1,INPUT);pinMode(C2,INPUT);pinMode(C3,INPUT);
 digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);  digitalWrite(C3,HIGH);
}
int i=0;
void loop() {
  digitalWrite(R1,LOW);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  if (digitalRead(C1) ==  LOW) {Serial.println("1"); delay(300);}
  if (digitalRead(C2) ==  LOW) {Serial.println("2"); delay(300);}
  if (digitalRead(C3) ==  LOW) {Serial.println("3"); delay(300);}
 //////////// second row
 digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  if (digitalRead(C1) ==  LOW) {Serial.println("4"); delay(300);}
  if (digitalRead(C2) ==  LOW) {Serial.println("5"); delay(300);}
  if (digitalRead(C3) ==  LOW) {Serial.println("6"); delay(300);} 
  //////////// third row
 digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  if (digitalRead(C1) ==  LOW) {Serial.println("7"); delay(300);}
  if (digitalRead(C2) ==  LOW) {Serial.println("8"); delay(300);}
  if (digitalRead(C3) ==  LOW) {Serial.println("9"); delay(300);} 
  
}
