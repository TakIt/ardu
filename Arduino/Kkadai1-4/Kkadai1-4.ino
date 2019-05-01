#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 13
#define anlg A0


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  String LED_Val;
  Serial.println("Please typer F or H or E");
  delay(3000);
  LED_Val = Serial.readStringUntil(";");
  if(LED_Val != -1){
  Serial.println(LED_Val);
  
  if(Serial.available()>0);{

    if(LED_Val='F'){
        analogWrite(LED_BUILTIN,255);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
    }else if(LED_Val='H'){
        analogWrite(LED_BUILTIN,204);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
    }else if(LED_Val='E'){
        analogWrite(LED_BUILTIN,178);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
    }else if(LED_Val='L'){
       analogWrite(LED_BUILTIN,153);
        Serial.print(" LED-Valume ");
        //Serial.write(LED_Val);
        delay(5000);
        break;
      }
    }else{
      Serial.println("End of program");
    delay(3000);
    }
  }
}else{
    Serial.println("End of program");
    delay(3000);
}
}
