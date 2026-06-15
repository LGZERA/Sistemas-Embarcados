int botao_start = 2;
int botao_stop = 3;

int esteira_chapa = 4;
int esteira_caixa = 5;

int cilindro = 6;

int sensor_S2 = A0;
int sensor_S3 = A1;

int lampada = 7;

int fase = 0;
int contador = 0;

unsigned long tempo_anterior = 0;
int intervalo = 1000; 

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(esteira_chapa, OUTPUT);
  pinMode(esteira_caixa, OUTPUT);
  pinMode(cilindro, OUTPUT);
  pinMode(lampada, OUTPUT);

  pinMode(sensor_S2, INPUT);
  pinMode(sensor_S3, INPUT);
}

void loop() {

  unsigned long tempo = millis();

  int start = digitalRead(botao_start);
  int stop = digitalRead(botao_stop);

  int S2 = digitalRead(sensor_S2);
  int S3 = digitalRead(sensor_S3);

  if(fase > 0){
    digitalWrite(lampada, HIGH);
  } else {
    digitalWrite(lampada, LOW);
  }

  if(stop == LOW){
    fase = 0;
    digitalWrite(esteira_chapa, LOW);
    digitalWrite(esteira_caixa, LOW);
    digitalWrite(cilindro, LOW);
  }

  if(start == LOW && fase == 0){
    fase = 1;
    contador = 0;
  }

  if(fase == 1){

    if(S2 == 0){
      digitalWrite(esteira_chapa, HIGH);
    } else {
      digitalWrite(esteira_chapa, LOW);
    }

    if(S3 == 0){
      digitalWrite(esteira_caixa, HIGH);
    } else {
      digitalWrite(esteira_caixa, LOW);
    }

    if(S2 == 1 && S3 == 1){
      fase = 2;
    }
  }

  if(fase == 2){

    if(tempo_anterior == 0){
      tempo_anterior = tempo;
      digitalWrite(cilindro, HIGH);
    }

    if(tempo - tempo_anterior >= intervalo){
      digitalWrite(cilindro, LOW); 
      tempo_anterior = 0;
      contador++;

      if(contador >= 5){
        fase = 3;
      }
    }
  }

  if(fase == 3){

    if(S3 == 0){
      digitalWrite(esteira_caixa, HIGH);
    } else {
      digitalWrite(esteira_caixa, LOW);
      fase = 0; 
    }
  }
}
