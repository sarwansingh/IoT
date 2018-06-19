#include<LiquidCrystal.h>
// A0=14 to A5=19
int rs=19 , e=18, d4=17,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=2,r2=3,r3=4 ;
int c1=6,c2=7,c3=9  ;

void setup()
{ lcd.begin(16,2); lcd.print("LCD Keypad example" ) ;
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   
  pinMode(c1,INPUT);  pinMode(c2,INPUT);  pinMode(c3,INPUT);  
  Serial.begin(9600);
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);   
  lcd.setCursor(0,1);
}

void loop(){
  
  //Check for ROW1
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("1"); delay(200);  }
  if(digitalRead(c2)==LOW){ lcd.print("2"); delay(200);  }
  if(digitalRead(c3)==LOW){ lcd.print("3"); delay(200);  }

 digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4"); delay(200);  }
  if(digitalRead(c2)==LOW){ lcd.print("5"); delay(200);  }
  if(digitalRead(c3)==LOW){ lcd.print("6"); delay(200);  }

 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); 
  if(digitalRead(c1)==LOW){ lcd.print("7"); delay(200);  }
  if(digitalRead(c2)==LOW){ lcd.print("8"); delay(200);  }
  if(digitalRead(c3)==LOW){ lcd.print("9"); delay(200);  }

}

