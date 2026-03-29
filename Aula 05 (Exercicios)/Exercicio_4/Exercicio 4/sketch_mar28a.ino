const int leds[] = {2, 3, 4, 5}; 
const int totalLeds = 4;

int indiceAtual = 0;

unsigned long ultimoTempo = 0;
const unsigned long intervalo = 500; 
void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  if (millis() - ultimoTempo >= intervalo) {
    ultimoTempo = millis();

    
    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    
    digitalWrite(leds[indiceAtual], HIGH);

    
    indiceAtual++;
    if (indiceAtual >= totalLeds) {
      indiceAtual = 0; 
    }
  }
}