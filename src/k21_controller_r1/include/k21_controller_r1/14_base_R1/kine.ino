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

  int m1 = abs(motor1);
  setMotor1(dir1, m1);
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

  int m2 = abs(motor2);
  setMotor2(dir2, m2);
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

  int m3 = abs(motor3);
  setMotor3(dir3, m3);
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
  
  int m4 = abs(motor4);
  setMotor4(dir4, m4);
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
