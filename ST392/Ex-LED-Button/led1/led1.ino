const int LEDarr[] = {8,10,12,13 };
void setup() {
  for(int i=0;i<4 ; i++) {
    pinMode(LEDarr[i], OUTPUT);
  }
  pinMode(2,INPUT);
}
int count =0;
void loop() {
  // check button is pressed
  if (digitalRead(2) == HIGH){
    count++;    
    if (count>3) count=0;
    while(digitalRead(2) == HIGH) ;
  }
  if (count==1)pattern1();
  if (count==2)pattern2();
  if (count==3)pattern3();
}
void pattern3()
{
  for (int i=1;i<=4 ; i++){
    for( int j=1;j<=i ; j++) {
           digitalWrite(LEDarr[j-1], HIGH);
    }
    delay(500);
  }
  for (int i=1;i<=4 ; i++){
           digitalWrite(LEDarr[i-1], LOW);
  }
  delay(500);
}

void pattern1(){
  for(int i=0;i<4 ; i++)    digitalWrite(LEDarr[i], HIGH);delay(500);
  for(int i=0;i<4 ; i++)    digitalWrite(LEDarr[i], LOW);delay(500);
}
void pattern2(){
  for(int i=0;i<4 ; i++)   
  { for (int j=0;j<4;j++ ) {
        digitalWrite(LEDarr[i], HIGH);delay(100);
        digitalWrite(LEDarr[i], LOW);delay(100);
    }
    
  }
  
}

