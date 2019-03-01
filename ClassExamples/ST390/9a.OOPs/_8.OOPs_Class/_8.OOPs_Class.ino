#include "flasher.h"
Flasher f2(13), f1(12,1000,500),f3(11,100,500) ;
void setup() {
   
}

void loop() {
  f1.update(); 
  f3.update(); 
  f2.update(); 
}
/*  constructor 
     *  1. always public
     *  2. name same as class name 
     *  3. no return type 
     *  4. automatically called (no explicit calling)
     *  5. can be overloaded.
     */ 
