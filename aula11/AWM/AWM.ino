 const int ledPin = 5;
  const int interruptPin = 2;
  const int interruptPin2 = 3;
  bool state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
    pinMode(interruptPin2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin2), eye, FALLING);

}

void loop() {
 digitalWrite(ledPin, state);
}

void blink() {
  state = 1;
}

void eye() {
  state = 0;
}