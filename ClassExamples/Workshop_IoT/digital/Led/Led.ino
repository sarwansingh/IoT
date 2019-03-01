// ex. 3 - three LED pattern
int LED[]={10,11,12,13};
void setup() {
  for (int i=0;i<4; i++){
    pinMode(LED[i], OUTPUT);
  }
  //pinMode(LED[0], OUTPUT);pinMode(LED[1], OUTPUT);  pinMode(LED[2], OUTPUT);
}
int upLED=0;
void loop() {
  for(int i=0 ;i<4;i++) {
      digitalWrite(LED[i], LOW);
  }
  digitalWrite(LED[upLED], HIGH);
  delay(500);
  upLED++;
  if (upLED >3) upLED=-1;
//  for(int i=0 ;i<4;i++) {
//      digitalWrite(LED[i], LOW);
//  }
//  delay(1000);
//  
//  digitalWrite(LED[0], LOW); digitalWrite(LED[1], LOW); digitalWrite(LED[2], LOW); digitalWrite(LED[3], LOW); delay(1000); 
//  digitalWrite(LED[0], LOW); digitalWrite(LED[1], LOW); digitalWrite(LED[2], LOW); digitalWrite(LED[3], HIGH); delay(1000);
//  digitalWrite(LED[0], LOW); digitalWrite(LED[1], LOW); digitalWrite(LED[2], HIGH); digitalWrite(LED[3], LOW); delay(1000);
//  digitalWrite(LED[0], LOW); digitalWrite(LED[1], HIGH); digitalWrite(LED[2], LOW); digitalWrite(LED[3], LOW); delay(1000);
//  digitalWrite(LED[0], HIGH); digitalWrite(LED[1], LOW); digitalWrite(LED[2], LOW); digitalWrite(LED[3], LOW); delay(1000);
}
//// ex. 2 - three LED pattern
//void setup() {
//  pinMode(11, OUTPUT);pinMode(12, OUTPUT);  pinMode(13, OUTPUT);
//}
//
//void loop() {
//  digitalWrite(11, LOW); digitalWrite(12, LOW);  digitalWrite(13, LOW); delay(1000); 
//  digitalWrite(11, LOW); digitalWrite(12, LOW);  digitalWrite(13, HIGH); delay(1000);
//  digitalWrite(11, LOW); digitalWrite(12, HIGH);  digitalWrite(13, LOW); delay(1000);
//  digitalWrite(11, HIGH); digitalWrite(12, LOW);  digitalWrite(13, LOW); delay(1000);
//}

//Example 1 
//void setup() {
//  pinMode(12, OUTPUT);
//  pinMode(13, OUTPUT);
//}
//
//void loop() {
//  digitalWrite(12, HIGH); 
//  digitalWrite(13, LOW); delay(1000); 
//  digitalWrite(12, LOW);  
//  digitalWrite(13, HIGH);delay(1000); 
//}
