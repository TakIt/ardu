#define LED_BUILTIN 13
#define pin A0

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  int Distance=analogRead(pin);
  Distance=map(Distance,0,1023,0,255);
  Serial.println(Distance);
  

  if(Distance<100){
    analogWrite(LED_BUILTIN,255);
    delay(100);
    analogWrite(LED_BUILTIN,0);
    delay(100);
  }else{
    analogWrite(LED_BUILTIN,0);
    delay(200);
  }
}
