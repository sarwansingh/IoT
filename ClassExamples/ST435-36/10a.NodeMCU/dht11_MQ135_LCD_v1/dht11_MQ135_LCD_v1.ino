#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
// working 
#include <LiquidCrystal_I2C.h>
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
int sensorValue;

void setup()
{ 
  lcd.clear();
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);
  lcd.init();
  lcd.backlight();

}
void loop() {
  sensorValue = analogRead(0); 
  lcd.setCursor(0,0);
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();  
    lcd.print("h=");
    lcd.print(hum);
    lcd.print("%");
 
    Serial.print("Current humidity = ");
    Serial.print(hum);
    Serial.print("% ");
    Serial.print("temperature = ");
    lcd.print(" T= ");
    Serial.print(temp); 
//    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.print("C");    
    Serial.println("C  ");
//  delay(800);
//   lcd.clear();
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);
  Serial.println(" PPM");
  lcd.setCursor(0,1);
  lcd.print("ArQ=");
  lcd.print(sensorValue,DEC);
  lcd.print(" PPM");
  lcd.println("       "); 
  lcd.print("  ");
  delay(1000); 
  
   lcd.clear();
}
