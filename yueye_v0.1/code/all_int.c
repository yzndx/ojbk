#include "all_int.h"
#include "zf_common_headfile.h"

#define SWITCH1                         (P33_12)//���뿪��1
#define SWITCH2                         (P33_13)//���뿪��2
#define ENCODER_QUADDEC                 (TIM5_ENCOEDER)// ������������Ӧʹ�õı������ӿڣ���ˢ��
#define ENCODER_QUADDEC_A               (TIM5_ENCOEDER_CH1_P10_3)// A ���Ӧ������
#define ENCODER_QUADDEC_B               (TIM5_ENCOEDER_CH2_P10_1)// B ���Ӧ������
#define ENCODER_DIR                     (TIM6_ENCOEDER)// �������������Ӧʹ�õı������ӿڣ���ˢ��
#define ENCODER_DIR_PULSE               (TIM6_ENCOEDER_CH1_P20_3)// PULSE ��Ӧ������
#define ENCODER_DIR_DIR                 (TIM6_ENCOEDER_CH2_P20_0)// DIR ��Ӧ������
#define X6F_CH1                         (P21_3)      //�����ͨ��
#define X6F_CH2                         (P21_5)      //����ͨ��
#define X6F_CH3                         (P21_2)      //ָʾ��ťͨ��
#define X6F_CH4                         (P21_4)      //������λͨ��
#define X6F_CH5                         (P33_7)      //��ťͨ��1
#define X6F_CH6                         (P33_6)      //��ťͨ��2
#define key_time                        50          //������ʼ��ʱ��
#define FLASH_PAGE_INDEX                11           //flash�洢����ҳ��

float l_gyro_x=0.0;               //�������˲�x��
float l_gyro_y=0.0;               //�������˲�y��
float l_gyro_z=0.0;               //�������˲�z��
float l_acc_x=0.0;                //���ٶȼ��˲�x��
float l_acc_y=0.0;                //���ٶȼ��˲�y��
float l_acc_z=0.0;                //���ٶȼ��˲�z��
float l_mag_x=0.0;                //�������˲�x��
float l_mag_y=0.0;                //�������˲�y��
float l_mag_z=0.0;                //�������˲�z��

int n=500;
int arr[500];

void lb_inint(void)
{
    ips200_set_dir(IPS200_PORTAIT);//������ʾ����
    ips200_set_color(RGB565_WHITE, RGB565_BLACK);//������Ļ��ɫ�����壬������
    ips200_init(IPS200_TYPE_PARALLEL8);//��Ļ��ʼ��
    system_delay_ms(2000);//��ʱ��Ϊ�������������
//    l_acc_x=acc_calibration_x(arr, n);
//    l_acc_y=acc_calibration_y(arr, n);
//    l_acc_z=acc_calibration_z(arr, n);
    l_gyro_z=Gyro_calibration_z(arr, n);//�õ���Ʈֵ
    //    ips200_show_string(0,16*0, "calibration_g&a is ojbk=");
    //    system_delay_ms(500);
    //    l_mag_x=mag_calibration_x(arr, n);
    //    l_mag_y=mag_calibration_y(arr, n);
    //l_mag_z=mag_calibration_z(arr, n);
    ips200_show_string(0,16*0, "calibration is ojbk=");
    system_delay_ms(500);
    ips200_clear();
}

void all_init(void)//����ģ���ʼ��
{
    float speed_kp = 0.21;//����ʽp
    float speed_ki = 0.85;//����ʽi
    float speed_kd = 0.41; //����ʽd
    MotorPID_init(pid_Speed, speed_kp, speed_ki, speed_kd);//����ʽpid������ʼ��
    float dupt_kp = 6.4;//λ��ʽp
    float dupt_kd = 2.5;//λ��ʽd
    MotorPID_init2(pid_Duty, dupt_kp,dupt_kd);//λ��ʽpid������ʼ��

    key_init(key_time);//������ʼ����ɨ�����ڣ�
    gpio_init(SWITCH1, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // ��ʼ�� SWITCH1 ���� Ĭ�ϸߵ�ƽ ��������[���뿪��]
    gpio_init(SWITCH2, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // ��ʼ�� SWITCH2 ���� Ĭ�ϸߵ�ƽ ��������[���뿪��]

    //    pwm_init(ATOM0_CH4_P02_4, 17*1000, 0);//��ˢ���pwm�����ʼ��������
    //    pwm_init(ATOM0_CH6_P02_6, 17*1000, 0);//��ˢ���pwm�����ʼ��������
    pwm_init(ATOM0_CH7_P02_7, 1*1000, 0);//��ˢ���pwm�����ʼ��
    gpio_init(P02_4, GPO, GPIO_HIGH, GPO_PUSH_PULL);//GPIO ��ʼ��Ϊ��� Ĭ����������ߣ��趨�����ת����
    pwm_init(ATOM1_CH1_P33_9, 100, mid);//���pwm��ʼ��


    //    encoder_dir_init(ENCODER_DIR, ENCODER_DIR_PULSE, ENCODER_DIR_DIR);// ��ʼ��������ģ�������� ����������������ģʽ����ˢ��                                             // ��ʼ�� PIT0 Ϊ�����ж� 100ms ��
    encoder_quad_init(ENCODER_QUADDEC, ENCODER_QUADDEC_A, ENCODER_QUADDEC_B);// ��ʼ��������ģ�������� �������������ģʽ����ˢ��

//    gpio_init(X6F_CH1, GPI, GPIO_LOW, GPI_PULL_UP);//�����ͨ��
//    gpio_init(X6F_CH2, GPI, GPIO_LOW, GPI_PULL_UP);//����ͨ��
//    gpio_init(X6F_CH3, GPI, GPIO_LOW, GPI_PULL_UP);//ָʾ��ťͨ��
//    gpio_init(X6F_CH4, GPI, GPIO_LOW, GPI_PULL_UP);//������λͨ��
//    gpio_init(X6F_CH5, GPI, GPIO_LOW, GPI_PULL_UP);//��ťͨ��1
//    gpio_init(X6F_CH6, GPI, GPIO_LOW, GPI_PULL_UP);//��ťͨ��2
    //���ջ���ͨ����ʼ��

    gps_init();//GPS��ʼ��

    //imu963ra_init();//�����ʼ��       /*�Ѿ����˲�ʱ��ʼ��*/

    //    wireless_uart_init();//��ʼ�����ߴ���  /*����ʱʹ��*/

//    flash_buffer_clear();//���������
//    if(flash_check(0, FLASH_PAGE_INDEX))// �ж��Ƿ������ݣ��еĻ����flash�������������
//    {
//        flash_buffer_clear();//���������
//        flash_read_page_to_buffer(0, FLASH_PAGE_INDEX);//�����ݴ�flash ��ȡ��������
//        flash_erase_page(0, FLASH_PAGE_INDEX);//������һҳ����flash��
//    }
//    else
//    {
//        flash_buffer_clear();//���������
//        flash_erase_page(0, FLASH_PAGE_INDEX);//������һҳ����flash��
//    }


//    if(flash_check(0, 10))// �ж��Ƿ������ݣ��еĻ������������
//    {
//        flash_buffer_clear();//���������
//        flash_read_page_to_buffer(0, FLASH_PAGE_INDEX);//�����ݴ�flash ��ȡ��������
//        //        flash_erase_page(0, FLASH_PAGE_INDEX);//������һҳ����flash��
//    }
//    else
//    {
//        flash_buffer_clear();//���������
//        flash_erase_page(0, 10);//������һҳ����flash��
//    }


    pit_us_init(CCU60_CH0, 80);//�����ȡ����
    pit_ms_init(CCU60_CH1, 100);//������������&���pid��+�����pid��
//    pit_us_init(CCU61_CH0, 10);//ң��
    pit_ms_init(CCU61_CH1, 20);//GPS���ݶ�ȡ
    //��ʼ����ʱ��
}
