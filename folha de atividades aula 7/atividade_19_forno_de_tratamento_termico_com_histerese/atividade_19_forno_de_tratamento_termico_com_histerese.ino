int led1 = 13; 
int led2 = 9;  
int botao = 7;
int sensor = A0;

int estadobotao = HIGH;
bool sistemaLigado = false;
bool aquecendo = false;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leitura = digitalRead(botao);
  int temperatura = analogRead(sensor); 

  if (leitura == LOW && estadobotao == HIGH) {
    sistemaLigado = true;
    aquecendo = true;
  }

  if (sistemaLigado) {

    if (temperatura >= 160) {
      aquecendo = false;
    }

    if (temperatura <= 150) {
      aquecendo = true;
    }

    digitalWrite(led1, aquecendo);

    if (temperatura >= 150 && temperatura <= 160) {
      digitalWrite(led2, HIGH);
    } else {
      digitalWrite(led2, LOW);
    }
  }

  estadobotao = leitura;
}=