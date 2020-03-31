/*
   Connect to LAN and get an IP address
  Connect to Firebase Realtime Database
  Push luminosity / LDR value to Firebase Realtime Database
*/

int sensorPin = A0;                 // References A0 analog pin
int sensorValue;                    // 10-bit equivalent value of analog signal

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define FIREBASE_HOST "YOUR_PROJECT_ID.firebaseio.com"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH" // secret (40 chars)
#define MEASURES "measures" // Firebase Realtime Database node to store measures

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Let's connect to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Let's measure analog value and print it
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  // Let's push it in firebase Realtime Database
  Firebase.pushInt(MEASURES, sensorValue);
  if (Firebase.failed()) {
      Serial.print("pushing failed:");
      Serial.println(Firebase.error());  
      return;
  }

   delay(30000); // 30 second delay  
}
