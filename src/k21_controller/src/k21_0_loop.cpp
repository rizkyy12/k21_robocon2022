#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "nol_cmdVel");
    ros::NodeHandle  nh;
    ros::Publisher pub_zero = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        geometry_msgs::Twist twist;
        twist.linear.x = 0;
        twist.linear.y = 0;
        twist.angular.z = 0;

        ROS_INFO("pub-zero velocity");
        pub_zero.publish(twist);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }
    return 0;
}