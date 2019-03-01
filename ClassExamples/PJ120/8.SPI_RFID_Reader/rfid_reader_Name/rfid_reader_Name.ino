#include <RFID.h>

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


int led = 7;
int power = 8; 
int serNum[5];
int cards[][5] = {
  {89, 204, 182, 115, 80 },
  {17, 92 ,48, 46, 83}
};
char names[][20]= { " Amitabh B" , " Hema malini " } ;
bool access = false;

void setup(){
    Serial.begin(9600);
    SPI.begin();
    rfid.init(); 
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

            if (rfid.serNum[0] == 89 ) { // match the entire
              Serial.println( names[0] );
            }
            if (rfid.serNum[0] == 17 ) {
              Serial.println( names[1] );
            }
        }
        
    }
  rfid.halt();
  
            
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
//    }
//    
//    
    
}


