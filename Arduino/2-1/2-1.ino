#define LED_BUILTIN 11
#define anlg A0

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  delay(1);
  sensorValue=sensorValue/4;
  if(sensorValue !=-1){
    
    Serial.println(sensorValue);
    analogWrite(LED_BUILTIN,sensorValue);
  }else{
    Serial.println("End of program");
  }
}
