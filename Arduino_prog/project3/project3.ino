int val = 100;                                  // Creating a integer variable d with value equal to 100
void setup()
  {
       pinMode(2, OUTPUT);          // Setting the pin 2 as output
       pinMode(3, OUTPUT);          // Setting the pin 3 as output
       pinMode(4, OUTPUT);          //Setting the pin 4 as output
       pinMode(5, OUTPUT);          // Setting the pin 5 as output
  }
void loop()
  {
      for (int i =2; i<6; i++)
        {
           digitalWrite(i, HIGH);
           delay(val);
           digitalWrite(i, LOW);
           delay(val);
        }
  }

