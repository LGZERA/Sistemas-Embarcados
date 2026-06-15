int Al = 2;
int Bl = 3;

int Rl = 4;

int lampadal = 5;

int fase = 0;

unsigned long tempo = 0;

void setup() {

  pinMode(Al, INPUT_PULLUP);
  pinMode(Bl, INPUT_PULLUP);

  pinMode(Rl, OUTPUT);
  pinMode(lampadal, OUTPUT);
}

void loop() {

  int a = digitalRead(Al);
  int b = digitalRead(Bl);

  if(fase > 0){
    digitalWrite(lampadal, HIGH);
  } else {
    digitalWrite(lampadal, LOW);
  }

  if(fase == 0){
    digitalWrite(Rl, LOW);

    if(a == LOW){
      tempo = millis();
      fase = 1;
    }

    if(b == LOW){
      tempo = millis();
      fase = 2;
    }
  }

  if(fase == 1){
    if(b == LOW && millis() - tempo <= 3000){
      digitalWrite(Rl, HIGH);
      fase = 3;
    }

    if(millis() - tempo > 3000){
      fase = 0;
    }
  }

  if(fase == 2){
    if(a == LOW && millis() - tempo <= 3000){
      digitalWrite(Rl, HIGH);
      fase = 3;
    }

    if(millis() - tempo > 3000){
      fase = 0;
    }
  }

  if(fase == 3){
    if(a == HIGH || b == HIGH){
      digitalWrite(Rl, LOW);
      tempo = millis();
      fase = 4;
    }
  }

  if(fase == 4){
    if(a == LOW && b == LOW && millis() - tempo <= 3000){
      digitalWrite(Rl, HIGH);
      fase = 3;
    }

    if(millis() - tempo > 3000){
      fase = 0;
    }
  }
}
