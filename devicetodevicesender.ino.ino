#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>

ThingerWifi thing("robmckay123", "nodemcu", "nodemcu");
int state =0;
void setup() {
  
  thing.add_wifi("BTHub5-NQ38", "schoolroadmassive");

   pinMode(15, INPUT);
   pinMode(5, OUTPUT);
  thing["blinknode"] = [](){

    digitalWrite(5,1);
    delay(50);
    digitalWrite(5,0);
    };
}

void loop() {
  thing.handle();
  
  if(digitalRead(15) ==1) {
  
    thing.call_endpoint("LED");
    delay(200);   
  }
}
