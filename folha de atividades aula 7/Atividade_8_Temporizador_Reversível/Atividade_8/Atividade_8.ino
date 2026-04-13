int led = 13;
int botaoA = 3;
int botaoB = 4;
bool estadoled = false;
int tempoinicial = 0;
int intervalo = 5000;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
 pinMode(botaoB, INPUT_PULLUP);

}

void loop()
{
 unsigned long tempoatual = millis();
  int estadoatualA = digitalRead(botaoA);
  int estadoatualB = digitalRead(botaoB);

  
  if(estadoatualA == LOW && !estadoled){
    digitalWrite(led, HIGH);
    tempoinicial = tempoatual;
	estadoled = true;
    estadoled = led;
  }
  
  if(estadoled && (tempoatual - tempoinicial >= intervalo)){
    digitalWrite(led, LOW);
    estadoled = false;
  }  
  
 if(estadoled && estadoatualB == LOW){
  digitalWrite(led, LOW);
   estadoled = false;

 }
}
