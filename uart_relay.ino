#include <SoftwareSerial.h>

#define RELAY_PIN     (1)
#define MSG_START_1   (0xA)
#define MSG_START_2   (0x5)
#define RX_TIMEOUT    (100)

SoftwareSerial mySerial(PB2, PB4); // RX only
uint8_t rx_buf[2] = {0};
uint32_t rx_time = 0;

void setup() { 
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT); 
 
}

void loop() { // run over and over
  if(mySerial.available() && (mySerial.read() == MSG_START_1)){
    if(mySerial.available() && (mySerial.read() == MSG_START_12){
      if(mySerial.available()){
        uint8_t rx = (mySerial.read();
        if(rx == 0){
          digitalWrite(RELAY_PIN, LOW);
          mySerial.write(0);
        }else if(rx == 1){
          digitalWrite(RELAY_PIN, HIGH);
          mySerial.write(0);
        }else{
          mySerial.write(1);
        }
      } 
    }    
  }
}
