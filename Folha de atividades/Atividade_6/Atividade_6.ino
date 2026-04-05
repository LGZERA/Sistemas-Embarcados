int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int botaomais = 7;
int botaomenos = 8;

int conta = 0;
int ultimoestadobotao1 = HIGH;
int ultimoestadobotao2 = HIGH;

void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botaomais, INPUT_PULLUP);
  pinMode(botaomenos, INPUT_PULLUP);
  	digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);

}

void loop() {
  int estadodobotao1 =  digitalRead(botaomais);
  int estadodobotao2 =  digitalRead(botaomenos);

  if (conta < 15)
    if (estadodobotao1 == LOW && ultimoestadobotao1 == HIGH){
    conta++;
  }
  if (estadodobotao2 == LOW && ultimoestadobotao2 == HIGH){
   	 conta--; 
  }    
  if (conta < 0) conta = 0;
  if (conta > 15) conta = 15;
    
    ultimoestadobotao1 = estadodobotao1;
    ultimoestadobotao2 = estadodobotao2;

      digitalWrite(led1, conta & 1);
      digitalWrite(led2, (conta >> 1) & 1);
      digitalWrite(led3, (conta >> 2) & 1);
      digitalWrite(led4, (conta >> 3) & 1);
	}