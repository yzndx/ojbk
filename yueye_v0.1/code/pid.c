
#include "pid.h"
#include "zf_common_headfile.h"

#define ENCODER_QUADDEC                 (TIM5_ENCOEDER)// 正交编码器对应使用的编码器接口（无刷）
#define proportion                      0.999           //互补滤波系数 /*此系数越大越信任九轴*/

/*
 定义结构体及结构体指针
 */
MotorPID pid1;
MotorPID *pid_Speed=&pid1;
MotorPID pid2;
MotorPID *pid_Duty=&pid2;


void MotorPID_init(MotorPID* pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->set = 0;
    pid->now = 0;
    pid->ek = 0 ;
    pid->ek1 = 0;
    pid->ek2 = 0;
    pid->out = 0;
    pid->motor_duty = 0;
}

void speed_pid(MotorPID* pid)
{
    pid->now = encoder_get_count(ENCODER_QUADDEC) / 2; // 获取编码器计数
    encoder_clear_count(ENCODER_QUADDEC); // 清空编码器计数
    pid->ek2 = pid->ek1; // 保存上上次误差
    pid->ek1 = pid->ek; // 保存上次误差
    pid->ek = pid->set - pid->now; // 计算当前误差

    pid->motor_duty = (int)(pid->kp * (pid->ek - pid->ek1) + pid->ki * pid->ek + pid->kd * (pid->ek - 2 * pid->ek1 + pid->ek2)); // 计算增量
//    if(pid->motor_duty > 249)
//    { // 限幅
//        pid->motor_duty = 249;
//    }
//    if(pid->motor_duty < -30)
//    { // 限幅
//        pid->motor_duty = -30;
//    }
    pid->out += pid->motor_duty;       //输出pwm
    if(pid->out > 9000)
    { // 限幅
        pid->out = 9000;
    }
    if(pid->out < -5000)
    { // 限幅
        pid->out = -5000;
    }
}

void MotorPID_init2(MotorPID* pid, float kp,  float kd)
{
    pid->kp = kp;
    pid->ki = 0;
    pid->kd = kd;
    pid->set = 0;
    pid->now = 0;
    pid->ek = 0;
    pid->ek1 = 0;
    pid->ek2 = 0;
    pid->out = 0;
    pid->motor_duty = 0;
}

void duty_pid(MotorPID* pid, double yaw, double jiao2)
{
    double jiao = 0;

    //    if(fabs(gps_tau1201.direction - yaw) > 50) {
    //        jiao = 0;
    //    }
    //    else {
    jiao = jiao2 * proportion + gps_tau1201.direction * (1 - proportion);//互补滤波
    //    }

    if(fabs(jiao - yaw) < 180)
    {
        pid->now = jiao - yaw;
    }
    else
    {
        if(jiao > 180)
        {
            jiao = 360 - jiao;
            pid->now = -(jiao + yaw);
        }
        else if(yaw > 180)
        {
            yaw = 360 - yaw;
            pid->now = jiao + yaw;
        }
    }

    pid->ek1 = pid->ek; // 保存上次误差
    pid->ek = pid->set - pid->now; // 计算本次误差
    pid->out = (int)(pid->kp * pid->ek + pid->kd * (pid->ek - pid->ek1)); // 进行PD运算

    if(pid->out > 170*2.2)
    { // 限幅
        pid->out = 170*2.2;
    }
    if(pid->out < -170*2.2)
    { // 限幅
        pid->out = -170*2.2;
    }
}

//void speed_pid(void)
//{
//    speed = encoder_get_count(ENCODER_QUADDEC)/2;// 获取编码器计数
//    encoder_clear_count(ENCODER_QUADDEC);// 清空编码器计数
//    ek2 = ek1;//保存上上次误差
//    ek1 = ek; //保存上次误差
//    ek = set_speed - speed;//计算当前误差
//    out_increment = (int16)(kp*(ek-ek1) + ki*ek + kd*(ek-2*ek1+ek2));  //计算增量
//    out += out_increment;       //输出增量
//    if(out>3000)//限幅
//    {
//        out=3000;
//    }
//    if(out<-3000)//限幅
//    {
//        out=-3000;
//    }
//}

//void duty_pid(void)
//{
//    //position=yaw-jiao2;//此次数据
//
//    if(fabs(gps_tau1201.direction-yaw)>50)
//    {
//        jiao=0;
//    }
//    else jiao=jiao2*proportion+gps_tau1201.direction*(1-proportion);
//    if(fabs(jiao-yaw)<180)
//    {
//        position=jiao-yaw;
//    }
//    if(fabs(jiao-yaw)>=180)
//    {
//        if(jiao>180)
//        {
//            jiao=360-jiao;
//            position=-(jiao+yaw);
//        }
//        else if(yaw>180)
//        {
//            yaw=360-yaw; position=jiao+yaw;
//        }
//    }
//
//    Ek1 = Ek;//保存上次误差
//    Ek = set_position - position;//计算本次误差
//
//    smotor_duty = (int)(Kp*Ek + Kd*(Ek-Ek1));//进行PD运算
//    if(smotor_duty>170)//限幅
//    {
//        smotor_duty=170;
//    }
//    if(smotor_duty<-170)//限幅
//    {
//        smotor_duty=-170;
//    }
//}
