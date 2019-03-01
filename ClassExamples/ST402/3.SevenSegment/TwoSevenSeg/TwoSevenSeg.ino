int seg1=11, seg2=10,t,p;
              // a,b,c,d,e,f,g 
int segment[]={9, 7, 5, 4, 6, 2 ,3};
int digits[][7] = {
  {0,0,0,0,0,0,1},{1,0,0,1,1,1,1},{0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},{1,0,0,1,1,0,0},{0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},{0,0,0,1,1,1,1},{0,0,0,0,0,0,0},{0,0,0,1,1,0,0}
};
void setup() {
    for (int i=0 ; i<7;i++) pinMode(segment[i], OUTPUT);
    pinMode(seg1,OUTPUT);  pinMode(seg2,OUTPUT);
}
void show(int j){
  for (int i=0 ; i<7;i++)
    digitalWrite(segment[i], digits[j][i]);
}
void digit2(int j){
  int k=60;
        while(k--){
          digitalWrite(seg1, 1);digitalWrite(seg2, 0);
          show(j%10);           delay(10); 
          digitalWrite(seg1, 0);digitalWrite(seg2, 1);
          show(j/10);          delay(10);
        }
}
void loop() {
      for (int j=0 ; j<25 ;j++){
        digit2 (j);
      }
}
