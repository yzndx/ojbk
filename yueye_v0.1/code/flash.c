#include "flash.h"
#include "zf_common_headfile.h"
int dian_num=15;//����ľ�γ�ȶ���
/*
һ��ʼʹ��flash,�����double�����������
����ʹ��floatû������
 */
//float double_to_float(double dou)//��Ϊtc264ֻ�ɴ���float���ͣ��ʽ�doubleת��
//{
//    float fl;
//        int m = dou*100000;
//        fl = m*1.0f/100000;
//   return fl;
//}

void read_dain(void)//��������������д��flash
{
//    flash_erase_page(0, 11);//������һҳ����flash��
//    flash_buffer_clear();
//    flash_read_page_to_buffer(0, 11);// ��ָ��Flash������ҳ��д�뻺��������
//    for(int i=0;i<=dian_num-1;i++)
//    {
//        la[i]=(double)flash_union_buffer[i*2].float_type;
//        lo[i]=(double)flash_union_buffer[i*2+1].float_type;
//    }
//    ips200_show_string(8*0,16*16, "flash_ok");
}

void write_dian(void)//����ʱ�ľ�γ��д�뻺����
{
//    flash_erase_page(0,11);
//    if(flash_num==(dian_num-1))//*2-1
//    {
//
//        flash_write_page_from_buffer(0, 11);//��ָ��Flash������ҳ��д�뻺��������
//        flash_num=0;
//    }
//    flash_union_buffer[flash_num].float_type=double_to_float(gps_tau1201.latitude);
    la[flash_num]=gps_tau1201.latitude;
//    flash_num++;
//    flash_union_buffer[flash_num].float_type=double_to_float(gps_tau1201.longitude);
    lo[flash_num]=gps_tau1201.longitude;
    flash_num++;
    ips200_show_string(8*0,16*16, "flash_ing");
}
