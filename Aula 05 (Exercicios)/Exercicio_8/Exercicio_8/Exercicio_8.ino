const int leds[] = {2, 3, 4, 5};
const int botao1 = 6; 
const int botao2 = 7; 

int indice = 0;
int direcao = 1; 
bool rodando = true;

bool estado1, ultimo1 = HIGH;
bool estado2, ultimo2 = HIGH;

unsigned long ultimoTempo = 0;
const unsigned long intervalo = 300;

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
    direcao = -direcao;
  }

  if (ultimo2 == HIGH && estado2 == LOW) {
    rodando = !rodando;
  }

  if (rodando && millis() - ultimoTempo >= intervalo) {
    ultimoTempo = millis();

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    digitalWrite(leds[indice], HIGH);

    indice += direcao;

    if (indice > 3) indice = 0;
    if (indice < 0) indice = 3;
  }

  ultimo1 = estado1;
  ultimo2 = estado2;
}
