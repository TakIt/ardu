#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 13
#define anlg A0

//int swv = 0;
int LED_Val = 0;
boolean state=false;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  analogWrite(11,LOW);
  analogWrite(12,LOW);
  analogWrite(LED_BUILTIN,LOW);
  delay(1);
  
    if(sensorValue>=800){
        analogWrite(11,255);
        Serial.println(" LED-on Green");
        delay(5000);
    }else if(sensorValue<800&&sensorValue>=500){
        analogWrite(12,255);
        Serial.println("= LED-on Yellow");
        delay(5000);
    }else if(sensorValue<500&&sensorValue>200){
        analogWrite(LED_BUILTIN,255);
        Serial.println("= LED-on RED");
        delay(5000);
    }else{
      analogWrite(11,255);
      analogWrite(12,255);
      analogWrite(LED_BUILTIN,255);
      Serial.println("=LED-ON FULL");
      delay(5000);
      }
    }
