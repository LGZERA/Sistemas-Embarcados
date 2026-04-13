int potenciometro = A0;
int led3 = 13;

void setup()
{
  pinMode(led3, OUTPUT);
}

void loop()
{
  int soma = 0;

  for (int i = 0; i < 10; i++) {
    soma += analogRead(potenciometro);
    delay(50); 
  }

  int media = soma / 10;

  if (media > 700) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}

