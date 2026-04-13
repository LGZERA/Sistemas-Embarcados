int led1 = 3;
int led2 = 4;
int led3 = 5;

int pot = A0;

int limite = 700;

unsigned long tempoAnterior = 0;
int intervalo = 100; 

bool estadoLed = false;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  int leitura = analogRead(pot);
  unsigned long tempoAtual = millis();

  if (leitura > limite) {

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      estadoLed = !estadoLed;

      digitalWrite(led1, estadoLed);
      digitalWrite(led2, estadoLed);
      digitalWrite(led3, estadoLed);
    }

  }
  
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
