int led1 =10, led2=9;
void setup() {
 pinMode(led1, OUTPUT);pinMode(led2, OUTPUT);
 Serial.begin(9600);
 Serial.print("LED control");
 // test led 
// for (int i=0; i<5; i++){
//  digitalWrite(led1, HIGH); delay(1000);
//  digitalWrite(led1, LOW); delay(1000);
//  digitalWrite(led2, HIGH); delay(1000);
//  digitalWrite(led2, LOW); delay(1000);
// }
}

void loop() {
  int x = Serial.read();
  if (x!=-1) { Serial.println(x);delay(100); } 
  // one to on led1
  if (x==49) digitalWrite(led1, HIGH);
  // zero to off led1 
  if (x==48) digitalWrite(led1, LOW);

   // 2 to on led2
  if (x==50) digitalWrite(led2, HIGH);
  // 3 to off led2 
  if (x==51) digitalWrite(led2, LOW);
//  delay(1000);
}
