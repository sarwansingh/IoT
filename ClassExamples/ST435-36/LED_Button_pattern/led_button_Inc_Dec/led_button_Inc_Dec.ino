int BUT1=7 , BUT2 = 8;  
//int LED[4]= {6,9,10,11};// for proteus
int LED[4]= {10,6,9,11}; // for kit

void setup() {
  for( int cnt=0 ; cnt<4; cnt++){
    pinMode (LED[cnt], OUTPUT);  
  }
}
int count = 0; 
void loop() {
  // inc button
  if (digitalRead(BUT1) == HIGH)  {
    if (count<4) count++; 
    while(digitalRead(BUT1) == HIGH); 
  }
  //dec
   if (digitalRead(BUT2) == HIGH)  {
    if (count>0)count--; 
    while(digitalRead(BUT2) == HIGH); 
  }

   // switch on only required LEDs
   for(int i=0 ; i<count; i++) digitalWrite(LED[i],HIGH);
     // switch off rest of  LEDs
     for(int i= count ; i<4; i++) digitalWrite(LED[i],LOW);
   
}

