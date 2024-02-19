
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
        int set;//Ŀ��ֵ
        int now;//����ֵ
        int ek;//���ֵ
        int ek1;//�ϴ����ֵ
        int ek2;//���ϴ����ֵ
        int out;//����ֵ
        int motor_duty;//���ֵ
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
