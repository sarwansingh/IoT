void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the analog value of LDR at A0
  int val=analogRead(A0);
  Serial.println(val);
  // if value is below 200 switch on LED else off
  if(val<200){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
  delay(1000);
}
