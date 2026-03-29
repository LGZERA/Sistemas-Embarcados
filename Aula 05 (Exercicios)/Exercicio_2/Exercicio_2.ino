const int led_vermelho = 5;
const int pin_botaoA = 2;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(pin_botaoA, INPUT_PULLUP);
}

void loop() {
  int estadoBotao = digitalRead(pin_botaoA);

  if (estadoBotao == LOW) { 
    digitalWrite(led_vermelho, HIGH);
  } else {
    digitalWrite(led_vermelho, LOW);
  }
}