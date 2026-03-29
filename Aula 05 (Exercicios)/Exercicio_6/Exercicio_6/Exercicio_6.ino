const int leds[] = {2, 3, 4, 5}; 
const int botao = 6;
const int botao2 = 7;

int contador = 0;

bool estadoBotao;
bool estadoBotao2;

bool ultimoEstado = HIGH;
bool ultimoEstado2 = HIGH; 

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  estadoBotao = digitalRead(botao);
  estadoBotao2 = digitalRead(botao2);

  if (ultimoEstado == HIGH && estadoBotao == LOW) {
    if (contador < 15) {
      contador++;
    }
  }

  if (ultimoEstado2 == HIGH && estadoBotao2 == LOW) { 
    if (contador > 0) {
      contador--;
    }
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], (contador >> i) & 1);
  }

  ultimoEstado = estadoBotao;
  ultimoEstado2 = estadoBotao2;
}
