#include<LiquidCrystal.h>
#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);//pins used 8,9,10, 11,12,13 
//PWM 3,5,6,9,10,11
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pos = 0;
//Servo servo_6;

int idOK=187 ; 

void setup()
{ 
  SPI.begin();
  rfid.init(); 
  lcd.begin(16,2);
  //servo_6.attach(9, 500, 2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rfid-Security" );
}

void loop()
{ if(rfid.isCard()){
    if(rfid.readCardSerial()){
      //lcd.print(rfid.serNum[0]);
      if (rfid.serNum[0] == idOK ) {
        //lcd.clear();
        lcd.setCursor(0,1); 
        lcd.print("Door Opening");
        doorOperate();  
        lcd.setCursor(0,1);
        lcd.print("Door  Closed");
      }
    }
  }
  rfid.halt();
  
} 
void doorOperate(){ 
    // sweep the servo from 0 to 180 degrees in steps of 1 degrees
  for (pos = 0; pos <= 90; pos += 1) {
   // servo_6.write(pos);
    lcd.setCursor(14,1); 
    if (pos%2)lcd.print("/"); 
    if (!(pos%2))lcd.print("\\");
    delay(50); 
  }
  for (pos = 90; pos >= 0; pos -= 1) {
   // servo_6.write(pos);
    delay(50); 
  }
  delay(1000); 
}
