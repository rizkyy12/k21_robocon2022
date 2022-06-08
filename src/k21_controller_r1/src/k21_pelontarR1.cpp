#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include <sensor_msgs/Joy.h>

ros::Publisher pelontar_pub;
ros::Subscriber joy;

void pelontarCb(const sensor_msgs::Joy &msg){
    std_msgs::Float64 pelontar;

    if(msg.buttons[3] == 1){
        pelontar.data = 1;
    }
    else{
        pelontar.data = 0;
    }

    pelontar_pub.publish(pelontar);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "pelontar_node");
    ros::NodeHandle nh;
    pelontar_pub = nh.advertise<std_msgs::Float64>("/pelontar", 100);
    joy = nh.subscribe("/joy", 1000, pelontarCb);
    ros::spin();
    return 0;
}
