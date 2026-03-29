const int leds[] = {2, 3, 4, 5}; 
const int botao = 6;

int contador = 0;
bool estadoBotao;
bool ultimoEstado = HIGH;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  estadoBotao = digitalRead(botao);

  if (ultimoEstado == HIGH && estadoBotao == LOW) {
    contador++;

    if (contador > 15) {
      contador = 0;
    }
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], (contador >> i) & 1);
  }

  ultimoEstado = estadoBotao;
}