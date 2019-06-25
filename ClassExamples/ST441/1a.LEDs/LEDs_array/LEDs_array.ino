int LED[]= {10,6,9,11 } ;
void setup() {
  for (int i=0;i<4 ; i++) {
    pinMode(LED[i],OUTPUT);
  }
//  pinMode(10,OUTPUT);
//  pinMode(6,OUTPUT);
//  pinMode(9,OUTPUT);
//  pinMode(11,OUTPUT);
}

void loop() {
    pat2();
 
}
void pat4(){
// pattern 4 print binary number system
  for(int i=0  ; i<16 ; i++){
    if ((i&1) ==0) digitalWrite(LED[3] , LOW);
    else  digitalWrite(LED[3] , HIGH);
    
    if ((i&2) ==0) digitalWrite(LED[2] , LOW);
    else  digitalWrite(LED[2] , HIGH);
    
    if ((i&4) ==0) digitalWrite(LED[1] , LOW);
    else  digitalWrite(LED[1] , HIGH);
    
    if ((i&8) ==0) digitalWrite(LED[0] , LOW);
    else  digitalWrite(LED[0] , HIGH);
    
    delay(1000);
  }
}
void pat1(){
  // pattern1 
  for (int i=0;i<4 ; i++) {
      digitalWrite(LED[i] , HIGH); 
      digitalWrite(LED[i-1] , LOW); 
      delay(1000);
    }
    digitalWrite(LED[3] , LOW); 
 
}
void pat2(){
//   pattern 2
  for (int i=3; i>=0 ; i--) {
      digitalWrite(LED[i] , HIGH); 
      digitalWrite(LED[1+i] , LOW); 
      delay(1000);
    }
    digitalWrite(LED[0] , LOW); 
}
void pat3()
{
  //pattern 3
  for (int i=3; i>=0 ; i--) {
    digitalWrite(LED[i] , HIGH); 
    digitalWrite(LED[2+i] , LOW); 
    delay(1000);
  }
  digitalWrite(LED[1] , LOW); delay(1000);
  digitalWrite(LED[0] , LOW);
}
