int digit[10][7] = {      { 0,0,0,0,0,0,1 },    // 0
                          { 1,0,0,1,1,1,1 },    // 1
                          { 0,0,1,0,0,1,0 },    // 2
                          { 0,0,0,0,1,1,0 },    // 3
                          { 1,0,0,1,1,0,0 },    // 4
                          { 0,1,0,0,1,0,0 },    // 5
                          { 0,1,0,0,0,0,0 },    // 6
                          { 0,0,0,1,1,1,1 },    // 7
                          { 0,0,0,0,0,0,0 },    // 8
                          { 0,0,0,1,1,0,0 }};   // 9
              //a , b  , c,  d,  e,   f,   g,  dot
int pins[] = { 11 , 10 , 8 , 7  ,6  , 12 ,13,  9 } ;                           

void setup() 
{ 
  // set pin modes
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT); 
  for (int j=0; j < 7; j++) {
   pinMode(pins[j], OUTPUT ) ;
  }
}
 int number =0 ;
void loop() 
{
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);  digitalWrite(9, 1); // disable dot

 for (number =0 ; number<=9 ; number++) {
  for (int j=0; j < 7; j++) {
   digitalWrite(pins[j], digit[number][j]);
  }
  delay(2000);
 }   
}
