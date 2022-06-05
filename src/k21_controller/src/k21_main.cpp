#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Twist.h"

int Vx, Vy, w;

class K21Main{
    private:
        ros::Subscriber joy;
        ros::Publisher vel_pub;
        ros::Publisher lifter_pub;

    public:
        K21Main(ros::NodeHandle *nh){
            vel_pub = nh->advertise<geometry_msgs::Twist>("/cmd_vel", 10);
            joy = nh->subscribe("/joy", 10, &K21Main::joyCb, this);


            // v_right_f_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/right_f_motor/command", 1);
            // v_left_f_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/left_f_motor/command", 1);
            // v_left_b_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/left_b_motor/command", 1);
            // v_right_b_Command = nh->advertise<std_msgs::Float64>("/k21_robocon/right_b_motor/command", 1);
        }
        void joyCb(const sensor_msgs::Joy& msg){

            geometry_msgs::Twist vel;

            // Base Command ====================================================
            // Y Axis
            if (msg.axes[1] == 1){
                vel.linear.y = 180;
                vel.linear.x = 0;
                vel.linear.z = 0;
            }
            else if(msg.axes[1] == -1){
                vel.linear.y = -180;
                vel.linear.x = 0;
                vel.linear.z = 0;
            }

            vel_pub.publish(vel);

            // ROS_INFO("Vx : %f", vel.linear.x);
            // ROS_INFO("Vy : %f", vel.linear.y);
            // ROS_INFO("w : %f", vel.angular.z);

            //X Axis
            // if (msg.axes[6] == -1){
            //     vel.Vx = 250;
            //     vel.Vy = 0;
            //     vel.w = 0;
            // }
            // else if(msg.axes[6] == 1){
            //     vel.Vx = -250;
            //     vel.Vy = 0;
            //     vel.w = 0;
            // }

            // // Rotate
            // if (msg.axes[3] == -1){
            //     vel.Vx = 0;
            //     vel.Vy = 0;
            //     vel.w = 250;
            // }
            // else if (msg.axes[3] == 1){
            //     vel.Vx = 0;
            //     vel.Vy = 0;
            //     vel.w = -250;
            // }

            // // Serong Kanan
            // for(int i = 0; i < 6; i++){
            //     if (msg.axes[6] == -1 && msg.axes[7] == 1 && msg.axes[i] == 0){
            //         vel.Vx = 180;
            //         vel.Vy = 180;
            //         vel.w = 0;
            //     }
            //     else if (msg.axes[6] == 1 && msg.axes[7] == -1 && msg.axes[i] == 0){
            //         vel.Vx = -180;
            //         vel.Vy = -180;
            //         vel.w = 0;
            //     }
            // }
            
            // // Serong Kiri
            // for (int j = 0; j < 6; j++){
            //     if (msg.axes[6] == 1 && msg.axes[7] == 1 && msg.axes[j] == 0){
            //         vel.Vx = -180;
            //         vel.Vy = 180;
            //         vel.w = 0;
            //     }
            //     else if (msg.axes[6] == -1 && msg.axes[7] == -1 && msg.axes[j] == 0){
            //         vel.Vx = 180;
            //         vel.Vy = -180;
            //         vel.w = 0;
            //     }
            // }
            // End Base Command ====================================================

            // vel_pub.publish(vel);
        }
        

};

int main(int argc, char** argv){
    ros::init(argc, argv, "k21_main");
    ros::NodeHandle nh;
    K21Main main = K21Main(&nh);
    ros::spin();
    return 0;
}
