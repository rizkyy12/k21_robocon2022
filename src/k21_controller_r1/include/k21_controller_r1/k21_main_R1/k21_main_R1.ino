#include <ros.h>

#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>
#include <util/atomic.h>

// ========= Motor Pin

#define R_PWM1 12
#define L_PWM1 13

#define R_PWM2 7
#define L_PWM2 6

#define R_PWM3 5
#define L_PWM3 4

#define R_PWM4 8
#define L_PWM4 9

#define R_PWM_MOT_ATAS 11
#define L_PWM_MOT_BAWAH 10

// Relay ===========================
#define CH1 45

// ============== Motor
int dir1, dir2, dir3, dir4;

int Vx, Vx_1;
int Vy, Vy_1;
int w, w_1;

// ============ Pelontar
double output;
int i_pelontar;

// ============ Relay
int out_relay;
int i_relay;


unsigned long lasttimepub, now;
ros::NodeHandle nh;

//=============== Callback Motor
void cmdCb(const geometry_msgs::Twist& msg) {
  Vx = msg.linear.x;
  Vy = msg.linear.y;
  w = msg.angular.z;

  if (w == 1) {
    Vx = 0;
    Vy = 0;
    w = 200;
  }
  else if (w == -1) {
    Vx = 0;
    Vy = 0;
    w = -200;
  }
}

// ============== Callback Pelontar
void pelontarCb(const std_msgs::Float64 &msg_pelontar) {
  output = msg_pelontar.data;
  if (output == 1) {
    i_pelontar++;
    if (i_pelontar == 1) {
      analogWrite(R_PWM_MOT_ATAS, 120);

      analogWrite(L_PWM_MOT_BAWAH, 120);
    }
    else if (i_pelontar == 2) {
      analogWrite(R_PWM_MOT_ATAS, 0);
      analogWrite(L_PWM_MOT_BAWAH, 0);
    }
  }
}

// ============== Callback Relay
void relayR1Cb(const std_msgs::Int32 &msg_relay){
  out_relay = msg_relay.data;
  if(out_relay == 1){
    i_relay++;
    if(i_relay == 1){
      digitalWrite(CH1, HIGH);
    }
    if(i_relay == 2){
      digitalWrite(CH1, LOW);
    }
  }
}


// ==================================== Subscribe For /cmd vel ==================================
ros::Subscriber<geometry_msgs::Twist> sub_cmdVel("/cmd_vel_r1", cmdCb);
// ==============================================================================================
// ==================================== Subscribe For Pelontar =================================
ros::Subscriber<std_msgs::Float64> sub_pelontar("/pelontar", pelontarCb);
// ==============================================================================================
// ==================================== Subscribe For Pelontar =================================
ros::Subscriber<std_msgs::Int32> sub_relay("/relayR1", relayR1Cb);
// ==============================================================================================


void setup() {
  Serial.begin(115200);
  setup_output();
  nh.subscribe(sub_cmdVel);
  nh.subscribe(sub_pelontar);
  nh.subscribe(sub_relay);
}

void loop() {
  Vx_1 = 0;
  Vy_1 = 0;
  w_1 = 0;

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    Vx_1 = Vx;
    Vy_1 = Vy;
    w_1 = w;
  }
  motor_1(Vx, Vy, w);
  motor_2(Vx, Vy, w);
  motor_3(Vx, Vy, w);
  motor_4(Vx, Vy, w);
  
  nh.spinOnce();
  delay(5);

}
