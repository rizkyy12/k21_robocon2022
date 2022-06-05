void pid_m1() {
  // var SV1 merupakan nilai absolute/mutlak dari setPointRpm1
  // jadi keluaran yang dihasilkan dari PID1 akan selalu +
  SV1 = abs(setPointRpm1);
  PV1 = rpm_m1;

  t1 = millis(); // Start time t1
  Ts1 = (t1 - t_1) / 10;

  et1 = SV1 - PV1;                                // -- Calculate Error
  eint1_update = ((et1 + et1_prev) * Ts1) / 2;    // -- Error Integral
  eint1 = eint1_prev + eint1_update;
  edif1 = (et1 - et1_prev) / Ts1;

  PID1 = Kp_1 * et1 + Ki_1 * eint1 + Kd_1 * edif1;     // -- Calculate PID

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
}

void pid_m2() {
  // var SV1 merupakan nilai absolute/mutlak dari setPointRpm1
  // jadi keluaran yang dihasilkan dari PID1 akan selalu +
  SV2 = abs(setPointRpm2);
  PV2 = rpm_m2;

  t2 = millis(); // Start time t1
  Ts2 = (t2 - t_2) / 10;

  et2 = SV2 - PV2;                                // -- Calculate Error
  eint2_update = ((et2 + et2_prev) * Ts2) / 2;    // -- Error Integral
  eint2 = eint2_prev + eint2_update;
  edif2 = (et2 - et2_prev) / Ts2;

  PID2 = Kp_2 * et2 + Ki_2 * eint2 + Kd_2 * edif2;     // -- Calculate PID

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
}

void pid_m3() {
  // var SV1 merupakan nilai absolute/mutlak dari setPointRpm1
  // jadi keluaran yang dihasilkan dari PID1 akan selalu +
  SV3 = abs(setPointRpm3);
  PV3 = rpm_m3;

  t3 = millis(); // Start time t1
  Ts3 = (t3 - t_3) / 10;

  et3 = SV3 - PV3;                                // -- Calculate Error
  eint3_update = ((et3 + et3_prev) * Ts3) / 3;    // -- Error Integral
  eint3 = eint3_prev + eint3_update;
  edif3 = (et3 - et3_prev) / Ts3;

  PID3 = Kp_3 * et3 + Ki_3 * eint3 + Kd_3 * edif3;     // -- Calculate PID

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
}

void pid_m4() {
  // var SV4 merupakan nilai absolute/mutlak dari setPointRpm1
  // jadi keluaran yang dihasilkan dari PID1 akan selalu +
  SV4 = abs(setPointRpm4);
  PV4 = rpm_m4;

  t4 = millis(); // Start time t1
  Ts4 = (t4 - t_4) / 10;

  et4 = SV4 - PV4;                                // -- Calculate Error
  eint4_update = ((et4 + et4_prev) * Ts4) / 4;    // -- Error Integral
  eint4 = eint4_prev + eint4_update;
  edif4 = (et4 - et4_prev) / Ts4;

  PID4 = Kp_4 * et4 + Ki_4 * eint4 + Kd_4 * edif4;     // -- Calculate PID

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
}
