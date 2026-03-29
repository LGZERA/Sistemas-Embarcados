const int led1 = 5;
const int botao = 2;

bool estadoLed = false;

int estadoBotao;
int ultimoEstadoBotao = HIGH;
int estadoEstavel = HIGH;

unsigned long ultimoTempo = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  int leitura = digitalRead(botao);

 
  if (leitura != ultimoEstadoBotao) {
    ultimoTempo = millis();
  }

  if ((millis() - ultimoTempo) > debounceDelay) {

    if (leitura != estadoEstavel) {
      estadoEstavel = leitura;

      if (estadoEstavel == HIGH) {
        estadoLed = !estadoLed;
        digitalWrite(led1, estadoLed);
      }
    }
  }

  ultimoEstadoBotao = leitura;
}