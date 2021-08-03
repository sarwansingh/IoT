#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C  // OLED display TWI address
Adafruit_SSD1306 OLED(-1);
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // initialize and clear display
  OLED.clearDisplay();
  OLED.display();
  
  OLED.setTextSize(2);     //set text size
  OLED.setTextColor(WHITE);    //set text color
  OLED.setCursor(10,10);     //set start coordinates for printing
  OLED.print("NIELIT Chandigarh");      //display text
  OLED.display();
}

void loop() {

}
