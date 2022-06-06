// Motor 1 
float Kp_1, Ki_1, Kd_1, Ti_1, Td_1;  
float interval_elapsed_1;
float interval_limit_1;

float PID1;
float et1, et1_prev;
float eint1, eint1_prev, eint1_update;
float edif1;
float setPointVel1;
float SV1, PV1;
float setPointRpm1;

int MV1;
unsigned long t1;
double t_1, Ts1;

volatile int encoderPos_1 = 0, encReal_Pos1 = 0;
float V1, rpm_m1;

unsigned long previousMillis1 = 0, previousMillis2 = 0;
const long interval1, interval2 = 100;

