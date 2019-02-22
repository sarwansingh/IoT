// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// SDA - A4 , SCL - A5
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(9600);
  lcd.begin(16,2);  lcd.print("Welcome RTC" ) ;
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  } 
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
     // in order to adjust date time use the command below
    //rtc.adjust(DateTime(2019,2, 22, 11, 35,05));
  }
}

void loop () {
    DateTime now = rtc.now();
    lcd.setCursor(0,1);
    lcd.print(now.minute());lcd.print(":");
    lcd.print(now.second());
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000);
}
