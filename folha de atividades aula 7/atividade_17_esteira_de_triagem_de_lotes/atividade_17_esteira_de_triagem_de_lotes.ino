int led1 = 6; // esteira
int botaoA = 3;
int botaoB = 4;

int estadoA = HIGH;
int estadoB = HIGH;

int caixas = 0;

bool rodando = false;
bool pausado = false;

unsigned long tempo = 0;
int intervalo = 3000;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
}

void loop()
{
  int leituraA = digitalRead(botaoA);
  int leituraB = digitalRead(botaoB);

  // BOTÃO A → start/reset
  if(leituraA == LOW && estadoA == HIGH){
    caixas = 0;
    rodando = true;
    pausado = false;
  }
  estadoA = leituraA;

  // CONTAGEM DE CAIXAS (botão B)
  if(leituraB == LOW && estadoB == HIGH && rodando && !pausado){
    caixas++;

    // a cada 5 caixas → pausa
    if(caixas % 5 == 0 && caixas < 20){
      pausado = true;
      tempo = millis();
    }
  }
  estadoB = leituraB;

  // PAUSA DE 3s
  if(pausado){
    digitalWrite(led1, LOW);

    if(millis() - tempo >= intervalo){
      pausado = false;
    }
  }

  // PARADA FINAL (20 caixas)
  if(caixas >= 20){
    rodando = false;
    digitalWrite(led1, LOW);
  }

  // ESTEIRA RODANDO
  if(rodando && !pausado){
    digitalWrite(led1, HIGH);
  }
}