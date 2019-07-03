#include<LiquidCrystal.h>

int rs=5 , e=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=13, r2=12, r3=11, r4=10 ;
int c1=9, c2=8, c3=7 ,c4=6 ;
int buzz=4; 
/*
 * 0 1 2 3  
 * 4 5 6 7 
 * 8 9 + -
 * C D E =
 */

void setup()
{ 
  lcd.begin(16,2); lcd.print("Security System" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
  delay(2000);
  lcd.clear();
  lcd.print("Enter password " ) ; 
  lcd.setCursor(0,1);
  pinMode(buzz, OUTPUT);
}
 int n=0,n1=0,sum=0; char opr=' '; int pass=342; int cntWrong=0 ;
void beep(int time){
    digitalWrite(buzz, HIGH); delay(time); digitalWrite(buzz, LOW);delay(time);
}
void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("*"); n=n*10+0; beep(100);   delay(100);   }
  if(digitalRead(c2)==LOW){ lcd.print("*"); n=n*10+1; beep(100); delay(100);   }
  if(digitalRead(c3)==LOW){ lcd.print("*"); n=n*10+2;beep(100); delay(100);  }
  if(digitalRead(c4)==LOW){ lcd.print("*"); n=n*10+3 ;beep(100); delay(100);  }
  
//make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4"); n=n*10+4; beep(100); delay(100);  }
  if(digitalRead(c2)==LOW){ lcd.print("5"); n=n*10+5; beep(100); delay(100);  }
  if(digitalRead(c3)==LOW){ lcd.print("6"); n=n*10+6; beep(100); delay(100);  }
  if(digitalRead(c4)==LOW){ lcd.print("7"); n=n*10+7; beep(100); delay(100);  }

//make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("8"); beep(100); delay(100);  }
  if(digitalRead(c2)==LOW){ lcd.print("9"); beep(100); delay(100);  }
  if(digitalRead(c3)==LOW){ lcd.print("+");  beep(100); delay(100);  }
  if(digitalRead(c4)==LOW){ lcd.print("-");   beep(100); delay(100);  }
  
  //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ lcd.clear(); n=0;beep(100); delay(100); 
    lcd.print("Enter password " ) ; 
    lcd.setCursor(0,1);
  }
  if(digitalRead(c2)==LOW){ lcd.print("D"); beep(100); delay(100);  }
  if(digitalRead(c3)==LOW){ lcd.print("E"); beep(100); delay(100);  }
  if(digitalRead(c4)==LOW){   beep(100); delay(100); 
    if ( n== pass ) {
      
      lcd.print ("Pass ok");
    }else {
      cntWrong++; 
      lcd.print("pass incorrect" ) ;
      if (cntWrong >3){
        lcd.clear();
        lcd.print("System Locked" ) ;
        while(1){
          beep(50);
        }
      }
    }
 
  }
}
