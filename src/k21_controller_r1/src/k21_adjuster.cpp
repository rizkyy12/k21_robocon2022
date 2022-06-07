#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/Joy.h"

ros::Publisher adjuster_pub;
ros::Subscriber joy;

void relayCb(const sensor_msgs::Joy &msg){
    std_msgs::Float64 adjuster;

    if(msg.buttons[7] == 1){
        adjuster.data = 80;
    }
    else if (msg.buttons[7] == -1){
        msg.buttons[7] == -80;
    }
    else{
        adjuster.data = 0;
        ROS_INFO("[OUT]");
    }
    ROS_INFO("Value Relay: %d", adjuster.data);
    adjuster_pub.publish(adjuster);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "adjuster_node");
    ros::NodeHandle nh;
    adjuster_pub = nh.advertise<std_msgs::Float64>("/adjuster", 100);
    joy = nh.subscribe("/joy", 1000, relayCb);
    ros::spin();
    return 0;
}

