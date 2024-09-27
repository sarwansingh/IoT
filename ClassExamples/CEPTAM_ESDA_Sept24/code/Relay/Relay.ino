int led1=13;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
 for (int i=0; i<5; i++){
  digitalWrite(led1, HIGH); delay(1000);
  digitalWrite(led1, LOW); delay(1000);
 }
}

void loop() {
 digitalWrite(led1, HIGH); delay(1000);
  digitalWrite(led1, LOW); delay(1000);
}
