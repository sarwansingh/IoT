// include the library code:
#include <LiquidCrystal.h>
int ledR=A0, ledY=A1, ledG=A2 ;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
    digitalWrite(ledR , HIGH);
    digitalWrite(ledY , HIGH);
    digitalWrite(ledG , HIGH);
    delay(500);
    digitalWrite(ledR , LOW);
    digitalWrite(ledY , LOW);
    digitalWrite(ledG , LOW);
    delay(500);
}

