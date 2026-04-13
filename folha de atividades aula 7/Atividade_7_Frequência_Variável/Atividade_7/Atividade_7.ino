int led1 = 13;
int potenciometro = A0;
int tempoinicial = 0;
int intervalo1 = 2000;
int intervalo2 = 100;
bool estadoled = false;

void setup()
{
  pinMode(led1, OUTPUT);
}

void loop()
{
  	unsigned long leitura = analogRead(potenciometro);
	unsigned long tempoatual = millis();
  	if(tempoatual - tempoinicial >= intervalo1){

      if(leitura < 10){
        digitalWrite(led1, !estadoled);
        estadoled = !estadoled;
        
       tempoinicial = tempoatual;

}
      
    }
	
 	if(leitura >= 1023){
       
  	if(tempoatual - tempoinicial >= intervalo2){

		digitalWrite(led1, !estadoled);
        estadoled = !estadoled;
	  	tempoinicial = tempoatual;

}
    }
}

