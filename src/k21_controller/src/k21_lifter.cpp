#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"

ros::Publisher lifter_pub;
ros::Subscriber joy;

void lifterCb(const sensor_msgs::Joy &msg){
    std_msgs::Float64 lifter;
    
    if (msg.buttons[5] ==1){
        lifter.data = 255;
    }
    else if(msg.buttons[4] == 1){
        lifter.data = -255;
    }
    ROS_INFO("V Lifter: %f", lifter.data);
    lifter_pub.publish(lifter);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "lifter_node");
    ros::NodeHandle nh;
    lifter_pub = nh.advertise<std_msgs::Float64>("/lifter", 100);
    joy = nh.subscribe("/joy_r2", 1000, lifterCb);
    ros::spin();
    return 0;
}
