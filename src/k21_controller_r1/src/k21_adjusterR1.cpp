#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"

ros::Publisher adjuster_pub;
ros::Subscriber joy;

void adjusterCb(const sensor_msgs::Joy &msg){
    std_msgs::Float64 adjuster;
    
    if (msg.axes[7] == 1){
        adjuster.data = 80;
    }
    else if(msg.axes[7] == -1){
        adjuster.data = -80;
    }
    adjuster_pub.publish(adjuster);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "k21_adjusterR1");
    ros::NodeHandle nh;
    adjuster_pub = nh.advertise<std_msgs::Float64>("/adjuster", 100);
    joy = nh.subscribe("/joy", 1000, adjusterCb);
    ros::spin();
    return 0;
}



