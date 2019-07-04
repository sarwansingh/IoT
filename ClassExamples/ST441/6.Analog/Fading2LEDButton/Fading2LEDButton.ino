int ledPin = 9, led2= 10;    // LED connected to digital pin 9
int but1=7;

void setup() {
  pinMode(but1, INPUT);
}
int glow=0;
void loop() {
 analogWrite(ledPin , 60);
 analogWrite(led2 , glow);
 
  if (digitalRead(but1) == HIGH){
    glow+=20;
    while (digitalRead(but1) == HIGH) ;
  }
 //delay(1000); 
}
