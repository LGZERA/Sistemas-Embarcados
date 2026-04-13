int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int intervalo = 200;
unsigned long tempoatual = 0;
int tempoanterior = 0;
int indice = 0;
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
  
  if(tempoatual - tempoanterior >= intervalo){
     tempoanterior = tempoatual;

 	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
	
    if(indice == 0) digitalWrite(led1, HIGH);
    if(indice == 1) digitalWrite(led2, HIGH);
    if(indice == 2) digitalWrite(led3, HIGH);
    if(indice == 3) digitalWrite(led4, HIGH);
     
    indice++;
      
    if(indice > 3){
      indice = 0;
    }   
  }
}
