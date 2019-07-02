#include <LiquidCrystal.h>
int button1=7, button2=8 ; 
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
int i=10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char letter[][10] = {"", "one", "two","three", "four" };
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("IncDec");
  pinMode(button1, INPUT);
  pinMode(button2, INPUT); 
}
int cnt=0;
void loop() {
   if (digitalRead(button1) == HIGH){
      lcd.clear(); lcd.setCursor(0,1);//col,row
      cnt++;
      
      if ((cnt>20) && (cnt<30)){
        lcd.print("twenty ");lcd.print(letter[cnt%10] );
      }else {
        lcd.print(cnt); 
      }
      while(digitalRead(button1) == HIGH);
   }
   if (digitalRead(button2) == HIGH){
      lcd.clear(); lcd.setCursor(0,1);//col,row
       cnt--;lcd.print(letter[cnt] );
      while(digitalRead(button2) == HIGH);
   }
}
