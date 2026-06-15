int botao_start = 2;
int botao_stop = 3;

int M1l = 4;
int M2l = 5;

int S1l = A0;
int S2l = A1;
int S3l = A2;

int lampadal = 6;
int limite5l = 7;

int fase = 0;
int contador = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(M1l, OUTPUT);
  pinMode(M2l, OUTPUT);

  pinMode(lampadal, OUTPUT);
  pinMode(limite5l, OUTPUT);

  pinMode(S1l, INPUT);
  pinMode(S2l, INPUT);
  pinMode(S3l, INPUT);
}

void loop() {

  int start = digitalRead(botao_start);
  int stop = digitalRead(botao_stop);

  int s1 = digitalRead(S1l);
  int s2 = digitalRead(S2l);
  int s3 = digitalRead(S3l);

  if(fase > 0){
    digitalWrite(lampadal, HIGH);
  } else {
    digitalWrite(lampadal, LOW);
  }

  if(contador >= 5){
    digitalWrite(limite5l, HIGH);
  } else {
    digitalWrite(limite5l, LOW);
  }

  if(stop == LOW){
    fase = 0;
    contador = 0;
    digitalWrite(M1l, LOW);
    digitalWrite(M2l, LOW);
  }

  if(start == LOW && fase == 0 && contador < 5){
    fase = 1;
  }

  if(fase == 1){
    if(s1 == 1){
      digitalWrite(M1l, HIGH);
      fase = 2;
    }
  }

  if(fase == 2){
    if(s2 == 1){
      digitalWrite(M1l, LOW);
      digitalWrite(M2l, HIGH);
      fase = 3;
    }
  }

  if(fase == 3){
    if(s3 == 1){
      digitalWrite(M2l, LOW);
      contador++;
      fase = 0;
    }
  }
}
