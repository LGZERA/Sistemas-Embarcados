int led1 = 3;
int led2 = 5; 
int led3 = 6;
int led4 = 9; 
int botao = 2;
int estadoSistema = 0; 
unsigned long tempoInicio = 0;
unsigned long tempoAnterior = 0;

int ultimoEstadoBotao = HIGH;

bool alterna = false;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leitura = digitalRead(botao);
  unsigned long tempoAtual = millis();

  if (leitura == LOW && ultimoEstadoBotao == HIGH && estadoSistema == 0) {
    estadoSistema = 1;
    tempoInicio = tempoAtual;
  }

  ultimoEstadoBotao = leitura;

  if (estadoSistema == 1) {
    digitalWrite(led1, HIGH);

    if (tempoAtual - tempoInicio >= 4000) {
      digitalWrite(led1, LOW);
      estadoSistema = 2;
      tempoInicio = tempoAtual;
    }
  }

  else if (estadoSistema == 2) {

    if (tempoAtual - tempoAnterior >= 500) {
      tempoAnterior = tempoAtual;
      alterna = !alterna;

      if (alterna) {
        analogWrite(led2, 127);
        analogWrite(led3, 0);
      } else {
        analogWrite(led2, 0);
        analogWrite(led3, 127); 
      }
    }

    if (tempoAtual - tempoInicio >= 8000) {
      analogWrite(led2, 0);
      analogWrite(led3, 0);
      estadoSistema = 3;
      tempoInicio = tempoAtual;
    }
  }

  else if (estadoSistema == 3) {
    digitalWrite(led4, HIGH);

    if (tempoAtual - tempoInicio >= 4000) {
      digitalWrite(led4, LOW);
      estadoSistema = 0;
    }
  }
}

