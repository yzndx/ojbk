#ifndef _ALL_INT_h
#define _ALL_INT_h

#include "zf_common_headfile.h"

#define mid 1443

extern float l_gyro_x;               //�������˲�x��
extern float l_gyro_y;               //�������˲�y��
extern float l_gyro_z;               //�������˲�z��
extern float l_acc_x;                //���ٶȼ��˲�x��
extern float l_acc_y;                //���ٶȼ��˲�y��
extern float l_acc_z;                //���ٶȼ��˲�z��
extern float l_mag_x;                //�������˲�x��
extern float l_mag_y;                //�������˲�y��
extern float l_mag_z;                //�������˲�z��

extern int n;
extern int arr[500];

void lb_inint(void);
void all_init(void);

#endif
