#include <SoftwareSerial.h>
#include "DHT.h"
DHT dht(5, DHT11);
SoftwareSerial WiFi_Serial(3, 4); //3-Rx, 4-Tx
String str="";  boolean wf = false; 
void setup()
{ Serial.begin(115200);  // Begin serial monitor to receive 115200 bits per second (BAUD RATE)
  pinMode(5, INPUT);
  dht.begin();
  WiFi_Serial.begin(9600); // Begin serial monitor to receive 9600 bits per second (BAUD RATE)
  WiFi_Serial.println("AT+UART_DEF=9600,8,1,0,0");  delay(1000); // set WiFi Send/Receive from 115200 bits per second (BAUD RATE) to 9600 bits per second
  WiFi_Serial.println("ATE0");  delay(200);
  WiFi_Serial.println("AT+CWQAP");delay(500); // Disconnect from previous network connections
}
void WiFi_check(){
  WiFi_Serial.println("AT"); delay(500);// send a Attention command
  if (WiFi_Serial.available())
  { if (WiFi_Serial.find("OK")) // check with expected output
    { Serial.println("WIFI PLUGGED ON TO THE BOARD..!");     
      WiFi_Serial.println("AT+CWMODE=1"); //set mode to client mode
      delay(500); 
    }
  }else{
    Serial.println("WIFI NOT PLUGGED..!   ");   
    Serial.println("PLUG IN YOUR WIFI CHIP");  wf =false;
  }
}
void loop()
{
  Serial.println("Welcome to ESP8266 interfacing with cloud");
  WiFi_check() ;
   delay(3000);
}

