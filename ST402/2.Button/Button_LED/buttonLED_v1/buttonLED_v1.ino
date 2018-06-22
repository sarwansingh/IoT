int  buttonPIN = 2;
int LEDs[]={10,11,12,13}; 
void setup() {
    for (int i=0 ; i<4 ; i++)
      pinMode(LEDs[i], OUTPUT);
      
      pinMode(buttonPIN, INPUT);
}
int count=0;
void loop() {
  if (digitalRead(buttonPIN) == HIGH){
      count++;
      if (count>2) count=0;
      while(digitalRead(buttonPIN) == HIGH);
  }
  if (count==0){
    for (int i=0 ; i<4 ; i++)
      digitalWrite(LEDs[i], LOW);
  }
  if (count==1){
    for (int i=0 ; i<4 ; i++)
    {  digitalWrite(LEDs[i], HIGH); } 
    delay(200);
    for (int i=0 ; i<4 ; i++)
    {  digitalWrite(LEDs[i], LOW);} 
    delay(200);
  }
  if (count==2){ // pattern 2
    pattern3();
  }
}
void pattern2(){
   for (int i=0 ; i<4 ; i++)
    {  if (i%2 ==0) digitalWrite(LEDs[i], LOW);
       else digitalWrite(LEDs[i], HIGH);
    }   delay(200);
    
     for (int i=0 ; i<4 ; i++)
    {  if (i%2 ==0) digitalWrite(LEDs[i], LOW);
       else digitalWrite(LEDs[i], LOW);
    }   delay(200);
}
void pattern3(){
  int arr[4]={0,0,0,0},n;
  for (int m=0 ;m<16; m++)
  {   n=m; int i=0;
      while(n>0){
        arr[i++]=n%2; n=n/2; 
      }
//      arr[0]=n%2; n=n/2; 
//      arr[1]=n%2; n=n/2; 
//      arr[2]=n%2; n=n/2;
       digitalWrite(LEDs[3], arr[3]);
       digitalWrite(LEDs[2], arr[2]);
       digitalWrite(LEDs[1], arr[1]);
       digitalWrite(LEDs[0], arr[0]);
       delay(400);
  }
}





