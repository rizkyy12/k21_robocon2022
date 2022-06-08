#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"

ros::Publisher gripper_pub;
ros::Subscriber joy;

void gripperCb(const sensor_msgs::Joy &msg){
    std_msgs::Float64 gripper;

    if (msg.buttons[1] ==1){
        gripper.data = 11; //buka
    }
    else if(msg.buttons[2] == 1){
        gripper.data = 22; //tutup
    }

    ROS_INFO("V Gripper: %f", gripper.data);
    gripper_pub.publish(gripper);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "gripper_lagori");
    ros::NodeHandle nh;
    gripper_pub = nh.advertise<std_msgs::Float64>("/gripper_lagori", 100);
    joy = nh.subscribe("/joy_r2", 1000, gripperCb);
    ros::spin();
    return 0;
}
