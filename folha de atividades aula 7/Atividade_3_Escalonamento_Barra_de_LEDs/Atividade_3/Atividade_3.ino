int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int pin_sensor = A0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pin_sensor, INPUT);

}

void loop()
{
  int valor_sensor = analogRead(pin_sensor);
  
  if(valor_sensor <= 255){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
}
  if(255 < valor_sensor && valor_sensor <= 511){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(511 < valor_sensor && valor_sensor <= 767){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(767 < valor_sensor && valor_sensor <= 920){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(920 < valor_sensor){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}
