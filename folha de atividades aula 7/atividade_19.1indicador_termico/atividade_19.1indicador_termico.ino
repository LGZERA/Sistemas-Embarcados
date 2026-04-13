int led1 = 3; 
int led2 = 5; 
int led3 = 6; 

int pot = A0; 
int ntc = A1; 
int botao = 2;

bool sistemaLigado = false;
int estadoBotao = HIGH;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leituraBotao = digitalRead(botao);

  if (leituraBotao == LOW && estadoBotao == HIGH) {
    sistemaLigado = !sistemaLigado;
  }

  estadoBotao = leituraBotao;

  if (sistemaLigado) {

    int nivel = analogRead(pot);
    int temperatura = analogRead(ntc);

    if (nivel < 400) {
      digitalWrite(led1, HIGH); 
    } else if (nivel > 700) {
      digitalWrite(led1, LOW); 
    }

    if (temperatura < 400) {
      analogWrite(led2, 200); 
      digitalWrite(led3, LOW); 
    } 
    else if (temperatura > 700) {
      analogWrite(led2, 0); 
      digitalWrite(led3, HIGH); 
    } 
    else {
      analogWrite(led2, 0); 
      digitalWrite(led3, LOW);
    }

  } else {
    digitalWrite(led1, LOW);
    analogWrite(led2, 0);
    digitalWrite(led3, LOW);
  }
}
