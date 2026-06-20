#ifndef _ESP01_H_
#define _ESP01_H_

// Connect ESP01 to Wi-Fi Access Point
void esp01_connectAP(void);

// Send data to ThingSpeak cloud
void esp01_sendToThingspeak(char val, u8 fieldNum);

#endif