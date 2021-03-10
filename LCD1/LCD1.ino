#include<LiquidCrystal.h>

char array1[] = "HELLO! DIe sooon! Goodbye!!";
int tim = 500; //the value of delay time
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);        //initialize the library with number of interface pins.
void setup() {
  lcd.begin(16, 2);         //set up the number of columns and rows in the lcd
}

void loop() {
  lcd.setCursor(15, 1);       //set the cursor to column 15, line 0
  for(int position_counter = 0; position_counter<= sizeof(array1); position_counter++){
    lcd.scrollDisplayLeft(); //scrolls display to left side
    lcd.print(array1[position_counter]);
    _delay_ms(tim);
  }
  lcd.clear();
}
