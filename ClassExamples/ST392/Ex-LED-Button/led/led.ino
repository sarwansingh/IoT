/* * led connected on 13 pin
 * on/off duty cycle 500ms
 */
const int LED1pin=10, LED2pin=11,LED3pin=12, LED4pin=13 ; 
void setup() {
  for(int i=10;i<14 ; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(2,INPUT);
}
void loop() {
  if(digitalRead(2)==HIGH) pattern1();
  else  pattern2();
}
void pattern1(){
  for(int i=10;i<14 ; i++) {
    for(int j=10 ; j<14 ; j++){
      if (i==j)digitalWrite(j, HIGH);
      else  digitalWrite(j, LOW);
    }
    delay(500);
  }
}
void pattern2(){
  for(int i=10;i<14 ; i++) {
      if ((i%2)==0)digitalWrite(i, HIGH);
      else  digitalWrite(i, LOW);
    }
      delay(500);
    for(int i=10;i<14 ; i++) {
      if ((i%2)==0)digitalWrite(i, LOW);
      else  digitalWrite(i, HIGH);
    }
      delay(500);
  
}
/// version 2 for blinking odd even leds
//for(int i=10;i<14 ; i++) {
//    if ((i%2)==0)digitalWrite(i, HIGH);
//    else  digitalWrite(i, LOW);
//  }
//    delay(500);
//  for(int i=10;i<14 ; i++) {
//    if ((i%2)==0)digitalWrite(i, LOW);
//    else  digitalWrite(i, HIGH);
//  }
//    delay(500);
///////version 2 ends 
//
//const int LED1pin=10, LED2pin=11,LED3pin=12, LED4pin=13 ; 
//void setup() {
//    pinMode(LED1pin, OUTPUT);
//    pinMode(LED2pin, OUTPUT);
//    pinMode(LED3pin, OUTPUT);
//    pinMode(LED4pin, OUTPUT);
//}
//void loop() {
//    digitalWrite(LED1pin , HIGH) ; 
//    digitalWrite(LED2pin , LOW) ;
//    digitalWrite(LED3pin , HIGH) ; 
//    digitalWrite(LED4pin , LOW) ; 
//    delay(500);
//    digitalWrite(LED1pin , LOW) ;
//    digitalWrite(LED2pin , HIGH) ; 
//    digitalWrite(LED3pin , LOW) ;
//    digitalWrite(LED4pin , HIGH) ; 
//    delay(500);
//}
