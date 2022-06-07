#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include "sensor_msgs/Joy.h"

ros::Publisher servo1;
ros::Publisher servo2;
ros::Publisher servo3;
// Servo 1 : Pelontar
// Servo 2 & 3 : Rak Ball

ros::Subscriber joy;

void servoCb(const sensor_msgs::Joy &msg){
    std_msgs::UInt16 servo1_data;
    std_msgs::UInt16 servo2_data;
    std_msgs::UInt16 servo3_data;

    if(msg.buttons[2] == 1){
        servo1_data.data = 180;
    }
    else if(msg.buttons[1] == 1){
        servo1_data.data = 180;
    }
    else if (msg.buttons[4] == 1){
        servo3_data.data = 180;
    }
    else{
        servo1_data.data = 0;
        servo2_data.data = 0;
        servo3_data.data = 0;
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "servo_node");
    ros::NodeHandle nh;
    servo1 = nh.advertise<std_msgs::UInt16>("/servo1", 100);
    servo2 = nh.advertise<std_msgs::UInt16>("/servo2", 100);
    servo3 = nh.advertise<std_msgs::UInt16>("/servo3", 100);
    joy = nh.subscribe("/joy", 1000, servoCb);
    ros::spin();
    return 0;
}
