#include<LiquidCrystal.h>
#include<EEPROM.h>
int rs=5 , e=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=13, r2=12, r3=11, r4=10 ;
int c1=9, c2=8, c3=7 ,c4=6 ;
int pwdInEEPROM =-1;
void setup()
{ 
  lcd.begin(16,2); 
  lcd.print("Welcome to " ) ;
  lcd.setCursor ( 0,1);  lcd.print("Security System " ) ;
  delay(1000);
  lcd.clear();
  lcd.print("Enter password" ) ;
  lcd.setCursor ( 0,1);  
  
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
  lcd.setCursor(0,1);
  pwdInEEPROM = EEPROM.read(2);
  lcd.print(pwdInEEPROM);
}
 int n=0;
void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ n=n*10 +1;lcd.print("1"); delay(300);   }
  if(digitalRead(c2)==LOW){ n=n*10 +2;lcd.print("2"); delay(300);   }
  if(digitalRead(c3)==LOW){ n=n*10 +3;lcd.print("3"); delay(300);  }
  if(digitalRead(c4)==LOW){ n=n*10 + 4;lcd.print("4"); delay(300);  }
  
//make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ n=5;lcd.print("5");  delay(300);  }
  if(digitalRead(c2)==LOW){ n=6;lcd.print("6");  delay(300);  }
  if(digitalRead(c3)==LOW){ n=7;lcd.print("7");  delay(300);  }
  if(digitalRead(c4)==LOW){ n=8; lcd.print("8");  delay(300);  }

//make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){  lcd.clear();
      lcd.print("Enter password" ) ;
      lcd.setCursor ( 0,1);  n=0;
  }
  if(digitalRead(c2)==LOW){ n=9; lcd.print("9"); delay(300);  }
  if(digitalRead(c3)==LOW){ n=0; lcd.print("0"); delay(300);  }
  if(digitalRead(c4)==LOW){ //enter 
      // check user has entered 9  in n 
      pwdInEEPROM = EEPROM.read(2);
      if (n == pwdInEEPROM) {
        lcd.print("OK");delay(300);
      }else{
        lcd.print("No");delay(300);
      }
      
   }

   //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ 
    EEPROM.write(2,n);
    lcd.print("PWD saved");  delay(300);
  }
  if(digitalRead(c2)==LOW){ lcd.print("D"); delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("E"); delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("F"); delay(300);  }
}
