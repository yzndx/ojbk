#include "963_MahonyAhrd.h"
#include "zf_common_headfile.h"

calibration nine;
calibration *lb_nine=&nine;
double yaw1=0.0; //姿态传感器上一次的航向角
double yaw=0.0;  //姿态传感器此次的航向角
double pitch=0.0;//翻滚角
double roll=0.0; //俯仰角
void calibration_init(calibration *lb_nine, int n)
{
    lb_nine->l_gyro_z = 0;
    lb_nine->l_acc_x = 0;
    lb_nine->l_acc_y = 0;
    lb_nine->l_acc_z = 0;
    lb_nine->l_mag_x = 0;
    lb_nine->l_mag_y = 0;
    lb_nine->l_mag_z = 0;
    lb_nine->n = n;
    lb_nine->arr[n] = 0;
}

float mapValue(float input, float targetMin, float targetMax)
{
    float inputMin = 0.0;
    float inputMax = 45.0;

    // 对输入值进行范围限制
    if (input < inputMin) {
        input = inputMin;
    }
    if (input > inputMax) {
        input = inputMax;
    }

    // 计算映射后的值
    float output = ((input - inputMin) / (inputMax - inputMin)) * (targetMax - targetMin) + targetMin;

    return output;
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a, num2 = *(int *)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}
/*
 最开始的找零飘值方式，也可试试
 */
float avg_median_avg(int arr[], int n) //校准九轴（找平均值，中位值，及其两者的平均值）
{
    imu963ra_init();//九轴初始化
    // 使用qsort函数对数组进行排序
    for(int i=0;i<n;i++)
    {
        imu963ra_get_gyro();
        arr[i]=imu963ra_gyro_z;  // 读取陀螺仪z轴的值
        system_delay_ms(2);
    }
    qsort(arr, n, sizeof(int), compare);
    // 计算平均数
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    float avg = (float)sum / n;
    // 计算中位数
    float median;
    if (n % 2 == 0)
    {
        median = (float)(arr[n/2 - 1] + arr[n/2]) / 2;
    } else {
        median = (float)arr[n/2];
    }
    // 计算平均数加中位数的平均数
    //    float result = (avg + median) / 2;
    return avg;
}
float Gyro_calibration_x(int arr[], int n)//陀螺仪x轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_gyro();
        arr[i]=imu963ra_gyro_x;  // 读取陀螺仪x轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float Gyro_calibration_y(int arr[], int n)//陀螺仪y轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_gyro();
        arr[i]=imu963ra_gyro_y;  // 读取陀螺仪y轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float Gyro_calibration_z(int arr[], int n)//陀螺仪z轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_gyro();
        arr[i]=imu963ra_gyro_z;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}

float mag_calibration_x(int arr[], int n)//磁力计x轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_mag();
        arr[i]=imu963ra_gyro_x;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float mag_calibration_y(int arr[], int n)//磁力计y轴校准

{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_mag();
        arr[i]=imu963ra_gyro_y;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float mag_calibration_z(int arr[], int n)//磁力计z轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_mag();
        arr[i]=imu963ra_gyro_z;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}


float acc_calibration_x(int arr[], int n)//加速度计x轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_acc();
        arr[i]=imu963ra_acc_x;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float acc_calibration_y(int arr[], int n)//加速度计y轴校准

{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_acc();
        arr[i]=imu963ra_acc_y;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
float acc_calibration_z(int arr[], int n)//加速度计z轴校准
{
    imu963ra_init();//九轴初始化
    for(int i=0;i<n;i++)
    {
        imu963ra_get_acc();
        arr[i]=imu963ra_acc_z;  // 读取陀螺仪z轴的值
        system_delay_ms(4);
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return (max+min)/2.0;
}
//float get_avg_gyro_z(int num_samples)//
//{
//    float sum = 0.0;
//    int16 gyro_z;
//    int i;
//
//    for (i = 0; i < num_samples; i++)
//    {
//        imu963ra_get_gyro();
//        gyro_z = imu963ra_gyro_z;  // 读取陀螺仪z轴的值
//        system_delay_ms(5);
//        sum += gyro_z;           // 累加到总和
//    }
//
//    return sum / num_samples;   // 返回平均值
//}





























/*
 移植的卡尔曼滤波四元数解算，但是效果差
 */







////---------------------------------------------------------------------------------------------------
//// Definitions
//
//#define sampleFreq  660.0f          // sample frequency in Hz
//#define twoKpDef    (0.0000000001)  // 2 * proportional gain
//#define twoKiDef    (0.0000000028)  // 2 * integral gain
//
////---------------------------------------------------------------------------------------------------
//// Variable definitions
//
//volatile float twoKp = twoKpDef;                                            // 2 * proportional gain (Kp)
//volatile float twoKi = twoKiDef;                                            // 2 * integral gain (Ki)
//extern float q0 = 0.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;                    // quaternion of sensor frame relative to auxiliary frame
//volatile float integralFBx = 0.0f,  integralFBy = 0.0f, integralFBz = 0.0f; // integral error terms scaled by Ki
//
////---------------------------------------------------------------------------------------------------
//// Function declarations
//
//float invSqrt(float x);
//
////====================================================================================================
//// Functions
//
////---------------------------------------------------------------------------------------------------
//// AHRS algorithm update
//
//void MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
//{
//    float recipNorm;
//    float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
//    float hx, hy, bx, bz;
//    float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
//    float halfex, halfey, halfez;
//    float qa, qb, qc;
//
//    // Use IMU algorithm if magnetometer measurement invalid (avoids NaN in magnetometer normalisation)
//    if((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
//        MahonyAHRSupdateIMU(gx, gy, gz, ax, ay, az);
//        return;
//    }
//
//    // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
//    if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {
//
//        // Normalise accelerometer measurement
//        recipNorm = invSqrt(ax * ax + ay * ay + az * az);
//        ax *= recipNorm;
//        ay *= recipNorm;
//        az *= recipNorm;
//
//        // Normalise magnetometer measurement
//
//        recipNorm = invSqrt(mx * mx + my * my + mz * mz);
//        mx *= recipNorm;
//        my *= recipNorm;
//        mz *= recipNorm;
//
//        // Auxiliary variables to avoid repeated arithmetic
//        q0q0 = q0 * q0;
//        q0q1 = q0 * q1;
//        q0q2 = q0 * q2;
//        q0q3 = q0 * q3;
//        q1q1 = q1 * q1;
//        q1q2 = q1 * q2;
//        q1q3 = q1 * q3;
//        q2q2 = q2 * q2;
//        q2q3 = q2 * q3;
//        q3q3 = q3 * q3;
//
//        // Reference direction of Earth's magnetic field
//        hx = 2.0f * (mx * (0.5f - q2q2 - q3q3) + my * (q1q2 - q0q3) + mz * (q1q3 + q0q2));
//        hy = 2.0f * (mx * (q1q2 + q0q3) + my * (0.5f - q1q1 - q3q3) + mz * (q2q3 - q0q1));
//        bx = sqrtf(hx * hx + hy * hy);
//        bz = 2.0f * (mx * (q1q3 - q0q2) + my * (q2q3 + q0q1) + mz * (0.5f - q1q1 - q2q2));
//
//        // Estimated direction of gravity and magnetic field
//        halfvx = q1q3 - q0q2;
//        halfvy = q0q1 + q2q3;
//        halfvz = q0q0 - 0.5f + q3q3;
//        halfwx = bx * (0.5f - q2q2 - q3q3) + bz * (q1q3 - q0q2);
//        halfwy = bx * (q1q2 - q0q3) + bz * (q0q1 + q2q3);
//        halfwz = bx * (q0q2 + q1q3) + bz * (0.5f - q1q1 - q2q2);
//
//        // Error is sum of cross product between estimated direction and measured direction of field vectors
//        halfex = (ay * halfvz - az * halfvy) + (my * halfwz - mz * halfwy);
//        halfey = (az * halfvx - ax * halfvz) + (mz * halfwx - mx * halfwz);
//        halfez = (ax * halfvy - ay * halfvx) + (mx * halfwy - my * halfwx);
//
//        // Compute and apply integral feedback if enabled
//        if(twoKi > 0.0f) {
//            integralFBx += twoKi * halfex * (1.0f / sampleFreq);    // integral error scaled by Ki
//            integralFBy += twoKi * halfey * (1.0f / sampleFreq);
//            integralFBz += twoKi * halfez * (1.0f / sampleFreq);
//            gx += integralFBx;  // apply integral feedback
//            gy += integralFBy;
//            gz += integralFBz;
//        }
//        else {
//            integralFBx = 0.0f; // prevent integral windup
//            integralFBy = 0.0f;
//            integralFBz = 0.0f;
//        }
//
//        // Apply proportional feedback
//        gx += twoKp * halfex;
//        gy += twoKp * halfey;
//        gz += twoKp * halfez;
//    }
//
//    // Integrate rate of change of quaternion
//    gx *= (0.5f * (1.0f / sampleFreq));     // pre-multiply common factors
//    gy *= (0.5f * (1.0f / sampleFreq));
//    gz *= (0.5f * (1.0f / sampleFreq));
//    qa = q0;
//    qb = q1;
//    qc = q2;
//    q0 += (-qb * gx - qc * gy - q3 * gz);
//    q1 += (qa * gx + qc * gz - q3 * gy);
//    q2 += (qa * gy - qb * gz + q3 * gx);
//    q3 += (qa * gz + qb * gy - qc * gx);
//    //q3=q3+ 0.000000311;
//    // Normalise quaternion
//    recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
//    q0 *= recipNorm;
//    q1 *= recipNorm;
//    q2 *= recipNorm;
//    q3 *= recipNorm;
//    if(q3>0)
//    {
//         q3=q3-0.0000911;
//    }
//    else q3=q3+0.0000911;
//    yaw = atan2f(2 * q1 * q2 + 2 * q0 * q3, -2 * q2*q2 - 2 * q3* q3 + 1)* 57.3-180; // yaw
////    if(yaw<0)
////    {
////        yaw=yaw+360;
////    }
//    pitch= asinf(-2 * q1 * q3 + 2 * q0* q2)* 57.3; // pitch
//    roll= atan2f(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2* q2 + 1)* 57.3; // roll
//}
////---------------------------------------------------------------------------------------------------
//// IMU algorithm update
//
//void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az) {
//    float recipNorm;
//    float halfvx, halfvy, halfvz;
//    float halfex, halfey, halfez;
//    float qa, qb, qc;
//
//    // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
//    if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {
//
//        // Normalise accelerometer measurement
//        recipNorm = invSqrt(ax * ax + ay * ay + az * az);
//        ax *= recipNorm;
//        ay *= recipNorm;
//        az *= recipNorm;
//
//        // Estimated direction of gravity and vector perpendicular to magnetic flux
//        halfvx = q1 * q3 - q0 * q2;
//        halfvy = q0 * q1 + q2 * q3;
//        halfvz = q0 * q0 - 0.5f + q3 * q3;
//
//        // Error is sum of cross product between estimated and measured direction of gravity
//        halfex = (ay * halfvz - az * halfvy);
//        halfey = (az * halfvx - ax * halfvz);
//        halfez = (ax * halfvy - ay * halfvx);
//
//        // Compute and apply integral feedback if enabled
//        if(twoKi > 0.0f) {
//            integralFBx += twoKi * halfex * (1.0f / sampleFreq);    // integral error scaled by Ki
//            integralFBy += twoKi * halfey * (1.0f / sampleFreq);
//            integralFBz += twoKi * halfez * (1.0f / sampleFreq);
//            gx += integralFBx;  // apply integral feedback
//            gy += integralFBy;
//            gz += integralFBz;
//        }
//        else {
//            integralFBx = 0.0f; // prevent integral windup
//            integralFBy = 0.0f;
//            integralFBz = 0.0f;
//        }
//
//        // Apply proportional feedback
//        gx += twoKp * halfex;
//        gy += twoKp * halfey;
//        gz += twoKp * halfez;
//    }
//
//    // Integrate rate of change of quaternion
//    gx *= (0.5f * (1.0f / sampleFreq));     // pre-multiply common factors
//    gy *= (0.5f * (1.0f / sampleFreq));
//    gz *= (0.5f * (1.0f / sampleFreq));
//    qa = q0;
//    qb = q1;
//    qc = q2;
//    q0 += (-qb * gx - qc * gy - q3 * gz);
//    q1 += (qa * gx + qc * gz - q3 * gy);
//    q2 += (qa * gy - qb * gz + q3 * gx);
//    q3 += (qa * gz + qb * gy - qc * gx);
//
//    // Normalise quaternion
//    recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
//    q0 *= recipNorm;
//    q1 *= recipNorm;
//    q2 *= recipNorm;
//    q3 *= recipNorm;
//
//
//    yaw = atan2f(2 * q1 * q2 + 2 * q0 * q3, -2 * q2*q2 - 2 * q3* q3 + 1)* 57.3-180;//*0.83
//
//
//
//    pitch= asinf(-2 * q1 * q3 + 2 * q0* q2)* 57.3; // pitch
//    roll= atan2f(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2* q2 + 1)* 57.3; // roll
//
//}
//
////---------------------------------------------------------------------------------------------------
//// Fast inverse square-root
//// See: http://en.wikipedia.org/wiki/Fast_inverse_square_root
//
//float invSqrt(float x) {
//    float halfx = 0.5f * x;
//    float y = x;
//    long i = *(long*)&y;
//    i = 0x5f3759df - (i>>1);
//    y = *(float*)&i;
//    y = y * (1.5f - (halfx * y * y));
//    return y;
//}
//
////====================================================================================================
//// END OF CODE
////====================================================================================================










