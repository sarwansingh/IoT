#include <dht.h>
#include<LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Ultrasonic sensor integration
#define trigPin  13
#define echoPin 12
long duration;
int distance_cm, distance_inch;

// DHT11 sensor integration
#define outPin 1  // Defines pin number to which the sensor is connected
dht DHT;      // Creates a DHT object

void setup() {
  lcd.begin(16, 2);
  lcd.print("Ultrasonic DHT11" );
  lcd.setCursor(0, 1);
  lcd.print("Sensor Int." );
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(2000);
}
void calDistance() {
  //clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //trigPin HIGH for 10 u sec
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //reads echoPin
}
void loop() {
  lcd.clear();
  calDistance();
  distance_cm   = duration * 0.034 / 2; //calculate distance
  //distance_inch = duration*0.0133/2;
  lcd.setCursor(0, 0);
  lcd.print("Dis : ");
  lcd.print(distance_cm);
  lcd.print(" cm");
  delay(20);

  int readData = DHT.read11(outPin);
  float t = DHT.temperature;  // Read temperature
  float h = DHT.humidity;
  lcd.setCursor(0, 1);
  lcd.print("T:" );
  lcd.print(t);
  lcd.print("  H:" );
  lcd.print(h);

  delay(1000);
}
