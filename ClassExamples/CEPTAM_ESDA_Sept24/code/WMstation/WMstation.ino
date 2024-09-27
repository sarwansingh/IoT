#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "DHT.h"
//DHT DHT;
#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// change the wifi username pwd accordingly
const char* ssid     = "demo";
const char* password = "123456789";

String serverURL  ="http://iotwebserver.glitch.me/savd" ; // donot change
// username and deviceno to be changed accordingly
String username   ="CGClandran";
String Device_No  ="sensor102" ; 
float CELSIUS=15, HUM =30;
char name1[40],blank[40],organization[40],mm_no[40],date_time[40], temperature[40], lot_number[40],storage_number[40], grain[40], moisture[40];
int i,j;

String getJSON( ){
  //////Get value from sensors////////////
//  int chk = DHT.read11(DHT11_PIN);
  String data = "";
  CELSIUS = dht.readTemperature();
  HUM     = dht.readHumidity();
  //////end //////////////
    //form the JSON string with the available sensor data
   data += "{\"username\":\"" + String(username)  + "\",\"sensorname\":\"";
   data += String(Device_No);
   data += "\",\"temprature\":\"";
   data += String( CELSIUS); //(unsigned char)
   data += "\",\"humidity\":\"";
   data += String(HUM); 
   data += "\",\"datetime\":\"";
   data += String("13-08-2024");
   data += "\",\"commodity\":\"";
   data += String(moisture); 
   data += "\"}";
   
   //CELSIUS++; HUM++; // comment these 
   return data;
}
void setup() {
  Serial.begin(9600);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}
void sendData(){
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      String JSONdata = getJSON();
      Serial.println("..Wifi connected sending JSON data.. ");
      Serial.println(JSONdata);
      
      http.begin(client, serverURL);
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST(JSONdata);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      http.end();
    }else {
      Serial.println("WiFi Disconnected");  
  }
}

void loop() {
    sendData(); 
    delay(60000) ;   
}

//    //for testing 
//      String JSONdata = getJSON();
//      Serial.println(JSONdata);
