char data = 0;            //Variable for storing received data
int LED = 2;

void setup(){
  Serial.begin(9600);   //Sets the baud for serial data transmission
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);                 
}
   
void loop(){
  if(Serial.available() > 0) {      //Check Serial data available
    data = Serial.read();        //Read the incoming data
    Serial.print(data);          //Print on Serial monitor
    if(data == '1') {
      digitalWrite(LED, LOW);     //LED ON
    }
    else if(data == '5'){
      digitalWrite(LED, HIGH);      //LED OFF
    }
  }
}
