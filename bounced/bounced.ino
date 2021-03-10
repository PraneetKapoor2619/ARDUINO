int state = 0;
void setup() {
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == HIGH) {
    if(state == 0){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("\nHIGHHHHHH!");
    state = 1;
    }
  }
  else{
    if (state == 1){
      state = 0;
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print("\nLOWWWWW!!!");
    }
  }
}
