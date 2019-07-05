#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "JSON.h"

const char* ssid     = "Sk";
const char* password = "12345678";
void  jsonPOST(String);
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 

// JSON String - {"username":"sandeep","name":"test101","sample1":"9","sample2":"99","sample5":"-1"}

String username="sandeep";
String Device_No="sensor1" ; 
int CELSIUS=-1, HUM =-1;

 //form the JSON string with the available sensor data
String getJSON(){
  String data ;
   data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
   data += String(Device_No);
   data += "\",\"sample1\":\"";
   data += String( CELSIUS); //(unsigned char)
   data += "\",\"sample2\":\"";
   data += String(HUM); 
   data += "\",\"sample5\":\"";
   int nosample=-1;
   data += String(nosample); 
   data += "\"}";
   return data;
}
void setup() {
 Serial.begin(9600);
  delay(10);
 // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
dht.begin();
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}
void loop() {
    HUM = dht.readHumidity();
    CELSIUS = dht.readTemperature(); 
    String content =  getJSON() ;
    Serial.println(content);
    jsonPOST( content);
  delay(5000) ;
}
