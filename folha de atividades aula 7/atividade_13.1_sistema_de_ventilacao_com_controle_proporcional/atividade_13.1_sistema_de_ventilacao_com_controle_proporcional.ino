int led = 9;
int tmp = A0;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
 int leitura = analogRead(tmp);
 int luzled = map(leitura, 20, 135, 0, 255);
 luzled = constrain(luzled, 0, 255);
  analogWrite(led, luzled);
}