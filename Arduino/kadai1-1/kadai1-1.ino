#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 13
#define SW_PIN 2

//int swv = 0;
boolean state=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(SW_PIN,INPUT);
}

void loop() {
  if(digitalRead(2)==LOW){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(5);
  digitalWrite(LED_BUILTIN,LOW);
  delay(15);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }

}
