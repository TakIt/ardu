#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#define LED_BUILTIN 11
#define anlg A0

long recv_data = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  byte data_size = Serial.available();
 
  byte buf[data_size], degree = 1;
  long recv_data = 0, dub = 1;
  Serial.println("Please typer 1-10");
  
  delay(3000);
  for (byte i = 0 ; i < data_size ; i++){
  buf[i] = Serial.read() - '0';
          Serial.print(buf[i]);
        delay(1000);
  
    }
      byte x=buf[0];
      byte y=buf[1];

      if(x==1&&y==0){
        
        Serial.println("LED=10");
  recv_data = 10;
  goto label1;
 
    }
    recv_data=x;

  if(recv_data != -1){
  Serial.println(recv_data);
  goto label1;
}
else
{
  goto label2;
}
label1:
  if(Serial.available()>0);{
    switch(recv_data){
      case 10:
        analogWrite(LED_BUILTIN,255);
        Serial.write(recv_data);
        Serial.println(" LED-on FULL");
        delay(5000);
        break;
      case 9:
        analogWrite(LED_BUILTIN,229);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 8:
        analogWrite(LED_BUILTIN,127);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 7:
        analogWrite(LED_BUILTIN,204);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 6:
        analogWrite(LED_BUILTIN,178);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 5:
        analogWrite(LED_BUILTIN,153);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 4:
        analogWrite(LED_BUILTIN,127);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 3:
        analogWrite(LED_BUILTIN,76);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 2:
        analogWrite(LED_BUILTIN,51);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
        case 1:
        analogWrite(LED_BUILTIN,25);
        Serial.print(recv_data);
        Serial.println("= LED");
        delay(5000);
        break;
      case 0:
        analogWrite(LED_BUILTIN,0);
        Serial.write(recv_data);
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
