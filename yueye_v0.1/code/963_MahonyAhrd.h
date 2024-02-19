#ifndef _963_MAHONYAHRD_H_
#define _963_MAHONYAHRD_H_

#include "zf_common_headfile.h"

extern double yaw1; //姿态传感器上一次的航向角
extern double yaw;  //姿态传感器此次的航向角
extern double pitch;//翻滚角
extern double roll; //俯仰角
//extern float yaw1;
//extern int i;
//extern float q0, q1 , q2 , q3 ;
//----------------------------------------------------------------------------------------------------
// Variable declaration
//
//extern volatile float twoKp;            // 2 * proportional gain (Kp)
//extern volatile float twoKi;            // 2 * integral gain (Ki)
//
////---------------------------------------------------------------------------------------------------
//// Function declarations
//
//void MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
//void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);
float mapValue(float input, float targetMin, float targetMax);
int compare(const void *a, const void *b);
float avg_median_avg(int arr[], int n);

//float get_avg_gyro_z(int num_samples);
float Gyro_calibration_x(int arr[], int n);
float Gyro_calibration_y(int arr[], int n);
float Gyro_calibration_z(int arr[], int n);
float mag_calibration_x(int arr[], int n);
float mag_calibration_y(int arr[], int n);
float mag_calibration_z(int arr[], int n);
float acc_calibration_x(int arr[], int n);
float acc_calibration_y(int arr[], int n);
float acc_calibration_z(int arr[], int n);

/*
 想以结构体统一变量，但是没有时间了
 */
typedef struct {
        float l_gyro_z;               //陀螺仪滤波z轴
        float l_acc_x;                //加速度计滤波x轴
        float l_acc_y;                //加速度计滤波y轴
        float l_acc_z;                //加速度计滤波z轴
        float l_mag_x;                //磁力计滤波x轴
        float l_mag_y;                //磁力计滤波y轴
        float l_mag_z;                //磁力计滤波
        int n;
        int arr[2000];
}calibration;

void calibration_init(calibration *lb_nine, int n);

#endif
