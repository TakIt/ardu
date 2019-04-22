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
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val;
  Serial.println("Please typer F or H or E");
  delay(3000);
  LED_Val = Serial.read();
  if(LED_Val != -1){
  Serial.println(LED_Val);
  
  if(Serial.available()>0);{
    val=(char)LED_Val;

    if(val='F'){
        analogWrite(LED_BUILTIN,255);
        Serial.write(val);
        Serial.println(" LED-on FULL");
        delay(5000);
    }else if(val='H'){
        analogWrite(LED_BUILTIN,127);
        Serial.print((char)val);
        Serial.println("= LED-on Half");
        delay(5000);
    }else if(val='E'){
        analogWrite(LED_BUILTIN,0);
        Serial.write(val);
        Serial.println("= LED-OFF");
    }else if(val='L'){
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
