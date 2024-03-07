#include <SoftwareSerial.h>

#define LED_PIN   1
SoftwareSerial mySerial(PB2, PB4); // RX only

void setup() { 
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  pinMode(LED_PIN, OUTPUT); 
 
}

void loop() { // run over and over
  if (mySerial.available()) {
    uint8_t rx = mySerial.read();
    if(rx == 'a'){
      digitalWrite(1, HIGH);   
      delay(1000);    
      digitalWrite(1, LOW);
    } else{
      mySerial.write(rx);
    }    
  }
 
}
