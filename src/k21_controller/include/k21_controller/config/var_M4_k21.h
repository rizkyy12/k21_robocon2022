// Motor 4 

float Kp_4, Ki_4, Kd_4, Ti_4, Td_4;
float interval_elapsed_4;
float interval_limit_4;

float PID4;
float et4, et4_prev;
float eint4, eint4_prev, eint4_update;
float edif4;
float setPointVel4;
float setPointRpm4;
float SV4, PV4;

int MV4;
unsigned long t4;
double t_4, Ts4;

volatile int encoderPos_4 = 0, encReal_Pos4 = 0;
float V4, rpm_m4;
unsigned long previousMillis7 = 0, previousMillis8 = 0;
const long interval7, interval8 = 100;
