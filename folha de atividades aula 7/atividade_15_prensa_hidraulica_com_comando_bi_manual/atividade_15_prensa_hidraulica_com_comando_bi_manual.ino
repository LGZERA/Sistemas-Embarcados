int led1= 13;
int led2= 12;
int botao1 = 4;
int botao2 = 3;
int tempoanterior = 0;
unsigned long tempo = 0;
int intervalo = 2000;
bool passou = false;
int estadoA = HIGH;
int estadoB = HIGH;
void setup()
{
	pinMode(led1, OUTPUT);
  	pinMode(led2, OUTPUT);
 	 pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);

} 
void loop()
{
  int leituraA = digitalRead(botao1);
  int leituraB = digitalRead(botao2);
  tempo = millis();
  
  if(leituraA == LOW && estadoA == HIGH){
  if(passou == false){
    tempoanterior = millis(); 
  }
}

if(leituraB == LOW && estadoB == HIGH){
  if(millis() - tempoanterior <= intervalo){
    digitalWrite(led1, HIGH);
  } 
}

if(millis() - tempoanterior > intervalo){
  passou = true;
  digitalWrite(led2, HIGH);
  tempoanterior = 0;
}

estadoA = leituraA;
estadoB = leituraB;
}
