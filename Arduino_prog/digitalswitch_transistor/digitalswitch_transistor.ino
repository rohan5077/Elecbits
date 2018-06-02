int led = 12;     // led is connected with transistor by pin 12 of arduino

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);     // set pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);     // led on
  delay(500);                 // delay of 0.5 sec
  digitalWrite(led,LOW);      // led on
  delay(500);
}
