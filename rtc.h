#ifndef _RTC_H_
#define _RTC_H_

#include "types.h"

// Initialize RTC
void RTC_Init(void);

// Set RTC time
void RTCSetTime(unsigned int hr, unsigned int min, unsigned int sec);

// Set RTC date
void RTCSetDate(unsigned int day, unsigned int mon, unsigned int year);

// Set day of week
void RTCSetDay(unsigned int day);

// Read current RTC time
void RTCGetTime(unsigned int *hr, unsigned int *min, unsigned int *sec);

// Configure alarm after 3 minutes
void SetRTCAlarmAfter3Min(unsigned int min, unsigned int sec);

#endif