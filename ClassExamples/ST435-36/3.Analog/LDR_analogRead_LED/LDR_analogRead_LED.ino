int LDRValue=0 ; 
// switch on the led at pin 13 when analog pin returns less than 400 value 
// else led to be off
void setup() {
  Serial.begin(9600); // 9600 baudrate
  pinMode(13, OUTPUT); 
}

void loop() {
    LDRValue = analogRead(A0);
    Serial.println(LDRValue ) ;
    if (LDRValue < 400){
      digitalWrite(13, HIGH);
    }else {
      digitalWrite(13, LOW);
    }
    delay(500);
}
