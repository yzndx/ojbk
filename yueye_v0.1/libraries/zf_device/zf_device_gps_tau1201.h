
#ifndef _zf_device_gps_tau1201_h_
#define _zf_device_gps_tau1201_h_

#include "zf_common_typedef.h"

//===============================================GPS 驱动配置====================================================
#define GPS_TAU1201_UART    (UART_3)
#define GPS_TAU1201_RX      (UART3_TX_P15_6)                                    // GPS RX引脚连接到单片机此
#define GPS_TAU1201_TX      (UART3_RX_P15_7)                                      // GPS TX串口引脚
//===============================================GPS 驱动配置====================================================

#define ANGLE_TO_RAD(x)    ((x) * PI / 180.0)                                   // 角度转换为弧度
#define RAD_TO_ANGLE(x)    ((x) * 180.0 / PI)                                   // 弧度转换为角度
#define PI                 (3.1415926535898)

//=============================================定义 GPS 数据结构体==================================================
typedef struct
{
    uint16      year;
    uint8       month;
    uint8       day;
    uint8       hour;
    uint8       minute;
    uint8       second;
}gps_time_struct;

typedef struct
{
    gps_time_struct    time;                                                    // 时间-
    uint8       state;                                                          // 有效状态  1：定位有效  0：定位无效
    uint16      latitude_degree;                                                // 度
    uint16      latitude_cent;                                                  // 分
    uint16      latitude_second;                                                // 秒
    uint16      longitude_degree;                                               // 度
    uint16      longitude_cent;                                                 // 分
    uint16      longitude_second;                                               // 秒
    double      latitude;                                                       // 经度
    double      longitude;                                                      // 纬度
    int8        ns;                                                             // 纬度半球 N（北半球）或 S（南半球）
    int8        ew;                                                             // 经度半球 E（东经）或 W（西经）
    float       speed;                                                          // 速度（公里/每小时）
    float       direction;                                                      // 地面航向（000.0~359.9 度，以真北方为参考基准）
    // 下面两个个信息从GNGGA语句中获取
    uint8       satellite_used;                                                 // 用于定位的卫星数量
    float       height;                                                         // 高度
}gps_info_struct;

typedef enum
{
    GPS_STATE_RECEIVING,    // 正在接收数据
    GPS_STATE_RECEIVED,     // 数据接收完成
    GPS_STATE_PARSING,      // 正在解析
}gps_state_enum;
//=============================================定义 GPS 数据结构体==================================================

//==============================================声明 GPS 数据变量===================================================
extern gps_info_struct  gps_tau1201;
extern vuint8           gps_tau1201_flag;
//==============================================声明 GPS 数据变量===================================================

//================================================GPS 基础函数====================================================
double      get_two_points_distance     (double lat1, double lng1, double lat2, double lng2);   // 计算从第一个点到第二个点的距离(单位：m)
double      get_two_points_azimuth      (double lat1, double lon1, double lat2, double lon2);   // 计算从第一个点到第二个点的方位角(单位：°)

uint8       gps_data_parse              (void);                                                 // 解析GPS数据
void        gps_uart_callback           (void);                                                 // GPS回调函数

uint8       gps_init                    (void);                                                 // GPS初始化
//================================================GPS 基础函数====================================================

#endif
