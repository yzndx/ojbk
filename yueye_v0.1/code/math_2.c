
#include "math_2.h"
#include "zf_common_headfile.h"
/*
 自定义的数学函数，计算速度和库不太相同，但提升不大
 */
//自定义pow函数
double func_pow(double x,int k)
{
    if (k > 0)
        return x * func_pow(x, k - 1);
    else if (k == 0)
        return 1;
    else
        return 1.0 / func_pow(x, -k);
}
//自定义sqrt函数
double func_sqrt(double x)
{
    double j,k;
    j=0.0;
    k=x/2;
    while(j!=k)
    {
        j=k;
        k=(j+x/j)/2;
    }
    return j;
}
////自定义cos函数
//double func_cos(double x)
//{
//    x=func_abs(x);
//    int t,q=1;
//    double term,factorial=1.0,sum2=1,sxm,sum1=0;
//    for(t=2;;t++)
//    {
//        factorial=factorial*t;
//        if(t%2==0)
//        {
//            sum1=sum2;
//            q=q*(-1);
//            sxm=func_abs(func_pow(x,t));
//            term=sxm/factorial;
//            sum2=q*term+sum2;
//        }
//        if(func_abs(sum2-sum1)<=1e-13)
//            break;
//    }
//    return sum2;
//}
//
////自定义sin函数
//double func_sin(double x)
//{
//    int counter=0;
//    if(x<0)
//        counter = 1;
//    else
//        counter = 0;
//    x=func_abs(x);
//    int t,q=1;
//    double term,factorial=1.0,sum2,sxm,sum1=0;
//    sum2=x;
//    for(t=2;;t++)
//    {
//        factorial=factorial*t;
//        if(t%2!=0)
//        {
//            sum1=sum2;
//            q=q*(-1);
//            sxm=func_abs(func_pow(x,t));
//            term=sxm/factorial;
//            sum2=q*term+sum2;
//        }
//        if(func_abs(sum2-sum1)<=1e-13)
//            break;
//    }
//    if(counter==1)
//    {
//        sum2=-sum2;
//        return sum2;
//    }
//    else
//        return sum2;
//}
