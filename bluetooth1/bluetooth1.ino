int tx = 1;
int rx = 0;
char inSerial[200];

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  int i = 0;
  _delay_ms(500);
  if(Serial.available() > 0) {
      while(Serial.available() > 0){
          inSerial[i] = Serial.read();
          i++;
      }
      inSerial[i] = '\0';
      Serial.println(inSerial);
  }
}
