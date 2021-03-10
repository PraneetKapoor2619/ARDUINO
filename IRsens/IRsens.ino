const int opin = A0;
int input_val = 0;

void setup() {
  pinMode(13, OUTPUT);        //Pin which is connected to the builtin LED
  pinMode(opin, INPUT);       //Pin 2 is connected to the output of the sensor
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(opin) == HIGH){   //Check the sensor output
    digitalWrite(13, HIGH);       //if sensor output is HIGH, turn the builtin LED ON
  }
  else{
    digitalWrite(13, LOW);        //if the sensor output is LOW, turn the builtin LED OFF
  }
  input_val = analogRead(opin);   //read the output value of the sensor
  Serial.println(input_val);       //print the read value on serial monitor
  _delay_ms(100);                //wait for one second
}
