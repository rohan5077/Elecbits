#define base_pin 12
 void setup()
  {
     pinMode(base_pin, OUTPUT);          // output for the transistor base pin
 }
void loop()
 {
             digitalWrite(base_pin, HIGH);       // provide current to base pin of transistor
             delay(1000);                                    // wait for 5 seconds

             digitalWrite(base_pin, LOW);       // stop the current flow to the transistor base pin
             delay(5000);                                   // wait for 5 seconds
       }

