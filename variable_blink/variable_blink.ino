void setup() {
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //first calculate the ratio of input to 1024;
  float ratio = analogRead(A1)/1024;
  int delay_time = (1 + ratio) * 1000;
  Serial.println(ratio);
  int i = 0;
  while(i < 10){
    digitalWrite(2, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_time);
    digitalWrite(2, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_time);
    ++i;
  }
}
