// initalize variables   
const int led1 =  10;  
const int led2 =  6;
const int led3 =  9; 
const int led4 =  11; 

void setup() 
{ 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() 
{
  for (int cnt=0 ; cnt <5 ; cnt++){
    digitalWrite(led1, HIGH); delay(1000);
    digitalWrite(led1, LOW); delay(1000);
  }
  for (int cnt=0 ; cnt <5 ; cnt++){
    digitalWrite(led2, HIGH); delay(1000);
    digitalWrite(led2, LOW); delay(1000);
  }
  for (int cnt=0 ; cnt <5 ; cnt++){
    digitalWrite(led3, HIGH); delay(1000);
    digitalWrite(led3, LOW); delay(1000);
  }
  for (int cnt=0 ; cnt <5 ; cnt++){
    digitalWrite(led4, HIGH); delay(1000);
    digitalWrite(led4, LOW); delay(1000);
  }
}
