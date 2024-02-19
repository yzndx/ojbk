#include "menu.h"
#include "zf_common_headfile.h"

/*
 一开始写的菜单，有点臃肿
 拨码开关加四个按键其实绰绰有余
 如想尝试菜单建议使用数表查询法比较好
 */
//
////menu cai_dan;
////menu *cai=&cai_dan;
//
//
////
////
//
//
//
//void fist_shou(void)
//{
//    ips200_show_string(8*0, 16*fist_biao, "<<");
//    ips200_show_string(8*3, 16*0, "pid_num");
//    ips200_show_string(8*3, 16*1, "GPS");
//    ips200_show_string(8*3, 16*2, "yaokong");
//    ips200_show_string(8*3, 16*3, "wife");
//}
//void sec_shou_0(void)
//{
//    ips200_show_string(8*0, 16*sec_biao, "<<");
//    ips200_show_string(8*3, 16*0, "kp=");
//    ips200_show_string(8*3, 16*1, "ki=");
//    ips200_show_string(8*3, 16*2, "kd=");
//    ips200_show_string(8*3, 16*3, "ta_dis=");
//
//    ips200_show_float(8*6, 16*0, pid_Duty->kp, 3,4);
//    ips200_show_float(8*6, 16*1, pid_Duty->ki, 3,4);
//    ips200_show_float(8*6, 16*2, pid_Duty->kd, 3,4);
//    ips200_show_float(8*10, 16*3, target_distance, 3,4);
//
//}
//
//void sec_shou_1(void)
//{
//    ips200_show_string(8*0, 16*sec_biao, "<<");
//
//    ips200_show_string(8*3,16*0, "la_now=");
//    ips200_show_string(8*3,16*1, "lo_now=");
//    ips200_show_string(8*3,16*2, "we=");
//    ips200_show_string(8*3,16*3, "ns=");
//    ips200_show_string(8*3,16*4, "set_point=");
//    ips200_show_string(8*3,16*5, "flash_num=");
//    ips200_show_string(8*3,16*6, "jiao=");
//    ips200_show_string(8*3,16*7, "set_distance=");
//    ips200_show_string(8*3,16*8, "yaw=");
//
//    ips200_show_float(8*3+8*7,16*0,gps_tau1201.latitude,4,6);
//    ips200_show_float(8*3+8*7,16*1,gps_tau1201.longitude,4,6);
//    ips200_show_float(8*3+8*3,16*2,la[set_point],4,6);
//    ips200_show_float(8*3+8*3,16*3,lo[set_point],4,6);
//    ips200_show_int  (8*3+8*11,16*4,set_point,2);
//    ips200_show_int  (8*3+8*10,16*5,flash_num,2);
//    ips200_show_float(8*3+8*5,16*6,jiao,4,6);
//    ips200_show_float(8*3+8*13,16*7,set_distance,4,6);
//    ips200_show_float(8*3+8*4,16*8,yaw,3,6);
//}
//
//void sec_shou_2(void)
//{
//    ips200_show_string(8*0, 16*sec_biao, "<<");
//
//    ips200_show_string(8*3,16*0, "out0=");
//    ips200_show_string(8*3,16*1, "out1=");
//    ips200_show_string(8*3,16*2, "out2=");
//    ips200_show_string(8*3,16*3, "out3=");
//    ips200_show_string(8*3,16*4, "out4=");
//    ips200_show_string(8*3,16*5, "out5=");
//
//    ips200_show_int(8*3+8*5,16*0,x6f_out[0],3);
//    ips200_show_int(8*3+8*5,16*1,x6f_out[1],3);
//    ips200_show_int(8*3+8*5,16*2,x6f_out[2],3);
//    ips200_show_int(8*3+8*5,16*3,x6f_out[3],3);
//    ips200_show_int(8*3+8*5,16*4,x6f_out[4],3);
//    ips200_show_int(8*3+8*5,16*5,x6f_out[5],3);
//}
//
//void sec_shou_3(void)
//{
//    ips200_show_string(8*0, 16*sec_biao, "<<");
//
//}
//
//
//float sec_n(int sec_biao)
//{
//    if(sec_biao==0)
//    {
//        sec_num=pid_Duty->kp;
//    }
//    if(sec_biao==1)
//    {
//        sec_num=pid_Duty->ki;
//    }
//    if(sec_biao==2)
//    {
//        sec_num=pid_Duty->kd;
//    }
//    if(sec_biao==3)
//    {
//        sec_num=target_distance;
//    }
//    return sec_num;
//}
//void sec_n2(int sec_biao)
//{
//    if(sec_biao==0)
//    {
//        pid_Duty->kp=sec_num;
//    }
//    if(sec_biao==1)
//    {
//        pid_Duty->ki=sec_num;
//    }
//    if(sec_biao==2)
//    {
//        pid_Duty->kd=sec_num;
//    }
//    if(sec_biao==3)
//    {
//        target_distance=sec_num;
//    }
//}
//
//int key_jian(void)//获取键值
//{
//    int a=0;
//    if(key_get_state(KEY_1)==KEY_SHORT_PRESS)
//    {
//        a=1;ips200_clear();
//    }
//    else if(key_get_state(KEY_2)==KEY_SHORT_PRESS)
//    {
//        a=2;ips200_clear();
//    }
//    else if(key_get_state(KEY_3)==KEY_SHORT_PRESS)
//    {
//        a=3;ips200_clear();
//    }
//    else if(key_get_state(KEY_4)==KEY_SHORT_PRESS)
//    {
//        a=4;ips200_clear();
//    }
//    else a=0;
//    return a;
//}
//
//void fist_key(int a)
//{
//    while(1)
//    {
//        if(a==0)
//            break;
//        if(a==1)
//        {
//            fist_biao--;
//            if(fist_biao<0)
//            {
//                fist_biao=3;
//            }
//        }
//        if(a==2)
//        {
//            fist_biao++;
//            if(fist_biao>=4)
//            {
//                fist_biao=0;
//            }
//        }
//        if(a==3)
//        {
//            ji_biao=1;
//        }
//        //    switch(fist_biao)
//        //    {
//        //        case 0:fist_shou_0();break;
//        //    }
//        fist_shou();
//        break;
//    }
//
//}
//
//void sec_key(int a)
//{
//    while(1)
//    {
//        switch(fist_biao)
//        {
//            case 0:sec_shou_0();break;
//            case 1:sec_shou_1();break;
//            case 2:sec_shou_2();break;
//            case 3:sec_shou_3();break;
//        }
//        if(fist_biao==0)
//        {
//            if(a==0)
//                break;
//            if(a==1)
//            {
//                sec_biao++;
//                if(fist_biao==0)
//                {
//                    if(sec_biao>=4)
//                    {
//                        sec_biao=0;
//                    }
//                }
//            }
//            if(a==2)
//            {
//                sec_num=sec_n(sec_biao);
//
//                sec_num=sec_num+0.01;
//                sec_n2(sec_num);
//            }
//            if(a==3)
//            {
//                sec_num=sec_n(sec_biao);
//
//                sec_num=sec_num-0.01;
//                sec_n2(sec_num);
//            }
//            if(a==4)
//            {
//                ji_biao=0;
//            }
//            break;
//        }
//        if(fist_biao==1)
//        {
//            if(a==0)
//                break;
//            if(a==1)
//                break;
//            if(a==2)
//            {
//                read_dain();
//            }
//            if(a==3)
//            {
//                write_dian();
//            }
//            if(a==4)
//            {
//                ji_biao=0;
//            }
//            break;
//        }
//        if(fist_biao==2)
//        {
//            if(a==0)
//                break;
//            if(a==1)
//                break;
//            if(a==2)
//            {
//
//            }
//            if(a==3)
//            {
//
//            }
//            if(a==4)
//            {
//                ji_biao=0;
//            }
//            break;
//        }
//        if(fist_biao==3)
//        {
//            if(a==0)
//                break;
//            if(a==1)
//                break;
//            if(a==2)
//            {
//
//            }
//            if(a==3)
//            {
//
//            }
//            if(a==4)
//            {
//                ji_biao=0;
//            }
//            break;
//        }
//    }
//
//}
