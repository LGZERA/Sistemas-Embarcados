int led = 13;
int pot = A0;
int valor = 0;

unsigned long tempo = 0;
int intervalo = 200;
bool estadoLed = false;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  valor = analogRead(pot);

  if(valor <= 409){
    digitalWrite(led, LOW);
  }

  else if(valor > 409 && valor < 818){
    if(millis() - tempo >= intervalo){
      tempo = millis();
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }

  else{
    digitalWrite(led, HIGH);
  }
}
