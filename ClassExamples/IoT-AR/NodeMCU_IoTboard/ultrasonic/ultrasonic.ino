int trigPin = 5;      //TRIG and ECHO pins
int echoPin = 13;
long duration;
int distance;

void setup(){
  pinMode(trigPin, OUTPUT); // Set trigPin as Output
  pinMode(echoPin, INPUT); // Set the echoPin as Input
  Serial.begin(9600); // Starts the serial communication
  digitalWrite(trigPin, LOW);
}

void loop(){
  digitalWrite(trigPin, HIGH);    //initial pulse on TRIG
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);    //reads the echoPin, travel time in microseconds
  distance= duration*0.034/2;     //calculate distance
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
}
  
