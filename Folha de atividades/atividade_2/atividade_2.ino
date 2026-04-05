int led = 3;
int botao = 5;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop(){
 int estadodobotao = digitalRead(botao);
  if (estadodobotao == LOW)
    digitalWrite(led, HIGH);


else 
    digitalWrite(led, LOW);
}

