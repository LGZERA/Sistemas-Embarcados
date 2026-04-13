int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int botao1 = 7;
int botao2 = 8;
unsigned long tempoinicial = 0;
int intervalo = 1000;
int estadoA = HIGH;
int estadoB = HIGH;
int contador = 0;
bool ativo = false; 

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop()
{
  unsigned long tempoatual = millis();
  int leituraA = digitalRead(botao1);
  int leituraB = digitalRead(botao2);
  
  if(leituraA == LOW && estadoA == HIGH){
    contador = 0;
    ativo = true;
  }
  estadoA = leituraA; 
  
  if(leituraB == LOW && estadoB == HIGH){
    contador = 0;
    ativo = false;

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  estadoB = leituraB; 
  
  if(ativo && tempoatual - tempoinicial >= intervalo){
    tempoinicial = tempoatual;
    contador++;
  }   
  
  if(contador > 4){
    contador = 4;
  }
  
  if(contador == 0){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  if(contador == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);       
  }
    
  if(contador == 2){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW); 
  }
    
  if(contador == 3){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW); 
  }
    
  if(contador == 4){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH); 
  }
}
  
