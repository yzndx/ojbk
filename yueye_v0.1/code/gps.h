#ifndef _GPS_h_
#define _GPS_h_

#include "zf_common_headfile.h"
#define num         32//�����С��ע��ÿ���޸���Ҫ��������
extern double la[num];//��������
extern double lo[num];//γ������

extern float we[num];
extern float ns[num];
double get_two_points_azimuth_2 (double latitude1, double longitude1, double latitude2, double longitude2);
double get_two_points_distance_2 (double latitude1, double longitude1, double latitude2, double longitude2);


void vincenty(double lat1, double lon1, double lat2, double lon2, double* distance, double* bearing);


#endif
