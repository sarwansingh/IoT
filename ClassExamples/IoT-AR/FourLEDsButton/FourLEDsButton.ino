int LEDs[ ] = {10,6,9,11} ; 
int button1=7, button2=8;
int LEDcount =sizeof(LEDs)/sizeof(int) ; 
void setup()
{ pinMode(button1, INPUT);  pinMode(button2, INPUT);
  for (int i=0; i<LEDcount ; i++)
    pinMode(LEDs[i], OUTPUT);
}
int count=0 ;
void loop()
{
  if (digitalRead(button1) == HIGH )
  { if (count<4)count++; 
    while(digitalRead(button1) == HIGH );
  }
  if (digitalRead(button2) == HIGH )
  { if (count>0)count--; 
    while(digitalRead(button2) == HIGH );
  }
  if(count==0) digitalWrite(LEDs[0], LOW);
  if (count==1){
    digitalWrite(LEDs[0], HIGH);
    digitalWrite(LEDs[1], LOW);
  }
  if (count==2){
    digitalWrite(LEDs[1], HIGH);
    digitalWrite(LEDs[2], LOW);
  }
  if (count==3){
    digitalWrite(LEDs[2], HIGH);
    digitalWrite(LEDs[3], LOW);
  }
   
  if (count==4)digitalWrite(LEDs[4], HIGH);
   
   
}
