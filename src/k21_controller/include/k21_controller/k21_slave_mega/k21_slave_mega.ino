// Base 4 Omni Wheel - K21 Robocon
// Using ROS Serial Comunication
// Slave MEGA
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
// -----------------------------------------------------------
#include <util/atomic.h>
#include <config_k21.h>
#include <var_M1_k21.h>
#include <var_M2_k21.h>
#include <var_M3_k21.h>
#include <var_M4_k21.h>

#define R_PWM_LIFTER 5
#define L_PWM_LIFTER 4
#define CH1 47

float maxRpm = 475;
float ppr = 7;
float interval_elapsed;
float interval_limit;
float t;
float Kp, Ki, Kd, Ti, Td;

unsigned long lasttimepub, now;

int Vx, Vx_1;
int Vy, Vy_1;
int w, w_1;

int dir1, dir2, dir3, dir4;
double output;

ros::NodeHandle nh;

// ======================== ROS =======================
// Lifter
void lifterCb(const std_msgs::Float64 &msg_lifter) {
  output = msg_lifter.data;
}
// Gripper Bola
void relayCb(const std_msgs::Int32 &msg_relay) {
  int out_relay = msg_relay.data;
  if (out_relay == 1) {
    digitalWrite(CH1, HIGH);
  }
  else {
    digitalWrite(CH1, LOW);
  }
}
// ======================== ROS =======================
void messageCb(const geometry_msgs::Twist& msg) {
  Vx = msg.linear.x;
  Vy = msg.linear.y;
  w = msg.angular.z;

  if (Vy == 1) {
    Vx = 0;
    Vy = 620;
    w = 0;
  }
  else if (Vy == -1) {
    Vx = 0;
    Vy = -620;
    w = 0;
  }
  else if (Vx == 1) {
    Vx = 620;
    Vy = 0;
    w = 0;
  }
  else if (Vx == -1) {
    Vx = -620;
    Vy = 0;
    w = 0;
  }
  else if (w == 1) {
    Vx = 0;
    Vy = 0;
    w = 620;
  }
  else if (w == -1) {
    Vx = 0;
    Vy = 0;
    w = -620;
  }
  else if (Vx == 1 && Vy == 1) {
    Vx = 620;
    Vy = 620;
    w = 0;
  }
  else if (Vx == -1 && Vy == -1) {
    Vx = -620;
    Vy = -620;
    w = 0;
  }
  else if (Vx == -1 && Vy == 1) {
    Vx = -620;
    Vy = 620;
    w = 0;
  }
  else if (Vx == 1 && Vy == -1) {
    Vx = 620;
    Vy = -620;
    w = 0;
  }
  else if (Vx == 0 && Vy == 0 && w == 0) {
    Vx = 0;
    Vy = 0;
    w = 0;
  }
}

// ==================================== Subscribe For /cmd vel ==================================
ros::Subscriber<geometry_msgs::Twist> sub_cmdVel("/cmd_vel", messageCb);
// ==============================================================================================
// ==================================== Subscribe For /lifter ===================================
ros::Subscriber<std_msgs::Float64> sub_lifter("/lifter", lifterCb);
// ==============================================================================================
// ==================================== Subscribe For /relay ====================================
ros::Subscriber<std_msgs::Int32> sub_relay("/value_relay", relayCb);
// ==============================================================================================


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_output();
  // =========================== PID Parameters =============================
  Kp = 0.008221;  //0.01021 //parameters Proportional
  Ti = 3.957;   //8.057     //parameters Integral
  Td = 0.11;   //1.071     //parameters Derivative

  // --> Menghitung Ki
  if (Ti == 0) {
    Ki = 0;
  }
  else {
    Ki = Kp / Ti;
  }
  // --> Menghitung Kd
  Kd = Kp * Td;

  et1_prev = 0;
  eint1_prev = 0;

  et2_prev = 0;
  eint2_prev = 0;

  et3_prev = 0;
  eint3_prev = 0;

  et4_prev = 0;
  eint4_prev = 0;
  //================================= End Parameters =======================
  // ======================== Ended PID Parameters =========================

  interval_limit = 0.05;
  interval_elapsed = 0;

  // ======================== ROS Subs =========================
  nh.subscribe(sub_cmdVel);
  nh.subscribe(sub_lifter);
  nh.subscribe(sub_relay);
  // ===================== Ended ROS Advertise & Subs ======================
  t1 = millis();
  t2 = millis();
  t3 = millis();
  t4 = millis();

  delay(10);
}

void loop() {
  now = millis();
  Vx_1 = 0;
  Vy_1 = 0;
  w_1 = 0;

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    Vx_1 = Vx;
    Vy_1 = Vy;
    w_1 = w;
  }

  // ================================== MOTOR ===========================
  unsigned long currentMillis1 = millis();
  unsigned long currentMillis2 = millis();
  //
  motor_1(Vx, Vy, w);
  motor_2(Vx, Vy, w);
  motor_3(Vx, Vy, w);
  motor_4(Vx, Vy, w);
  //  mobility(Vx, Vy, w);
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    rpm_m1 = abs((encoderPos_1 / ppr) * 600);
    encoderPos_1 = 0;
    rpm_m2 = abs((encoderPos_2 / ppr) * 600);
    encoderPos_2 = 0;
    rpm_m3 = abs((encoderPos_3 / ppr) * 600);
    encoderPos_3 = 0;
    rpm_m4 = abs((encoderPos_4 / ppr) * 600);
    encoderPos_4 = 0;
  }
  //lifter
  OutPwm(output);

  nh.spinOnce();
}
