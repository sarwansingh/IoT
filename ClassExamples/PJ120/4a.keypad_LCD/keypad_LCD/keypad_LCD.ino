#include <Keypad.h>
#include <LiquidCrystal.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3' },
  {'4','5','6' },
  {'7','8','9' },
  {'*','0','#' }
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 9}; //connect to the column pinouts of the keypad
LiquidCrystal lcd(19,18,17,16,15,14);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.begin(16,2);
  lcd.print("-keypad-LCD-");
  lcd.setCursor(0,1);
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    lcd.print(key);
  }
}
