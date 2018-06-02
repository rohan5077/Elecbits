#define LED 12
#define BUTTON 7

void setup() {
  // put your setup code here, to run once:
   pinMode(LED, OUTPUT);   // output for the LED
  pinMode(BUTTON, INPUT); // input for the button

}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(LED, LOW);
  int buttonstate = digitalRead(BUTTON);
  if ( buttonstate == 1 ) // Check if the button has been pressed
  {
     digitalWrite(LED, HIGH);   // turn on the LED
     delay(5000);               // wait for 0.5 seconds
     digitalWrite(LED, LOW);    // turn off the LED
  }

  else
    digitalWrite(LED, LOW);
}
