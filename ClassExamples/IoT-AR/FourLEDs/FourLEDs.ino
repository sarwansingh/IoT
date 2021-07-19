int LEDs[ ] = {10,6,9,11} ; 
int LEDcount =sizeof(LEDs)/sizeof(int) ; 
void setup()
{
  for (int i=0; i<LEDcount ; i++)
    pinMode(LEDs[i], OUTPUT) 
}
void blink(int wled, int times){
  for (int x=0; x<times ; x++){
    digitalWrite(wled, HIGH);  delay(1000);
    digitalWrite(wled, LOW);  delay(1000);
  }
}

void loop()
{
  for (int i=0; i<LEDcount ; i++) blink(LEDs[i],i+1);
  
 /* blink(LEDs[0],1);
  blink(LEDs[1] ,2 );
  blink(LEDs[2] ,3 );
  blink(LEDs[3],4 ); */
}
