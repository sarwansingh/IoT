int But1=2 , But2=3  ; 
int LEDs[]={10,11,12,13}; 
void setup() {
    pinMode(But1 , INPUT);  pinMode(But2 , INPUT);
    for (int i=0 ; i<4 ; i++)  pinMode(LEDs[i], OUTPUT);
}
// But1 is pressed then leds are inc. and dec. for But2 press
int count=0 ; 
void updateLED(){
  //make all leds off
  //one by on put leds HIGH till count
  for (int i=0 ; i<4 ; i++)  digitalWrite(LEDs[i], LOW);
      for (int i=0 ; i<count ; i++)  digitalWrite(LEDs[i], HIGH);
}
void loop() {
  if( digitalRead(But1) ==HIGH){  
      if (count<4)count++;
      while( digitalRead(But1) ==HIGH) ;
      updateLED();
  }
  if( digitalRead(But2) ==HIGH)  {  
      if (count>0)count--;
      while( digitalRead(But2) ==HIGH) ;
      updateLED() ; 
  }
   
  
//  if (count<=1) digitalWrite(LEDs[0] , HIGH);
//  else digitalWrite(LEDs[0] , LOW);
//  if (count==2) digitalWrite(LEDs[1] , HIGH);
//  else digitalWrite(LEDs[1] , LOW);
//  if (count==3) digitalWrite(LEDs[2] , HIGH);
//  else digitalWrite(LEDs[2] , LOW);
//  if (count==4) digitalWrite(LEDs[3] , HIGH);
}
void pattern1(){
  for (int i=0 ; i<4 ; i++)   digitalWrite(LEDs[i], HIGH);
   delay(200);
   for (int i=0 ; i<4 ; i++)    digitalWrite(LEDs[i], LOW);   
   delay(200);
}
void pattern2(){
   for (int i=0 ; i<4 ; i++)
    {  if (i%2 ==0) digitalWrite(LEDs[i], LOW);
       else digitalWrite(LEDs[i], HIGH);
    }   delay(200);
    
     for (int i=0 ; i<4 ; i++)
    {  if (i%2 ==0) digitalWrite(LEDs[i], HIGH);
       else digitalWrite(LEDs[i], LOW);
    }   delay(200);
}
