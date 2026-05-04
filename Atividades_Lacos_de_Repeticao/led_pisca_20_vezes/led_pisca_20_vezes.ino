int led = 3;
unsigned long ultimotempo = 0;
int intervalo = 500;

bool estadoled = false;
int i = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long tempoatual = millis();

  for(; i < 40; ) { 
    if (tempoatual - ultimotempo >= intervalo) {
      ultimotempo = tempoatual;

      estadoled = !estadoled;
      digitalWrite(led, estadoled);

      i++; 
    }
    break; 
  }
}
