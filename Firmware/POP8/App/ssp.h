#ifndef __SSP_H__
#define __SSP_H__

#include "chip.h"

#define OUTPUT_CMD_CONTROL  (0x00 << 2)
#define OUTPUT_PWM_ENABLE   (0x04 << 2)

void SSP_Init();
void SSP_Enable();
void SSP_Disable();
unsigned char SSP_Write(unsigned char * buffer, unsigned int size);
unsigned char SSP_Read(unsigned char * buffer, unsigned int size);

#endif
