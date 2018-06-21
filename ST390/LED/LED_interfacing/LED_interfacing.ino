// Program will blink the LED  
int  led1  =13, led2=12,led3=10;

void setup() {
  Serial.begin(9600);
    pinMode(led1 , OUTPUT) ;// set the 13 no pin in output mode 
     pinMode(led2 , OUTPUT) ; pinMode(led3 , OUTPUT) ;
}

void loop() {
  int i; 
  for (i=1 ; i<10;i++) 
  {
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(100*i);
    digitalWrite(led1, LOW);  
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(100*i);
  }
  

//    digitalWrite(led1, HIGH);  
//    digitalWrite(led2, LOW);
//    digitalWrite(led3, LOW);
//    delay(1000);  
//    digitalWrite(led1, LOW);  
//    digitalWrite(led2,HIGH );
//    digitalWrite(led3, LOW);
//    delay(1000);  
//    digitalWrite(led1, LOW);  
//    digitalWrite(led2, LOW);
//    digitalWrite(led3, HIGH);
//    delay(1000); 
}
