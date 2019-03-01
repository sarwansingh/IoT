#include <RFID.h>
#include <Wire.h>
#include "RTClib.h"
/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/

#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int led = 7;
int power = 8; 
int serNum[5];
struct  Employee {
    int card[5];
    char name[20];
} ;
struct  Employee emp[] ={
  {{2,107,84,195,254}, "Ms. Anita" },
  {{43, 226, 236, 102, 67}, "Amit Kumar Dhadak" },
  {{171, 119, 245, 102, 79 } , "Rohini Pathak"},
  {{225, 84, 14, 45, 150 } ,"Kunwar Vijay Pratap"}
};
bool access = false;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    if (! rtc.begin()) {
      Serial.println("Couldn't find RTC"); //while (1);
    }

//    pinMode(led, OUTPUT);
//    digitalWrite(led, LOW);
   
}
int i ; 
void showTime(){
   DateTime now = rtc.now();
    
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
}
void loop(){
    
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
        }
        for( i=0 ;i<sizeof(emp) ;i++) {
          if ((rfid.serNum[0]== emp[i].card[0]) && 
              (rfid.serNum[1]== emp[i].card[1]) &&
              (rfid.serNum[2]== emp[i].card[2]) &&
              (rfid.serNum[3]== emp[i].card[3]) &&
              (rfid.serNum[4]== emp[i].card[4]) ) 
          {
             Serial.println( emp[i].name);
             Serial.print( "Time now :  ");
             showTime();
             delay(800);
          }
        }    
        
    }
    
 rfid.halt();

}

/*
 * if ((rfid.serNum[0]== emp[0].card[0]) && 
            (rfid.serNum[1]== emp[0].card[1]) &&
             (rfid.serNum[2]== emp[0].card[2]) &&
             (rfid.serNum[3]== emp[0].card[3]) &&
             (rfid.serNum[4]== emp[0].card[4]) ) 
             Serial.println( emp[0].name);  

         if ((rfid.serNum[0]== emp[1].card[0]) && 
            (rfid.serNum[1]== emp[1].card[1]) &&
             (rfid.serNum[2]== emp[1].card[2]) &&
             (rfid.serNum[3]== emp[1].card[3]) &&
             (rfid.serNum[4]== emp[1].card[4]) ) 
             Serial.println( emp[1].name);  
 */
       
//            for(int x = 0; x < sizeof(cards); x++){
//              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
//                  if(rfid.serNum[i] != cards[x][i]) {
//                      access = false;
//                      break;
//                  } else {
//                      access = true;
//                  }
//              }
//              if(access) break;
//            }
//           
//        }
//        
//       if(access){
//          Serial.println("Welcome!");
//           digitalWrite(led, HIGH); 
//           delay(1000);
//           digitalWrite(led, LOW);
//           digitalWrite(power, HIGH);
//           delay(1000);
//           digitalWrite(power, LOW);
//           
//      } else {
//           Serial.println("Not allowed!"); 
//           digitalWrite(led, HIGH);
//           delay(500);
//           digitalWrite(led, LOW); 
//           delay(500);
//           digitalWrite(led, HIGH);
//           delay(500);
//           digitalWrite(led, LOW);         
//       }        
//    }
//    
//    
    
   


