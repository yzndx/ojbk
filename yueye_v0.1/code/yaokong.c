
#include "yaokong.h"
/*
 ң�ص�ԭ���Ǽ����ͨ���ĸߵ�ƽʱ��
 */
#define X6F_CH1                         (P21_3)      //�����ͨ��
#define X6F_CH2                         (P21_5)      //����ͨ��
#define X6F_CH3                         (P21_2)      //ָʾ��ťͨ��
#define X6F_CH4                         (P21_4)      //������λͨ��
#define X6F_CH5                         (P33_7)      //��ťͨ��1
#define X6F_CH6                         (P33_6)      //��ťͨ��2
int16 x6f_count[6]={0};
int16 x6f_out[6]={0};
int16 x6f_pin_map[6] = {X6F_CH1, X6F_CH2, X6F_CH3, X6F_CH4, X6F_CH5, X6F_CH6};

int low_low=250;
int low_high=550;
int high_low=400;
int high_high=650;

void x6f_scan(void)                 // ͨ��ɨ��
{
    for(int i = 0; i < 6; i ++)
    {
        if(gpio_get_level(x6f_pin_map[i]))
        {
            x6f_count[i]++;
        }
        else if(x6f_count[i] > 0)
        {
            x6f_out[i] = x6f_count[i];
            x6f_count[i] = 0;
        }
    }

}

void yaokong (void)
{
    if(x6f_out[0]<=154&&x6f_out[0]>=147)
    {
        pwm_sgin=1447;
    }
    else if(x6f_out[0]>154)
    {
        pwm_sgin=1447+(x6f_out[0]-150)*7;
    }
    else if(x6f_out[0]<147)
    {
        pwm_sgin=1447-(150-x6f_out[0])*7;
    }

    if(x6f_out[1]>153)
    {
        yao_speed=(x6f_out[1]-150)*160;
    }
    if(x6f_out[1]<147)
    {
        yao_speed=(x6f_out[1]-150)*160;
    }
    if((x6f_out[1]>=147&&x6f_out[1]<=153)||x6f_out[1]>203||x6f_out[1]<47)
    {
        yao_speed=0;
    }

    if(x6f_out[2]<=133&&x6f_out[2]>=127)
    {
        yao_dupt=1;
    }
    if((x6f_out[2]<=173&&x6f_out[2]>=167)||x6f_out[2]>203||x6f_out[2]<47)
    {
        yao_dupt=0;
    }

//    if(x6f_out[3]>128&&x6f_out[3]<132)
//    {
//        pid_Speed->set=0;
//    }
//    if(x6f_out[3]>148&&x6f_out[3]<152)
//    {
//        if((set_point==0)||(set_point==14)||(set_point<=4&&set_point>=2))
//        {
//            pid_Speed->set=low_high;
//        }
//        else pid_Speed->set=low_low;
//
//    }
//    if(x6f_out[3]>168&&x6f_out[3]<172)
//    {
//        if((set_point==0)||(set_point==14)||(set_point<=4&&set_point>=2))
//        {
//            pid_Speed->set=high_high;
//        }
//        else pid_Speed->set=high_low;
//    }


}
