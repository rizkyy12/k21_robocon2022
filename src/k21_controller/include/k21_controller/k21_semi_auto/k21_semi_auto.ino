#include <ros.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Vector3.h>

// Motor 1 Kiri - K21 ABU Robocon
#define R_PWM1 6
#define L_PWM1 7
#define ENCOA1 21
#define ENCOB1 20

// Motor 2 Kanan - K21 ABU Robocon
#define R_PWM2 9
#define L_PWM2 8
#define ENCOA2 19
#define ENCOB2 18

// Lifter - K21 ABU Robocon
#define R_PWM3 12
#define L_PWM3 13
#define ENCOA3 2
#define ENCOB3 3


long encoderPos_1, encoderPos_2, encoderPos_3 = 0;
int dir1, dir2, dir3;
int MV1, MV2, MV3;
long setPoint1, setPoint2, setPoint3 = 0;

long curT1, prevT1, eT1 = 0;
float ePrev1, deltaT1 = 0;
float dt1, eIntegral1 = 0;
int e1;
float PID1;

long curT2, prevT2, eT2 = 0;
float ePrev2, deltaT2 = 0;
float dt2, eIntegral2 = 0;
int e2;
float PID2;

long curT3, prevT3, eT3 = 0;
long int ePrev3, deltaT3 = 0;
float dt3, eIntegral3 = 0;
long int e3;
float PID3;

float interval_elapsed_1;
float interval_limit_1;
unsigned long t1;
double t_1, Ts1;

float Kp1, Ki1, Kd1;
float Kp2, Ki2, Kd2;
float Kp3, Ki3, Kd3;

int i1, i2, i3 = 0;
int i_lifter1, i_lifter2, i_lifter3 = 0;
int data_lifter1;
int data_set1, data_set2, data_set3;

String pos1_lifter;

ros::NodeHandle nh;

// --- Publisher =============================================
std_msgs::Int32 enc1_state;
ros::Publisher enc1("/k21/enc1_data", &enc1_state);

std_msgs::Int32 enc2_state;
ros::Publisher enc2("/k21/enc2_data", &enc2_state);

std_msgs::Int32 enc3_state;
ros::Publisher enc3("/k21/enc3_data", &enc3_state);

// --- Subscriber ============================================
std_msgs::Int32 sp1_state;

void setPosisi1(std_msgs::Int32 &pos1) {
  data_set1 = pos1.data;
  // posisi 1
  if (data_set1 == 1) {
    if (i1 == 0) {
      i1 = 1;
      setPoint1 = 1600;
      setPoint2 = 1600;
    }
    else {
      i1 = 0;
      setPoint1 = 0;
      setPoint2 = 0;
    }
  }
}

void setPosisi2(std_msgs::Int32 &pos2) {
  data_set2 = pos2.data;
  // posisi 1
  if (data_set2 == 2) {
    if (i2 == 0) {
      i2 = 1;
      setPoint1 = 3600;
      setPoint2 = 3600;
    }
    else {
      i2 = 0;
      setPoint1 = 0;
      setPoint2 = 0;
    }
  }
}

void setPosisi3(std_msgs::Int32 &pos3) {
  data_set3 = pos3.data;
  // posisi 1
  if (data_set3 == 3) {
    if (i3 == 0) {
      i3 = 1;
      setPoint1 = 5800;
      setPoint2 = 5800;
    }
    else {
      i3 = 0;
      setPoint1 = 0;
      setPoint2 = 0;
    }
  }
}

void cb_Lifter(geometry_msgs::Vector3 &msg){
  if (msg.x == 1){
    if (i_lifter1 == 0){
      i_lifter1 = 1;
      setPoint3 = -12318;
    }
    else{
      i_lifter1 = 0;
      setPoint3 = 0;
    }
  }
  if (msg.y == 2){
    if (i_lifter2 == 0){
      i_lifter2 = 1;
      setPoint3 = -26006;
    }
    else{
      i_lifter2 = 0;
      setPoint3 = 0;
    }
  }
  if (msg.z == 3){
    if (i_lifter3 == 0){
      i_lifter3 = 1;
      setPoint3 = -39693;
    }
    else{
      i_lifter3 = 0;
      setPoint3 = 0;
    }
  }
}

//void setPosisi3(geometry_msgs::Vector3 &msg_m3) {
//  if (msg_m3.x == 11 && msg_m3.y == 14 && msg_m3.z == 16){
//    encoderPos_1 = 0;
//    setPoint3 = 2000; 
//  }
//  else if (msg_m3.x == 12 && msg_m3.y == 13 && msg_m3.z == 16){
//    encoderPos_1 = 0;
//    setPoint3 = 3000;
//  }
//  else if (msg_m3.x == 12 && msg_m3.y == 13 && msg_m3.z == 16){
//    encoderPos_1 = 0;
//    setPoint3 = 4000;
//  }
//  else if (msg_m3.x == 12 && msg_m3.y == 14 && msg_m3.z == 16){
//    setPoint3 = 0; 
//  }
//}

ros::Subscriber<std_msgs::Int32> pos1("/k21/posisi1", setPosisi1);
ros::Subscriber<std_msgs::Int32> pos2("/k21/posisi2", setPosisi2);
ros::Subscriber<std_msgs::Int32> pos3("/k21/posisi3", setPosisi3);
//ros::Subscriber<geometry_msgs::Vector3> pos_lifter("/k21/posisilifter", cb_Lifter);

void setup() {
  Serial.begin(115200);
  setup_output();
  nh.subscribe(pos1);
  nh.subscribe(pos2);
  nh.subscribe(pos3);
//  nh.subscribe(pos_lifter);
  nh.advertise(enc1);
  nh.advertise(enc2);
  nh.advertise(enc3);
  delay(10);
}

void loop() {
  t1 = millis();
  Ts1 = (t1 - t_1) / 10;

  pid_m1();
  setMotor1(dir1, MV1, R_PWM1, L_PWM1);
  pid_m2();
  setMotor2(dir2, MV2, R_PWM2, L_PWM2);
  pid_m3();
  setMotor3(dir3, MV3, R_PWM3, L_PWM3);
  

  interval_elapsed_1 += Ts1;
  if (interval_elapsed_1 >= interval_limit_1) {
    enc1_state.data = encoderPos_1;
    enc2_state.data = encoderPos_2;
    enc3_state.data = encoderPos_3;
    enc1.publish(&enc1_state);
    enc2.publish(&enc2_state);
    enc3.publish(&enc3_state);
  }

  nh.spinOnce();
  t_1 = t1;
  delay(10);
}

void setMotor1(int dir1, int pwmVal1, int lpwmVal1, int rpwmVal1) {
  if (dir1 == 1) {
    analogWrite(R_PWM1, pwmVal1);
    analogWrite(L_PWM1, 0);
  }
  else if (dir1 == -1) {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, pwmVal1);
  }
  else {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, 0);
  }
}

void setMotor2(int dir2, int pwmVal2, int lpwmVal2, int rpwmVal2) {
  if (dir2 == 1) {
    analogWrite(R_PWM2, pwmVal2);
    analogWrite(L_PWM2, 0);
  }
  else if (dir2 == -1) {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, pwmVal2);
  }
  else {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, 0);
  }
}

void setMotor3(int dir3, int pwmVal3, int lpwmVal3, int rpwmVal3){
  if (dir3 == 1) {
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, pwmVal3);
  }
  else if(dir3 == -1){
    analogWrite(R_PWM3, pwmVal3);
    analogWrite(L_PWM3, 0);
  }
  else{
    analogWrite(R_PWM3, 0);
    analogWrite(L_PWM3, 0);
  }
}

//void lifter_auto(){
//  if (pos1_lifter == "lifter_pos1"){
//    setPoint3 = -12500;
//  }
//  else{
//    setPoint3 = 0;
//  }
//}
