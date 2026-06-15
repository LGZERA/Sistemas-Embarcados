int botao_start = 2;
int botao_stop = 3;

int M1l = 4;

int C1l = 5;
int C2l = 6;
int C3l = 7;

int S1l = A0;
int S2l = A1;
int S3l = A2;
int S4l = A3;

int lampadal = 8;

int fase = 0;

unsigned long tempo = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(M1l, OUTPUT);

  pinMode(C1l, OUTPUT);
  pinMode(C2l, OUTPUT);
  pinMode(C3l, OUTPUT);

  pinMode(lampadal, OUTPUT);

  pinMode(S1l, INPUT);
  pinMode(S2l, INPUT);
  pinMode(S3l, INPUT);
  pinMode(S4l, INPUT);
}

void loop() {

  int start = digitalRead(botao_start);
  int stop = digitalRead(botao_stop);

  int s1 = digitalRead(S1l);
  int s2 = digitalRead(S2l);
  int s3 = digitalRead(S3l);
  int s4 = digitalRead(S4l);

  if(fase > 0){
    digitalWrite(lampadal, HIGH);
  } else {
    digitalWrite(lampadal, LOW);
  }

  if(stop == LOW){
    fase = 0;
    digitalWrite(M1l, LOW);
    digitalWrite(C1l, LOW);
    digitalWrite(C2l, LOW);
    digitalWrite(C3l, LOW);
  }

  if(start == LOW && fase == 0){
    fase = 1;
  }

  if(fase == 1){
    digitalWrite(M1l, HIGH);

    if(s4 == 1){
      digitalWrite(M1l, LOW);
      fase = 2;
    }
  }

  if(fase == 2){
    digitalWrite(C1l, HIGH);

    if(s1 == 1){
      tempo = millis();
      fase = 3;
    }
  }

  if(fase == 3){
    if(millis() - tempo >= 2000){
      digitalWrite(C3l, HIGH);

      if(s3 == 1){
        tempo = millis();
        fase = 4;
      }
    }
  }

  if(fase == 4){
    if(millis() - tempo >= 2000){
      digitalWrite(C2l, HIGH);

      if(s2 == 1){
        fase = 5;
      }
    }
  }

  if(fase == 5){
    digitalWrite(C1l, LOW);
    digitalWrite(C2l, LOW);
    digitalWrite(C3l, LOW);

    fase = 0;
  }
}
