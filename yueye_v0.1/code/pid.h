
#ifndef _PID_H_
#define _PID_H_

#include "zf_common_headfile.h"


//void speed_pid(void);
//void duty_pid(void);
//int pid();

typedef struct {
        float kp;
        float ki;
        float kd;
        int set;//目标值
        int now;//现在值
        int ek;//误差值
        int ek1;//上次误差值
        int ek2;//上上次误差值
        int out;//计算值
        int motor_duty;//输出值
} MotorPID;

extern MotorPID pid1;
extern MotorPID *pid_Speed;
extern MotorPID pid2;
extern MotorPID *pid_Duty;

void MotorPID_init(MotorPID* pid, float kp, float ki, float kd);
void speed_pid(MotorPID* pid);

void MotorPID_init2(MotorPID* pid, float kp, float kd);
void duty_pid(MotorPID* pid, double yaw, double jiao2);

#endif
