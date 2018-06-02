 #include<LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(5, 0);
  lcd.print("*Hello*");
  lcd.setCursor(4, 1);
 // Print a message to the LCD.
  lcd.print("World");
  delay(1000);
  lcd.clear();
}

