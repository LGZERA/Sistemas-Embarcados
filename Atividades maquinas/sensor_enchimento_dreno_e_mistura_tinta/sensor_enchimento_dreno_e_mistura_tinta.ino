int botao_liga = 9;

int valvula1 = 3;
int valvula2 = 4;

int sensor_alto = A0;
int sensor_baixo = A1;

int motor = 5;

int aquecimento = 6;

int dreno = 7;

int dreno_final = 8;

bool Estado = 0;

int fase = 0;

int contador = 0;

unsigned long ultimo_tempo = 0;
unsigned long ultimo_tempo2 = 0;

int intervalo = 10000;
int intervalo2 = 10000;

void setup() {

 pinMode(valvula1, OUTPUT);
  pinMode(valvula2, OUTPUT);

  pinMode(sensor_alto, INPUT);
  pinMode(sensor_baixo, INPUT);

  pinMode(motor, OUTPUT);
  pinMode(aquecimento, OUTPUT);

  pinMode(dreno, OUTPUT);
  pinMode(dreno_final, OUTPUT);

  pinMode(botao_liga, INPUT_PULLUP);


}

void loop() {
  unsigned long Tempo = millis();
  int leitura_botao = digitalRead(botao_liga);
  int leitura_sensor_alto = digitalRead(sensor_alto);
  int leitura_sensor_baixo = digitalRead(sensor_baixo);

  if(leitura_botao == LOW){
     Estado = 1; 
  }
  
  if(Estado == 1 && fase == 0){
    fase = 1;
  }

  if (fase == 1 && Estado == 1){
    digitalWrite(valvula1, HIGH);
  }
  
  if(fase == 1 && Estado == 1 && leitura_sensor_baixo == 1){
    digitalWrite(valvula1, LOW);
    digitalWrite(valvula2, HIGH);
  }

  if(fase == 1 && Estado == 1 && leitura_sensor_alto == 1){
    digitalWrite(valvula1, LOW);
    digitalWrite(valvula2, LOW);
    fase = 2;
  }

  if(fase == 2){
    if (ultimo_tempo == 0) {
      ultimo_tempo = Tempo;
    }

    digitalWrite(motor, HIGH);
    digitalWrite(aquecimento, HIGH);

  if(Tempo - ultimo_tempo >= intervalo && fase == 2){
    digitalWrite(motor, LOW);
    digitalWrite(aquecimento, LOW);
    fase = 3;
    ultimo_tempo = 0;
  }
    }
  

  if(fase == 3){
    digitalWrite(dreno, HIGH);
    digitalWrite(dreno_final, HIGH);
  
    if(ultimo_tempo2 == 0){
      ultimo_tempo2 = Tempo; 
  }

    if(Tempo - ultimo_tempo2 >= intervalo2 && fase == 3){
      digitalWrite(dreno, LOW);
      digitalWrite(dreno_final, LOW);
      fase = 4;
      ultimo_tempo2 = 0;
    }
  }
    if(fase == 4){
      contador++;
      Estado = 0;
      fase = 0;
    }







}
