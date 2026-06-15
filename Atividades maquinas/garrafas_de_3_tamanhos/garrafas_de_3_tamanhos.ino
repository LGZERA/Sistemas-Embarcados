int Ll = 2;
int Dl = 3;

int Pl = 4;
int Ml = 5;
int Gl = 6;

int Al = A0;
int Bl = A1;
int Cl = A2;

int El = 7;
int ALl = 8;

int fase = 0;

void setup() {

  pinMode(Ll, INPUT_PULLUP);
  pinMode(Dl, INPUT_PULLUP);

  pinMode(Pl, INPUT_PULLUP);
  pinMode(Ml, INPUT_PULLUP);
  pinMode(Gl, INPUT_PULLUP);

  pinMode(Al, INPUT);
  pinMode(Bl, INPUT);
  pinMode(Cl, INPUT);

  pinMode(El, OUTPUT);
  pinMode(ALl, OUTPUT);
}

void loop() {

  int l = digitalRead(Ll);
  int d = digitalRead(Dl);

  int p = digitalRead(Pl);
  int m = digitalRead(Ml);
  int g = digitalRead(Gl);

  int a = digitalRead(Al);
  int b = digitalRead(Bl);
  int c = digitalRead(Cl);

  if(d == LOW){
    fase = 0;
    digitalWrite(El, LOW);
    digitalWrite(ALl, LOW);
  }

  if(l == LOW && fase == 0){
    fase = 1;
  }

  if(fase == 1){
    digitalWrite(El, HIGH);
    digitalWrite(ALl, LOW);

    if(g == LOW){
      if(a == 1 || b == 1){
        digitalWrite(El, LOW);
        digitalWrite(ALl, HIGH);
        fase = 2;
      }
    }

    if(m == LOW){
      if(a == 1 || c == 1){
        digitalWrite(El, LOW);
        digitalWrite(ALl, HIGH);
        fase = 2;
      }
    }

    if(p == LOW){
      if(b == 1 || c == 1){
        digitalWrite(El, LOW);
        digitalWrite(ALl, HIGH);
        fase = 2;
      }
    }
  }

  if(fase == 2){
    digitalWrite(El, LOW);
  }
}
