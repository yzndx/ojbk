
#include "isp200.h"
#include "zf_common_headfile.h"
#define PI                 (3.1415926535898)
//行8*30 列16*20
/*
 注意：屏幕放入while循环会占用大量资源
 后期调试好后只放有必要的变量即可
 */
void int_kan(void)//不变字符输出区
{
    ips200_show_string(0,16*0, "la=");
    ips200_show_string(0,16*1, "lo=");
//    ips200_show_string(0,16*2, "we=");
//    ips200_show_string(0,16*3, "ns=");
    ips200_show_string(0,16*2, "set_point=");
    ips200_show_string(0,16*3, "flash_num=");
    ips200_show_string(0,16*4, "set_distance=");
    ips200_show_string(0,16*5, "set_speed=");
    ips200_show_string(0,16*6, "speed=");
    ips200_show_string(0,16*7, "yaw=");
    ips200_show_string(0,16*8, "used=");
    ips200_show_string(0,16*9, "jiao2=");

    ips200_show_string(0,16*18, "time=");
    ips200_show_string(0,16*11, "point_a=");
//    ips200_show_string(0,16*18, "jiao=");

}
void all_kan(void)//刷新数据区
{
    ips200_show_int(8*20,16*0,key_number,1);
    ips200_show_int(8*20,16*1,point_a,1);
    ips200_show_float(8*3,16*0,gps_tau1201.latitude,4,6);
    ips200_show_float(8*3,16*1,gps_tau1201.longitude,4,6);
//    ips200_show_float(8*3,16*2,la[set_point],4,6);
//    ips200_show_float(8*3,16*3,lo[set_point],4,6);
    ips200_show_int(8*11,16*2,set_point,2);
    ips200_show_int(8*10,16*3,flash_num,2);
    ips200_show_float(8*13,16*4,set_distance,4,6);
    ips200_show_int(8*10,16*5,pid_Speed->set,5);
    ips200_show_int(8*6,16*6,pid_Speed->now,5);
    ips200_show_float(8*4,16*7,yaw,3,3);
    ips200_show_int(8*5,16*8,gps_tau1201.satellite_used,4);
    ips200_show_float(8*6,16*9,jiao2,3,6);ips200_show_int(8*16,16*8,key_run,1);


    ips200_show_int(8*0,16*12,low_low,4);ips200_show_int(8*5,16*12,low_high,4);
//    ips200_show_int(8*10,16*15,high_low,4);
    ips200_show_int(8*0,16*13,high_high,4);
    ips200_show_int(8*9,16*11,point_a,2);

//    ips200_show_float(8*0,16*13,pid_Speed->kp,1,2);
//    ips200_show_float(8*8,16*13,pid_Speed->ki,1,2);
//    ips200_show_float(8*16,16*13,pid_Speed->kd,1,2);
    ips200_show_int(8*5,16*18,time,4);
}
