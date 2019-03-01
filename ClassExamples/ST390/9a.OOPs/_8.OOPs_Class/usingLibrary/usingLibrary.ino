#include <Flasher.h>
//Flasher f1(13),f2(12),f3(11); 
//Flasher LEDs[3]={ f1,f2,f3 } ;

Flasher LEDs[ ]={   Flasher(13) ,Flasher(12) ,Flasher(11)   } ;

void setup() {
}

void loop() {
  for (int  i=0; i<3 ;i++) LEDs[i].update();
}
