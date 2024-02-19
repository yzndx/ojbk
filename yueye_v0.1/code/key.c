#include "key.h"
#include "zf_common_headfile.h"
#define SWITCH1                         (P33_12)//拨码开关1
#define SWITCH2                         (P33_13)//拨码开关2
char key_run=0;
int key_number=0;//拨码查看
int flash_num=0;//查看数组位数
/*
两个拨码开关四个按键
按键可长按和短按
组合方式很多
 */
void key(void)//按键函数
{
    if((gpio_get_level(SWITCH1)==1)&&(gpio_get_level(SWITCH2)==1))//all 12
    {
        key_number=0;
        if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
        {
            read_dain();//将缓存区的内容写入flash
        }
        if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
        {
            write_dian();//将此时的经纬度写入缓冲区
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

