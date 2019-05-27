#define pin A0

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  double val = analogRead(pin);
  //出力電圧に変換
  double vol = val*5.0/1023;
  //温度に変換(気温一度につき10mV)
  double temp=vol*100.0;

 //Serial.print("ls");
 //Serial.println(val);
 Serial.print("Volt:");
 Serial.println(vol);
 Serial.print("Temperature:");
 Serial.println(temp); 
 Serial.println("");


 if(temp>=31){
  analogWrite(13,255);
  analogWrite(12,LOW);
  delay(100);
  analogWrite(13,255);
  analogWrite(12,255);
 }else if(temp<30&&temp>=28){
  analogWrite(13,255);
 }else if(temp<28&&temp>=25){
  analogWrite(12,255);
 }else{
  analogWrite(11,255);
 }

delay(1000);

   analogWrite(11,LOW);
  analogWrite(12,LOW);
    analogWrite(13,LOW);
}
