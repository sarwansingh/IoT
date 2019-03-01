#include <LiquidCrystal.h>
int R1=2,R2=3,R3=4,R4=5 ;
int C1=6,C2=7,C3=9  ;
int buzz=12;
LiquidCrystal lcd(19,18,17,16,15,14);
void setup() {
 lcd.begin(16,2);
 lcd.print("Calculator");
 // all rows OUTPUT and cols INPUT
 pinMode(R1,OUTPUT);pinMode(R2,OUTPUT);pinMode(R3,OUTPUT);pinMode(R4,OUTPUT);
 pinMode(C1,INPUT);pinMode(C2,INPUT);pinMode(C3,INPUT);
 digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);  digitalWrite(C3,HIGH);
 lcd.setCursor(0,1); // move lcd cursor to second row first column. 
 pinMode(buzz,OUTPUT);
}
void buzzON(){digitalWrite(buzz,HIGH);}
void buzzOFF(){digitalWrite(buzz,LOW);}
 int n=0,n1=0;
void loop() {
  digitalWrite(R1,LOW);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  if  (digitalRead(C1) ==  LOW) {     
      lcd.print("1"); buzzON();delay(300);buzzOFF();
      n=n*10+1;
  }
  if (digitalRead(C2) ==  LOW) {
      lcd.print("2"); buzzON();delay(300);buzzOFF();
      n=n*10+2;
   }
  if (digitalRead(C3) ==  LOW) {  
      lcd.print("3"); buzzON();delay(300);buzzOFF();
      n=n*10+3;
   }
 //////////// second row
 digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  if (digitalRead(C1) ==  LOW) {lcd.print("4"); delay(300);}
  if (digitalRead(C2) ==  LOW) {lcd.print("5"); delay(300);}
  if (digitalRead(C3) ==  LOW) {lcd.print("6"); delay(300);} 
  //////////// third row
 digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  if (digitalRead(C1) ==  LOW) {
      lcd.print("+"); 
      n1 = n;  n=0; 
      delay(300);}
  if (digitalRead(C2) ==  LOW) {lcd.print("8"); delay(300);}
  if (digitalRead(C3) ==  LOW) {lcd.print("9"); delay(300);} 
   //////////// fourth row
 digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,LOW);
  if (digitalRead(C1) ==  LOW) {lcd.clear(); lcd.setCursor(0,0);}
  if (digitalRead(C2) ==  LOW) {lcd.print("0"); delay(300);}
  if (digitalRead(C3) ==  LOW) {lcd.print("="); 
      n1+=n; n=0;
      lcd.print(n1);
      delay(300);} 
  
}
