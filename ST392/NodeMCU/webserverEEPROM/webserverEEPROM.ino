#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "postJSON.h"

const char* ssid = "Electronics";//type your ssid
const char* password = "12345678";//type your password
int value = LOW; 
int ledPin = 2 ;// LED_BUILTIN ; // GPIO2 of ESP8266
WiFiServer server(80);
int getDefaultStatus(){
    int value=  EEPROM.read(0);
    return value ; 
}
void writeEEPROM(int addr, int val){
    EEPROM.write(addr ,  val);
    EEPROM.commit();
}
////////// Upload status on webserver
String username="ST392";
String Device_No="sensor1" ; 
 //form the JSON string with the available sensor data

void updateWebserver(int value) {
  String data ;
   data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
   data += String(Device_No);
   data += "\",\"sample1\":\"";
   
   if (value==1){
        data += "1"; 
   }else {
        data += "2"; 
   }
   data += "\"}";
   jsonPOST( data );
}
///////////End - Upload status on Webserver
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);

  delay(10);
 
  pinMode(ledPin, OUTPUT);
 // default status
  value= getDefaultStatus();  
  if (value==1) {
      digitalWrite(ledPin, LOW);
  }else {
      digitalWrite(ledPin, HIGH);
  }
  // Connect to WiFi network
  Serial.println();  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
     // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) { //client ==NULL
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client" );
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW);
    writeEEPROM(0,1); // location, value to be written
    updateWebserver(1) ; 
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, HIGH);
    writeEEPROM(0,0); // location, value to be written
    updateWebserver(0) ;
    value = LOW;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("Led pin is now: ");
  if(value == HIGH) {
    client.print("On");
    
  } else {
    client.print("Off");
  }
  client.println("<br><h1> NodeMCU Automation</h1><hr>");

  if(value == HIGH) {
    //client.print("On");
    client.println("Click to <a href=\"/LED=OFF\">OFF</a> <br><br>");
  } else {
    //client.print("Off");
    client.println("Click to<a href=\"/LED=ON\">ON</a> <br><br>");
  }
  
 // client.println("<hr>Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 ON<br><br>");
 // client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("<hr>@Copyright<br><br>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
