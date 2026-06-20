#include <LPC21xx.H>
#include "rtc.h"
#include "rtc_defines.h"
#include "types.h"
#include "lcd.h"

// Weekday names
signed char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

// Initialize RTC
void RTC_Init(void)
{
    // Reset RTC
    CCR = RTC_CTC_RESET;

    // Set RTC prescaler values
    PREINT = PREINT_VAL;
    PREFRAC = PREFRAC_VAL;

    // Enable RTC with external clock source
    CCR = RTC_CCR_EN | RTC_CLKSRC;
}

// Read current RTC time
void RTCGetTime(u32 *hr,u32 *mi,u32 *se)
{
    *hr = HOUR;
    *mi = MIN;
    *se = SEC;
}

// Read current RTC date
void RTCGetDate(u32 *dt,u32 *mo,u32 *yr)
{
    *dt = DOM;
    *mo = MONTH;
    *yr = YEAR;
}

// Read current day of week
void RTCGetDay(u32 *day)
{
    *day = DOW;
}

// Set RTC time
void RTCSetTime(u32 hr,u32 mi,u32 se)
{
    HOUR = hr;
    MIN  = mi;
    SEC  = se;
}

// Set RTC date
void RTCSetDate(u32 dt,u32 mo,u32 yr)
{
    DOM   = dt;
    MONTH = mo;
    YEAR  = yr;
}

// Set day of week
void RTCSetDay(u32 day)
{
    DOW = day;
}