int botao_start = 2;
int botao_stop = 3;

int M1l = 4;

int C1l = 5;

int S1l = A0;
int S2l = A1;
int S3l = A2;

int V1l = 6;

int lampadal = 7;

int fase = 0;

unsigned long tempo = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(M1l, OUTPUT);
  pinMode(C1l, OUTPUT);
  pinMode(V1l, OUTPUT);

  pinMode(lampadal, OUTPUT);

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

  if(stop == LOW){
    fase = 0;
    digitalWrite(M1l, LOW);
    digitalWrite(C1l, LOW);
    digitalWrite(V1l, LOW);
  }

  if(start == LOW && fase == 0){
    fase = 1;
  }

  if(fase == 1){
    digitalWrite(M1l, HIGH);
    digitalWrite(C1l, HIGH);

    if(s1 == 1){
      digitalWrite(C1l, LOW);
      fase = 2;
    }
  }

  if(fase == 2){
    if(s2 == 1){
      digitalWrite(M1l, LOW);
      digitalWrite(V1l, HIGH);
      tempo = millis();
      fase = 3;
    }
  }

  if(fase == 3){
    if(millis() - tempo >= 5000){
      digitalWrite(V1l, LOW);
      digitalWrite(M1l, HIGH);
      fase = 4;
    }
  }

  if(fase == 4){
    if(s3 == 1){
      digitalWrite(M1l, LOW);
      digitalWrite(C1l, LOW);
      fase = 0;
    }
  }
}
