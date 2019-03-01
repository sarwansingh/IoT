int LEDpin1=13,LEDpin2=12,LEDpin3=11,LEDpin4=10, buttonPIN = 2;
void setup() {
    pinMode(LEDpin1, OUTPUT);
    pinMode(LEDpin2, OUTPUT);
    pinMode(LEDpin3, OUTPUT);
    pinMode(LEDpin4, OUTPUT);
    pinMode(buttonPIN, INPUT);
}
int count=0;
void loop() {
  if (digitalRead(buttonPIN) == HIGH){
      count++;
      if (count>2) count=0;
      while(digitalRead(buttonPIN) == HIGH);
  }
  if (count==0){
    digitalWrite(LEDpin1, LOW); digitalWrite(LEDpin2, LOW); 
    digitalWrite(LEDpin3, LOW);  digitalWrite(LEDpin4, LOW);  
  }
  if (count==1){
    digitalWrite(LEDpin1, HIGH);  
    digitalWrite(LEDpin2, HIGH);  
    digitalWrite(LEDpin3, HIGH);  
    digitalWrite(LEDpin4, HIGH); delay(200);
    digitalWrite(LEDpin1, LOW);
    digitalWrite(LEDpin2, LOW);
    digitalWrite(LEDpin3, LOW);
    digitalWrite(LEDpin4, LOW);    delay(200);
  }
  if (count==2){ // pattern 2
    digitalWrite(LEDpin1, HIGH);  
    digitalWrite(LEDpin2, LOW);  
    digitalWrite(LEDpin3, HIGH);  
    digitalWrite(LEDpin4, LOW); delay(200);
    digitalWrite(LEDpin1, LOW);
    digitalWrite(LEDpin2, HIGH);
    digitalWrite(LEDpin3, LOW);
    digitalWrite(LEDpin4, HIGH);    delay(200);
  }
}
