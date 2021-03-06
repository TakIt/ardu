#define LED_BUILTIN 13
#define pin A0

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  //距離から電圧値の数値を取得
  float Distance=analogRead(pin);
  //0～1023で取得した値を0～255までにする
  Distance=map(Distance,0,1023,0,255);
  //数値から距離に変換
  float kyori=map(Distance,55,220,50,4);
  Serial.println(kyori);
  //数値を電圧値に変換
  Distance=Distance*5.0/255.0;
  Serial.println(Distance);
  Serial.println("");
  
  
//紙の時10cm以下になると点滅するようにした
  if(kyori<10){
    analogWrite(LED_BUILTIN,255);
    delay(100);
    analogWrite(LED_BUILTIN,0);
    delay(100);
  }else{
    analogWrite(LED_BUILTIN,0);
    delay(200);
  }
  delay(1000);
}
