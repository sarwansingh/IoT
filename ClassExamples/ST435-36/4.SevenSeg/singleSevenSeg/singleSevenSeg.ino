              //a , b  , c,  d,  e,   f,   g,  dot
int pins[] = { 11 , 10 , 8 , 7  ,6  , 12 ,13,  9 } ; 
int zero[] = { 1 ,  1 ,  1 , 1  ,1  , 1   ,0,  0 } ;
int one[]  = { 0,   1 ,  1 , 0  ,0  , 0   ,0,  0 } ;  
int two[]  = { 1 ,  1 ,  0 , 1  ,1  , 0   ,1,  0 } ;  
int three[]= { 1 ,  1 ,  1 , 1  , 0 , 0   ,1,  0 } ;    
int four[] = { 0 ,  1 ,  1 , 0  ,0  , 1   ,1,  0 } ;  
int five[] = { 1 ,  0 ,  1 , 1  , 0 , 1   ,1,  0 } ; 

int digits[][8] = {
       { 1 ,  1 ,  1 , 1  ,1  , 1   ,0,  0 } ,   
       { 0,   1 ,  1 , 0  ,0  , 0   ,0,  0 } , 
       { 1 ,  1 ,  0 , 1  ,1  , 0   ,1,  0 } ,
       { 1 ,  1 ,  1 , 1  , 0 , 0   ,1,  0 } ,
       { 0 ,  1 ,  1 , 0  ,0  , 1   ,1,  0 },
        { 1 ,  0 ,  1 , 1  , 0 , 1   ,1,  0 }           
};

void setup() {
  for (int i=0 ; i<7 ; i++)   pinMode(pins[i] ,OUTPUT);
  // set pin modes
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
//  pinMode(pins[0] ,OUTPUT);pinMode(pins[1] ,OUTPUT);
//  pinMode(pins[2] ,OUTPUT);
//  pinMode(pins[3] ,OUTPUT);pinMode(pins[4] ,OUTPUT);
//  pinMode(pins[5] ,OUTPUT);pinMode(pins[6] ,OUTPUT);
}

void loop() {  // version 2
  digitalWrite(5,HIGH);  digitalWrite(3,HIGH);
  for (int row =0 ; row <6 ; row++){
    // make all LEDs low 
    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], digits[row][i]); 
    delay(1000);
  }
     
}
/// version 2
//// make all LEDs low 
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], digits[0][i]); 
//    delay(1000);
//    // make all LEDs low 
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], digits[1][i]); 
//    delay(1000);
//    
/////version 1
// digitalWrite(5,HIGH);  digitalWrite(3,HIGH);
//    // make all LEDs low 
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    // for making 1 
//    digitalWrite(pins[1], HIGH);  digitalWrite(pins[2], HIGH);
//    delay(1000);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    // for making 1 
////    digitalWrite(pins[0], HIGH);digitalWrite(pins[1], HIGH);digitalWrite(pins[3], HIGH);
////    digitalWrite(pins[6], HIGH);digitalWrite(pins[4], HIGH);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], two[i]);
//    delay(1000);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], three[i]);
//    delay(1000);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], LOW);
//    for (int i=0 ; i<7 ; i++)     digitalWrite(pins[i], four[i]);
//    delay(1000);
