const int trig_pin = 11;
const int echo_pin = 12;
float duration, distance;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  _delay_us(10);
  digitalWrite(trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration*0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  _delay_ms(100);
}
