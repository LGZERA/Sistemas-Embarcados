int led1= 13;
int led2= 12;

int pot = A0;
int valor = 0;
bool passou = false;
bool estadoLed = false;

void setup()
{
	pinMode(led1, OUTPUT);
  	pinMode(led2, OUTPUT);
} 
void loop()
{
  valor = analogRead(pot);

  if(valor <= 971 && passou == false){
      
    digitalWrite(led1, HIGH);
    digitalWrite(led2,LOW);
  }
 
  if(valor >= 971 && passou == false){
     digitalWrite(led1, LOW);
     digitalWrite(led2,HIGH);
    passou = !passou;
    }


    if(passou == true && valor <= 307){
        (led1, HIGH);
        (led2, LOW);
      passou = !passou;
      }
  }
