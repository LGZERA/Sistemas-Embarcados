const int pin_botao_start = 2;
const int pin_botao_stop = 3;

const int PinoSensor1 = A0;
const int PinoSensor2 = A1;
const int PinoSensor3 = A2;
const int PinoSensor4 = A3;


int motor = 4;
int motorb = 5;

int peca_pequena = 0;
int peca_grande = 0;


int estado = 0;

unsigned long tempo_ant = 0, tempo_atual = 0;

void setup() {
  pinMode(PinoSensor1, INPUT);
  pinMode(PinoSensor1, INPUT);
  pinMode(PinoSensor2, INPUT);
  pinMode(PinoSensor3, INPUT);
  pinMode(PinoSensor4, INPUT);

  pinMode(pin_botao_start, INPUT_PULLUP);
  pinMode(pin_botao_stop, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
    pinMode(motorb, OUTPUT);

}

void loop() {
  bool stop = digitalRead(pin_botao_stop);
  if (stop == 0) {
    estado = 0;
  }

  switch (estado) {

    case 0:
      bool start = digitalRead(pin_botao_start);
      if (start == 0) {
        estado = 1;
        tempo_ant = millis();
      }
      break;

    case 1:
      tempo_atual = millis();
      if (tempo_atual - tempo_ant > 2000) {
        estado = 2;
      }
      break;

    case 2:
      if (digitalRead(PinoSensor3) == 1 && digitalRead(PinoSensor4) == 0) {
        estado = 4;
      }
      if (digitalRead(PinoSensor3) == 1 && digitalRead(PinoSensor4) == 1) {
        estado = 3;
      }
      break;

    case 3:
      digitalWrite(motor, HIGH);
      digitalWrite(motorb, LOW);
      estado = 5;

      break;

    case 4:
      digitalWrite(motorb, HIGH);
      digitalWrite(motor, LOW);
      estado = 6;
      break;

    case 5:

      if (digitalRead(PinoSensor1 == 1)) {
        peca_grande++;
        digitalWrite(motor, LOW);
      }

      estado = 1;
      break;

    case 6:
      if (digitalRead(PinoSensor2 == 1)) {
        peca_pequena++;
        digitalWrite(motorb, LOW);
      }

      break;
  }
}
