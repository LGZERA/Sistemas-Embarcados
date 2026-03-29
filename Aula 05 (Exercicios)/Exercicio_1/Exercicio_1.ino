const int led1 = 5;
unsigned long tempoanterior = 0;
const unsigned long intervalo = 500;
bool estadoLed = false;

void setup() {
  pinMode(led1, OUTPUT);   
}

void loop() {
  unsigned long tempoatual = millis();

  if (tempoatual - tempoanterior >= intervalo) {
    tempoanterior = tempoatual;
    
    estadoLed = !estadoLed;              // inverte o estado
    digitalWrite(led1, estadoLed);     // aplica no LED
  }
}
