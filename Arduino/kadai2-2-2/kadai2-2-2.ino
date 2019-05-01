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
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);    
  if(sensorValue != -1){
  Serial.println(sensorValue);
  
  if(Serial.available()>0);{

    if(sensorValue>=125){
        analogWrite(11,255);
        Serial.write(sensorValue);
        Serial.println(" LED-on FULL");
        delay(5000);
    }else if(sensorValue<125||sensorValue>=50){
        analogWrite(9,127);
        Serial.print(sensorValue);
        Serial.println("= LED-on Half");
        delay(5000);
    }else if(sensorValue>0||sensorValue<50){
        analogWrite(5,0);
        Serial.write(sensorValue);
        Serial.println("= LED-OFF");
    }else if(sensorValue=0){
      for(int i = 0;i<5;i++){
      analogWrite(LED_BUILTIN,HIGH);
      delay(1000);
      analogWrite(LED_BUILTIN,LOW);
      delay(1000);
      }
    }else{
      Serial.println("End of routine");
    }
  }
}else{
    Serial.println("End of program");
    delay(3000);
}
}
