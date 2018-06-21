#include<LiquidCrystal.h>
int rs=7 , e=6, d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 

void setup() {
  lcd.begin(16,2);
  lcd.print("hello st390");
}
char arr[]="I am Indian. we love India";
void loop() { 
  for (int k=0;k<sizeof(arr);k++){
    lcd.setCursor(0,1);
    for (int i=k;i<k+16; i++)
      lcd.print(arr[i]);
    delay(200);
  }
    
  
}

//  version 1
//  lcd.setCursor(0,1);
//  for (int i=0;i<16; i++)
//    lcd.print(arr[i]);
//  delay(1000);
//  lcd.setCursor(0,1);
//  for (int i=1;i<17; i++)
//    lcd.print(arr[i]);
//  delay(1000);
//  lcd.setCursor(0,1);
//  for (int i=2;i<18; i++)
//    lcd.print(arr[i]);
//  delay(1000);
