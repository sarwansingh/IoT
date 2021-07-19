#define ledPin 10
#define relayPin 12
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  pinMode(relayPin, OUTPUT);
  digitalWrite(ledPin, LOW);digitalWrite(relayPin, LOW);
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }

 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  digitalWrite(relayPin, LOW);
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  digitalWrite(relayPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 } 
}
