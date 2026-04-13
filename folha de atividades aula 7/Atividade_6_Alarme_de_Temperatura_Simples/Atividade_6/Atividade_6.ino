int led4 = 13;
int sensor = A0;

int referencia = 350; // valor aproximado pra ~40°C

unsigned long tempo = 0;
int intervalo = 100;
bool estadoLed = false;

void setup()
{
  pinMode(led4, OUTPUT);
}

void loop()
{
  int leitura = analogRead(sensor);

  if(leitura > referencia){
    if(millis() - tempo >= intervalo){
      tempo = millis();
      estadoLed = !estadoLed;
      digitalWrite(led4, estadoLed);
    }
  } else {
    digitalWrite(led4, LOW);
  }
}
