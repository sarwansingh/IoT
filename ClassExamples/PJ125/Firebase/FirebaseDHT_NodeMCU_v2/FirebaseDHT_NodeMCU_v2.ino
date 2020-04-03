// This program connects DHT sensor on pin 14 and push data to firebase
// the data from firebase can be displayed on Android app

#include <FirebaseArduino.h>
#include "DHT.h"

#include  <ESP8266WiFi.h>

// Set these to run example.
#define FIREBASE_HOST "nodemcu-nielit125.firebaseio.com"
#define FIREBASE_AUTH "2QVppV5F95FDPGTp39AlD29BUAQUlOk2tBTnopjn"
#define WIFI_SSID     "demo123"
#define WIFI_PASSWORD "12345678"

//
//#define FIREBASE_HOST "yyyyyyyyyyyy.firebaseio.com"
//#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
//#define WIFI_SSID     "ssssss"
//#define WIFI_PASSWORD "pppppp"

#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
 float h=0 ,t=-1;
void loop() {

  h = dht.readHumidity();
  t = dht.readTemperature();  // Reading temperature as Celsius (the default)
//  h++ ; t++; // testing
  Serial.print("Humidity: ");  Serial.print(h);
  Serial.print("%  Temperature: ");  Serial.print(t);  Serial.println("°C ");
  
  String name = Firebase.pushInt("measures", t);
  //String name1 = Firebase.pushInt("measures", h);
  
  Firebase.setFloat ("Temp", t);
  Firebase.setFloat ("Humidity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing failed : ");
      Serial.println(Firebase.error());  
      return;
  }else {
    Serial.print("pushed: /measures/");
    Serial.println(name);
  }
   
  delay(20000);  // 10 second wait

// for realtime implementation
// Now let's go in deep sleep for 5 minutes:
// ESP.deepSleep(300e6, WAKE_RF_DEFAULT); // 1st parameter is in µs!
}
 
