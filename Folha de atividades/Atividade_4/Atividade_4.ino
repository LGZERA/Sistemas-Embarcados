int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
  
int etapa = 0;
int tempoanterior = 0;
unsigned long tempoatual = 0;
int intervalo = 500;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);       
  pinMode(led4, OUTPUT);
}

void loop()
{
  tempoatual = millis();
  if (tempoatual - tempoanterior >= intervalo){
  tempoanterior = tempoatual;
 
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
    
   	if (etapa == 0) digitalWrite(led1, HIGH);
    if (etapa == 1) digitalWrite(led2, HIGH);
    if (etapa == 2) digitalWrite(led3, HIGH);
    if (etapa == 3) digitalWrite(led4, HIGH);

    etapa++;

    if (etapa > 3) etapa = 0;
  }
}