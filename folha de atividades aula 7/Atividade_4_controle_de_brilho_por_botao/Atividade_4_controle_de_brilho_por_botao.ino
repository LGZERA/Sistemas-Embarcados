int led = 3;
int botao = 4;
int nivel = 0;
int estadoAnterior = HIGH;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  int leitura = digitalRead(botao);
  
  if (leitura == LOW && estadoAnterior == HIGH) {
  	nivel++;
      if(nivel > 4){
      nivel = 0;  
}
  }
    estadoAnterior = leitura;
  
    
    if(nivel == 0) analogWrite(led, 0);
    if(nivel == 1) analogWrite(led, 64);
    if(nivel == 2) analogWrite(led, 128);
    if(nivel == 3) analogWrite(led, 192);
    if(nivel == 4) analogWrite(led, 255);
}

