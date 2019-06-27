int LED[]= { 10,6,9,11}  ;
int button1=7 ;
void setup() {
  for (int i=0; i<4 ; i++)
    pinMode ( LED[i], OUTPUT);
   pinMode(button1, INPUT); 
}
int cnt=0; 
bool isOnTop=false; 
void loop() {
  if (digitalRead(button1) ==HIGH){
    if (isOnTop == false){
      if (cnt<4) cnt++;
    }
    if (cnt==4) isOnTop = true; 
    if (cnt==0) isOnTop = false; 
    if (isOnTop == true){
        if (cnt>0) cnt--;  
    }
    
    while(digitalRead(button1) == HIGH);
  }
   
  for (int i=0; i<4 ; i++)
  {  digitalWrite(LED[i], LOW); }  
  for (int i=0; i<cnt ; i++)
  {  digitalWrite(LED[i], HIGH); }  

}
