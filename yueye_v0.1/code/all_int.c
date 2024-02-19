#include "all_int.h"
#include "zf_common_headfile.h"

#define SWITCH1                         (P33_12)//拨码开关1
#define SWITCH2                         (P33_13)//拨码开关2
#define ENCODER_QUADDEC                 (TIM5_ENCOEDER)// 正交编码器对应使用的编码器接口（无刷）
#define ENCODER_QUADDEC_A               (TIM5_ENCOEDER_CH1_P10_3)// A 相对应的引脚
#define ENCODER_QUADDEC_B               (TIM5_ENCOEDER_CH2_P10_1)// B 相对应的引脚
#define ENCODER_DIR                     (TIM6_ENCOEDER)// 带方向编码器对应使用的编码器接口（有刷）
#define ENCODER_DIR_PULSE               (TIM6_ENCOEDER_CH1_P20_3)// PULSE 对应的引脚
#define ENCODER_DIR_DIR                 (TIM6_ENCOEDER_CH2_P20_0)// DIR 对应的引脚
#define X6F_CH1                         (P21_3)      //方向舵通道
#define X6F_CH2                         (P21_5)      //油门通道
#define X6F_CH3                         (P21_2)      //指示按钮通道
#define X6F_CH4                         (P21_4)      //拨动挡位通道
#define X6F_CH5                         (P33_7)      //旋钮通道1
#define X6F_CH6                         (P33_6)      //旋钮通道2
#define key_time                        50          //按键初始化时间
#define FLASH_PAGE_INDEX                11           //flash存储扇区页码

float l_gyro_x=0.0;               //陀螺仪滤波x轴
float l_gyro_y=0.0;               //陀螺仪滤波y轴
float l_gyro_z=0.0;               //陀螺仪滤波z轴
float l_acc_x=0.0;                //加速度计滤波x轴
float l_acc_y=0.0;                //加速度计滤波y轴
float l_acc_z=0.0;                //加速度计滤波z轴
float l_mag_x=0.0;                //磁力计滤波x轴
float l_mag_y=0.0;                //磁力计滤波y轴
float l_mag_z=0.0;                //磁力计滤波z轴

int n=500;
int arr[500];

void lb_inint(void)
{
    ips200_set_dir(IPS200_PORTAIT);//设置显示方向
    ips200_set_color(RGB565_WHITE, RGB565_BLACK);//设置屏幕颜色（字体，背景）
    ips200_init(IPS200_TYPE_PARALLEL8);//屏幕初始化
    system_delay_ms(2000);//延时是为了消除车晃误差
//    l_acc_x=acc_calibration_x(arr, n);
//    l_acc_y=acc_calibration_y(arr, n);
//    l_acc_z=acc_calibration_z(arr, n);
    l_gyro_z=Gyro_calibration_z(arr, n);//得到零飘值
    //    ips200_show_string(0,16*0, "calibration_g&a is ojbk=");
    //    system_delay_ms(500);
    //    l_mag_x=mag_calibration_x(arr, n);
    //    l_mag_y=mag_calibration_y(arr, n);
    //l_mag_z=mag_calibration_z(arr, n);
    ips200_show_string(0,16*0, "calibration is ojbk=");
    system_delay_ms(500);
    ips200_clear();
}

void all_init(void)//所有模块初始化
{
    float speed_kp = 0.21;//增量式p
    float speed_ki = 0.85;//增量式i
    float speed_kd = 0.41; //增量式d
    MotorPID_init(pid_Speed, speed_kp, speed_ki, speed_kd);//增量式pid参数初始化
    float dupt_kp = 6.4;//位置式p
    float dupt_kd = 2.5;//位置式d
    MotorPID_init2(pid_Duty, dupt_kp,dupt_kd);//位置式pid参数初始化

    key_init(key_time);//按键初始化（扫描周期）
    gpio_init(SWITCH1, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // 初始化 SWITCH1 输入 默认高电平 浮空输入[拨码开关]
    gpio_init(SWITCH2, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // 初始化 SWITCH2 输入 默认高电平 浮空输入[拨码开关]

    //    pwm_init(ATOM0_CH4_P02_4, 17*1000, 0);//有刷电机pwm输出初始化（正）
    //    pwm_init(ATOM0_CH6_P02_6, 17*1000, 0);//有刷电机pwm输出初始化（反）
    pwm_init(ATOM0_CH7_P02_7, 1*1000, 0);//无刷电机pwm输出初始化
    gpio_init(P02_4, GPO, GPIO_HIGH, GPO_PUSH_PULL);//GPIO 初始化为输出 默认上拉输出高（设定电机旋转方向）
    pwm_init(ATOM1_CH1_P33_9, 100, mid);//舵机pwm初始化


    //    encoder_dir_init(ENCODER_DIR, ENCODER_DIR_PULSE, ENCODER_DIR_DIR);// 初始化编码器模块与引脚 带方向增量编码器模式（有刷）                                             // 初始化 PIT0 为周期中断 100ms 周
    encoder_quad_init(ENCODER_QUADDEC, ENCODER_QUADDEC_A, ENCODER_QUADDEC_B);// 初始化编码器模块与引脚 正交解码编码器模式（无刷）

//    gpio_init(X6F_CH1, GPI, GPIO_LOW, GPI_PULL_UP);//方向舵通道
//    gpio_init(X6F_CH2, GPI, GPIO_LOW, GPI_PULL_UP);//油门通道
//    gpio_init(X6F_CH3, GPI, GPIO_LOW, GPI_PULL_UP);//指示按钮通道
//    gpio_init(X6F_CH4, GPI, GPIO_LOW, GPI_PULL_UP);//拨动挡位通道
//    gpio_init(X6F_CH5, GPI, GPIO_LOW, GPI_PULL_UP);//旋钮通道1
//    gpio_init(X6F_CH6, GPI, GPIO_LOW, GPI_PULL_UP);//旋钮通道2
    //接收机各通道初始化

    gps_init();//GPS初始化

    //imu963ra_init();//九轴初始化       /*已经在滤波时初始化*/

    //    wireless_uart_init();//初始化无线串口  /*调试时使用*/

//    flash_buffer_clear();//清除缓冲区
//    if(flash_check(0, FLASH_PAGE_INDEX))// 判断是否有数据（有的话清除flash并清除缓冲区）
//    {
//        flash_buffer_clear();//清除缓冲区
//        flash_read_page_to_buffer(0, FLASH_PAGE_INDEX);//将数据从flash 读取到缓冲区
//        flash_erase_page(0, FLASH_PAGE_INDEX);//擦除这一页（擦flash）
//    }
//    else
//    {
//        flash_buffer_clear();//清除缓冲区
//        flash_erase_page(0, FLASH_PAGE_INDEX);//擦除这一页（擦flash）
//    }


//    if(flash_check(0, 10))// 判断是否有数据（有的话清除缓冲区）
//    {
//        flash_buffer_clear();//清除缓冲区
//        flash_read_page_to_buffer(0, FLASH_PAGE_INDEX);//将数据从flash 读取到缓冲区
//        //        flash_erase_page(0, FLASH_PAGE_INDEX);//擦除这一页（擦flash）
//    }
//    else
//    {
//        flash_buffer_clear();//清除缓冲区
//        flash_erase_page(0, 10);//擦除这一页（擦flash）
//    }


    pit_us_init(CCU60_CH0, 80);//九轴读取数据
    pit_ms_init(CCU60_CH1, 100);//（编码器计数&电机pid）+（舵机pid）
//    pit_us_init(CCU61_CH0, 10);//遥控
    pit_ms_init(CCU61_CH1, 20);//GPS数据读取
    //初始化定时器
}
