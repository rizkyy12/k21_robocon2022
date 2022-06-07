#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "sensor_msgs/Joy.h"

ros::Publisher relayR1_pub;
ros::Subscriber joy;

void relayCb(const sensor_msgs::Joy &msg){
    std_msgs::Int32 relay;

    if(msg.buttons[0] == 1){
        relay.data = 1;
        ROS_INFO("[HIGH]");
    }
    else{
        relay.data = 0;
        ROS_INFO("[LOW]");
    }
    ROS_INFO("Value Relay: %d", relay.data);
    relayR1_pub.publish(relay);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "relay_node");
    ros::NodeHandle nh;
    relayR1_pub = nh.advertise<std_msgs::Int32>("/relayR1", 100);
    joy = nh.subscribe("/joy", 1000, relayCb);
    ros::spin();
    return 0;
}

