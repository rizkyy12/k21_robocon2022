#include <ros.h>
#include <std_msgs/UInt16.h>
#include <Servo.h>

#define pin_servo1 9
#define pin_servo2 10
#define pin_servo3 11

ros::NodeHandle nh;

Servo servo;

void servo1Cb(const std_msgs::UInt16 &cmd_msg1){
  servo.write(cmd_msg1.data);
}

void servo2Cb(const std_msgs::UInt16 &cmd_msg2){
  servo.write(cmd_msg2.data);
}

void servo3Cb(const std_msgs::UInt16 &cmd_msg3){
  servo.write(cmd_msg3.data);
}

ros::Subscriber<std_msgs::UInt16> sub_servo1("/servo1", servo1Cb);
ros::Subscriber<std_msgs::UInt16> sub_servo2("/servo2", servo2Cb);
ros::Subscriber<std_msgs::UInt16> sub_servo3("/servo3", servo3Cb);


void setup() {
  Serial.begin(115200);
  nh.subscribe(sub_servo1);
  nh.subscribe(sub_servo2);
  nh.subscribe(sub_servo3);

  servo.attach(pin_servo1);
  servo.attach(pin_servo2);
  servo.attach(pin_servo3);

}

void loop() {
  nh.spinOnce();
  
  delay(1);
}
