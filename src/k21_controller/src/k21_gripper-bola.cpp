#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "sensor_msgs/Joy.h"

ros::Publisher relay_pub;
ros::Subscriber joy;

void relayCb(const sensor_msgs::Joy &msg){
    std_msgs::Int32 relay;

    if(msg.buttons[0] == 1){
        relay.data = 1;
        ROS_INFO("[IN]");
    }
    else{
        relay.data = 0;
        ROS_INFO("[OUT]");
    }
    ROS_INFO("Value Relay: %d", relay.data);
    relay_pub.publish(relay);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "relay_node");
    ros::NodeHandle nh;
    relay_pub = nh.advertise<std_msgs::Int32>("/relay", 100);
    joy = nh.subscribe("/joy", 1000, relayCb);
    ros::spin();
    return 0;
}

