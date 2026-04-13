int led = 3;
int botao = 2;

int estadoBotao = HIGH;

bool cicloAtivo = false;

unsigned long tempoInicio = 0;
unsigned long duracao = 5000; 

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leitura = digitalRead(botao);
  unsigned long tempoAtual = millis();

  if (leitura == LOW && estadoBotao == HIGH) {
    cicloAtivo = true;
    tempoInicio = tempoAtual;
  }

  if (cicloAtivo) {
    digitalWrite(led, HIGH);

    if (tempoAtual - tempoInicio >= duracao) {
      digitalWrite(led, LOW);
      cicloAtivo = false;
    }
  }

  estadoBotao = leitura;
}