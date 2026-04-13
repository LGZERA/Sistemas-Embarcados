int ledverde = 4;
int ledamarelo = 5;
int ledazul = 6;
int ledvermelho = 7;
int pot = A0;

unsigned long tempoErro = 0;
bool emErro = false;

void setup()
{
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
}

void loop()
{
  int leitura = analogRead(pot);
  unsigned long tempoAtual = millis();

  if (leitura >= 859 && leitura <= 941) {
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledazul, LOW);
  }
  else if (leitura < 859) {
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarelo, HIGH);
    digitalWrite(ledazul, LOW);
  }
  else {
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledazul, HIGH);
  }

  if (leitura < 736 || leitura > 982) {

    if (!emErro) {
      tempoErro = tempoAtual;
      emErro = true;
    }

    if (tempoAtual - tempoErro >= 2000) {
      digitalWrite(ledvermelho, HIGH);
    }

  } else {
    emErro = false;
    digitalWrite(ledvermelho, LOW);
  }
}
