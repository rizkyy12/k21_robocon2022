void readEncoder1() {
  int a = digitalRead(ENCOA1);
  if (a > 0) {
    encoderPos_1--;
  }
  else {
    encoderPos_1++;
  }
}

void readEncoder2() {
  int a = digitalRead(ENCOA2);
  if (a > 0) {
    encoderPos_2--;
  }
  else {
    encoderPos_2++;
  }
}

void readEncoder3() {
  int a = digitalRead(ENCOA3);
  if (a > 0) {
    encoderPos_3--;
  }
  else {
    encoderPos_3++;
  }
}

void readEncoder4() {
  int a = digitalRead(ENCOA4);
  if (a > 0) {
    encoderPos_4--;
  }
  else {
    encoderPos_4++;
  }
}
