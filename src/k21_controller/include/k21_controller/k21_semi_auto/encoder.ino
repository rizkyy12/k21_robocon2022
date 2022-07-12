// ========================================== Encoder 1 ================================================ //
void readEncoderA1() {
  int a = digitalRead(ENCOA1);
  int b = digitalRead(ENCOB1);
  if (a == HIGH) {
    if (b == LOW) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
  else {
    if (b == HIGH) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
}

void readEncoderB1() {
  int a = digitalRead(ENCOA1);
  int b = digitalRead(ENCOB1);
  if (b == HIGH) {
    if (a == HIGH) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
  else {
    if (a == LOW) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
}
// ========================================== ========= ================================================ //
// ========================================== Encoder 2 ================================================ //
void readEncoderA2() {
  int a = digitalRead(ENCOA2);
  int b = digitalRead(ENCOB2);
  if (a == HIGH) {
    if (b == LOW) {
      encoderPos_2++;
    }
    else {
      encoderPos_2--;
    }
  }
  else {
    if (b == HIGH) {
      encoderPos_2++;
    }
    else {
      encoderPos_2--;
    }
  }
}

void readEncoderB2() {
  int a = digitalRead(ENCOA2);
  int b = digitalRead(ENCOB2);
  if (b == HIGH) {
    if (a == HIGH) {
      encoderPos_2++;
    }
    else {
      encoderPos_2--;
    }
  }
  else {
    if (a == LOW) {
      encoderPos_2++;
    }
    else {
      encoderPos_2--;
    }
  }
}
// ========================================================================================================
// ========================================== Encoder 3 ================================================ //
void readEncoderA3() {
  int a = digitalRead(ENCOA3);
  int b = digitalRead(ENCOB3);
  if (a == HIGH) {
    if (b == LOW) {
      encoderPos_3++;
    }
    else {
      encoderPos_3--;
    }
  }
  else {
    if (b == HIGH) {
      encoderPos_3++;
    }
    else {
      encoderPos_3--;
    }
  }
}

void readEncoderB3() {
  int a = digitalRead(ENCOA3);
  int b = digitalRead(ENCOB3);
  if (b == HIGH) {
    if (a == HIGH) {
      encoderPos_3++;
    }
    else {
      encoderPos_3--;
    }
  }
  else {
    if (a == LOW) {
      encoderPos_3++;
    }
    else {
      encoderPos_3--;
    }
  }
}
// ========================================== ========= ================================================ //
