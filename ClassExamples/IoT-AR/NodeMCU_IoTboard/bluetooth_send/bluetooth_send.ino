void setup() {
    Serial.begin(9600);   //Sets the baud for serial data transmission                        
}
   
void loop() {
   Serial.println("ETI Labs"); //data to be sent
   delay(1000); //Delay of 2 seconds  
}
