int botao_start = 2;
int botao_stop = 3;

int M1 = 4;

int C1 = 5;
int C2 = 6;

int S1 = A0;
int S2 = A1;
int S3 = A2;
int S4 = A3;

int lampada = 7;

int fase = 0;

unsigned long tempo = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(M1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);

  pinMode(lampada, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
}

void loop() {

  int start = digitalRead(botao_start);
  int stop = digitalRead(botao_stop);

  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);

  if(fase > 0){
    digitalWrite(lampada, HIGH);
  } else {
    digitalWrite(lampada, LOW);
  }

  if(stop == LOW){
    fase = 0;
    digitalWrite(M1, LOW);
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);
  }

  if(start == LOW && fase == 0){
    fase = 1;
  }

  if(fase == 1){
    digitalWrite(M1, HIGH);
    digitalWrite(C1, HIGH);

    if(s1 == 1){
      digitalWrite(C1, LOW);
      fase = 2;
    }
  }

  if(fase == 2){
    if(s2 == 1){
      digitalWrite(M1, LOW);
      digitalWrite(C2, LOW);
      fase = 3;
      tempo = millis();
    }
  }

  if(fase == 3){
    if(s3 == 1){
      if(millis() - tempo >= 6000){
        digitalWrite(C2, HIGH);
        fase = 4;
      }
    }
  }

  if(fase == 4){
    digitalWrite(M1, HIGH);

    if(s4 == 1){
      digitalWrite(M1, LOW);
      fase = 5;
    }
  }

  if(fase == 5){
    if(s4 == 0){
      fase = 0;
    }
  }
}