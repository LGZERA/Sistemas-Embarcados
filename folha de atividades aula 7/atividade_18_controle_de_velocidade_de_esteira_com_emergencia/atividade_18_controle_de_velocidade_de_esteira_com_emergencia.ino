int led1 = 3;
int led2 = 4;
int botao = 5;
int pot = A0;
int estadobotao = HIGH;
int valor_sensor = 0;
bool ledLigado = true;
unsigned long tempoAnterior = 0;
int intervalo = 100;
bool estadoLed = false;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(pot, INPUT);


}

void loop()
{
    unsigned long tempoAtual = millis();

  	int leitura = digitalRead(botao);
	int valorsensor = analogRead(pot);
	int luzled = map(valorsensor, 0, 1023, 0, 255);
 
  if(leitura == LOW && estadobotao == HIGH){
	ledLigado = false;
  }
  if(ledLigado == true){
    analogWrite(led1, luzled);
}
   if(ledLigado == false &&(tempoAtual - tempoAnterior >= intervalo)){
  	  tempoAnterior = tempoAtual;
     estadoLed = !estadoLed;          
     digitalWrite(led1, LOW);
     digitalWrite(led2, estadoLed);

     
   } 
  
     
}