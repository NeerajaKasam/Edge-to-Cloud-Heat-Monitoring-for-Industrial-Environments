#include <string.h>
#include <stdio.h>
#include "uart0.h"
#include "delay.h"
#include "lcd.h"

extern char buff[200];      // UART receive buffer
extern unsigned char i;     // Buffer index

// Connect ESP01 to Wi-Fi Access Point
void esp01_connectAP()
{
    // Check ESP01 communication
    UART0_Str("AT\r\n");

    i = 0;
    memset(buff, '\0', 200);   // Clear receive buffer

    while(i < 4);              // Wait for response

    if(strstr(buff,"OK"))      // Verify module response
    {
        ...
    }
    else
    {
        return;
    }

    // Disable command echo
    UART0_Str("ATE0\r\n");

    i = 0;
    memset(buff, '\0', 200);

    while(i < 4);

    if(strstr(buff,"OK"))
    {
        ...
    }
    else
    {
        return;
    }

    // Configure single TCP connection mode
    UART0_Str("AT+CIPMUX=0\r\n");

    i = 0;
    memset(buff, '\0', 200);

    while(i < 4);

    if(strstr(buff,"OK"))
    {
        ...
    }
    else
    {
        return;
    }

    // Disconnect from any previously connected Wi-Fi network
    UART0_Str("AT+CWQAP\r\n");

    i = 0;
    memset(buff, '\0', 200);

    while(i < 4);

    if(strstr(buff,"OK"))
    {
        ...
    }
    else
    {
        return;
    }

    // Connect to Wi-Fi Access Point
    UART0_Str("AT+CWJAP=\"YOUR_WIFI_SSID\",\"YOUR_WIFI_PASSWORD\"\r\n");

    i = 0;
    memset(buff, '\0', 200);

    while(i < 4);

    // Verify Wi-Fi connection
    if(strstr(buff,"WIFI CONNECTED"))
    {
        ...
    }
    else
    {
        return;
    }
}