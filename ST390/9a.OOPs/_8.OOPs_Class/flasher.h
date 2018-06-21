class Flasher{
  int onTime,offTime;  int ledPin; 
  public : 
    // creating constructor
    //Flasher() { onTime=500; offTime=500; }  
    Flasher(int pin , int on=500, int off=500){  
      ledPin=pin; 
      pinMode(ledPin , OUTPUT);
      onTime=on; offTime=off; 
    }
    void  setData(int on, int off=500){ // default value for argument
      onTime=on; offTime=off; 
    }
    void update(){
      digitalWrite(ledPin , HIGH); delay (onTime);
      digitalWrite(ledPin , LOW); delay (offTime);
    }
};
