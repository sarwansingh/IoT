#include<LiquidCrystal.h>
// A0=14 to A5=19
int rs=19 , e=18, d4=17,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=2,r2=3,r3=4 ;
int c1=6,c2=7,c3=9  ;

void setup()
{ lcd.begin(16,2); lcd.print("LCD Keypad example" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   
  pinMode(c1,INPUT);  pinMode(c2,INPUT);  pinMode(c3,INPUT);  
  Serial.begin(9600);
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);   
  lcd.setCursor(0,1);
}
int col=0,row=1;
void loop(){
  
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ 
      lcd.setCursor ( col,row) ;  lcd.print("1"); delay(300); 
      col++;
      if(digitalRead(c1)==LOW){
        lcd.setCursor ( --col,row) ;
        lcd.print("a");  delay(300); col++;
      }
      if(digitalRead(c1)==LOW){
        lcd.setCursor ( --col,row) ;
        lcd.print("b"); delay(300); col++;
      }
      if(digitalRead(c1)==LOW){
        lcd.setCursor ( --col,row) ;
        lcd.print("c");  delay(300); col++;
      }
  }
  if(digitalRead(c2)==LOW){ lcd.setCursor ( col,row) ; lcd.print("2");delay(300); col++;  }
  if(digitalRead(c3)==LOW){ lcd.print("3"); Serial.print("3");delay(300);  }
  
//make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4");Serial.print("4"); delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("5");Serial.print("5"); delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("6"); Serial.print("6");delay(300);  }

//make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); 
  if(digitalRead(c1)==LOW){ lcd.print("7"); Serial.print("7");delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("8"); Serial.print("8");delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.clear();lcd.print("9"); Serial.print("9");delay(300);  }

}

