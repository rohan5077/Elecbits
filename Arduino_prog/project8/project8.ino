#define piezo_pin 3  // pin 3 is capable of PWM output to drive tones 
int del = 500;

void setup()
{
  pinMode (piezo_pin, OUTPUT);
}

void loop()
{ 
   analogWrite (piezo_pin, 250);  // 50 percent duty cycle tone to the piezo 
 delay(del);  
   digitalWrite (piezo_pin, LOW); // turn the piezo off 
 delay(del);
 }

