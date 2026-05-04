const int leds[5] = {3,4,5,6,7};

void setup() {
  for(int i = 0; i < 5; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 5; i++){
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }
}