int segment[]={3,4,5,6,7,8,9};
int zero[]={ 0,0,0,0,0,0,1} , one[]={ 1,0,0,1,1,1,1};;
void setup() {
  for (int i=0 ;i<7; i++ ){ 
    pinMode(segment[i],OUTPUT);
    digitalWrite(segment[i],HIGH);
  }
}
void loop() {
  for (int i=0 ;i<7; i++ ) digitalWrite(segment[i],zero[i]);
  delay(1000);
  for (int i=0 ;i<7; i++ ) digitalWrite(segment[i],one[i]);
  delay(1000);
}
