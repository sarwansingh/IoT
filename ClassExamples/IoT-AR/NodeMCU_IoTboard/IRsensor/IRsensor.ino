int Buzzer = 14; // pin number of Buzzer
int sensor = 12;  // pin number of sensor

void setup() {
  pinMode(Buzzer, OUTPUT); //set Buzzer as OUTPUT
  pinMode(sensor, INPUT); //set sensor as INPUT
}

void loop() {
  if(digitalRead(sensor)){    // Checking the sensor
    digitalWrite(Buzzer, HIGH);   // turn the Buzzer ON 
  }
  else{
      digitalWrite(Buzzer, LOW);     // turn the Buzzer OFF

  }
}
