
#ifndef _RUN_H_
#define _RUN_H_
#include "zf_common_headfile.h"
#define num         32//�����С��ע��ÿ���޸���Ҫ��������
extern char tuo_biao;
//extern MotorPID *speed_pid_1;
extern float target_distance;
extern double jiao;
extern double jiao2;

//extern double distance;
//extern double we[num];
//extern double ns[num];
extern double set_distance;
extern double set_distance2;
extern int set_point;//Ŀ���
extern int yao_dupt;
extern int yao_speed;//ʹ��ң��ʱ��������pwm
extern int pwm_sgin;//ʹ��ң��ʱ��������pwm
extern int stop_biao;
void run_go(void);

extern int point_a;
extern int fan_biao;
extern int time_biao;
extern int stop_time;

#endif
