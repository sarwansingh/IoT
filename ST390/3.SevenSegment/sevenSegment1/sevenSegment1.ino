void setup() {
  Serial.begin(9600);
  // set the mode of pins as output 
  for (int i=2; i<9 ; i++){
    pinMode(i,OUTPUT);
  }
}
int zero[]={0,0,0,0,0,0,1}, one[]={1,0,0,1,1,1,1}, two[]={0,0,1,0,0,1,0};
int three[] ={0,0,0,0,1,1,0} , four[]={1,0,0,1,1,0,0} ; 

void loop() {
  zero[7]=99;
  for (int k=0 ; k<18 ; k++) 
  {  Serial.println(zero[k]); }
    Serial.println("line over" );
      for (int k=0 ; k<7 ; k++) 
  {  Serial.println(one[k]); }
    Serial.println("line over" );
      for (int k=0 ; k<7 ; k++) 
  {  Serial.println(two[k]); }
    Serial.println("line over" );
    
  // zero 
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, zero[j]);
  }
  delay(1000);
  // one 
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, one[j]);
  }
  delay(1000);
   // two 
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, two[j]);
  }
  delay(1000);
   // three 
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, three[j]);
  }
  delay(1000);
   // four 
  for (int i=2,j=0; i<9 ; i++,j++){
    digitalWrite(i, four[j]);
  }
  delay(1000);
  
}
   
//  pinMode(2,OUTPUT);
//  pinMode(3,OUTPUT);
//  pinMode(4,OUTPUT);
//  pinMode(5,OUTPUT);
//  pinMode(6,OUTPUT);
//  pinMode(7,OUTPUT);
//  pinMode(8,OUTPUT);
// zero 
//  digitalWrite ( 2, LOW); 
//  digitalWrite ( 3, LOW); 
//  digitalWrite ( 4, LOW); 
//  digitalWrite ( 5, LOW); 
//  digitalWrite ( 6, LOW); 
//  digitalWrite ( 7, LOW); 
//  digitalWrite ( 8, HIGH); 
//one 
//  digitalWrite ( 2, HIGH); 
//  digitalWrite ( 3, LOW); 
//  digitalWrite ( 4, LOW); 
//  digitalWrite ( 5, HIGH); 
//  digitalWrite ( 6, HIGH); 
//  digitalWrite ( 7, HIGH); 
///  digitalWrite ( 8, HIGH); 
