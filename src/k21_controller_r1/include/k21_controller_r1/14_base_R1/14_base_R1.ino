#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>
#include <util/atomic.h>

#define R_PWM1 6
#define L_PWM1 7
#define R_PWM2 8
#define L_PWM2 9
#define R_PWM3 10
#define L_PWM3 11
#define R_PWM4 12
#define L_PWM4 13

int dir1, dir2, dir3, dir4;

int Vx, Vx_1;
int Vy, Vy_1;
int w, w_1;

unsigned long lasttimepub, now;
ros::NodeHandle nh;

// ======================== ROS =======================
//Base
void cmdCb(const geometry_msgs::Twist& msg) {
  Vx = msg.linear.x;
  Vy = msg.linear.y;
  w = msg.angular.z;

  if (w == 1) {
    Vx = 0;
    Vy = 0;
    w = 200;
  }
  else if (w == -1){
    Vx = 0;
    Vy = 0;
    w = -200;
  }
}

// ==================================== Subscribe For /cmd vel ==================================
ros::Subscriber<geometry_msgs::Twist> sub_cmdVel("/cmd_vel", cmdCb);
// ==============================================================================================

void setup() {
  Serial.begin(115200);
  setup_output();
  nh.subscribe(sub_cmdVel);
  delay(10);
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
  motor_1(Vx, Vy, w);
  motor_2(Vx, Vy, w);
  motor_3(Vx, Vy, w);
  motor_4(Vx, Vy, w);
  nh.spinOnce();
}
