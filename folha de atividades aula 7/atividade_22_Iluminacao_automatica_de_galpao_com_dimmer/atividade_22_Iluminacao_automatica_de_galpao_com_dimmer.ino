int led = 8;
int bot = 2;

int pot = A0;
int ldr = A1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bot, INPUT_PULLUP);
}

void loop() {

  int botao = digitalRead(bot);
  int valorPot = analogRead(pot);
  int valorLdr = analogRead(ldr);

  int nivelDesejado = map(valorPot, 0, 1023, 0, 255);
  int luzNatural = map(valorLdr, 0, 1023, 0, 255);

  int brilho;
  if (botao == HIGH) {
    brilho = 25; 
      digitalWrite(led, brilho); 

  } 
  else {
    brilho = nivelDesejado - luzNatural;

    if (brilho < 0) brilho = 0;
    if (brilho > 255) brilho = 255;
  }

  analogWrite(led, brilho);
}
