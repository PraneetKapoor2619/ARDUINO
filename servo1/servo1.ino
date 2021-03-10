#include<Servo.h>

int servo_pin = 3;              //control pin of the servo will be connected to the third pin of Arduino Nano/Uno
Servo Servo1;                   //Create servo object

void setup() {
  Servo1.attach(servo_pin);     //Attach Servo1 to servo_pin
}

void loop() {
  Servo1.write(0);              //Make Servo1 go to 0 deg
  _delay_ms(1000);
  Servo1.write(90);             //Make Servo1 go to 90 deg
  _delay_ms(1000);
  Servo1.write(180);            //Make Servo1 go to 180 deg
  _delay_ms(1000);
}
