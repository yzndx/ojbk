#ifndef _YAOKONG_h_
#define _YAOKONG_h_

#include "zf_common_headfile.h"

extern int16 x6f_count[6];
extern int16 x6f_out[6];
extern int16 x6f_pin_map[6];
extern int yao_dupt;
extern int yao_speed;//使用遥控时输出的pwm
extern int pwm_sgin;

extern int low_low;
extern int low_high;
extern int high_low;
extern int high_high;

void x6f_scan(void);
void yaokong (void);







#endif
