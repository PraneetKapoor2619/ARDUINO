#define MOSI 6
#define MOSILED 9
#define SCK 7
#define SCKLED 10

int debounce_detect();
int OperateSlave(int);

void setup() {
  // put your setup code here, to run once:
pinMode(5,INPUT);            //will take input of zero
pinMode(8,INPUT);             //will take input of one
pinMode(MOSI, OUTPUT);
pinMode(MOSILED, OUTPUT);
pinMode(SCK, OUTPUT);
pinMode(SCKLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int keyvalue = debounce_detect();
OperateSlave(keyvalue);
}

int debounce_detect()
{ 
  int ONE, ZERO, C0, C1;
  ONE = digitalRead(8);
  ZERO = digitalRead(5);
  delay(30);
  C0 = digitalRead(5);
  C1 = digitalRead(8);
  if(ZERO == HIGH && C0 == HIGH)
    return 5;
  else if(ONE == HIGH && C1 == HIGH)
    return 8;
  else
    return 0;
}

int OperateSlave(int keyvalue)
{ 
  switch(keyvalue)
  {   
    case 0: return 0;
            break;
    case 5: digitalWrite(SCK,HIGH);
            digitalWrite(SCKLED,HIGH);
            delay(10);
            digitalWrite(SCK,LOW);
            digitalWrite(SCKLED,LOW);
            break;
    case 8: digitalWrite(MOSI, HIGH);
            digitalWrite(MOSILED, HIGH);
            delay(10);
            digitalWrite(SCK, HIGH);
            digitalWrite(SCKLED,HIGH);
            delay(10);
            digitalWrite(SCK, LOW);
            digitalWrite(SCKLED, LOW);
            digitalWrite(MOSI, LOW);
            digitalWrite(MOSILED, LOW);
            break;
   default: return 0;
            break;
  }

}
