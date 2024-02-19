//
#include "run.h"
#include "zf_common_headfile.h"

float target_distance=0.68;//�����µ��л���ֵ
int stop_biao=0;     //ͣ����־λ
int fan_biao=0;      //������־λ
int time_biao=0;     //ʱ���־λ
int stop_time=90;

int set_point=0;            //Ŀ�����
double set_distance=0.0;    //����һ����ľ���
double set_distance2=0.0;   //������һ����ľ���
double jiao=0.0;             //�ںϹ���ĺ����
double jiao2=0.0;              //GPS�ĺ����
char tuo_biao=0;

int yao_speed=0;//ʹ��ң��ʱ��������pwm
int pwm_sgin=0; //ʹ��ң��ʱ��������pwm
int yao_dupt=0; //�л�ң����pid���pwm�ı�־λ

int point_a=18;//Ŀ���ĸ���



void run_go(void)//�ܳ��߼�
{

    if(set_distance<target_distance&&pid_Speed->motor_duty!=0&&pid_Speed->now>20)/*&&set_distance!=0*///������һ���㻹���趨��Χ���Ҿ����ٶ��л�����һ����
    {
        set_point++;
    }

    if(set_point>=point_a)//����ͣ����־λ
    {
        stop_biao=1;
    }
    else stop_biao=0;

    if(!stop_biao&&key_run&&!time_biao)//��־λ���Ʒ���
        /*
         ���Ƹ����ٶȼ�������ֵ
         */
    {
        if((set_point==point_a-1))
        {
            pid_Speed->set=high_high;
            target_distance=1.6;
        }
        else if((set_point>=3&&set_point<=5)||(set_point==0))//(set_point>=point_a&&set_point<=(point_a+3))||(set_point==point_a+5)
        {
            pid_Speed->set=low_high;
            target_distance=1.6;
        }
        else
        {
            pid_Speed->set=low_low;
            target_distance=0.68;
        }
        /*
         ͨ��pid���Ƶ����������
         */
        if(pid_Speed->out>=0)//����ת
        {
            gpio_set_level(P02_4, GPIO_HIGH);
            pwm_set_duty(ATOM0_CH7_P02_7, pid_Speed->out);
        }
        else
        {
            gpio_set_level(P02_4, GPIO_LOW);
            pwm_set_duty(ATOM0_CH7_P02_7, -(pid_Speed->out));
        }
        pwm_set_duty(ATOM1_CH1_P33_9, 1443 - pid_Duty->out);//���ƶ��ת��
    }
    else
    {
        pwm_set_duty(ATOM0_CH7_P02_7, 0);
        pid_Speed->set=0;
    }

}
