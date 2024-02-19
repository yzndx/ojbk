#include "gps.h"
#include "zf_common_headfile.h"
#define num         32//数组大小（注意每次修改需要改三处）
double la[num]={0.0};//经度数组
double lo[num]={0.0};//纬度数组

/*
自定义的计算方位角及距离函数
和逐飞库计算时间差不多
 */
////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     计算从第一个点到第二个点的方位角
//// 参数说明     latitude1       第一个点的纬度
//// 参数说明     longitude1      第一个点的经度
//// 参数说明     latitude2       第二个点的纬度
//// 参数说明     longitude2      第二个点的经度
//// 返回参数     double          返回方位角（0至360）
//// 使用示例     get_two_points_azimuth(latitude1, longitude1, latitude2, longitude2);
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//double get_two_points_azimuth_2 (double latitude1, double longitude1, double latitude2, double longitude2)
//{
//    latitude1 = ANGLE_TO_RAD(latitude1);
//    latitude2 = ANGLE_TO_RAD(latitude2);
//    longitude1 = ANGLE_TO_RAD(longitude1);
//    longitude2 = ANGLE_TO_RAD(longitude2);
//    double x = func_sin(longitude2 - longitude1) * func_cos(latitude2);
//    double y = func_cos(latitude1) * func_sin(latitude2) - func_sin(latitude1) * func_cos(latitude2) * func_cos(longitude2 - longitude1);
//    double angle = RAD_TO_ANGLE(atan2f(x, y));
//    return ((angle > 0) ? angle : (angle + 360));
//}
////-------------------------------------------------------------------------------------------------------------------
//// 函数简介     计算从第一个点到第二个点的距离
//// 参数说明     latitude1       第一个点的纬度
//// 参数说明     longitude1      第一个点的经度
//// 参数说明     latitude2       第二个点的纬度
//// 参数说明     longitude2      第二个点的经度
//// 返回参数     double          返回两点距离
//// 使用示例     get_two_points_distance(latitude1_1, longitude1, latitude2, longitude2);
//// 备注信息
////-------------------------------------------------------------------------------------------------------------------
//double get_two_points_distance_2 (double latitude1, double longitude1, double latitude2, double longitude2)
//{
//    const double EARTH_RADIUS = 6378137;                                        // 地球半径(单位：m)
//    double rad_latitude1;
//    double rad_latitude2;
//    double rad_longitude1;
//    double rad_longitude2;
//    double distance=0;
//    double a;
//    double b;
//    rad_latitude1 = ANGLE_TO_RAD(latitude1);                                    // 根据角度计算弧度
//    rad_latitude2 = ANGLE_TO_RAD(latitude2);
//    rad_longitude1 = ANGLE_TO_RAD(longitude1);
//    rad_longitude2 = ANGLE_TO_RAD(longitude2);
//    a = rad_latitude1 - rad_latitude2;
//    b = rad_longitude1 - rad_longitude2;
//    distance = 2 * asinf(func_sqrt(func_pow(func_sin(a / 2), 2) + func_cos(rad_latitude1) * func_cos(rad_latitude2) * func_pow(func_sin(b / 2), 2)));   // google maps 里面实现的算法
//    distance = distance * EARTH_RADIUS;
//    return distance;
//}

#define EARTH_RADIUS 6378137.0  // 地球半径，单位：米
#define M_PI 3.14159265358979323846

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

double toDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

void vincenty(double lat1, double lon1, double lat2, double lon2, double* distance, double* bearing)
{
    double a = EARTH_RADIUS;
    double b = 6356752.314245;  // 地球扁率
    double f = 1 / 298.257223563;  // 地球椭球体参数
    double L = toRadians(lon2 - lon1);
    double U1 = atan((1 - f) * tan(toRadians(lat1)));
    double U2 = atan((1 - f) * tan(toRadians(lat2)));
    double sinU1 = sin(U1), cosU1 = cos(U1);
    double sinU2 = sin(U2), cosU2 = cos(U2);

    double lambda = L, lambdaP, iterLimit = 100;
    double sinLambda, cosLambda, sinSigma, cosSigma, sigma, sinAlpha, cosSqAlpha, cos2SigmaM;
    do {
        sinLambda = sin(lambda), cosLambda = cos(lambda);
        sinSigma = sqrt((cosU2 * sinLambda) * (cosU2 * sinLambda) +
                        (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda) *
                        (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda));
        if (sinSigma == 0) {
            *distance = 0;
            *bearing = 0;
            return;  // 距离为 0
        }
        cosSigma = sinU1 * sinU2 + cosU1 * cosU2 * cosLambda;
        sigma = atan2(sinSigma, cosSigma);
        sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
        cosSqAlpha = 1 - sinAlpha * sinAlpha;
        cos2SigmaM = cosSigma - 2 * sinU1 * sinU2 / cosSqAlpha;
        if (isnan(cos2SigmaM)) cos2SigmaM = 0;  // 跨越 180 度子午线
        double C = f / 16 * cosSqAlpha * (4 + f * (4 - 3 * cosSqAlpha));
        lambdaP = lambda;
        lambda = L + (1 - C) * f * sinAlpha *
                 (sigma + C * sinSigma *
                  (cos2SigmaM + C * cosSigma *
                   (-1 + 2 * cos2SigmaM * cos2SigmaM)));
    } while (fabs(lambda - lambdaP) > 1e-12 && --iterLimit > 0);

    if (iterLimit == 0) {
        *distance = NAN;
        *bearing = NAN;
        return;  // 计算失败
    }

    double uSq = cosSqAlpha * (a * a - b * b) / (b * b);
    double A =1 + uSq / 16384 * (4096 + uSq * (-768 + uSq * (320 - 175 * uSq)));
    double B = f / 1024 * (256 + f * (-128 + f * (74 - 47 * f))) *
               (sinSigma + f / 4 * (cos2SigmaM * (-1 + 2 * sinSigma * sinSigma) -
                                    f / 6 * sinSigma * (-3 + 4 * sinSigma * sinSigma) *
                                    (-3 + 4 * cos2SigmaM * cos2SigmaM)));
    *distance = A * b * (sigma - B);
    *bearing = toDegrees(atan2(cosU2 * sinLambda,
                               cosU1 * sinU2 - sinU1 * cosU2 * cosLambda));
    if (*bearing < 0) {
        *bearing += 360;  // 转换为 0 到 360 度
    }
}
