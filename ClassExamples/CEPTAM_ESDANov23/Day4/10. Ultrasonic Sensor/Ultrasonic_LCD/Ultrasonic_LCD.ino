 /*
 * for LCD interfacing use myLCD.h file
 */
#include "myLCD.h"
#define trigPin  13
#define echoPin 12

long duration;
int distance_cm,distance_inch;

void setup(){
    lcd.begin(16,2);
    lcd.print("Ultrasonic Sensor" );
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    delay(2000);
}

void loop(){
    lcd.clear();
     //clear trigPin
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   //trigPin HIGH for 10 u sec
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   
   duration=pulseIn(echoPin,HIGH);//reads echoPin
   distance_cm=duration*0.034/2; //calculate distance
   distance_inch=duration*0.0133/2;
   lcd.setCursor(0,0);
   lcd.print("Distance: ");
   lcd.print(distance_cm);
   lcd.print(" cm");
   delay(20);
   lcd.setCursor(0,1);
   lcd.print("Distance: ");
   lcd.print(distance_inch);
   lcd.print(" inch");
   delay(500);
}
