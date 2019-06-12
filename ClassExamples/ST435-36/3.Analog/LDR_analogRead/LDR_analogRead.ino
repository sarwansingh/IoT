int LDRValue=0 ; 
void setup() {
  Serial.begin(9600); // 9600 baudrate
}

void loop() {
    LDRValue = analogRead(A0);
    Serial.println(LDRValue ) ;
    delay(500);
}
