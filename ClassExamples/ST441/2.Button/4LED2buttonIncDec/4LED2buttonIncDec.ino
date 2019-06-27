int LED[]= { 10,6,9,11}  ;
int button1=7, button2=8 ;
void setup() {
  for (int i=0; i<4 ; i++)
    pinMode ( LED[i], OUTPUT);
   pinMode(button1, INPUT); pinMode(button2, INPUT); 
}
int cnt=0; 
void loop() {
  if (digitalRead(button1) ==HIGH){
    if (cnt<4) cnt++;
    while(digitalRead(button1) == HIGH);
  }
  if (digitalRead(button2) ==HIGH){
    if (cnt>0) cnt--;
    while(digitalRead(button2) == HIGH);
  }
  for (int i=0; i<4 ; i++)
  {  digitalWrite(LED[i], LOW); }  
  for (int i=0; i<cnt ; i++)
  {  digitalWrite(LED[i], HIGH); }  

}
