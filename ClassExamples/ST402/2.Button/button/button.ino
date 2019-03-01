int LEDpin=13, BUTTONpin=2 ; 
void setup() {
    pinMode(LEDpin , OUTPUT);
    pinMode(BUTTONpin , INPUT);
}
int status=0;
void loop() {
    if ( digitalRead(BUTTONpin) == HIGH) {
        if (status==0) status=1;
        else status=0;
        while(digitalRead(BUTTONpin) == HIGH) ; 
    }
    if (status==1){
      digitalWrite(LEDpin , HIGH); delay(100);
      digitalWrite(LEDpin , LOW); delay(100);  
    }
}
