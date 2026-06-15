int botao_start = 5;
int botao_stop = 9;

int motor_esteira_T = 3;
int motor_esteira_G = 4;

int motor_CR = 7;

int alarme_FT = 6;

int sensor_ST1 = A0;
int sensor_SP1 = A1;

int sensor_SR = A2;
int sensor_SA = A3;

int sensor_ST2 = A4;

int alarme_FC = 8;

int contador = 0;

unsigned long tempo_anterior = 0;
int intervalo = 2000;

int estado = 0;

bool erro1 = 0;
bool erro2 = 0;

void setup() {
  pinMode(botao_start, INPUT_PULLUP);
  pinMode(botao_stop, INPUT_PULLUP);

  pinMode(motor_esteira_T, OUTPUT);
  pinMode(motor_esteira_G, OUTPUT);

  pinMode(motor_CR, OUTPUT);

  pinMode(alarme_FT, OUTPUT);
  pinMode(alarme_FC, OUTPUT);

  pinMode(sensor_ST1, INPUT);
  pinMode(sensor_SP1, INPUT);

  pinMode(sensor_SR, INPUT);
  pinMode(sensor_SA, INPUT);

  pinMode(sensor_ST2, INPUT);
}

void loop() {
  unsigned long tempo = millis();

  int botao_startl = digitalRead(botao_start);
  int botao_stopl = digitalRead(botao_stop);

  int sensor_ST1l = digitalRead(sensor_ST1);
  int sensor_SP1l = digitalRead(sensor_SP1);
  int sensor_SRl = digitalRead(sensor_SR);
  int sensor_SAl = digitalRead(sensor_SA);
  int sensor_ST2l = digitalRead(sensor_ST2);

  if(sensor_ST1l == 0 && erro1 == 0){
    erro1 = 1;
  }

  if(erro1 == 1){
    digitalWrite(alarme_FT, HIGH);
    digitalWrite(motor_esteira_T, LOW);
    digitalWrite(motor_esteira_G, LOW);
  } else {
    digitalWrite(alarme_FT, LOW);
  }

  if(botao_startl == LOW && erro1 == 0){
    estado = 1;
  }

  if(botao_stopl == LOW){
    estado = 0;
    digitalWrite(motor_esteira_T, LOW);
    digitalWrite(motor_esteira_G, LOW);
    digitalWrite(motor_CR, LOW);
  }

  if(estado == 1){
    digitalWrite(motor_esteira_T, HIGH);
    digitalWrite(motor_esteira_G, HIGH);

    if(sensor_SP1l == 1){
      estado = 2;
    }
  }

  if(estado == 2){
    if (tempo_anterior == 0) {
      tempo_anterior = tempo;
    }

    digitalWrite(motor_esteira_T, LOW);
    digitalWrite(motor_esteira_G, LOW);
    digitalWrite(motor_CR, HIGH);

    if(tempo - tempo_anterior >= intervalo){
      digitalWrite(motor_CR, LOW);
      tempo_anterior = 0;
      estado = 3;
    }
  }

  if(estado == 3){
    if(sensor_ST2l == 0){
      digitalWrite(alarme_FC, HIGH);
      digitalWrite(motor_esteira_T, LOW);
      digitalWrite(motor_esteira_G, LOW);
      erro2 = 1;
    } else {
      digitalWrite(alarme_FC, LOW);
      contador++;
      digitalWrite(motor_esteira_T, HIGH);
      digitalWrite(motor_esteira_G, HIGH);
      estado = 1;
    }
  }

  if(erro2 == 1 && botao_startl == LOW){
    erro2 = 0;
    digitalWrite(alarme_FC, LOW);
    estado = 1;
  }

  if(contador >= 24){
    digitalWrite(motor_esteira_T, LOW);
    digitalWrite(motor_esteira_G, LOW);
    estado = 4;
  }

  if(estado == 4 && botao_startl == LOW){
    contador = 0;
    estado = 1;
  }
}