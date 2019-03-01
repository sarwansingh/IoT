void setup() {
  pinMode(13 , OUTPUT) ; 
  pinMode(2, INPUT) ; 
  digitalWrite(13 , LOW);  
}

void loop() {
  if(digitalRead(2)==HIGH){
    digitalWrite(13  , HIGH);  
  }else {
    digitalWrite(13 , LOW);  
  }
}
