#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
int ledR=A0, ledY=A1, ledG=A2 ;
int relay=4 ; 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
SoftwareSerial mySerial(5, 6); // RX, TX

void setup() {
  lcd.begin(16, 2);
  lcd.print("BT-HomeAutomation");
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(relay,OUTPUT);
  mySerial.begin(9600);
}
char a; 
void loop() {
    lcd.setCursor(0, 1);
    
    if (mySerial.available()) {
      a = mySerial.read();
      lcd.print(a);
    }
    if (a=='1') {
      digitalWrite(ledR , HIGH);
      digitalWrite(relay , HIGH);
    }
    if (a=='2'){
      digitalWrite(ledR , LOW);
      digitalWrite(relay , LOW);
    }

    if (a=='3')digitalWrite(ledG , HIGH);
    if (a=='4') digitalWrite(ledG , LOW);

    if (a=='5')digitalWrite(ledY , HIGH);
    if (a=='6') digitalWrite(ledY , LOW);
}

