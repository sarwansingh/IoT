#include <ESP8266WiFi.h>
#include<EEPROM.h>
int ledPin=2,ledStatus=-1;
WiFiServer server(80);  
//create server object of class WiFiServer listening at port 80

void setup() {
  pinMode(ledPin,OUTPUT); 
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to WiFi ");
  //WiFi.begin ( username, pwd ) 
  WiFi.begin("school" , "12345678");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());  // IP address of NodeMCU
  Serial.println("/");
  server.begin();
  Serial.println("Server started");
   EEPROM.begin(512);
  ledStatus = EEPROM.read(10);
  if (ledStatus == 0){
    digitalWrite(ledPin, LOW);
  }else {
    digitalWrite(ledPin, HIGH);
  } 
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) { //client ==NULL
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
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
    digitalWrite(ledPin, LOW);
    EEPROM.write(10,0);EEPROM.commit();
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, HIGH);
    EEPROM.write(10,1);EEPROM.commit();
    value = LOW;
  }
 
   // Return the response in form HTML page
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
  client.println("<br><h1> Welcome to NIELIT </h1><hr><br>");
  //if (value == LOW){ 
      client.println("Click <a href=\"/LED=ON\">here on</a> turn the LED ON<br>");
  //}else {
      client.println("Click <a href=\"/LED=OFF\"> here Off</a> turn the LED OFF <br>");
      // with image 
      client.println("Click <a href=\"/LED=OFF\"> <img src=\"http://getdrawings.com/img/light-bulb-silhouette-vector-11.png\" height=100 width=100 alt=\"OFF\"> here Off</a> turn the LED OFF <br>");
  //}
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  
 
}
