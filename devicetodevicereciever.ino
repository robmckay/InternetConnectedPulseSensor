#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>

ThingerWifi thing("robmckay123", "d1mini", "d1mini");

void setup() {
  
  thing.add_wifi("BTHub5-NQ38", "schoolroadmassive");

   pinMode(5, OUTPUT);
   pinMode(15, INPUT);
  thing["blink"] = [](){
      for(int i=0; i <=255; i++){
       analogWrite(5,i);
        delay(1);
      }
      delay(300);
      for(int i=255; i >=0; i--){
       analogWrite(5,i);
       delay(2);
      }
    };

  
}

void loop() {
  thing.handle();
  if(digitalRead(15) ==1) {
  
    thing.call_endpoint("LEDnode");
    delay(200);   
  }
  
}
