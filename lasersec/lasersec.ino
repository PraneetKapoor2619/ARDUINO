const int opin = A0;
float thresh = 50.0;
int t = 50;
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float val = analogRead(A0);
  if(val > thresh){
    Serial.println(val);
    digitalWrite(2, HIGH);
    _delay_ms(t);
    digitalWrite(2, LOW);
    _delay_ms(t);
  }
  Serial.println(val);
  digitalWrite(2, LOW);
}
