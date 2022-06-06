// Motor 3
float Kp_3, Ki_3, Kd_3, Ti_3, Td_3;  

float interval_elapsed_3;
float interval_limit_3;

float PID3;
float et3, et3_prev;
float eint3, eint3_prev, eint3_update;
float edif3;
float setPointVel3;
float SV3, PV3;
float setPointRpm3;

int MV3;
unsigned long t3;
double t_3, Ts3;

volatile int encoderPos_3 = 0, encReal_Pos3 = 0;
float V3, rpm_m3;
unsigned long previousMillis5 = 0, previousMillis6 = 0;
const long interval5, interval6 = 100;

