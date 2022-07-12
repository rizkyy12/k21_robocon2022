void pid_m1(){
  
  Kp1 = 0.3962;
  Ki1 = 0.003127;
  Kd1 = 0.021;
  
  curT1 = micros();
  eT1 = curT1 - prevT1;
  deltaT1 = ((float) (curT1 - prevT1)/1.0e6);
  prevT1 = curT1;

  e1 = encoderPos_1 - setPoint1;

  dt1 = (e1 - ePrev1) / deltaT1;

  eIntegral1 = eIntegral1 + e1 * deltaT1;

  PID1 = Kp1 * e1 + Ki1 * eIntegral1 + Kd1 * dt1;

  MV1 = fabs(PID1);

  if (MV1 > 255){
    MV1 = 255;
  }

  if(PID1 < 0){
    dir1 = -1;
  }
  else{
    dir1 = 1;
  }

  ePrev1 = e1;
}

void pid_m2(){
  Kp2 = 0.3962;
  Ki2 = 0.00000172;
  Kd2 = 0.021;
  
  curT2 = micros();
  eT2 = curT2 - prevT2;
  deltaT2 = ((float) (curT2 - prevT2)/1.0e6);
  prevT2 = curT3;

  e2 = encoderPos_2 - setPoint2;

  dt2 = (e2 - ePrev2) / deltaT2;

  eIntegral2 = eIntegral2 + e2 * deltaT2;

  PID2 = Kp2 * e2 + Ki2 * eIntegral2 + Kd2 * dt2;

  MV2 = fabs(PID2);

  if (MV2 > 255){
    MV2 = 255;
  }

  if(PID2 < 0){
    dir2 = -1;
  }
  else{
    dir2 = 1;
  }

  ePrev2 = e2;
}

void pid_m3(){
  Kp3 = 0.3962;
  Ki3 = 0.000427;
  Kd3 = 0.021;
  
  curT3 = micros();
  eT3 = curT3 - prevT3;
  deltaT3 = ((float) (curT3 - prevT3)/1.0e6);
  prevT3 = curT3;

  if (i1 == 1 && encoderPos_1 >= 1400 && encoderPos_1 <= 1500){
     setPoint3 = -19318;
  }
  else if(i1 == 0 && encoderPos_1 <= 50 && encoderPos_1 >= 1){
    setPoint3 = 0;
  }

  if (i2 == 1 && encoderPos_1 >= 3460 && encoderPos_1 <= 3600){
     setPoint3 = -31006;
  }
  else if(i2 == 0 && encoderPos_1 <= 50 && encoderPos_1 >= 1){
    setPoint3 = 0;
  }

  if (i3 == 1 && encoderPos_1 >= 5650 && encoderPos_1 <= 5800){
     setPoint3 = -41693;
  }
  else if(i3 == 0 && encoderPos_1 <= 30 && encoderPos_1 >= 1){
    setPoint3 = 0;
  }
//  if (encoderPos_2 >= 3075 && encoderPos_2 <= 3100){
//      setPoint3 = -28000;
//  }
//  else if(encoderPos_2 <= 25 && encoderPos_2 >= 1){
//    setPoint3 = 0;
//  }

  e3 = encoderPos_3 - setPoint3;

  dt3 = (e3 - ePrev3) / deltaT3;

  eIntegral3 = eIntegral3 + e3 * deltaT3;

  PID3 = Kp3 * e3 + Ki3 * eIntegral3 + Kd3 * dt3;

  MV3 = fabs(PID3);

  if (MV3 > 255){
    MV3 = 255;
  }

  if(PID3 < 0){
    dir3 = -1;
  }
  else{
    dir3 = 1;
  }

  ePrev3 = e3;
}
