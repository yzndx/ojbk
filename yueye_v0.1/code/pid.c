
#include "pid.h"
#include "zf_common_headfile.h"

#define ENCODER_QUADDEC                 (TIM5_ENCOEDER)// ������������Ӧʹ�õı������ӿڣ���ˢ��
#define proportion                      0.999           //�����˲�ϵ�� /*��ϵ��Խ��Խ���ξ���*/

/*
 ����ṹ�弰�ṹ��ָ��
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
    pid->now = encoder_get_count(ENCODER_QUADDEC) / 2; // ��ȡ����������
    encoder_clear_count(ENCODER_QUADDEC); // ��ձ���������
    pid->ek2 = pid->ek1; // �������ϴ����
    pid->ek1 = pid->ek; // �����ϴ����
    pid->ek = pid->set - pid->now; // ���㵱ǰ���

    pid->motor_duty = (int)(pid->kp * (pid->ek - pid->ek1) + pid->ki * pid->ek + pid->kd * (pid->ek - 2 * pid->ek1 + pid->ek2)); // ��������
//    if(pid->motor_duty > 249)
//    { // �޷�
//        pid->motor_duty = 249;
//    }
//    if(pid->motor_duty < -30)
//    { // �޷�
//        pid->motor_duty = -30;
//    }
    pid->out += pid->motor_duty;       //���pwm
    if(pid->out > 9000)
    { // �޷�
        pid->out = 9000;
    }
    if(pid->out < -5000)
    { // �޷�
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
    jiao = jiao2 * proportion + gps_tau1201.direction * (1 - proportion);//�����˲�
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

    pid->ek1 = pid->ek; // �����ϴ����
    pid->ek = pid->set - pid->now; // ���㱾�����
    pid->out = (int)(pid->kp * pid->ek + pid->kd * (pid->ek - pid->ek1)); // ����PD����

    if(pid->out > 170*2.2)
    { // �޷�
        pid->out = 170*2.2;
    }
    if(pid->out < -170*2.2)
    { // �޷�
        pid->out = -170*2.2;
    }
}

//void speed_pid(void)
//{
//    speed = encoder_get_count(ENCODER_QUADDEC)/2;// ��ȡ����������
//    encoder_clear_count(ENCODER_QUADDEC);// ��ձ���������
//    ek2 = ek1;//�������ϴ����
//    ek1 = ek; //�����ϴ����
//    ek = set_speed - speed;//���㵱ǰ���
//    out_increment = (int16)(kp*(ek-ek1) + ki*ek + kd*(ek-2*ek1+ek2));  //��������
//    out += out_increment;       //�������
//    if(out>3000)//�޷�
//    {
//        out=3000;
//    }
//    if(out<-3000)//�޷�
//    {
//        out=-3000;
//    }
//}

//void duty_pid(void)
//{
//    //position=yaw-jiao2;//�˴�����
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
//    Ek1 = Ek;//�����ϴ����
//    Ek = set_position - position;//���㱾�����
//
//    smotor_duty = (int)(Kp*Ek + Kd*(Ek-Ek1));//����PD����
//    if(smotor_duty>170)//�޷�
//    {
//        smotor_duty=170;
//    }
//    if(smotor_duty<-170)//�޷�
//    {
//        smotor_duty=-170;
//    }
//}
