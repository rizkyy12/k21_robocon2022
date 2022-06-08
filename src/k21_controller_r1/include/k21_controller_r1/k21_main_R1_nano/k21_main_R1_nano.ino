#include <ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>
#include <Servo.h>

#define R_PWM_ADJUSTER 5
#define L_PWM_ADJUSTER 6

ros::NodeHandle nh;

//=============== Servo
int servoR;
int servoL;
int servoF;

int servoRLast;
int servoLLast;
int servoFLast;

// ============ Adjuster
double nilai_adjuster;

// ============ Callback Adjuster
void adjusterCb(const std_msgs::Float64 &msg_adjuster) {
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

Servo servokanan;
Servo servokiri;
Servo servodepan;

//=============== Callback Servo
void servo1Cb(const std_msgs::UInt16 &cmd_msg1) {
  servoR = cmd_msg1.data;
}

void servo2Cb(const std_msgs::UInt16 &cmd_msg2) {
  servoL = cmd_msg2.data;
}

void servo3Cb(const std_msgs::UInt16 &cmd_msg3) {
  servoF = cmd_msg3.data;
}

// ==================================== Subscribe For Servo =====================================
ros::Subscriber<std_msgs::UInt16> servo_kanan("/servo_kanan", servo1Cb);
ros::Subscriber<std_msgs::UInt16> servo_kiri("/servo_kiri", servo2Cb);
ros::Subscriber<std_msgs::UInt16> servo_depan("/servo_depan", servo3Cb);
// ==================================== Subscribe For Servo =====================================
ros::Subscriber<std_msgs::Float64> sub_adjuster("/adjuster", adjusterCb);

void setup() {
  Serial.begin(115200);
  
  pinMode(R_PWM_ADJUSTER, OUTPUT);
  pinMode(L_PWM_ADJUSTER, OUTPUT);
  
  nh.subscribe(servo_kanan);
  nh.subscribe(servo_kiri);
  nh.subscribe(servo_depan);
  
  nh.subscribe(sub_adjuster);
  
  servokanan.attach(3);
  servokiri.attach(9);
  servodepan.attach(10);
}

void loop() {
  
  delay(1);
  if (servoR != servoRLast) {
    servokanan.write(servoR);
    servoRLast = servoR;
  }
  if (servoL != servoLLast) {
    servokiri.write(servoL);
    servoLLast = servoL;
  }
  if (servoF != servoFLast) {
    servodepan.write(servoF);
    servoFLast = servoF;
  }
  delay(5);

  nh.spinOnce();
}
