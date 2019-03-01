int R1=2,R2=3,R3=4,R4=5;
int C1=6,C2=7,C3=8 ;
int valc1, valc2, valc3;

char keys1[4][3] = { { '1' , '2', '3' },
            { '4' , '5', '6' },
            { '7' , '8', '9' },
            { '*' , '0', '#' }
      };
 char keys[4][3] = { { '7' , '8', '9' },
            { '4' , '5', '6' },
            { '1' , '2', '3' },
            { '*' , '0', '#' }
      };
#include "mykey.h"
void setup() {
  pinMode(R1,OUTPUT) ; pinMode(R2,OUTPUT) ; 
  pinMode(R3,OUTPUT) ; pinMode(R4,OUTPUT) ; 
  pinMode(C1,INPUT) ; pinMode(C2,INPUT) ; 
  pinMode(C3,INPUT) ;
  Serial.begin(9600);
  Serial.println("Welcome to Keypad");
//  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
//  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
}
void loop() {
  getKeyPress();
}
