const int leds[3] = {3, 4, 5}; 

int tempos[3] = {3000, 1000, 2000};

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 3; i++){
    
    for(int j = 0; j < 3; j++){
      digitalWrite(leds[j], LOW);
    }

    digitalWrite(leds[i], HIGH);

    delay(tempos[i]);
  }
}
