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
boolean state=false;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);    
  if(sensorValue != -1){
  Serial.println(sensorValue);
  
  if(Serial.available()>0);{

    if(sensorValue<=125){
        analogWrite(LED_BUILTIN,HIGH);
        Serial.write(sensorValue);
        Serial.println(" LED-ON");
        delay(5000);
    }else if(sensorValue>125){
        analogWrite(LED_BUILTIN,LOW);
        Serial.print(sensorValue);
        Serial.println("= LED-OFF");
        delay(5000);
    }else{
      Serial.println("End of routine");
    }
  }
}else{
    Serial.println("End of program");
    delay(3000);
}
}
