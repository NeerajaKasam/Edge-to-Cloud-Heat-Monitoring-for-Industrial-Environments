#include <LPC214x.H>

#include "adc_defines.h"
#include "types.h"
#include "defines.h"
#include "delay.h"

void Init_ADC(void)
{
    // Enable ADC and set ADC clock divider
    AD0CR = (1 << PDN_BIT) | (CLKDIV << 8);

    // Configure ADC pins (AD0.x functions)
    PINSEL1 = 0x15400000;
}

f32 Read_ADC(u8 chNo)
{
    u16 adcVal = 0;
    f32 eAR;

    // Select required ADC channel
    AD0CR &= 0xFFFFFFF0;
    AD0CR |= 1 << chNo;

    // Start ADC conversion
    AD0CR |= 1 << 24;

    // Wait for conversion time
    delay_us(3);

    // Wait until conversion completes
    while(((AD0GDR >> 31) & 1) == 0);

    // Stop ADC conversion
    AD0CR &= ~(1 << 24);

    // Extract 10-bit ADC result
    adcVal = (AD0GDR >> 6) & 0x3FF;

    // Convert ADC value into voltage
    eAR = (adcVal * 3.3) / 1023;

    return eAR;
}