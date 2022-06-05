// Base 4 Omni Wheel - K21 Robocon
// Using ROS Serial Comunication
// Slave MEGA
#include <ros.h>
#include <std_msgs/Float64.h>
// -----------------------------------------------------------
#include <config_k21.h>
#include <var_M1_k21.h>
#include <var_M2_k21.h>
#include <var_M3_k21.h>
#include <var_M4_k21.h>

float maxRpm = 800;
float ppr = 7;
float interval_elapsed;
float interval_limit;

unsigned long lasttimepub, now;

// ======================== ROS =======================
// ================= Motor 1 Publisher ================
ros::NodeHandle nh;
std_msgs::Float64 vel1_state;
std_msgs::Float64 pid1_state;
std_msgs::Float64 rpm1_state;

ros::Publisher vel1("/vel_m1", &vel1_state);
ros::Publisher pid1("/pid_m1", &pid1_state);
ros::Publisher rpm1("/rpm_m1", &rpm1_state);

// ================= Motor 2 Publisher ================
std_msgs::Float64 vel2_state;
std_msgs::Float64 pid2_state;
std_msgs::Float64 rpm2_state;

ros::Publisher vel2("/vel_m2", &vel2_state);
ros::Publisher pid2("/pid_m2", &pid2_state);
ros::Publisher rpm2("/rpm_m2", &rpm2_state);

// ================= Motor 3 Publisher ================
std_msgs::Float64 vel3_state;
std_msgs::Float64 pid3_state;
std_msgs::Float64 rpm3_state;

ros::Publisher vel3("/vel_m3", &vel3_state);
ros::Publisher pid3("/pid_m3", &pid3_state);
ros::Publisher rpm3("/rpm_m3", &rpm3_state);

// ================= Motor 4 Publisher ================
std_msgs::Float64 vel4_state;
std_msgs::Float64 pid4_state;
std_msgs::Float64 rpm4_state;

ros::Publisher vel4("/vel_m4", &vel4_state);
ros::Publisher pid4("/pid_m4", &pid4_state);
ros::Publisher rpm4("/rpm_m4", &rpm4_state);
// ====================== || ===========================

// =========== Callback Function Motor 1 ===============
void setPoint_Cb1(std_msgs::Float64 &msg_motor1) {
  setPointVel1 = msg_motor1.data;
  if (setPointVel1 <= 3 and setPointVel1 >= -3) {
    setPointRpm1 = 0;
  }
  else {
    setPointRpm1 = setPointVel1 * 9.5492965964254; // rad/s to RPM
  }
}

// =========== Callback Function Motor 2 ===============
void setPoint_Cb2(std_msgs::Float64 &msg_motor2) {
  setPointVel2 = msg_motor2.data;
  if (setPointVel2 <= 3 and setPointVel2 >= -3) {
    setPointRpm2 = 0;
  }
  else {
    setPointRpm2 = setPointVel2 * 9.5492965964254; // rad/s to RPM
  }
}

// =========== Callback Function Motor 3 ===============
void setPoint_Cb3(std_msgs::Float64 &msg_motor3) {
  setPointVel3 = msg_motor3.data;
  if (setPointVel3 <= 3 and setPointVel3 >= -3) {
    setPointRpm3 = 0;
  }
  else {
    setPointRpm3 = setPointVel3 * 9.5492965964254; // rad/s to RPM
  }
}

// =========== Callback Function Motor 4 ===============
void setPoint_Cb4(std_msgs::Float64 &msg_motor4) {
  setPointVel4 = msg_motor4.data;
  if (setPointVel4 <= 3 and setPointVel4 >= -3) {
    setPointRpm4 = 0;
  }
  else {
    setPointRpm4 = setPointVel4 * 9.5492965964254; // rad/s to RPM
  }
}

// ==================================== Subscriber For Each Motor ==================================
// ========================= Get data from value Kinematics 4 Wheel ================================
ros::Subscriber<std_msgs::Float64> m1("/k21_robocon/right_f_motor/command", setPoint_Cb1);
ros::Subscriber<std_msgs::Float64> m2("/k21_robocon/left_f_motor/command", setPoint_Cb2);
ros::Subscriber<std_msgs::Float64> m3("/k21_robocon/left_b_motor/command", setPoint_Cb3);
ros::Subscriber<std_msgs::Float64> m4("/k21_robocon/right_b_motor/command", setPoint_Cb4);
// ========================================== Ended ROS ===========================================
// ================================================================================================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_output();
  // =========================== PID Parameters =============================
  // -- Parameters Motor 1 ==================================================
  Kp_1 = 0.009121;  //0.01021 //parameters Proportional
  Ti_1 = 4.957;   //8.057     //parameters Integral
  Td_1 = 1.071;   //1.071     //parameters Derivative
  // --> Menghitung Ki
  if (Ti_1 == 0) {
    Ki_1 = 0;
  }
  else {
    Ki_1 = Kp_1 / Ti_1;
  }
  // --> Menghitung Kd
  Kd_1 = Kp_1 * Td_1;
  et1_prev = 0;
  eint1_prev = 0;

  // -- Parameters Motor 2 ==================================================
  Kp_2 = 0.009121;  //0.01021 //parameters Proportional
  Ti_2 = 4.957;   //8.057     //parameters Integral
  Td_2 = 1.071;   //1.071     //parameters Derivative
  // --> Menghitung Ki
  if (Ti_2 == 0) {
    Ki_2 = 0;
  }
  else {
    Ki_2 = Kp_2 / Ti_2;
  }

  // --> Menghitung Kd
  Kd_2 = Kp_2 * Td_2;
  et2_prev = 0;
  eint2_prev = 0;

  // -- Parameters Motor 3 ==================================================
  Kp_3 = 0.009121;  //0.01021 //parameters Proportional
  Ti_3 = 4.957;   //8.057     //parameters Integral
  Td_3 = 1.071;   //1.071     //parameters Derivative
  // --> Menghitung Ki
  if (Ti_3 == 0) {
    Ki_3 = 0;
  }
  else {
    Ki_3 = Kp_3 / Ti_3;
  }

  // --> Menghitung Kd
  Kd_3 = Kp_3 * Td_3;
  et3_prev = 0;
  eint3_prev = 0;

  // -- Parameters Motor 4 ==================================================
  Kp_4 = 0.009121;  //0.01021 //parameters Proportional
  Ti_4 = 4.957;   //8.057     //parameters Integral
  Td_4 = 1.071;   //1.071     //parameters Derivative
  // --> Menghitung Ki
  if (Ti_4 == 0) {
    Ki_4 = 0;
  }
  else {
    Ki_4 = Kp_4 / Ti_4;
  }

  // --> Menghitung Kd
  Kd_4 = Kp_4 * Td_4;
  et4_prev = 0;
  eint4_prev = 0;
  //================================= End Parameters =======================
  // ======================== Ended PID Parameters =========================

  interval_limit = 0.05;
  interval_elapsed = 0;

  // ======================== ROS Advertise & Subs =========================
  // =============================== Motor 1 ===============================
  nh.advertise(vel1);
  nh.advertise(pid1);
  nh.subscribe(m1);
  t1 = millis();
  // =============================== Motor 2 ===============================
  nh.advertise(vel2);
  nh.advertise(pid2);
  nh.subscribe(m2);
  t2 = millis();
  // =============================== Motor 3 ===============================
  nh.advertise(vel3);
  nh.advertise(pid3);
  nh.subscribe(m3);
  t3 = millis();
  // =============================== Motor 4 ===============================
  nh.advertise(vel4);
  nh.advertise(pid4);
  nh.subscribe(m4);
  t4 = millis();
  // ===================== Ended ROS Advertise & Subs ======================

  delay(10);
}

void loop() {
  now = millis();

  // ================================== MOTOR 1 ===========================
  unsigned long currentMillis1 = millis();
  unsigned long currentMillis2 = millis();

  pid_m1();

  if (currentMillis1 - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis1;
    if (setPointVel1 > 0.00001 ) {
      pid1_state.data = PID1;
      pid1.publish (&pid1_state);
      vel1_state.data = MV1;
      vel1.publish(&vel1_state);
      analogWrite(R_PWM1, MV1);
      analogWrite(L_PWM1, 0);
    }
    else if (setPointVel1 < -0.00001) {
      pid1_state.data = (PID1 * -1);
      pid1.publish(&pid1_state);
      vel1_state.data = (MV1 * -1);
      vel1.publish(&vel1_state);
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM1, MV1);
    }
    else {
      pid1_state.data = 0;
      pid1.publish(&pid1_state);
      vel1_state.data = 0;
      vel1.publish(&vel1_state);
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM1, 0);
    }
  }

  nh.spinOnce();

  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    rpm_m1 = abs((encoderPos_1 / ppr) * 600);
    //    rpm1_state.data = setPointRpm1;
    //    rpm1.publish(&rpm1_state);
    encoderPos_1 = 0;
  }

  nh.spinOnce();
  // ================================== EBD Motor 1 ===================================

  // ================================== MOTOR 2 ===========================
  unsigned long currentMillis3 = millis();
  unsigned long currentMillis4 = millis();

  pid_m2();

  if (currentMillis3 - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis3;
    if (setPointVel2 > 0.00001 ) {
      pid2_state.data = PID2;
      pid2.publish (&pid2_state);
      vel2_state.data = MV2;
      vel2.publish(&vel2_state);
      analogWrite(R_PWM2, MV2);
      analogWrite(L_PWM2, 0);
    }
    else if (setPointVel2 < -0.00001) {
      pid2_state.data = (PID2 * -1);
      pid2.publish(&pid2_state);
      vel2_state.data = (MV2 * -1);
      vel2.publish(&vel2_state);
      analogWrite(R_PWM2, 0);
      analogWrite(L_PWM2, MV2);
    }
    else {
      pid2_state.data = 0;
      pid2.publish(&pid2_state);
      vel2_state.data = 0;
      vel2.publish(&vel2_state);
      analogWrite(R_PWM2, 0);
      analogWrite(L_PWM2, 0);
    }
  }

  nh.spinOnce();

  if (currentMillis4 - previousMillis4 >= interval4) {
    previousMillis4 = currentMillis4;
    rpm_m2 = abs((encoderPos_2 / ppr) * 600);
    //    rpm1_state.data = setPointRpm1;
    //    rpm1.publish(&rpm1_state);
    encoderPos_2 = 0;
  }

  nh.spinOnce();
  // ================================== EBD Motor 2 ===================================
  
  // ================================== MOTOR 3 ===========================
  unsigned long currentMillis5 = millis();
  unsigned long currentMillis6 = millis();

  pid_m3();

  if (currentMillis5 - previousMillis5 >= interval5) {
    previousMillis5 = currentMillis5;
    if (setPointVel3 > 0.00001 ) {
      pid3_state.data = PID3;
      pid3.publish (&pid3_state);
      vel3_state.data = MV3;
      vel3.publish(&vel3_state);
      analogWrite(R_PWM3, MV3);
      analogWrite(L_PWM3, 0);
    }
    else if (setPointVel3 < -0.00001) {
      pid3_state.data = (PID3 * -1);
      pid3.publish(&pid3_state);
      vel3_state.data = (MV3 * -1);
      vel3.publish(&vel3_state);
      analogWrite(R_PWM3, 0);
      analogWrite(L_PWM3, MV3);
    }
    else {
      pid3_state.data = 0;
      pid3.publish(&pid3_state);
      vel3_state.data = 0;
      vel3.publish(&vel3_state);
      analogWrite(R_PWM3, 0);
      analogWrite(L_PWM3, 0);
    }
  }

  nh.spinOnce();

  if (currentMillis6 - previousMillis6 >= interval6) {
    previousMillis6 = currentMillis6;
    rpm_m3 = abs((encoderPos_3 / ppr) * 600);
    //    rpm1_state.data = setPointRpm1;
    //    rpm1.publish(&rpm1_state);
    encoderPos_3 = 0;
  }

  nh.spinOnce();
  // ================================== END Motor 3 ===================================
  
  // ================================== MOTOR 4 ===========================
  unsigned long currentMillis7 = millis();
  unsigned long currentMillis8 = millis();

  pid_m4();

  if (currentMillis7 - previousMillis7 >= interval7) {
    previousMillis7 = currentMillis7;
    if (setPointVel4 > 0.00001 ) {
      pid4_state.data = PID4;
      pid4.publish (&pid4_state);
      vel4_state.data = MV4;
      vel4.publish(&vel4_state);
      analogWrite(R_PWM4, MV4);
      analogWrite(L_PWM4, 0);
    }
    else if (setPointVel4 < -0.00001) {
      pid4_state.data = (PID4 * -1);
      pid4.publish(&pid4_state);
      vel4_state.data = (MV4 * -1);
      vel4.publish(&vel4_state);
      analogWrite(R_PWM4, 0);
      analogWrite(L_PWM4, MV4);
    }
    else {
      pid4_state.data = 0;
      pid4.publish(&pid4_state);
      vel4_state.data = 0;
      vel4.publish(&vel4_state);
      analogWrite(R_PWM4, 0);
      analogWrite(L_PWM4, 0);
    }
  }

  nh.spinOnce();

  if (currentMillis8 - previousMillis8 >= interval8) {
    previousMillis8 = currentMillis8;
    rpm_m4 = abs((encoderPos_4 / ppr) * 600);
    //    rpm1_state.data = setPointRpm1;
    //    rpm1.publish(&rpm1_state);
    encoderPos_4 = 0;
  }

  nh.spinOnce();
  // ================================== END Motor 4 ===================================
  delay(100);
}
