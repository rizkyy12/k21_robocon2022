void setup_output(){
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(ENCOA1, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCOA1), readEncoder1, RISING);

  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(ENCOA2, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCOA2), readEncoder2, RISING);

  pinMode(R_PWM3, OUTPUT);
  pinMode(L_PWM3, OUTPUT);
  pinMode(ENCOA3, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCOA3), readEncoder3, RISING);
  
  pinMode(R_PWM4, OUTPUT);
  pinMode(L_PWM4, OUTPUT);
  pinMode(ENCOA4, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCOA4), readEncoder4, RISING);
}
