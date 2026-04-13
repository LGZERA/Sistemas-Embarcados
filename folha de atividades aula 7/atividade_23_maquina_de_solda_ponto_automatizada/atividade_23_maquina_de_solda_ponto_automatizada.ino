int led = 8;
int led2 = 9;
int led3 = 10;

int bot = 2;
int estadobot = HIGH;

int pot = A0;

int tempoanterior = 0;
int etapa = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(bot, INPUT_PULLUP);

}

void loop()
{
  unsigned long tempo = millis();
  int botao = digitalRead(bot);
  int valorPot = analogRead(pot);
  int luzled = map(valorPot, 0, 1023, 0, 255);

  if (botao == LOW && estadobot == HIGH){
    etapa = 1;
  }
  estadobot = botao;
  
  if (etapa == 1) {
    if (tempo - tempoanterior >= 800) {
      tempoanterior = tempo;
	     etapa = 2;
      digitalWrite(led, HIGH);

    }
  }
  if (etapa == 2) {
     if (tempo - tempoanterior >= 200){
        tempoanterior = tempo;

       analogWrite(led2, luzled);
       etapa = 3;
   }    
}
    if (etapa == 3) {
	 if (tempo - tempoanterior >= 1500){
       analogWrite(led2, LOW);
       tempoanterior = tempo;
       etapa = 4;
     }
    }    
       if (etapa == 4) {
     if (tempo - tempoanterior >= 500){
        analogWrite(led, LOW);
       tempoanterior = tempo;
       etapa = 5;
     }
       }
  		if (etapa == 5) {
         digitalWrite(led3, HIGH);
         etapa = 6;
        }

	  if(etapa == 6){
      if (tempo - tempoanterior >= 2000){
       digitalWrite(led3, LOW);
      }
      }
}
