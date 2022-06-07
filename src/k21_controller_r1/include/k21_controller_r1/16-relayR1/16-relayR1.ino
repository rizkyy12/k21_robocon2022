// Pelontar R1 - K21 Robocon
// Using ROS Serial Comunication
#include <ros.h>
#include <std_msgs/Int32.h>

#define CH1 41
#define CH2 42

int out_relay;

ros::NodeHandle nh;
std_msgs::Int32 relayR1;

void relayR1Cb(const std_msgs::Int32 &msg_relay){
  out_relay = msg_relay.data;
  if(out_relay == 1){
    digitalWrite(CH1, HIGH);
  }
  else{
    digitalWrite(CH1, LOW);
  }
}

ros::Subscriber<std_msgs::Int32> sub_relay("/relayR1", relayR1Cb);

void setup() {
  Serial.begin(115200);
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  nh.subscribe(sub_relay);
}

void loop() {
  nh.spinOnce();
  delay(5);
}
