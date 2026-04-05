int led1 = 2;
int led2 = 3;
int led3 = 4;

int botao1 = 5;
int botao2 = 6;

int sequencia[3] = {1, 3, 2}; 
int tamanho = 3;

int entrada[3];
int indice = 0;

int fase = 0; 

unsigned long tempoanterior = 0;
unsigned long tempoatual = 0;
int intervalo = 600;

int ultimoBotao1 = HIGH;
int ultimoBotao2 = HIGH;

int contadorCliques = 0;
unsigned long tempoClique = 0;
int tempoMaxClique = 300;

int etapa = 0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop()
{
  tempoatual = millis();

 
  if (fase == 0) {
    if (tempoatual - tempoanterior >= intervalo) {
      tempoanterior = tempoatual;

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);

      if (sequencia[etapa] == 1) digitalWrite(led1, HIGH);
      if (sequencia[etapa] == 2) digitalWrite(led2, HIGH);
      if (sequencia[etapa] == 3) digitalWrite(led3, HIGH);

      etapa++;

      if (etapa >= tamanho) {
        etapa = 0;
        fase = 1;

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
      }
    }
  }

  
  if (fase == 1) {

    int leitura1 = digitalRead(botao1);
    int leitura2 = digitalRead(botao2);

    if (ultimoBotao1 == HIGH && leitura1 == LOW) {
      entrada[indice] = 1;
      indice++;

      digitalWrite(led1, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
    }

    if (ultimoBotao2 == HIGH && leitura2 == LOW) {
      contadorCliques++;
      tempoClique = millis();
    }

    if (contadorCliques > 0 && (millis() - tempoClique > tempoMaxClique)) {

      if (contadorCliques == 1) {
        entrada[indice] = 2;

        digitalWrite(led2, HIGH);
        delay(200);
        digitalWrite(led2, LOW);
      }

      if (contadorCliques == 2) {
        entrada[indice] = 3;

        digitalWrite(led3, HIGH);
        delay(200);
        digitalWrite(led3, LOW);
      }

      indice++;
      contadorCliques = 0;
    }

    ultimoBotao1 = leitura1;
    ultimoBotao2 = leitura2;

   
    if (indice == tamanho) {

      bool erro = false;

      for (int i = 0; i < tamanho; i++) {
        if (entrada[i] != sequencia[i]) {
          erro = true;
        }
      }

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);

      if (erro) {
        digitalWrite(led1, HIGH);
        delay(600);
        digitalWrite(led1, LOW);
      } else {
        
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(600);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
      }

    
      indice = 0;
      fase = 0;
    }
  }
}