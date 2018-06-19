int r1=2,r2=3,r3=4 ;
int c1=6,c2=7,c3=9  ;

void setup()
{
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   
  pinMode(c1,INPUT);  pinMode(c2,INPUT);  pinMode(c3,INPUT);  
  Serial.begin(9600);
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);   
}

void loop(){
  //Check for ROW1
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ Serial.println("1"); delay(200);  }
  if(digitalRead(c2)==LOW){ Serial.println("2"); delay(200);  }
  if(digitalRead(c3)==LOW){ Serial.println("3"); delay(200);  }

 digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); 
  if(digitalRead(c1)==LOW){ Serial.println("4"); delay(200);  }
  if(digitalRead(c2)==LOW){ Serial.println("5"); delay(200);  }
  if(digitalRead(c3)==LOW){ Serial.println("6"); delay(200);  }

 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); 
  if(digitalRead(c1)==LOW){ Serial.println("7"); delay(200);  }
  if(digitalRead(c2)==LOW){ Serial.println("8"); delay(200);  }
  if(digitalRead(c3)==LOW){ Serial.println("9"); delay(200);  }

}

