int leds[] = {3, 4, 5, 6};
int quantidade = 4;

int botao1 = 7;
int botao2 = 8;

unsigned long tempoInicial = 0;
int intervalo = 500;

int indice = 0;

int direcao = 1;     // controla sentido
bool rodando = true; // controla start/stop

int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;

void setup()
{
  for (int i = 0; i < quantidade; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop()
{
  unsigned long tempoAtual = millis();

  int leituraBotao1 = digitalRead(botao1);
  int leituraBotao2 = digitalRead(botao2);

  // BOTÃO 1 → inverte direção
  if (leituraBotao1 == LOW && estadoBotao1 == HIGH) {
    direcao = -direcao;
  }

  // BOTÃO 2 → start/stop
  if (leituraBotao2 == LOW && estadoBotao2 == HIGH) {
    rodando = !rodando;
  }

  // EXECUÇÃO DO EFEITO
  if (rodando && (tempoAtual - tempoInicial >= intervalo)) {
    tempoInicial = tempoAtual;

    // desliga todos
    for (int i = 0; i < quantidade; i++) {
      digitalWrite(leds[i], LOW);
    }

    // liga atual
    digitalWrite(leds[indice], HIGH);

    // atualiza índice
    indice += direcao;

    // controle de limites
    if (indice >= quantidade) {
      indice = 0;
    }
    if (indice < 0) {
      indice = quantidade - 1;
    }
  }

  // salva estado anterior dos botões
  estadoBotao1 = leituraBotao1;
  estadoBotao2 = leituraBotao2;
}