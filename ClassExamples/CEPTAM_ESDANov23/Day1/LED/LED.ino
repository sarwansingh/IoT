void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{ digitalWrite(12, HIGH);
  // blinking logic 
  for (int cnt=0; cnt<5 ; cnt++){
    digitalWrite(13, HIGH);  delay(1000); 
    digitalWrite(13, LOW);  delay(1000); 
  }
   digitalWrite(12, LOW);    delay(2000); 
}
