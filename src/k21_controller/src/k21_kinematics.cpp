#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Twist.h"
#include "k21_controller/VelCmd.h"

std_msgs::Float64 value;

double Vx, Vy, w;

class K21Kinematics{
    private:
        ros::Publisher v_right_f_Command;
        ros::Publisher v_left_f_Command;
        ros::Publisher v_right_b_Command;
        ros::Publisher v_left_b_Command;

        ros::Subscriber velocity;
        int count;

    public:
        K21Kinematics(ros::NodeHandle *nh){
            // velocity = nh->subscribe("/vel_cmd", 10, &K21Kinematics::kinematics_Cb, this);
            velocity = nh->subscribe("/cmd_vel", 10, &K21Kinematics::kinematics_Cb, this);
            // velocity = nh->subscribe("/vel_cmd", 10, &k21Kinematics::kinematics_Cb, this);
            v_right_f_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/right_f_motor/command", 1000);
            v_left_f_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/left_f_motor/command", 1000);
            v_left_b_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/left_b_motor/command", 1000);
            v_right_b_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/right_b_motor/command", 1000);
        }
        void kinematics_Cb(const geometry_msgs::Twist &msg){

            std_msgs::Float64 motor1;
            std_msgs::Float64 motor2;
            std_msgs::Float64 motor3;
            std_msgs::Float64 motor4;

            Vx = msg.linear.x;
            Vy = msg.linear.y;
            w = msg.linear.z;

            motor1.data = 0.7071*(Vy - Vx) + (w * 0.471);
            motor2.data = 0.7071*(-Vx - Vy) + (w * 0.471);
            motor3.data = 0.7071*(Vx - Vy) + (w * 0.471);
            motor4.data = 0.7071*(Vx + Vy) + (w * 0.471);

            v_right_f_Command.publish(motor2);
            v_left_f_Command.publish(motor1);
            v_right_b_Command.publish(motor3);
            v_left_b_Command.publish(motor4);   
            ROS_INFO("Motor1: %f", motor1.data);
            ROS_INFO("Motor2: %f", motor2.data);
            ROS_INFO("Motor3: %f", motor3.data);
            ROS_INFO("Motor4: %f", motor4.data);
        }
};

int main(int argc, char** argv){
    ros::init(argc, argv, "k21_kinematics");
    ros::NodeHandle nh;
    K21Kinematics kinematics = K21Kinematics(&nh);
    ros::spin(); 
    return 0;
}
