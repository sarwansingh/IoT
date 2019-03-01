
/*once the button is pressed and released Led should start glowing
 * till the button is pressed and release again
 * 
 */void setup() {
  pinMode(13 , OUTPUT) ; 
  pinMode(2, INPUT) ; 
  digitalWrite(13 , LOW);  
}
int btnState =0 ;
void loop() {
  if(digitalRead(2)==HIGH){
    // read the button if HIGH toogle the value in btnState
    if(btnState ==0) btnState  =1; 
    else btnState = 0;
  }
  if (btnState ==1){
    digitalWrite(13  , HIGH);  
  }else {
    digitalWrite(13 , LOW);  
  }
}
