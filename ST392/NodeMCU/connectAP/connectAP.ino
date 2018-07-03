#include "ESP8266WiFi.h"
int led = 2;
void setup() {
    Serial.begin(115200);
    WiFi.begin("Electronics", "12345678");
    while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Not connected");
    }
    Serial.print("Connected now : Available at ");
    Serial.println(WiFi.localIP());
    pinMode(led, OUTPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED){
      digitalWrite(led , LOW);   delay(1000); 
      digitalWrite(led , HIGH);   delay(1000);   
  }else {
    Serial.println("Not connected - - Inside loop()");
  }
}
