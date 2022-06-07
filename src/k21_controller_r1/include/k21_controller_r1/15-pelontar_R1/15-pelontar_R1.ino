#include <ros.h>
#include <std_msgs/Float64.h>

#define R_PWM_MOT_ATAS 4
#define L_PWM_MOT_ATAS 5
#define R_PWM_MOT_BAWAH 6
#define L_PWM_MOT_BAWAH 7

ros::NodeHandle nh;

double output;

void pelontarCb(const std_msgs::Float64 &msg_lifter) {
  output = msg_lifter.data;
}

ros::Subscriber<std_msgs::Float64> sub_pelontar("/pelontar", pelontarCb);


void setup() {
  Serial.begin(115200);
  nh.subscribe(sub_pelontar);
  pinMode(R_PWM_MOT_ATAS, OUTPUT);
  pinMode(L_PWM_MOT_ATAS, OUTPUT);
  pinMode(R_PWM_MOT_BAWAH, OUTPUT);
  pinMode(L_PWM_MOT_BAWAH, OUTPUT);
}

void loop() {
  OutPwm(output);
  nh.spinOnce();
}

void OutPwm(float out) {
  if (out > 0) {
    analogWrite(R_PWM_MOT_ATAS, out);
    analogWrite(L_PWM_MOT_ATAS, 0);
    analogWrite(R_PWM_MOT_BAWAH, 0);
    analogWrite(L_PWM_MOT_BAWAH, out);
  }
  else {
    analogWrite(R_PWM_MOT_ATAS, 0);
    analogWrite(L_PWM_MOT_ATAS, 0);
    analogWrite(R_PWM_MOT_BAWAH, 0);
    analogWrite(L_PWM_MOT_BAWAH, 0);
  }
}
