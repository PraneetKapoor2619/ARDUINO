const int trig_pin = 11;
const int echo_pin = 12;
const int speaker = 5;
const float unit_note = 2.273e-3;
float duration, distance;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  trigger();
  duration = pulseIn(echo_pin, HIGH);
  distance = (duration*0.0343)/2;
  note();
  Serial.print("Distance: ");
  Serial.println(distance);
}

int trigger(){
    digitalWrite(trig_pin, LOW);
  _delay_us(10);
  digitalWrite(trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(trig_pin, LOW);
  return 0;
}

int note(){
  int val = distance * unit_note;
  for(int i = 1; i <= 10; ++i){
    digitalWrite(speaker, HIGH);
    delay(val);
    digitalWrite(speaker, LOW);
    delay(val);
  }
  return 0;
}
