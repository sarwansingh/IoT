// LED should blink till button is pressed 
int LED=13, BUTTON=4; 
void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON,INPUT);
}

void loop() {
    while (digitalRead(BUTTON) ==HIGH)
    {  
      digitalWrite (LED , HIGH);delay(500); 
      digitalWrite (LED , LOW );delay(500);
    }
}
