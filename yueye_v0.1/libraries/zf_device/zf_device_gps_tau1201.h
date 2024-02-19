
#ifndef _zf_device_gps_tau1201_h_
#define _zf_device_gps_tau1201_h_

#include "zf_common_typedef.h"

//===============================================GPS ��������====================================================
#define GPS_TAU1201_UART    (UART_3)
#define GPS_TAU1201_RX      (UART3_TX_P15_6)                                    // GPS RX�������ӵ���Ƭ����
#define GPS_TAU1201_TX      (UART3_RX_P15_7)                                      // GPS TX��������
//===============================================GPS ��������====================================================

#define ANGLE_TO_RAD(x)    ((x) * PI / 180.0)                                   // �Ƕ�ת��Ϊ����
#define RAD_TO_ANGLE(x)    ((x) * 180.0 / PI)                                   // ����ת��Ϊ�Ƕ�
#define PI                 (3.1415926535898)

//=============================================���� GPS ���ݽṹ��==================================================
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
    gps_time_struct    time;                                                    // ʱ��-
    uint8       state;                                                          // ��Ч״̬  1����λ��Ч  0����λ��Ч
    uint16      latitude_degree;                                                // ��
    uint16      latitude_cent;                                                  // ��
    uint16      latitude_second;                                                // ��
    uint16      longitude_degree;                                               // ��
    uint16      longitude_cent;                                                 // ��
    uint16      longitude_second;                                               // ��
    double      latitude;                                                       // ����
    double      longitude;                                                      // γ��
    int8        ns;                                                             // γ�Ȱ��� N�������򣩻� S���ϰ���
    int8        ew;                                                             // ���Ȱ��� E���������� W��������
    float       speed;                                                          // �ٶȣ�����/ÿСʱ��
    float       direction;                                                      // ���溽��000.0~359.9 �ȣ����汱��Ϊ�ο���׼��
    // ������������Ϣ��GNGGA����л�ȡ
    uint8       satellite_used;                                                 // ���ڶ�λ����������
    float       height;                                                         // �߶�
}gps_info_struct;

typedef enum
{
    GPS_STATE_RECEIVING,    // ���ڽ�������
    GPS_STATE_RECEIVED,     // ���ݽ������
    GPS_STATE_PARSING,      // ���ڽ���
}gps_state_enum;
//=============================================���� GPS ���ݽṹ��==================================================

//==============================================���� GPS ���ݱ���===================================================
extern gps_info_struct  gps_tau1201;
extern vuint8           gps_tau1201_flag;
//==============================================���� GPS ���ݱ���===================================================

//================================================GPS ��������====================================================
double      get_two_points_distance     (double lat1, double lng1, double lat2, double lng2);   // ����ӵ�һ���㵽�ڶ�����ľ���(��λ��m)
double      get_two_points_azimuth      (double lat1, double lon1, double lat2, double lon2);   // ����ӵ�һ���㵽�ڶ�����ķ�λ��(��λ����)

uint8       gps_data_parse              (void);                                                 // ����GPS����
void        gps_uart_callback           (void);                                                 // GPS�ص�����

uint8       gps_init                    (void);                                                 // GPS��ʼ��
//================================================GPS ��������====================================================

#endif
