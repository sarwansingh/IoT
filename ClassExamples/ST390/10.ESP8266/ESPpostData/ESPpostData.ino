#include <SoftwareSerial.h>
SoftwareSerial WiFi_Serial(3, 4); //3-Rx, 4-Tx
String str="";  boolean wf = false; 
void setup()
{ Serial.begin(115200);  // Begin serial monitor to receive 115200 bits per second (BAUD RATE)
  WiFi_Serial.begin(9600); // Begin serial monitor to receive 9600 bits per second (BAUD RATE)
  WiFi_Serial.println("AT+UART_DEF=9600,8,1,0,0");  delay(1000); // set WiFi Send/Receive from 115200 bits per second (BAUD RATE) to 9600 bits per second
  WiFi_Serial.println("ATE0");  delay(200);
  WiFi_Serial.println("AT+CWQAP");delay(500); // Disconnect from previous network connections
}
void WiFi_check(){
  WiFi_Serial.println("AT"); delay(500);// send a Attention command
  if (WiFi_Serial.available())
  { if (WiFi_Serial.find("OK")) // check with expected output
    { Serial.println("WIFI PLUGGED ON TO THE BOARD..!");     
      WiFi_Serial.println("AT+CWMODE=1"); //set mode to client mode
      delay(500);  wf = true; 
    }
  }else{
    Serial.println("WIFI NOT PLUGGED..!   ");   
    Serial.println("PLUG IN YOUR WIFI CHIP");  wf =false;
  }
}
void connectWifi()   // connect to wifi network
{ Serial.println("Connecting to Wifi Network ");  
  WiFi_Serial.println("AT+CWJAP?"); delay(2000);//check if WIFI connected to any WiFi network
  if (WiFi_Serial.available())
  { if (WiFi_Serial.find("No AP")) //we receive reponse "No AP" when not connected to any network
    { 
      //Serial.println("NOT CONNECTED TO WIFI NETWORK");    
      Serial.println("Trying to Connect to WiFi Network");
      str="AT+CWJAP=\"demo2\",\"12345678\"";
      WiFi_Serial.println(str); // CWJAP followed by username and password
      delay(2000);
      
      if (WiFi_Serial.available())
      {    String RES_input = "";
        while (WiFi_Serial.available()) // read the data into a variable as long as the
        {  RES_input += (char)WiFi_Serial.read(); }
        Serial.println("--->"+ RES_input);
        if (WiFi_Serial.find("WIFI CONNECTED")){         
            Serial.println("CONNECTED TO WIFI NETWORK..!"); 
        }else {
            Serial.println("ESP not CONNECTED TO WIFI NETWORK..!"); 
        }
     }
    } 
  }
}
int CELSIUS=31, HUM =79;
String Device_No="sensor101" ; // change device_no 1-19
String DST_IP="arshbir.com",username="demo";
void postData()
{ 
  String data; //form the JSON string with the available sensor data
   data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
   data += String(Device_No);
   data += "\",\"sample1\":\"";
   data += String( CELSIUS); //(unsigned char)
   data += "\",\"sample2\":\"";
   data += String(HUM); 
   data += "\",\"sample5\":\"";
   int nosample=-1;
   data += String(nosample); 
   data += "\"}";
  Serial.println( data); 
  String uri = "/iot/cht/rec.php";
  String port = "80";
  String http_req = "POST " + uri + " HTTP/1.1\r\n" + "Host: " + DST_IP + ":" + port + "\r\n" + "Accept: *" + "/" + "*\r\n" + "Content-Length: " + data.length() + "\r\n" ;
  String http_req1 = "Content-Type: application/json\r\n\r\n" ; // form the headder to post the WiFi data
  //String http_req1 = "Content-Type: application/json" ;
  Serial.println("-data->" + data + "<--");
  Serial.println("-req->" +http_req + "<--");
  Serial.println("-req1->" +http_req1 + "<--");
  int len_hedder1 = (http_req.length());
  int len_hedder2 = (http_req1.length());
  int len_data = data.length();
  int Total_req_data_Length = (len_hedder1 + len_hedder2 + len_data); // total length of headder and data
  Serial.println();
  String cmd = "AT+CIPSTART=\"TCP\",\""; // open the tcp port 
  cmd += DST_IP;
  cmd += "\",80";
  Serial.println(cmd);
  WiFi_Serial.println(cmd);
  delay(1000);
  if (WiFi_Serial.available())
  {
    String RES_input = "";
    while (WiFi_Serial.available()) // read the data into a variable as long as the
    {    RES_input += (char)WiFi_Serial.read();     }
     Serial.println(RES_input);
    if (WiFi_Serial.find("CONNECT"));
    Serial.print("AT+CIPSEND="); // start sending data to opened TCP port
    WiFi_Serial.print("AT+CIPSEND=");
    WiFi_Serial.println(Total_req_data_Length); //specify the total length of data
    delay(100);
    if (WiFi_Serial.available());
    RES_input = "";
    while (WiFi_Serial.available()) // read the data into a variable as long as the
    {   RES_input += (char)WiFi_Serial.read();   }
    Serial.println(RES_input);
    {
      if (WiFi_Serial.find(">")); // when ">" is response from WiFi that means it is ready to receive the total length of data 
      {   WiFi_Serial.print(http_req); //Send headder first
          WiFi_Serial.print(http_req1);
          WiFi_Serial.print(data); //later send data
          delay(1000);
      }
    }
    if (WiFi_Serial.available()) // wait for response and print the same to terminal
    {      delay(100);
      String RES_input = "";
      while (WiFi_Serial.available()) // read the data into a variable as long as the
      {   RES_input += (char)WiFi_Serial.read();   }
       Serial.println("-RES_input->" +RES_input +"<--");
      
      if ((RES_input.indexOf("SEND OK") >0) ||(RES_input.indexOf("Recv ") >0) ) {      
          Serial.println("== Data Save Successfully ==");
          delay(  1000);
      }else 
          delay( 4000);
   }
  }
}
void loop()
{
  Serial.println("Welcome to ESP8266 interfacing with cloud");

  WiFi_check() ;
  if (wf == true){ 
    connectWifi();  
    postData();
  } 
     
  delay(1000);
}




