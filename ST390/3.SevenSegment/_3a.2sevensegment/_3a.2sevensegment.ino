int seg1=13, seg2=12,t,p;
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<9;i++)    pinMode(i,OUTPUT);
  pinMode(seg1,OUTPUT);
  pinMode(seg2,OUTPUT);
}
int arr[][7]={
    {0,0,0,0,0,0,1},{1,0,0,1,1,1,1},{0,0,1,0,0,1,0},
    {0,0,0,0,1,1,0},{1,0,0,1,1,0,0},{0,1,0,0,1,0,0},
    {0,1,0,0,0,0,0},{0,0,0,1,1,1,1},{0,0,0,0,0,0,0},{0,0,0,1,1,0,0}};
    
void show(int k){
  for(int i=2, j=0;i<9,j<7;i++,j++)
    digitalWrite(i,arr[k][j]);
}
int bVal, c=-1;
void loop() 
{  c++;
      t=c%10;
      p=c/10;
      unsigned long startTime = millis();
      for (unsigned long elapsed=0; elapsed < 600; elapsed = millis() - startTime) {
        digitalWrite(seg1,HIGH);
        digitalWrite(seg2,LOW);
        show(t);    delay(5);
        digitalWrite(seg2,HIGH);
        digitalWrite(seg1,LOW);
        show(p);    delay(5);
      }
    if(c>99)    c=-1; // restart from -1
}





