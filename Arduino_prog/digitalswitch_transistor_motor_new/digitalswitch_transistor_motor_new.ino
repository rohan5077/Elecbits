int motor = 9;           // the PWM pin the MOTOR is attached to
int val = 0;              // Set the initial speed
int motor_speed = 5;    // how many points to change the speed

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(motor, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the speed of motor:
  analogWrite(motor, val);

  // change the speed for next time through the loop:
  val = val + motor_speed;

  // reverse the speed
  if (val <= 0 || val >= 255) {
    motor_speed = -motor_speed;
  }
  // wait for 30 milliseconds to see the changing speed
  delay(30);
}
