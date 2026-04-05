int leds[] = {3, 4, 5, 6};
int quantidade = 4;

int botao0 = 7;
int botao1 = 8;

int senha[4] = {1, 0, 1, 0};
int entrada[4];

int indice = 0;

unsigned long tempoAtual = 0;
unsigned long tempoAnterior = 0;

bool verificando = false;
bool correto = false;

int estadoBotao0 = HIGH;
int estadoBotao1 = HIGH;

int etapa = 0; // 0 = entrada, 1 = resultado

int piscaEstado = LOW;

void setup() {
  for (int i = 0; i < quantidade; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao0, INPUT_PULLUP);
  pinMode(botao1, INPUT_PULLUP);
}

void loop() {
  tempoAtual = millis();

  int leitura0 = digitalRead(botao0);
  int leitura1 = digitalRead(botao1);

  if (etapa == 0) {
    if (leitura0 == LOW && estadoBotao0 == HIGH) {
      entrada[indice] = 0;
      indice++;
    }

    if (leitura1 == LOW && estadoBotao1 == HIGH) {
      entrada[indice] = 1;
      indice++;
    }

    if (indice >= 4) {
      indice = 0;
      correto = true;

      for (int i = 0; i < 4; i++) {
        if (entrada[i] != senha[i]) {
          correto = false;
        }
      }

      etapa = 1;
      tempoAnterior = tempoAtual;
    }
  }

  if (etapa == 1) {
    if (correto) {
      for (int i = 0; i < quantidade; i++) {
        digitalWrite(leds[i], HIGH);
      }

      if (tempoAtual - tempoAnterior >= 2000) {
        for (int i = 0; i < quantidade; i++) {
          digitalWrite(leds[i], LOW);
        }
        etapa = 0;
      }
    } else {
      if (tempoAtual - tempoAnterior >= 200) {
        tempoAnterior = tempoAtual;
        piscaEstado = !piscaEstado;

        for (int i = 0; i < quantidade; i++) {
          digitalWrite(leds[i], piscaEstado);
        }
      }

      if (tempoAtual - tempoAnterior >= 2000) {
        for (int i = 0; i < quantidade; i++) {
          digitalWrite(leds[i], LOW);
        }
        etapa = 0;
      }
    }
  }

  estadoBotao0 = leitura0;
  estadoBotao1 = leitura1;
}