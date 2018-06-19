#include <LiquidCrystal.h>
// A0=14 to A5=19  - 
int rs=19 , e=18, d4=17,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
char ar[]="st392 is intelligent and champ" ; 
void setup() {
  lcd.begin(16, 2);
//  for ( int i=0 ; i<26 ; i++)
    lcd.print("hello world" );
    
}
int start=0;
void loop() {
  lcd.setCursor(0, 1);
  for (int i=start; i<(16+start); i++ ) 
  {    lcd.print(ar[i]);
  }
    delay(500);
  start++; // check this variable 
  
}


/*
 *   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 

 */
