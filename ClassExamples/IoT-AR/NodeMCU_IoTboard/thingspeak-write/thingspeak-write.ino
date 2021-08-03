#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid     = "wifi-ssid";
const char* password = "wifi-password";
unsigned long myChannelNumber = 584824;
const char * myWriteAPIKey = "GR6OYFO8CDTYCWUJ";
WiFiClient WiFiclient;

int val=0;

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(WiFiclient);
}

void loop() {
  val++;
  ThingSpeak.setField(1, val);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(val==10){
    val=0;
  }
  delay(17000);
}
