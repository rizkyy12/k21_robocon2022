void setup_output(){
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_PWM3, OUTPUT);
  pinMode(L_PWM3, OUTPUT);
  
  pinMode(ENCOA1, INPUT_PULLUP);
  pinMode(ENCOB1, INPUT_PULLUP);
  pinMode(ENCOA2, INPUT_PULLUP);
  pinMode(ENCOB2, INPUT_PULLUP);
  pinMode(ENCOA3, INPUT_PULLUP);
  pinMode(ENCOB3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCOA1), readEncoderA1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOB1), readEncoderB1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOA2), readEncoderA2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOB2), readEncoderB2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOA3), readEncoderA3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOB3), readEncoderB3, CHANGE);
 
}
