/*once the button is pressed and released  speed of blinking leds vary * 
 */void setup() {
  pinMode(13 , OUTPUT) ; 
  pinMode(2, INPUT) ; 
  digitalWrite(13 , LOW);  
}
int btnState =0 ;
void loop() {
  if(digitalRead(2)==HIGH){
    // read the button if HIGH toogle the value in btnState
    btnState++;
    if(btnState >2) btnState  = 0;
    while(digitalRead(2)==HIGH);// wait here
  }
  if (btnState ==0){
    digitalWrite(13  , LOW);     
  }
  if (btnState ==1){
    digitalWrite(13  , HIGH);  delay(500);
    digitalWrite(13 , LOW);  delay(500);
  }
  if (btnState ==2){
    digitalWrite(13  , HIGH);  delay(1500);
    digitalWrite(13 , LOW);  delay(1500);
  }
  if (btnState ==3){
    digitalWrite(13  , HIGH);  delay(2500);
    digitalWrite(13 , LOW);  delay(2500);
  }
}
