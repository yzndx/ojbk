//
#include "run.h"
#include "zf_common_headfile.h"

float target_distance=0.68;//距离下点切换阈值
int stop_biao=0;     //停车标志位
int fan_biao=0;      //翻车标志位
int time_biao=0;     //时间标志位
int stop_time=90;

int set_point=0;            //目标点数
double set_distance=0.0;    //与下一个点的距离
double set_distance2=0.0;   //与下下一个点的距离
double jiao=0.0;             //融合过后的航向角
double jiao2=0.0;              //GPS的航向角
char tuo_biao=0;

int yao_speed=0;//使用遥控时电机输出的pwm
int pwm_sgin=0; //使用遥控时舵机输出的pwm
int yao_dupt=0; //切换遥控与pid输出pwm的标志位

int point_a=18;//目标点的个数



void run_go(void)//跑车逻辑
{

    if(set_distance<target_distance&&pid_Speed->motor_duty!=0&&pid_Speed->now>20)/*&&set_distance!=0*///距离下一个点还有设定范围并且具有速度切换下下一个点
    {
        set_point++;
    }

    if(set_point>=point_a)//点数停车标志位
    {
        stop_biao=1;
    }
    else stop_biao=0;

    if(!stop_biao&&key_run&&!time_biao)//标志位控制发车
        /*
         控制各点速度及距离阈值
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
         通过pid控制电机及舵机打角
         */
        if(pid_Speed->out>=0)//正反转
        {
            gpio_set_level(P02_4, GPIO_HIGH);
            pwm_set_duty(ATOM0_CH7_P02_7, pid_Speed->out);
        }
        else
        {
            gpio_set_level(P02_4, GPIO_LOW);
            pwm_set_duty(ATOM0_CH7_P02_7, -(pid_Speed->out));
        }
        pwm_set_duty(ATOM1_CH1_P33_9, 1443 - pid_Duty->out);//控制舵机转动
    }
    else
    {
        pwm_set_duty(ATOM0_CH7_P02_7, 0);
        pid_Speed->set=0;
    }

}
