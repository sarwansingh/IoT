#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
int i,j;
#define OLED_ADDR   0x3C    // OLED display TWI address

Adafruit_SSD1306 OLED(-1);

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);        // initialize and clear display
  OLED.clearDisplay();
  OLED.display();
  
  for(i=0;i<64;i++){      //make rectangle with single pixels
    OLED.drawPixel(0, i, WHITE);
    OLED.drawPixel(127, i, WHITE);
  }
  for(j=0;j<128;j++){
    OLED.drawPixel(j, 0, WHITE);
    OLED.drawPixel(j, 63, WHITE);
  }
  OLED.display();
}

void loop() {

}
