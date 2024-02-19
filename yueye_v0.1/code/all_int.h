#ifndef _ALL_INT_h
#define _ALL_INT_h

#include "zf_common_headfile.h"

#define mid 1443

extern float l_gyro_x;               //陀螺仪滤波x轴
extern float l_gyro_y;               //陀螺仪滤波y轴
extern float l_gyro_z;               //陀螺仪滤波z轴
extern float l_acc_x;                //加速度计滤波x轴
extern float l_acc_y;                //加速度计滤波y轴
extern float l_acc_z;                //加速度计滤波z轴
extern float l_mag_x;                //磁力计滤波x轴
extern float l_mag_y;                //磁力计滤波y轴
extern float l_mag_z;                //磁力计滤波z轴

extern int n;
extern int arr[500];

void lb_inint(void);
void all_init(void);

#endif
