#include<LiquidCrystal.h>
#include <Servo.h>

const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pos = 0;
Servo servo_9;

void setup()
{ lcd.begin(16,2);
  servo_9.attach(9, 500, 2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Servo is at " );
}

void loop()
{ 
  // sweep the servo from 0 to 180 degrees in steps of 1 degrees
  for (pos = 0; pos <= 90; pos += 1) {
    servo_9.write(pos);
    lcd.setCursor(0,1);
    lcd.print("+"); lcd.print(pos);  delay(50); 
  }
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_9.write(pos);
    lcd.setCursor(0,1);
    lcd.print("-"); lcd.print(pos);delay(50); 
  }
  delay(2000);
}
