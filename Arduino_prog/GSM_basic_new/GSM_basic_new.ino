#include <SoftwareSerial.h>

//****************************************************************************
//SIM800 TX is connected to Arduino D8
#define SIM800_TX_PIN 2

//SIM800 RX is connected to Arduino D7
#define SIM800_RX_PIN 3

//Create software serial object to communicate with SIM800
SoftwareSerial serialSIM800(SIM800_TX_PIN, SIM800_RX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialSIM800.begin(9600);
  Serial.println("Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    serialSIM800.write(Serial.read());
  }
  if(serialSIM800.available()>0){
    Serial.write(serialSIM800.read());
  }
}
