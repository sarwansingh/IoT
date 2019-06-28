#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();

const int button1Pin = D5, button2Pin = D6;// the number of the pushbutton pin
const int button3Pin = D7, button4Pin = D8;// the number of the pushbutton pin

const int led1Pin =  D0, led2Pin =  D1;     // the number of the LED pin
const int led1Addr = 100, led2Addr = 101;   // address in EEPROM for LED1 , LED2 status

const int led3Pin =  D2, led4Pin =  D3;     // the number of the LED pin
const int led3Addr = 103, led4Addr = 104;   // address in EEPROM for LED1 , LED2 status

const char* ssid = "demo";                //type your ssid
const char* password = "12345678";        //type your password
const char* mqtt_server = "test.mosquitto.org";

int btn1flag = 0, btn2flag = 0;
int btn3flag = 0, btn4flag = 0;

int button1State = 0, button2State = 0; // variable for button1State the pushbutton status
int button3State = 0, button4State = 0; // variable for button1State the pushbutton status

WiFiClient espClient;
PubSubClient client(espClient);

void connectWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(D4, HIGH);
    delay(500);
    digitalWrite(D4, LOW);
    Serial.print(".");
  } WiFiServer server(80);

  Serial.println("");
    digitalWrite(D4, HIGH);
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");
  

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void readEEPROMupdateLED();
void   updateLEDstatus();
void setup() {
 
  Serial.begin(9600);
  EEPROM.begin(512);
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT); pinMode(led2Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT); pinMode(button2Pin, INPUT);

  pinMode(led3Pin, OUTPUT); pinMode(led4Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button3Pin, INPUT); pinMode(button4Pin, INPUT);

 Serial.println(" -----------------------------------Control in setup " ) ;
  readEEPROMupdateLED();// read from EEPROM the status of LEDs
  connectWifi(); // connect to wifi
  //  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  reconnect();
 
}
void readEEPROMupdateLED() {
  byte val1InEEPROM = EEPROM.read( led1Addr);
  byte val2InEEPROM = EEPROM.read( led2Addr);

  byte val3InEEPROM = EEPROM.read( led3Addr);
  byte val4InEEPROM = EEPROM.read( led4Addr);
  Serial.print("value in EEPROM ");
  Serial.print(" LED1 ");
  Serial.println(val1InEEPROM);
  Serial.print(" LED2 ");
  Serial.println(val2InEEPROM);
  btn1flag = val1InEEPROM;
  btn2flag = val2InEEPROM;

  Serial.print("value in EEPROM ");
  Serial.print(" LED3 ");
  Serial.println(val3InEEPROM);
  Serial.print(" LED4 ");
  Serial.println(val4InEEPROM);
  btn3flag = val3InEEPROM;
  btn4flag = val4InEEPROM;

  updateLEDstatus();
}
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  if ((char)payload[0] == 'o' && (char)payload[1] == 'n' && (char)payload[2] == '1') {
    //     digitalWrite(gpio0_pin, HIGH);
    btn1flag = 1;
    updateLEDstatus();
    client.publish("room1/light1", "on1");
    Serial.print("LED 1 high");
  }
  else if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f' && (char)payload[3] == '1')
  { //digitalWrite(gpio0_pin, LOW);
    btn1flag = 0;
    updateLEDstatus();
    client.publish("room1/light1", "off1");
    
    Serial.print("pin0  low");
  }
  if ((char)payload[0] == 'o' && (char)payload[1] == 'n' && (char)payload[2] == '2') { //on
    btn2flag = 1;
    updateLEDstatus();
     client.publish("room1/light2", "on2");
    Serial.print("pin2 high");
  }
  else if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f' && (char)payload[3] == '2') //off
  { btn2flag = 0;
    updateLEDstatus();
     client.publish("room1/light2", "off2");
    Serial.print("pin2  low");
  }
  ////////////////////////////////////////////////////////////////////////
  if ((char)payload[0] == 'o' && (char)payload[1] == 'n' && (char)payload[2] == '3') {
    //     digitalWrite(gpio0_pin, HIGH);
    btn3flag = 1;
    updateLEDstatus();
     client.publish("room1/light3", "on3");
    Serial.print("LED 3 high");
  }
  else if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f' && (char)payload[3] == '3')
  { //digitalWrite(gpio0_pin, LOW);
    btn3flag = 0;
    updateLEDstatus();
     client.publish("room1/light3", "off3");
    Serial.print("pin3  low");
  }
  if ((char)payload[0] == 'o' && (char)payload[1] == 'n' && (char)payload[2] == '4') { //on
    btn4flag = 1;
    updateLEDstatus();
     client.publish("room1/light4", "on4");
    Serial.print("pin4 high");
  }
  else if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f' && (char)payload[3] == '4') //off
  { btn4flag = 0;
    updateLEDstatus();
     client.publish("room1/light4", "off4");
    Serial.print("pin4  low");
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("testnielit47")) { //NodeMCUNielit123
      Serial.println("connected");
      // Once connected, publish an announcement...
//      if (btn1flag == 1 ) client.publish("room1/light1", "on1");
//      else client.publish("room1/light1", "off1");
//      if (btn2flag == 1 ) client.publish("room1/light2", "on2");
//      else client.publish("room1/light2", "off2");
//     
//      if (btn3flag == 1 ) client.publish("room1/light3", "on3");
//      else client.publish("room1/light3", "off3");
//      if (btn4flag == 1 ) client.publish("room1/light4", "on4");
//      else client.publish("room1/light4", "off4");

       client.subscribe("room1/light1");   //NODEMCU/LED1
      client.subscribe("room1/light2");//NODEMCU/LED2
      client.subscribe("room1/light3");   //NODEMCU/LED1
      client.subscribe("room1/light4");//NODEMCU/LED2

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      //delay(5000);
    }
  }
}
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;

unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;

unsigned long debounceDelay = 50;

int lastButtonState1 = LOW;
int buttonState;

int lastButtonState2 = LOW;
int buttonState2;

int lastButtonState3 = LOW;
int buttonState3;

int lastButtonState4 = LOW;
int buttonState4;

void loop() {
  
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);

  if (button1State != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  ////////////////////////////////////////BUTTON 1///////////////////////////
  if ((millis() - lastDebounceTime1) > debounceDelay) {

    if (button1State != buttonState) {
      buttonState = button1State;
      if (button1State == HIGH) {
        btn1flag = !btn1flag;
        updateLEDstatus();
        if (btn1flag == 1 ) {client.publish("room1/light1", "on1");
        }
        else {client.publish("room1/light1", "off1");
       }
        Serial.println("message published btn1");
      }
    }
  }
  lastButtonState1 = button1State;
  /////////////////////////////////////////BUTTON 2/////////////////////////////////////////////
  if (button2State != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {

    if (button2State != buttonState2) {
      buttonState2 = button2State;
      if (button2State == HIGH) {
        btn2flag = !btn2flag;
        updateLEDstatus();
        if (btn2flag == 1 ) client.publish("room1/light2", "on2");
        else client.publish("room1/light2", "off2");
        Serial.println("message published");
      }
    }
  }
  lastButtonState2 = button2State;
  //////////////////////////////////BUTTON 3///////////////////////////////

  if (button3State != lastButtonState3) {
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay) {

    if (button3State != buttonState3) {
      buttonState3 = button3State;
      if (button3State == HIGH) {
        btn3flag = !btn3flag;
        updateLEDstatus();
        if (btn3flag == 1 ) client.publish("room1/light3", "on3");
        else client.publish("room1/light3", "off3");
        Serial.println("message published btn3");
      }
    }
  }
  lastButtonState3 = button3State;
  /////////////////////////////////////BUTTON 4/////////////////////////////////////////////

  if (button4State != lastButtonState4) {
    lastDebounceTime4 = millis();
  }

  if ((millis() - lastDebounceTime4) > debounceDelay) {

    if (button4State != buttonState4) {
      buttonState4 = button4State;
      if (button4State == HIGH) {
        btn4flag = !btn4flag;
        updateLEDstatus();
        if (btn4flag == 1 ) client.publish("room1/light4", "on4");
        else client.publish("room1/light4", "off4");
        Serial.println("message published btn4");
      }
    }
  }
  lastButtonState4 = button4State;

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // Serial.println(" inside loop ");
}
void updateLEDstatus() {
  if (btn1flag == 1)
  { digitalWrite(led1Pin, HIGH);
    int s = 1;
    EEPROM.write(led1Addr, s);
  } else {
    digitalWrite(led1Pin, LOW);
    int s = 0;
    EEPROM.write(led1Addr, s);
  }
  if (btn2flag == 1)
  { digitalWrite(led2Pin, HIGH);
    int s = 1;
    EEPROM.write(led2Addr, s);
  } else {
    digitalWrite(led2Pin, LOW);
    int s = 0;
    EEPROM.write(led2Addr, s);
  }
  /////////////
  if (btn3flag == 1)
  { digitalWrite(led3Pin, HIGH);
    int s = 1;
    EEPROM.write(led3Addr, s);
  } else {
    digitalWrite(led3Pin, LOW);
    int s = 0;
    EEPROM.write(led3Addr, s);
  }
  if (btn4flag == 1)
  { digitalWrite(led4Pin, HIGH);
    int s = 1;
    EEPROM.write(led4Addr, s);
  } else {
    digitalWrite(led4Pin, LOW);
    int s = 0;
    EEPROM.write(led4Addr, s);
  }

  EEPROM.commit();
}
