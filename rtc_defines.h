#ifndef _RTC_DEFINES_H
#define _RTC_DEFINES_H

// Clock Configuration
#define FOSC    12000000       // Oscillator Frequency
#define CCLK    (5 * FOSC)     // CPU Clock
#define PCLK    (CCLK / 4)     // Peripheral Clock

// RTC Prescaler Values
#define PREINT_VAL  (int)((PCLK / 32768) - 1)
#define PREFRAC_VAL (PCLK - ((PREINT + 1) * 32768))

// RTC Control Register (CCR) Bits
#define RTC_CCR_EN     (1 << 0)   // Enable RTC
#define RTC_CTC_RESET  (1 << 1)   // Reset RTC Counters
#define RTC_CLKSRC     (1 << 4)   // Select External RTC Clock

#endif