int led = 9;
int botaoMais = 3;
int botaoMenos = 5;

int velocidade = 0;

int estadoMais = HIGH;
int estadoMenos = HIGH;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botaoMais, INPUT_PULLUP);
  pinMode(botaoMenos, INPUT_PULLUP);
}

void loop()
{
  int leituraMais = digitalRead(botaoMais);
  int leituraMenos = digitalRead(botaoMenos);

  if (leituraMais == LOW && estadoMais == HIGH) {
    velocidade += 25;

    if (velocidade > 255) {
      velocidade = 255;
    }
  }

  if (leituraMenos == LOW && estadoMenos == HIGH) {
    velocidade -= 25;

    if (velocidade < 0) {
      velocidade = 0;
    }
  }

  analogWrite(led, velocidade);

  estadoMais = leituraMais;
  estadoMenos = leituraMenos;
}
