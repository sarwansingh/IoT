// ex. 2 binary no display thru 4 LEDs
int LED[] = {10, 11, 12, 13};
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT);
  }
}
int no , a;
void loop() {
  for (int i = 0 ; i < 4; i++) {
    digitalWrite(LED[i], LOW);
  }
  for (int z = 3; z < 16 ; z++) {
    int x = 0;
    no = z;
    while (no > 0) {
      a = no % 2;
      no = no / 2;
      if (a == 0) digitalWrite(LED[x], LOW);
      else digitalWrite(LED[x], HIGH);
      x++ ;
    }
    delay(1000);
  }

}

//ex 1
//// ex. 3 - three LED pattern
//int LED[] = {10, 11, 12, 13};
//void setup() {
//  for (int i = 0; i < 4; i++) {
//    pinMode(LED[i], OUTPUT);
//  }
//}
//int upLED = 0;
//void loop() {
//  for (int i = 0 ; i < 4; i++) {
//    digitalWrite(LED[i], LOW);
//  }
//  digitalWrite(LED[upLED], HIGH);
//  delay(500);
//  upLED++;
//  if (upLED > 3) {
//    upLED = -1;
////    int cnt = 0;
////    while (cnt < 4) {
//    for(int cnt=0; cnt <2 ; cnt++){
//      for (int i = 0 ; i < 4; i++) {
//        digitalWrite(LED[i], LOW);
//      }
//      delay(500);
//      for (int i = 0 ; i < 4; i++) {
//        digitalWrite(LED[i], HIGH);
//      }delay(500);
////      cnt++;
//    }
//  }
//}
