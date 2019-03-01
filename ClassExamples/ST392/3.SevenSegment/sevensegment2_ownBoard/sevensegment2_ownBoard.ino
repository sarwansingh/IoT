int seg1=11, seg2=10,t,p;
              // a,b,c,d,e,f,g 
int segment[]={9, 7, 5, 4, 6,2 ,3};
void setup() {
  for(int i=0;i<7;i++)    pinMode(segment[i],OUTPUT);
  pinMode(seg1,OUTPUT);
  pinMode(seg2,OUTPUT);
}
int arr[][7]={
    {0,0,0,0,0,0,1},{1,0,0,1,1,1,1},{0,0,1,0,0,1,0},
    {0,0,0,0,1,1,0},{1,0,0,1,1,0,0},{0,1,0,0,1,0,0},
    {0,1,0,0,0,0,0},{0,0,0,1,1,1,1},{0,0,0,0,0,0,0},{0,0,0,1,1,0,0}};
    
void show(int k){
  for(int i=0;i<7;i++ )
    digitalWrite(segment[i],arr[k][i]);
}
int bVal, c=1;
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
    if(c>19)    c=-1; // restart from -1
}





