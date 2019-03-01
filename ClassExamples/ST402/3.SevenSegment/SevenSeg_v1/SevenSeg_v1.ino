int a=3,b=4,c=5,d=6,e=7,f=8,g=9 ; 
int segment[]={3,4,5,6,7,8,9};
int zero[] = {0,0,0,0,0,0,1};
int one[] ={1,0,0,1,1,1,1} ;
int two[] ={0,0,1,0,0,1,0} ; 
int three[] = {0,0,0,0,1,1,0} ;
int four[] = {1,0,0,1,1,0,0} ;
void setup() {
    for (int i=0 ; i<7;i++) pinMode(segment[i], OUTPUT);
}

void loop() {
    for (int i=0 ; i<7;i++) digitalWrite(segment[i], zero[i]);
    delay(1000); 
      for (int i=0 ; i<7;i++) digitalWrite(segment[i], one[i]);
      delay(1000); 
    for (int i=0 ; i<7;i++) digitalWrite(segment[i], two[i]);
    delay(1000); 
    for (int i=0 ; i<7;i++) digitalWrite(segment[i], three[i]);
    delay(1000); 
    for (int i=0 ; i<7;i++) digitalWrite(segment[i], four[i]);
    delay(1000); 
   
}
/*
 * pinMode(a, OUTPUT);pinMode(b, OUTPUT);pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);pinMode(e, OUTPUT);pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
 * 
 *  for (int i=0 ; i<7;i++) digitalWrite(segment[i], zero[i]);
//   digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);
//    digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);
//    digitalWrite(g, HIGH);
    delay(1000); 
      for (int i=0 ; i<7;i++) digitalWrite(segment[i], one[i]);
//    digitalWrite(a, HIGH);digitalWrite(b, LOW);digitalWrite(c, LOW);
//    digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);
//    digitalWrite(g, HIGH);
  delay(1000); 
   digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, HIGH);
    digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
   delay(1000); 
 */
