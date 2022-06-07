void motor_1(float vx, float vy, float w) {
  float motor1 = 0.7071 * (-vx + vy) + (w * 0.471);
  if (motor1 > 0) {
    dir1 = 1;
  }
  if (motor1 < 0) {
    dir1 = -1;
  }
  if (motor1 == 0) {
    motor1 = 0;
  }
//  if (motor1 <= 3 and motor1 >= -3){
//    setPointRpm1 = 0;
//  }
  //  Serial.print(motor1); Serial.print("\t");
  //  Serial.println();

  int m1 = abs(motor1);
  setPointRpm1 = motor1 * 9.5492965964254;
  SV1 = abs(setPointRpm1);
  PV1 = rpm_m1;

  t1 = millis(); // Start time t1
  Ts1 = (t1 - t_1) / 10;

  et1 = SV1 - PV1;                                // -- Calculate Error
  eint1_update = ((et1 + et1_prev) * Ts1) / 2;    // -- Error Integral
  eint1 = eint1_prev + eint1_update;
  edif1 = (et1 - et1_prev) / Ts1;

  PID1 = Kp * et1 + Ki * eint1 + Kd * edif1;     // -- Calculate PID

  if (PID1 > maxRpm) {                           // -- If the PID greather than maxRpm,
    PID1 = maxRpm;                               // -- Set value PID1 to maxRpm
  }
  else if (PID1 < 0) {
    PID1 = 0;
  }

  else {
    PID1 = PID1;
  }

  PID1 = PID1 / maxRpm;
  MV1 = PID1 * 255;                             // -- Measured Value * 255 (PWM)

  et1_prev = et1;
  eint1_prev = eint1;
  t_1 = t1;
  
  setMotor1(dir1, MV1);
}

void setMotor1(int dir, int pwmVal) {
  if (dir1 == 1) {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, pwmVal);
  }
  else if (dir1 == -1) {
    analogWrite(R_PWM1, pwmVal);
    analogWrite(L_PWM1, 0);
  }
  else {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, 0);
  }
}

void motor_2(float vx, float vy, float w) {
  float motor2 = 0.7071 * (-vy - vx) + (w * 0.471);
  if (motor2 > 1) {
    dir2 = 1;
  }
  else if (motor2 < -1) {
    dir2 = -1;
  }
  else{
    motor2 = 0;
  }
  //  Serial.print(motor1); Serial.print("\t");
  //  Serial.println();

  int m2 = abs(motor2);
  setPointRpm2 = motor2 * 9.5492965964254;
  SV2 = abs(setPointRpm2);
  PV2 = rpm_m2;

  t2 = millis(); // Start time t1
  Ts2 = (t2 - t_2) / 10;

  et2 = SV2 - PV2;                                // -- Calculate Error
  eint2_update = ((et2 + et2_prev) * Ts2) / 2;    // -- Error Integral
  eint2 = eint2_prev + eint2_update;
  edif2 = (et2 - et2_prev) / Ts2;

  PID2 = Kp * et2 + Ki * eint2 + Kd * edif2;     // -- Calculate PID

  if (PID2 > maxRpm) {                           // -- If the PID greather than maxRpm,
    PID2 = maxRpm;                               // -- Set value PID1 to maxRpm
  }
  else if (PID2 < 0) {
    PID2 = 0;
  }

  else {
    PID2 = PID2;
  }

  PID2 = PID2 / maxRpm;
  MV2 = PID2 * 255;                             // -- Measured Value * 255 (PWM)

  et2_prev = et2;
  eint2_prev = eint2;
  t_2 = t2;

  setMotor2(dir2, MV2);
}

void setMotor2(int dir, int pwmVal) {
  if (dir2 == 1) {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, pwmVal);
  }
  else if (dir2 == -1) {
    analogWrite(R_PWM2, pwmVal);
    analogWrite(L_PWM2, 0);
  }
  else {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, 0);
  }
}

void motor_3(int vx, int vy, int w) {
  float motor3 = 0.7071 * (vx - vy) + (w * 0.471);
  if (motor3 > 0) {
    dir3 = 1;
  }
  if (motor3 < 0) {
    dir3 = -1;
  }
  if (motor3 == 0) {
    motor3 = 0;
  }
  //  Serial.print(motor3); Serial.print("\t");
  //  Serial.println();
  int m3 = abs(motor3);
  setPointRpm3 = motor3 * 9.5492965964254;
  SV3 = abs(setPointRpm3);
  PV3 = rpm_m3;

  t3 = millis(); // Start time t1
  Ts3 = (t3 - t_3) / 10;

  et3 = SV3 - PV3;                                // -- Calculate Error
  eint3_update = ((et3 + et3_prev) * Ts3) / 3;    // -- Error Integral
  eint3 = eint3_prev + eint3_update;
  edif3 = (et3 - et3_prev) / Ts3;

  PID3 = Kp * et3 + Ki * eint3 + Kd * edif3;     // -- Calculate PID

  if (PID3 > maxRpm) {                           // -- If the PID greather than maxRpm,
    PID3 = maxRpm;                               // -- Set value PID1 to maxRpm
  }
  else if (PID3 < 0) {
    PID3 = 0;
  }

  else {
    PID3 = PID3;
  }

  PID3 = PID3 / maxRpm;
  MV3 = PID3 * 255;                             // -- Measured Value * 255 (PWM)

  et3_prev = et3;
  eint3_prev = eint3;
  t_3 = t3;

  setMotor3(dir3, MV3);
}


void setMotor3(int dir, int pwmVal) {
  if (dir3 == 1) {
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, pwmVal);
  }
  else if (dir3 == -1) {
    analogWrite(R_PWM3, pwmVal);
    analogWrite(L_PWM3, 0);
  }
  else {
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, 0);
  }
}

void motor_4(int vx, int vy, int w) {
  float motor4 = 0.7071 * (vx + vy) + (w * 0.471);
  if (motor4 > 0) {
    dir4 = 1;
  }
  if (motor4 < 0) {
    dir4 = -1;
  }
  if (motor4 == 0) {
    motor4 = 0;
  }
//  Serial.print(motor4); Serial.print("\t");
//  Serial.println();
  int m4 = abs(motor4);
  setPointRpm4 = motor4 * 9.5492965964254;
  SV4 = abs(setPointRpm4);
  PV4 = rpm_m4;

  t4 = millis(); // Start time t1
  Ts4 = (t4 - t_4) / 10;

  et4 = SV4 - PV4;                                // -- Calculate Error
  eint4_update = ((et4 + et4_prev) * Ts4) / 4;    // -- Error Integral
  eint4 = eint4_prev + eint4_update;
  edif4 = (et4 - et4_prev) / Ts4;

  PID4 = Kp * et4 + Ki * eint4 + Kd * edif4;     // -- Calculate PID

  if (PID4 > maxRpm) {                           // -- If the PID greather than maxRpm,
    PID4 = maxRpm;                               // -- Set value PID1 to maxRpm
  }
  else if (PID4 < 0) {
    PID4 = 0;
  }

  else {
    PID4 = PID4;
  }

  PID4 = PID4 / maxRpm;
  MV4 = PID4 * 255;                             // -- Measured Value * 255 (PWM)

  et4_prev = et4;
  eint4_prev = eint4;
  t_4 = t4;
  
  setMotor4(dir4, MV4);
}

void setMotor4(int dir, int pwmVal) {
  if (dir4 == 1) {
    analogWrite(R_PWM4, 0);
    analogWrite(L_PWM4, pwmVal);
  }
  else if (dir4 == -1) {
    analogWrite(R_PWM4, pwmVal);
    analogWrite(L_PWM4, 0);
  }
  else {
    analogWrite(R_PWM4, 0);
    analogWrite(L_PWM4, 0);
  }
}
