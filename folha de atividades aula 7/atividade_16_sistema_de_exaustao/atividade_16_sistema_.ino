if(leitura < temp30){
    pwm = 51; // 20% de 255
    digitalWrite(led1, LOW);
  }

  // ENTRE 30°C E 60°C → linear
  else if(leitura >= temp30 && leitura <= temp60){
    pwm = map(leitura, temp30, temp60, 51, 255);
    digitalWrite(led1, LOW);
  }

  // ACIMA DE 60°C → 100% + LED1 ligado
  else{
    pwm = 255;
    digitalWrite(led1, HIGH);
  }

  analogWrite(led2, pwm);
}
