#ifndef _ADC_DEFINES_H
#define _ADC_DEFINES_H

// ADC Channel Selection
#define CH0 (1<<0)
#define CH1 (1<<1)
#define CH2 (1<<2)
#define CH3 (1<<3)

// Clock Configuration
#define FOSC    12000000      // Oscillator frequency (12 MHz)
#define CCLK    (5*FOSC)      // CPU clock frequency
#define PCLK    (CCLK/4)      // Peripheral clock frequency
#define ADCLK   3000000       // ADC clock frequency
#define CLKDIV  ((PCLK/ADCLK)-1)  // ADC clock divider value

// AD0CR Register Bit Positions
#define PDN_BIT       21      // ADC Power Down bit
#define ADC_START_BIT 24      // ADC Start Conversion bit

// AD0GDR Register Bit Position
#define DONE_BIT      31      // Conversion Complete bit

#endif