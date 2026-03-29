const int leds[] = {2, 3, 4, 5}; 
const int botao1 = 6;
const int botao2 = 7;

bool modoEfeito = false;

bool estado1, ultimo1 = HIGH;
bool estado2, ultimo2 = HIGH;

unsigned long ultimoTempo = 0;
const unsigned long intervalo = 300;

bool alterna = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);

  if (ultimo1 == HIGH && estado1 == LOW) {
    modoEfeito = true;
  }

  if (ultimo2 == HIGH && estado2 == LOW) {
    modoEfeito = false;

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }
  }

  if (modoEfeito) {
    if (millis() - ultimoTempo >= intervalo) {
      ultimoTempo = millis();
      alterna = !alterna;

      if (alterna) {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[3], LOW);
      } else {
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[3], HIGH);
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[2], LOW);
      }
    }
  }

  ultimo1 = estado1;
  ultimo2 = estado2;
}
