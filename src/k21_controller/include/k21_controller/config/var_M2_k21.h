// Motor 2
float Kp_2, Ki_2, Kd_2, Ti_2, Td_2;  

float interval_elapsed_2;
float interval_limit_2;

float PID2;
float et2, et2_prev;
float eint2, eint2_prev, eint2_update;
float edif2;
float setPointVel2;
float setPointRpm2;
float SV2, PV2;

int MV2;
unsigned long t2;
double t_2, Ts2;

volatile int encoderPos_2 = 0, encReal_Pos2 = 0;
float V2, rpm_m2;

unsigned long previousMillis3 = 0, previousMillis4 = 0;
const long interval3, interval4 = 100;


