// Adjuster R1 - K21 Robocon
// Using ROS Serial Communication
// Slave Nano
#include <ros.h>
#include <std_msgs/Float64.h>

#define R_PWM_ADJUSTER 5
#define L_PWM_ADJUSTER 4

ros::NodeHandle nh;
std_msgs::Float64 value_adjuster;

ros::Publisher adjuster("/adjuster", &value_adjuster);

double nilai_adjuster;

void lifterCb(const std_msgs::Float64 &msg_adjuster) {
  nilai_adjuster = msg_adjuster.data;
  if (nilai_adjuster > 0) {
    analogWrite(R_PWM_ADJUSTER, nilai_adjuster);
    analogWrite(L_PWM_ADJUSTER, 0);
  }
  else if (nilai_adjuster < 0) {
    analogWrite(R_PWM_ADJUSTER, 0);
    analogWrite(L_PWM_ADJUSTER, nilai_adjuster);
  }
  else {
    analogWrite(R_PWM_ADJUSTER, 0);
    analogWrite(L_PWM_ADJUSTER, 0);
  }
}

ros::Subscriber<std_msgs::Float64> sub_adjuster("/lifter", lifterCb);

void setup() {
  Serial.begin(115200);
  nh.subscribe(sub_adjuster);
  pinMode(R_PWM_ADJUSTER, OUTPUT);
  pinMode(L_PWM_ADJUSTER, OUTPUT);
}

void loop() {
  nh.spinOnce();
}
