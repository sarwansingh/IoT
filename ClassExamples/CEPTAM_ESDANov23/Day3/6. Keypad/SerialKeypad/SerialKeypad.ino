int r1=13, r2=12, r3=11, r4=10 ;
int c1=9, c2=8, c3=7 ,c4=6 ;
/*
 * 0 1 2 3  
 * 4 5 6 7 
 * 8 9 A B
 * C D E F
 */

void setup()
{ Serial.begin(9600); Serial.println("Serial Keypad ex" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
}
 
void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ Serial.println("0"); delay(300);   }
  if(digitalRead(c2)==LOW){ Serial.println("1"); delay(300);   }
  if(digitalRead(c3)==LOW){ Serial.println("2"); delay(300);  }
  if(digitalRead(c4)==LOW){ Serial.println("3"); delay(300);  }
  
//make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ Serial.println("4");  delay(300);  }
  if(digitalRead(c2)==LOW){ Serial.println("5");  delay(300);  }
  if(digitalRead(c3)==LOW){ Serial.println("6");  delay(300);  }
  if(digitalRead(c4)==LOW){ Serial.println("7");  delay(300);  }

//make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ Serial.println("8"); delay(300);  }
  if(digitalRead(c2)==LOW){ Serial.println("9"); delay(300);  }
  if(digitalRead(c3)==LOW){ Serial.println("A"); delay(300);  }
  if(digitalRead(c4)==LOW){ Serial.println("B"); delay(300);  }
  
  //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ Serial.println("C"); delay(300);  }
  if(digitalRead(c2)==LOW){ Serial.println("D"); delay(300);  }
  if(digitalRead(c3)==LOW){ Serial.println("E"); delay(300);  }
  if(digitalRead(c4)==LOW){ Serial.println("F"); delay(300);  }
}
