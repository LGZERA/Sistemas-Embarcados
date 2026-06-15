int botao_start = 3;
int botao_stop = 4;

int sensor_s3 = A0;
int sensor_s4 = A1;

int sensor_s1 = A2;
int sensor_s2 = A3;

int motorE = 5;
int motorD = 7;

int lampada = 6;

int fase = 0;

unsigned long tempo_anterior = 0;
int intervalo = 2000;

void setup() {
  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(sensor_s1, INPUT);
  pinMode(sensor_s2, INPUT);
  pinMode(sensor_s3, INPUT);
  pinMode(sensor_s4, INPUT);

  pinMode(motorE, OUTPUT);
  pinMode(motorD, OUTPUT);
  pinMode(lampada, OUTPUT);
}

void loop() {

  unsigned long tempo = millis();

  int botao_startl = digitalRead(botao_start);
  int botao_stopl = digitalRead(botao_stop);

  int sensor_s1l = digitalRead(sensor_s1);
  int sensor_s2l = digitalRead(sensor_s2);
  int sensor_s3l = digitalRead(sensor_s3);
  int sensor_s4l = digitalRead(sensor_s4);

  if(fase > 0 && fase <= 3){
    digitalWrite(lampada, HIGH);
  } else {
  digitalWrite(lampada, LOW);
}

  if(botao_stopl == LOW){
    digitalWrite(motorE, LOW);
    digitalWrite(motorD, LOW);
    fase = 0;
  }

  if(fase == 0 && botao_startl == LOW){
    fase = 1;
  }

  if(fase == 1){
    if (tempo_anterior == 0) {
      tempo_anterior = tempo;
    }
    if(tempo - tempo_anterior >= intervalo){
      fase = 2;
      tempo_anterior = 0;
    }
  }

    if(fase == 2 && sensor_s3l == 1 && sensor_s4l == 0){
      digitalWrite(motorD, HIGH);
      fase = 3;
    }

    if(fase == 2 && sensor_s3l == 1 && sensor_s4l == 1){
      digitalWrite(motorE, HIGH);
      fase = 3;
    }

    if(fase == 3 && sensor_s1l == 1){
      digitalWrite(motorE, LOW);
      fase = 1;
    }
    if(fase == 3 && sensor_s2l == 1){
      digitalWrite(motorD, LOW);
      fase = 1;
    }

}
