int LED=13, BUTTON=4; 
void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON,INPUT);
}
int status,c=0; 
void loop() {
    status = digitalRead(BUTTON); 
    if (status  == HIGH){
      if (c==0)c=1;
      else c=0;
      while (digitalRead(BUTTON) ==HIGH); 
    }
    if (c==1)
    { digitalWrite (LED , LOW );delay(500);
      digitalWrite (LED , HIGH);delay(500); 
    }else {
   
    }
}
