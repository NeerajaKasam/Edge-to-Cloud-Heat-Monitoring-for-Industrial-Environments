#include<lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "adc.h"
#include "rtc.h"
#include "lcd.h"
#include "uart0.h"
#include "esp01.h"

#define BUZZER 13    // Buzzer connected to P0.13
#define MQ2    14    // MQ-2 Gas Sensor connected to P0.14

u8 min, flag = 0;    // Variable to store next upload minute
u32 temp;            // Stores temperature value
f32 adc;             // Stores ADC converted voltage

int main()
{
    InitUART0();     // Initialize UART0 for ESP01 communication

    LCD_Init();      // Initialize LCD

    // Display welcome message
    Write_str_LCD("EDGE TO CLOUD");
    Write_CMD_LCD(0XC0);
    Write_str_LCD("**PROJECT**");
    delay_ms(2000);

    Write_CMD_LCD(0X01); // Clear LCD

    Init_ADC();      // Initialize ADC for LM35 sensor
    RTC_Init();      // Initialize RTC

    RTCSetTime(7,25,0); // Set RTC time (HH,MM,SS)

    esp01_connectAP();  // Connect ESP01 to Wi-Fi Access Point

    Write_CMD_LCD(0X01); // Clear LCD after Wi-Fi connection

    min = MIN; // Store current minute value

    while(1)
    {
        adc = Read_ADC(1); // Read LM35 sensor value from ADC channel 1

        temp = adc * 100;  // Convert LM35 voltage to temperature
                           // LM35 gives 10mV/°C

        // Display temperature on LCD
        Write_CMD_LCD(0X80);
        Write_str_LCD("TEMP: ");
        Write_int_LCD(temp);
        Write_DAT_LCD(223); // Degree symbol
        Write_DAT_LCD('C');

        // Display smoke status label
        Write_CMD_LCD(0XC0);
        Write_str_LCD("SMOKE: ");

        // Check MQ2 sensor status
        if(((IOPIN0 >> MQ2) & 1))
        {
            // No smoke detected
            Write_CMD_LCD(0XC0 + 7);
            Write_str_LCD("NOT DETECTED");
        }

        // Upload temperature to ThingSpeak every 3 minutes
        if(min == MIN)
        {
            esp01_sendToThingspeak(temp,1); // Field-1 Temperature

            min += 3; // Schedule next upload after 3 minutes
        }

        // Smoke detected condition
        if(((IOPIN0 >> MQ2) & 1) == 0)
        {
            // Clear previous LCD message
            Write_CMD_LCD(0XC0 + 7);
            Write_str_LCD("                ");

            // Display smoke detected message
            Write_CMD_LCD(0XC0 + 8);
            Write_str_LCD("DETECTED");

            // Send smoke alert to ThingSpeak
            esp01_sendToThingspeak(1,2); // Field-2 Smoke Alert
        }

        // Handle minute rollover
        if(MIN == 59)
        {
            min = 0;
        }

        delay_ms(1000); // Refresh every 1 second
    }
}