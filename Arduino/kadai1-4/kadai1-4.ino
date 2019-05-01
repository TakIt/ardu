#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 11
#define anlg A0

int LED_Val=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  char val;
  Serial.println("Please typer 1-10");
  delay(3000);
  if(LED_Val != -1){
  Serial.println(LED_Val);
  goto label1;
}
else
{
  goto label2;
}
  }
label1:
  if(Serial.available()>0);{
     val=(char)LED_Val;
    switch(val){
      case "9":
        analogWrite(LED_BUILTIN,255);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
      case "8":
        analogWrite(LED_BUILTIN,204);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
      case "7":
        analogWrite(LED_BUILTIN,178);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
      case "6":
        analogWrite(LED_BUILTIN,153);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
      case "5":
        analogWrite(LED_BUILTIN,127);
        Serial.write(LED_Val);
        Serial.println("= LED-on Half");
        delay(5000);
        break;
      case "4":
        analogWrite(LED_BUILTIN,102);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
       case "3":
        analogWrite(LED_BUILTIN,76);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
       case "2":
        analogWrite(LED_BUILTIN,51);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
       case "1":
        analogWrite(LED_BUILTIN,25);
        Serial.print(" LED-Valume ");
        Serial.write(LED_Val);
        delay(5000);
        break;
      case "0":
        analogWrite(LED_BUILTIN,0);
        Serial.write(LED_Val);
        Serial.println("= LED-OFF");
        break;
      default :
        Serial.println("End of routine");
        break;
    }
  }
  label2:
    Serial.println("End of program");
    delay(3000);
    
    }
