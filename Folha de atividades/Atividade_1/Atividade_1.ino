int led = 3;

unsigned long tempoatual = 0;
int intervalo = 500;
int tempoanterior = 0;
bool estadoled = false;

  void setup(){
  
  pinMode(led, OUTPUT);
  
}

void loop(){
  
 	 tempoatual = millis();
  
	if (tempoatual - tempoanterior >= intervalo){
   	tempoanterior = tempoatual;
      
    estadoled = !estadoled;
    digitalWrite(led, estadoled);   
	}
}
