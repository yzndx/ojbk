#include "key.h"
#include "zf_common_headfile.h"
#define SWITCH1                         (P33_12)//���뿪��1
#define SWITCH2                         (P33_13)//���뿪��2
char key_run=0;
int key_number=0;//����鿴
int flash_num=0;//�鿴����λ��
/*
�������뿪���ĸ�����
�����ɳ����Ͷ̰�
��Ϸ�ʽ�ܶ�
 */
void key(void)//��������
{
    if((gpio_get_level(SWITCH1)==1)&&(gpio_get_level(SWITCH2)==1))//all 12
    {
        key_number=0;
        if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
        {
            read_dain();//��������������д��flash
        }
        if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
        {
            write_dian();//����ʱ�ľ�γ��д�뻺����
        }
        if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
        {
            set_point++;
        }
        if(key_get_state(KEY_3)==KEY_LONG_PRESS)
        {
            set_point--;
        }
        if(key_get_state(KEY_4)==KEY_SHORT_PRESS)
        {
            point_a++;
        }
        if(key_get_state(KEY_4)==KEY_LONG_PRESS)
        {
            point_a--;
        }

    }
    if((gpio_get_level(SWITCH1)==0)&&(gpio_get_level(SWITCH2)==1))
    {
        key_number=1;
        if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
        {
            high_high+=50;//
        }

        if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
        {
            high_high-=50;
        }

        if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
        {
            point_a++;
        }
        if(key_get_state(KEY_4)==KEY_SHORT_PRESS)
        {
            point_a--;
        }


    }
    if((gpio_get_level(SWITCH1)==1)&&(gpio_get_level(SWITCH2)==0))
    {
        key_number=2;
        if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
        {
            low_low+=50;//
        }
        //        if(key_get_state(KEY_1)==KEY_LONG_PRESS)
        //        {
        //            low_low-=50;//
        //        }
        if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
        {
            low_low-=50;//
        }
        //        if(key_get_state(KEY_2)==KEY_LONG_PRESS)
        //        {
        //            low_high-=50;//
        //        }
        if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
        {
            low_high+=50;//
        }
        //        if(key_get_state(KEY_3)==KEY_LONG_PRESS)
        //        {
        //            high_low-=50;//
        //        }
        if(key_get_state(KEY_4)==KEY_SHORT_PRESS)
        {
            low_high-=50;//
        }
        //        if(key_get_state(KEY_4)==KEY_LONG_PRESS)
        //        {
        //            high_high-=50;//
        //        }
    }
    if((gpio_get_level(SWITCH1)==0)&&(gpio_get_level(SWITCH2)==0))//all no
    {
        key_number=3;
        if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
        {
            key_run=0;
        }

        if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
        {
            key_run=1;
        }
        if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
        {
            yaw=0;yaw1=0;
        }
        //        if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
        //        {
        //            pid_Speed->set=0;//
        //        }
        //
        //        if(key_get_state(KEY_4)==KEY_SHORT_PRESS)
        //        {
        //            high_high+=50;//
        //        }

    }

}

