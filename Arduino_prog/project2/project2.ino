void setup()
  {
       pinMode(12, OUTPUT);          // Setting the pin 2 as output
       pinMode(3, OUTPUT);          // Setting the pin 3 as output
       pinMode(4, OUTPUT);          //Setting the pin 4 as output
       pinMode(5, OUTPUT);          // Setting the pin 5 as output
  }
void loop()
  {
digitalWrite(12, HIGH);           // Turn on LED 1
      delay(100);                             //  Wait for 100milliseconds
  digitalWrite(12, LOW);           //  Turn off LED 1
      digitalWrite(3, HIGH);          //  Turn on LED 2
      delay(100);                             //  Wait for 100milliseconds
                digitalWrite(3, LOW);           // Turn off LED 2
      digitalWrite(4, HIGH);          //  Turn on LED 3
      delay(100);                             //  Wait for 100milliseconds
      digitalWrite(4, LOW);           //  Turn off LED 3
digitalWrite(5, HIGH);          // Turn on LED 4
                delay(100);                             //  Wait for 100 milliseconds
                digitalWrite(5, LOW);           //  Turn off LED 4
             }

