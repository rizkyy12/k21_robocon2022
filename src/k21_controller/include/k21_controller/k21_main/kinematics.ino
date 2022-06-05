void motor_1(int vx, int vy, int w) {
  float motor1 = 0.7071 * (vy - vx) + (w * 0.471);
  if (motor1 > 0) {
    dir = 1;
  }
  if (motor1 < 0) {
    dir = -1;
  }
  if (motor1 == 0) {
    motor1 = 0;
  }
  Serial.print(motor1); Serial.print("\t");
  Serial.println();
  int m1 = abs(motor1);
  setMotor1(dir, m1);
}

void motor_2(int vx, int vy, int w) {
  float motor2 = 0.7071 * (-vy - vx) + (w * 0.471);
  if (motor2 > 0) {
    dir = 1;
  }
  if (motor2 < 0) {
    dir = -1;
  }
  if (motor2 == 0) {
    motor2 = 0;
  }
  Serial.print(motor2); Serial.print("\t");
  Serial.println();
  int m2 = abs(motor2);
  setMotor2(dir, m2);
}

void motor_3(int vx, int vy, int w) {
  float motor3 = 0.7071 * (vx - vy) + (w * 0.471);
  if (motor3 > 0) {
    dir = 1;
  }
  if (motor3 < 0) {
    dir = -1;
  }
  if (motor3 == 0) {
    motor3 = 0;
  }
  Serial.print(motor3); Serial.print("\t");
  Serial.println();
  int m3 = abs(motor3);
  setMotor3(dir, m3);
}

void motor_4(int vx, int vy, int w) {
  float motor4 = 0.7071 * (vx + vy) + (w * 0.471);
  if (motor4 > 0) {
    dir = 1;
  }
  if (motor4 < 0) {
    dir = -1;
  }
  if (motor4 == 0) {
    motor4 = 0;
  }
  Serial.print(motor4); Serial.print("\t");
  Serial.println();
  int m4 = abs(motor4);
  setMotor4(dir, m4);
}

void setMotor1(int dir, int pwmVal) {
  if (dir == 1) {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, pwmVal);
  }
  else if (dir == -1) {
    analogWrite(R_PWM1, pwmVal);
    analogWrite(L_PWM1, 0);
  }
  else {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, 0);
  }
}

void setMotor2(int dir, int pwmVal) {
  if (dir == 1) {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, pwmVal);
  }
  else if (dir == -1) {
    analogWrite(R_PWM2, pwmVal);
    analogWrite(L_PWM2, 0);
  }
  else {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, 0);
  }
}

void setMotor3(int dir, int pwmVal) {
  if (dir == 1) {
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, pwmVal);
  }
  else if (dir == -1) {
    analogWrite(R_PWM3, pwmVal);
    analogWrite(L_PWM3, 0);
  }
  else {
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, 0);
  }
}

void setMotor4(int dir, int pwmVal) {
  if (dir == 1) {
    analogWrite(R_PWM4, 0);
    analogWrite(L_PWM4, pwmVal);
  }
  else if (dir == -1) {
    analogWrite(R_PWM4, pwmVal);
    analogWrite(L_PWM4, 0);
  }
  else {
    analogWrite(R_PWM4, 0);
    analogWrite(L_PWM4, 0);
  }
}
