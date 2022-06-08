#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include "sensor_msgs/Joy.h"

ros::Publisher servokanan;
ros::Publisher servokiri;
ros::Publisher servodepan;
// Servo 1 : Pelontar
// Servo 2 & 3 : Rak Ball

ros::Subscriber joy;

void servoCb(const sensor_msgs::Joy &msg){
    std_msgs::UInt16 servokanan_data;
    std_msgs::UInt16 servokiri_data;
    std_msgs::UInt16 servodepan_data;

    if(msg.buttons[4] == 1){
        servodepan_data.data = 90;
    }
    else if(msg.buttons[1] == 1){
        servokiri_data.data = 90;
    }
    else if (msg.buttons[2] == 1){
        servokanan_data.data = 90;
    }
    else{
        servokanan_data.data = 0;
        servokiri_data.data = 0;
        servodepan_data.data = 0;
    }

    servokanan.publish(servokanan_data);
    servokiri.publish(servokiri_data);
    servodepan.publish(servodepan_data);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "servo_node");
    ros::NodeHandle nh;
    servokanan = nh.advertise<std_msgs::UInt16>("/servo_kanan", 100);
    servokiri = nh.advertise<std_msgs::UInt16>("/servo_kiri", 100);
    servodepan = nh.advertise<std_msgs::UInt16>("/servo_depan", 100);
    joy = nh.subscribe("/joy", 1000, servoCb);
    ros::spin();
    return 0;
}
