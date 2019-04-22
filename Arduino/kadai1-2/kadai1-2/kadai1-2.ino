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
  pinMode(LED_BUILTIN,OUTPUT);
  //pinMode(SW_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //swv=digitalRead(SW_PIN);

  /**
   * if(swv==HIGH){
    state =! state;
  }
*/
  //if(state){
  LED_Val=analogRead(anlg);
  analogWrite(LED_BUILTIN,LED_Val/4);
  /**
   * delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }
  */

}
