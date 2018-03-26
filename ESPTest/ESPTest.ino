#include <SoftwareSerial.h>
SoftwareSerial WiFi_Serial(4, 3); //3-Rx, 4-Tx
String str="";  boolean wf = false; 
void setup()
{ Serial.begin(115200);  // Begin serial monitor to receive 115200 bits per second (BAUD RATE)
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
      delay(500);  wf = true; 
    }
  }else{
    Serial.println("WIFI NOT PLUGGED..!   ");   
    Serial.println("PLUG IN YOUR WIFI CHIP");  wf =false;
  }
}
//void connectWifi()   // connect to wifi network
//{ WiFi_Serial.println("AT+CWJAP?"); delay(2000);//check if WIFI connected to any WiFi network
//  if (WiFi_Serial.available())
//  { 
//    if (WiFi_Serial.find("No AP")) //we receive reponse "No AP" when not connected to any network
//    { 
//      //Serial.println("NOT CONNECTED TO WIFI NETWORK");    
//      Serial.println("Trying to Connect to WiFi Network");
//      str="AT+CWJAP=\"demo1\",\"12345678\"";
//      WiFi_Serial.println(str); // CWJAP followed by username and password
//      delay(2000);
//      
//      if (WiFi_Serial.available())
//      {    String RES_input = "";
//        while (WiFi_Serial.available()) // read the data into a variable as long as the
//        {  RES_input += (char)WiFi_Serial.read(); }
//        Serial.println("--->"+ RES_input);
//        if (WiFi_Serial.find("WIFI CONNECTED")){         
//            Serial.println("CONNECTED TO WIFI NETWORK..!"); 
//        }else {
//            Serial.println("ESP not CONNECTED TO WIFI NETWORK..!"); 
//        }
//     }
//    } 
//  }
//}
void loop()
{
  Serial.println("Welcome to ESP8266 interfacing with cloud");

  WiFi_check() ;
     
  delay(1000);
}


//  if (wf == true){ 
//    connectWifi();  
//  } 

