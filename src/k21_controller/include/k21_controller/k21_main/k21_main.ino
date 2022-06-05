// Full Program Slave Mega K21 Robocon
// Using ROS Serial Communication

#include <util/atomic.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

#include <config_k21.h>
#include <var_M1_k21.h>
#include <var_M2_k21.h>
#include <var_M3_k21.h>
#include <var_M4_k21.h>

#define R_PWM_LIFTER 5
#define L_PWM_LIFTER 4

ros::NodeHandle nh;

int Vx, Vx_1;
int Vy, Vy_1;
int w, w_1;

std_msgs::Float64 value_lifter;
double output;

void lifterCb(const std_msgs::Float64 &msg_lifter){
  output = msg_lifter.data;
}

void messageCb(const geometry_msgs::Twist& msg) {
  Vx = msg.linear.x;
  Vy = msg.linear.y;
  w = msg.angular.z;

  if (Vy == 1) {
    Vx = 0;
    Vy = 120;
    w = 0;
  }
  else if (Vy == -1) {
    Vx = 0;
    Vy = -120;
    w = 0;
  }
  else if (Vx == 1) {
    Vx = 120;
    Vy = 0;
    w = 0;
  }
  else if (Vx == -1) {
    Vx = -120;
    Vy = 0;
    w = 0;
  }
  else if (w == 1) {
    Vx = 0;
    Vy = 0;
    w = 120;
  }
  else if (w == -1) {
    Vx = 0;
    Vy = 0;
    w = -120;
  }
  else if (Vx == 1 && Vy == 1) {
    Vx = 120;
    Vy = 120;
    w = 0;
  }
  else if (Vx == -1 && Vy == -1) {
    Vx = -120;
    Vy = -120;
    w = 0;
  }
  else if (Vx == -1 && Vy == 1) {
    Vx = -120;
    Vy = 120;
    w = 0;
  }
  else if (Vx == 1 && Vy == -1) {
    Vx = 120;
    Vy = -120;
    w = 0;
  }
  else {
    Vx = 0;
    Vy = 0;
    w = 0;
  }
}

ros::Subscriber<std_msgs::Float64> sub_lifter("/lifter", lifterCb);

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", messageCb);

int dir;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_PWM3, OUTPUT);
  pinMode(L_PWM3, OUTPUT);
  pinMode(R_PWM4, OUTPUT);
  pinMode(L_PWM4, OUTPUT);
  pinMode(R_PWM_LIFTER, OUTPUT);
  pinMode(L_PWM_LIFTER, OUTPUT);
  nh.subscribe(sub_lifter);
  nh.subscribe(sub);
}

void loop() {
  Vx_1 = 0;
  Vy_1 = 0;
  w_1 = 0;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    Vx_1 = Vx;
    Vy_1 = Vy;
    w_1 = w;
  }
  
  //  int w = 0;
  motor_1(Vx, Vy, w);
  motor_2(Vx, Vy, w);
  motor_3(Vx, Vy, w);
  motor_4(Vx, Vy, w);
  //lifter
  OutPwm(output);
  nh.spinOnce();
}
