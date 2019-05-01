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
  goto label1;
}
else
{
  goto label2;
}
label1:
  if(Serial.available()>0);{
    val=(char)LED_Val;
    switch(val){
      case 'F':
        analogWrite(LED_BUILTIN,255);
        Serial.write(val);
        Serial.println(" LED-on FULL");
        delay(5000);
        break;
      case 'H':
        analogWrite(LED_BUILTIN,50);
        Serial.print((char)val);
        Serial.println("= LED-on Half");
        delay(5000);
        break;
      case 'E':
        analogWrite(LED_BUILTIN,0);
        Serial.write(val);
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
