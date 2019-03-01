 #include<SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
int i; 
void loop() {
  if (mySerial.available()) {
    i=mySerial.read() ; 
    Serial.println(i);
    // switch on LED if 1 is received
    if (i=='1') digitalWrite(LED_BUILTIN, HIGH);   
    // switch off LED if 2 is received
    if (i=='2') digitalWrite(LED_BUILTIN, LOW);   
    //delay(1000);
  } 
}
