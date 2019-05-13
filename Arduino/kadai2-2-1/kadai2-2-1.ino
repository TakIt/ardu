#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 11
#define anlg A0

//int swv = 0;
int LED_Val = 0;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);
  
    if(sensorValue<=400){
        analogWrite(LED_BUILTIN,255);
        Serial.println(" LED-ON");
        delay(5000);
    }else{
      analogWrite(LED_BUILTIN,LOW);
      Serial.println("LED-OFF");
      delay(5000);
    }
}
