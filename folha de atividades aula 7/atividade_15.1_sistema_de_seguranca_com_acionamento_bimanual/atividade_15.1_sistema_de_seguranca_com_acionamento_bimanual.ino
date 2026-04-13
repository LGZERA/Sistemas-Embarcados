int led = 3;
int botao1 = 4;
int botao2 = 5;

int estadoA = HIGH;
int estadoB = HIGH;

unsigned long tempoPrimeiro = 0;
int pressionar = 0;
int primeiroBotao = 0; // 0 = nenhum, 1 = A, 2 = B

int intervalo = 500;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop()
{
  int leituraA = digitalRead(botao1);
  int leituraB = digitalRead(botao2);
  unsigned long tempo = millis();

  // Botão A
  if (leituraA == LOW && estadoA == HIGH) {

    // evita contar A duas vezes
    if (primeiroBotao != 1) {
      pressionar++;

      if (pressionar == 1) {
        primeiroBotao = 1;
        tempoPrimeiro = tempo;
      }
    }
  }

  // Botão B
  if (leituraB == LOW && estadoB == HIGH) {

    // evita contar B duas vezes
    if (primeiroBotao != 2) {
      pressionar++;

      if (pressionar == 1) {
        primeiroBotao = 2;
        tempoPrimeiro = tempo;
      }
    }
  }

  // Só liga se forem 2 cliques de botões diferentes
  if (pressionar == 2 && (tempo - tempoPrimeiro <= intervalo)) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  // Reset
  if (tempo - tempoPrimeiro > intervalo) {
    pressionar = 0;
    primeiroBotao = 0;
  }

  estadoA = leituraA;
  estadoB = leituraB;
}
