int led = 3;
int botao = 5;
unsigned long tempoatual = 0;
int inicial = 0;
int intervalo = 500;
int estadobotao = HIGH;
bool estadoled = 0;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
 int estadoatualbotao = digitalRead(botao);
	 tempoatual = millis();

 if (estadoatualbotao == LOW && estadobotao == HIGH){
   if (tempoatual - inicial >= intervalo){
    inicial = tempoatual;
    estadoled = !estadoled;
    digitalWrite(led, estadoled);    
  }
  }   
    estadobotao = estadoatualbotao;
}

