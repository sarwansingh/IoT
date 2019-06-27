int a=11,b=10,c=9,d=8,e=7,f=6,g=5;
void setup() {
  pinMode(a, OUTPUT);pinMode(b, OUTPUT);pinMode(c, OUTPUT);pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);pinMode(f, OUTPUT);pinMode(g, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 // print 1
  digitalWrite(b,LOW);digitalWrite(c,LOW);
  digitalWrite(a,HIGH);digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);                       // wait for a second
  // print 2
  digitalWrite(b,LOW);digitalWrite(c,HIGH);
  digitalWrite(a,LOW);digitalWrite(d,LOW);
  digitalWrite(e,LOW);digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  delay(1000);                       // wait for a second
}
