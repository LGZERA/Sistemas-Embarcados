int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int botao1 = 7;
int botao2 = 8;

unsigned long tempoatual = 0;
unsigned long tempoanterior = 0;
int intervalo = 300;

int estadobotao1 = HIGH;
int estadobotao2 = HIGH;

bool estadoled1 = 0;
bool estadoled2 = 0;
bool estadoled3 = 0;
bool estadoled4 = 0;

bool desligado = false; // controle geral

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);		
}

void loop() {
  tempoatual = millis();

  int estadoatualdobotao1 = digitalRead(botao1);
  int estadoatualdobotao2 = digitalRead(botao2);

  // BOTÃO 1 → liga sistema e alterna grupo
  if (estadoatualdobotao1 == LOW && estadobotao1 == HIGH) {
    desligado = false;
    estadoled1 = !estadoled1;
    estadoled3 = !estadoled3;
  }

  // BOTÃO 2 → desliga tudo
  if (estadoatualdobotao2 == LOW && estadobotao2 == HIGH) {
    desligado = true;
  }

  // CONTROLE PRINCIPAL
  if (!desligado) {
    if (tempoatual - tempoanterior >= intervalo) {
      tempoanterior = tempoatual;

      estadoled1 = !estadoled1;
      estadoled2 = !estadoled2;
      estadoled3 = !estadoled3;
      estadoled4 = !estadoled4;
    }
  } else {
    // força tudo desligado
    estadoled1 = 0;
    estadoled2 = 0;
    estadoled3 = 0;
    estadoled4 = 0;
  }

  // Atualiza LEDs
  digitalWrite(led1, estadoled1);
  digitalWrite(led2, estadoled2);
  digitalWrite(led3, estadoled3);
  digitalWrite(led4, estadoled4);

  // Atualiza estado dos botões
  estadobotao1 = estadoatualdobotao1;
  estadobotao2 = estadoatualdobotao2;
}