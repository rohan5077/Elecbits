int ledpin = 3;                        // Define led pin
int photoresistor = 0;             // Variable to store data from analog pin for photoresistor

void setup()
 {
pinMode(ledpin, OUTPUT);  // output for the led pin
   Serial.begin (9600);                            // Serial communication begins
}
void loop()
 {
Serial.println(analogRead(0)); //Write the value of the photoresistor to the serial 
                                                                         // monitor
             photoresistor = (analogRead(0)/4);    // Divides input 0-1023 to resemble 0-255
             analogWrite(ledpin,photoresistor);    // Getting the desired dimming effect   
            delay(20);                            
}

