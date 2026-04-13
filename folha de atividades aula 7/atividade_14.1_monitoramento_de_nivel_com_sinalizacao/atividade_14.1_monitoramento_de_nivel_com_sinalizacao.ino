int led1 = 3;
int led2 = 4;
int led3 = 5;
int pot = A0;
bool estadoled = false;
bool alerta = false;
int tempoanterior = 0;
int intervalo = 500;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  unsigned long tempo = millis();
  int leitura = analogRead(pot);
  
  if(leitura >= 200 && leitura <= 400){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

}
  if(leitura > 400 && leitura <= 600){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  if(leitura > 600 && leitura <= 700){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  if(leitura > 700 || leitura < 200){
    if(tempo - tempoanterior >= intervalo){
      tempoanterior = tempo;
    digitalWrite(led1, estadoled);
    digitalWrite(led2, estadoled);
    digitalWrite(led3, estadoled);
    estadoled = !estadoled;
  }
}
}