#include <dht.h>
#define DHT11_PIN D7
dht DHT11;
void setup(){
  Serial.begin(9600);
}

void loop(){
   
    DHT11.read11(DHT11_PIN);    //read DHT11 data
    Serial.print("Temp: ");
    Serial.print(DHT11.temperature);  // Print the temperature
    Serial.println("*C");
    Serial.print("Relative Humidity: ");
    Serial.print(DHT11.humidity);     // Print the humidity
    Serial.println("%");
    delay(2000);
}
