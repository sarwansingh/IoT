/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/
/*
 * for LCD interfacing use myLCD.h file
 */
#include "myLCD.h"
#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

void setup(){
    lcd.begin(16,2);
    SPI.begin();
    rfid.init(); 
    lcd.print("Rfid Card Reader" );
    delay(2000);
}

void loop(){
   
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Rfid Card No - " );
            lcd.setCursor(0,1);
            lcd.print(rfid.serNum[0]);
            lcd.print(" ");
            lcd.print(rfid.serNum[1]);
            lcd.print(" ");
            lcd.print(rfid.serNum[2]);
            lcd.print(" ");
            lcd.print(rfid.serNum[3]);
            lcd.print(" ");
            lcd.print(rfid.serNum[4]);
            lcd.println("");
         }
        
    }
  rfid.halt();
  
     
}
