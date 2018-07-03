#include "ESP8266WiFi.h"
int led = 2;
WiFiServer server(80); // configure Node as server running at port 80;
//WiFiClient client ;   
void setup() {
    Serial.begin(115200);
    WiFi.begin("demo", "12345678");
    while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Not connected");
    }
    Serial.print("Connected now : Available at ");
    Serial.println(WiFi.localIP());
    pinMode(led, OUTPUT);
}

void loop() {

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
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(led, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(led, LOW);
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
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br><br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

