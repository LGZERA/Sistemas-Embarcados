int botao_start = 2;
int botao_stop = 3;

int M1 = 4;

int C1 = 5;
int C2 = 6;

int S4 = A0; 
int S5 = A1; 
int S6 = A2; 

int lampada = 7;

int fase = 0;

void setup() {

  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(M1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);

  pinMode(lampada, OUTPUT);

  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
}

void loop() {

  int start = digitalRead(botao_start);
  int stop = digitalRead(botao_stop);

  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);
  int s6 = digitalRead(S6);

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

    if(s4 == 1){
      fase = 2;
    }

    if(s6 == 1){
      fase = 3;
    }
  }

  if(fase == 2){
    digitalWrite(C2, HIGH);

    if(s5 == 1){
      fase = 3;
    }
  }

  if(fase == 3){
    digitalWrite(M1, LOW);
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);

    fase = 0;
  }
}