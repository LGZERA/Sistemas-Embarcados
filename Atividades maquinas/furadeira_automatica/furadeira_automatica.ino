int botao_start = 2;

int M1l = 3;

int C1l = 4;
int C2l = 5;

int S1l = A0;
int S2l = A1;
int S3l = A2;

int lampadal = 6;

int fase = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);

  pinMode(M1l, OUTPUT);
  pinMode(C1l, OUTPUT);
  pinMode(C2l, OUTPUT);

  pinMode(lampadal, OUTPUT);

  pinMode(S1l, INPUT);
  pinMode(S2l, INPUT);
  pinMode(S3l, INPUT);
}

void loop() {

  int start = digitalRead(botao_start);

  int s1 = digitalRead(S1l);
  int s2 = digitalRead(S2l);
  int s3 = digitalRead(S3l);

  if(fase > 0){
    digitalWrite(lampadal, HIGH);
  } else {
    digitalWrite(lampadal, LOW);
  }

  if(start == LOW && fase == 0){
    fase = 1;
  }

  if(fase == 1){
    digitalWrite(C1l, HIGH);

    if(s1 == 1){
      fase = 2;
    }
  }

  if(fase == 2){
    digitalWrite(M1l, HIGH);
    fase = 3;
  }

  if(fase == 3){
    digitalWrite(C2l, HIGH);

    if(s2 == 1){
      fase = 4;
    }
  }

  if(fase == 4){
    digitalWrite(C2l, LOW);

    if(s3 == 1){
      fase = 5;
    }
  }

  if(fase == 5){
    digitalWrite(M1l, LOW);
    digitalWrite(C1l, LOW);

    fase = 0;
  }
}
