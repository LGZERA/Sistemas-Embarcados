//Luis Gustavo, meca

const int botaoMais = 6;
const int botaoMenos = 7;

int contador = 0;

int ultimoEstadoMais = HIGH;
int estadoEstavelMais = HIGH;
unsigned long ultimoTempoMais = 0;

int ultimoEstadoMenos = HIGH;
int estadoEstavelMenos = HIGH;
unsigned long ultimoTempoMenos = 0;

const unsigned long debounceDelay = 50;

void setup() {
  pinMode(botaoMais, INPUT_PULLUP);
  pinMode(botaoMenos, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int leituraMais = digitalRead(botaoMais);
  int leituraMenos = digitalRead(botaoMenos);

  if (leituraMais != ultimoEstadoMais) {
    ultimoTempoMais = millis();
  }

  if ((millis() - ultimoTempoMais) > debounceDelay && leituraMais != estadoEstavelMais) {
    estadoEstavelMais = leituraMais;

    if (estadoEstavelMais == LOW) {
      if (contador < 15) {
        contador++;
        Serial.println(contador);
      }
    }
  }

  ultimoEstadoMais = leituraMais;

  if (leituraMenos != ultimoEstadoMenos) {
    ultimoTempoMenos = millis();
  }

  if ((millis() - ultimoTempoMenos) > debounceDelay && leituraMenos != estadoEstavelMenos) {
    estadoEstavelMenos = leituraMenos;

    if (estadoEstavelMenos == LOW) {
      if (contador > 0) {
        contador--;
        Serial.println(contador);
      }
    }
  }

  ultimoEstadoMenos = leituraMenos;
}