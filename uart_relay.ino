#include <SoftwareSerial.h>

#define RELAY_PIN     (1)
#define MSG_START   (0xA5)
#define RX_TIMEOUT    (100)

SoftwareSerial mySerial(PB2, PB4); // RX, TX
uint8_t rx_buf[2] = {0};
uint32_t rx_time = 0;

void setup() { 
  mySerial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);  
}

void loop() { 
  if(mySerial.available() > 1){
    if(mySerial.read() == MSG_START){
      uint8_t rx = mySerial.read();
      if(rx == 0){
        digitalWrite(RELAY_PIN, LOW);
        mySerial.print("OK");
      }else if(rx == 1){
        digitalWrite(RELAY_PIN, HIGH);
        mySerial.print("OK");
      }else{
        mySerial.print("ERR");
      }
    }
  }
}
