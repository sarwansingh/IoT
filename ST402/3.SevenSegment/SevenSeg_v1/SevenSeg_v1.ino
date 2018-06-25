int a=3,b=4,c=5,d=6,e=7,f=8,g=9 ; //segment[]={3,4,5,6,7,8,9};
void setup() {
    pinMode(a, OUTPUT);pinMode(b, OUTPUT);pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);pinMode(e, OUTPUT);pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
}

void loop() {
    digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, LOW);
    digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  delay(1000); 
    digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);
    digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    delay(1000); 
}
