int digits[][7] = {
  {0,0,0,0,0,0,1}, // zero 
  {1,0,0,1,1,1,1}, //one
  {0,0,1,0,0,1,0}, //two 
  {0,0,0,0,1,1,0} // three
};
int BUTTON = 10;
void setup() {
  pinMode(BUTTON , INPUT);
  // set the mode of pins as output 
  for (int i=2; i<9 ; i++){
    pinMode(i,OUTPUT);
  }
}
void show(int dgt){
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, digits[dgt][j]);
  }
}
int bVal, count=0;
void loop() {
    bVal = digitalRead(BUTTON);
    if (bVal==HIGH){
      if (count<3)count++;
      else count=0;
      while(digitalRead(BUTTON) ==HIGH); 
    }
    show (count);
}
