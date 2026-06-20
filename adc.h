#ifndef _ADC_H
#define _ADC_H

#include "types.h"

// Initialize ADC peripheral
void Init_ADC(void);

// Read ADC value from selected channel
f32 Read_ADC(u8 chNo);

#endif