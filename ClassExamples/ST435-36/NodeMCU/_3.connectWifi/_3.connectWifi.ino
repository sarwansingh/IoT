#include <ESP8266WiFi.h>
int ledPin=2;
void setup() {
  pinMode(ledPin,OUTPUT); 
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to WiFi ");
  
  WiFi.begin("VS" , "0987654321");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
   digitalWrite (ledPin, HIGH) ; delay(1000);
   Serial.println("LED high");
   digitalWrite (ledPin, LOW) ; delay(1000);
   Serial.println("LED low");
}
