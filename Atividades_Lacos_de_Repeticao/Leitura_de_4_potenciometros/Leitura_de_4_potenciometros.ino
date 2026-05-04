const int pots[4] = {A0, A1, A2, A3};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 4; i++){
    int leitura = analogRead(pots[i]);
    Serial.println(leitura);
  }
  delay(300);
}
