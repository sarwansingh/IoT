 /*
 * client.connect - ESP8266NielitLab1
led control by          client.subscribe  - ESP8266/LED1 
if we want to publish       client.publish  - ESP8266/LED1_status"   
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include<EEPROM.h>
#include "JSON.h"

void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();void updateLED(int) ; 

const char* ssid = "Electronics";
const char* password = "12345678";

const char* mqtt_server = "iot.eclipse.org";
int gpio2_pin = 2;
int buttonPin = 0;     // onboard  flash button
int buttonState = 0;   
WiFiClient espClient;
PubSubClient client(espClient);
String username="st40217";
String Device_No="sensor1" ; 

 //form the JSON string with the available sensor data
String getJSON(){
  String data ;
   data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
   data += String(Device_No);
   data += "\",\"sample1\":\"";
   data += String( buttonState); 
   data += "\"}";
   return data;
}
void setup() {
    pinMode(gpio2_pin, OUTPUT);
    pinMode(buttonPin, INPUT);
    
    Serial.begin(9600);
    EEPROM.begin(512);
    //// read the EEPROM 
    buttonState = EEPROM.read(0);
    digitalWrite(gpio2_pin, buttonState);
  
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    reconnect();
}

void setup_wifi(){

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

 // while (WiFi.status() != WL_CONNECTED) {
  if (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  if((char)payload[0] == 'o' && (char)payload[1] == 'n') { //on
     if (buttonState == 0) buttonState = 1 ;  // digitalWrite(gpio2_pin, HIGH);
     updateLED(2);
     Serial.print(" pin high");
  }   
  else if((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') //off
  {  if (buttonState == 1) buttonState = 0 ;   
     updateLED(2);
     Serial.print(" pin low");
  }
  Serial.println();
}
void updateLED(int status){
  if (buttonState == 1) {
    digitalWrite(gpio2_pin, LOW);
    EEPROM.write(0, 1);
    EEPROM.commit();
    // update status on web 
    
  } else {
    digitalWrite(gpio2_pin, HIGH);
    EEPROM.write(0, 0);
    EEPROM.commit();
  }
  if (status ==2){
    String content =  getJSON() ;
    Serial.print("Status updated on web : " ) ;
    Serial.println(content);
    jsonPOST( content);
  }
}
void reconnect() {
  // Loop until we're reconnected
  //while (!client.connected()) {
  if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("NIELITst404")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish("st404/light1", "on");
      // ... and resubscribe
      client.subscribe("st404/light1");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      //delay(5000);
    }
  }
}

void loop() {
//    Serial.print("default button status  : ");
//    Serial.println(digitalRead(buttonPin) );
    if ( digitalRead(buttonPin) ==LOW) {
      if (buttonState ==1) {
        buttonState =0;
        client.publish("st404/light1", "off");
      }
      else{
        buttonState =1;
        client.publish("st404/light1", "on");
      }
      while(digitalRead(buttonPin) ==LOW ) ;
      //delay(300);
      updateLED(1);
  }
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

