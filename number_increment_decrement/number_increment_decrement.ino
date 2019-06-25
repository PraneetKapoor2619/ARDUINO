#include <TM1637Display.h>

#define CLK 9
#define DIO 8
#define INPLUS 10
#define INMINUS 11

TM1637Display display(CLK, DIO);


void detect();
void displaunumber();

int number = 0;
int pin10 = 0, pin101 = 0;
int pin11 = 0, pin111 = 0;

void setup() {
// put your setup code here, to run once:
pinMode(10, INPUT);
pinMode(11, INPUT);
digitalWrite(INPLUS, LOW);
digitalWrite(INMINUS, LOW);
display.setBrightness(1);

}

void loop() {
  // put your main code here, to run repeatedly:
detect();

displaynumber();

}

void detect()
{   pin10 = digitalRead(INPLUS);
    pin11 = digitalRead(INMINUS);
    delay(90);
    pin101 = digitalRead(INPLUS);
    pin111 = digitalRead(INMINUS);

    if(pin101 == pin10 && pin111 == pin11)
    {   if(pin10 == HIGH)
         {   ++number;
         }
         else if(pin11 == HIGH)
         {  if(number>0)
              --number;
         }
    }
    

}

void displaynumber()
{   display.showNumberDec(number);
}
