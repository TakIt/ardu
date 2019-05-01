#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 13
#define anlg A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  int i=analogRead(anlg);
  float f = i * 5.0/1023.0;
  Serial.println(f);
  if(f>=4){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(15);
  digitalWrite(LED_BUILTIN,LOW);
  delay(5);
  }else if(f<4&&f>2){
      digitalWrite(LED_BUILTIN,HIGH);
  delay(10);
  digitalWrite(LED_BUILTIN,LOW);
  delay(10);
  }else if(f<=2){
      digitalWrite(LED_BUILTIN,HIGH);
  delay(5);
  digitalWrite(LED_BUILTIN,LOW);
  delay(15);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }

}
