#include <LPC21xx.h>

#include "delay.h"
#include "lcd.h"
#include "defines.h"

#define LCD_DAT 16   // LCD data lines connected from P1.16 to P1.23
#define RS      16   // Register Select pin connected to P0.16
#define RW      18   // Read/Write pin connected to P0.18
#define EN      17   // Enable pin connected to P0.17

void LCD_Init(void)
{
    // Configure LCD data pins as output
    WRITEBYTE(IODIR1, LCD_DAT, 0xFF);

    // Configure LCD control pins as output
    WRITEBIT(IODIR0, RS, 1);
    WRITEBIT(IODIR0, RW, 1);
    WRITEBIT(IODIR0, EN, 1);

    // Wait for LCD power stabilization
    delay_ms(16);

    // LCD initialization sequence
    Write_CMD_LCD(0x30);
    delay_ms(6);

    Write_CMD_LCD(0x30);
    delay_ms(1);

    Write_CMD_LCD(0x30);
    delay_ms(1);

    // 8-bit mode, 2-line display, 5x7 font
    Write_CMD_LCD(0x38);

    // Display OFF, Cursor OFF
    Write_CMD_LCD(0x10);

    // Clear display memory
    Write_CMD_LCD(0x01);

    // Auto increment cursor after each character
    Write_CMD_LCD(0x06);

    // Display ON, Cursor ON, Blinking Cursor ON
    Write_CMD_LCD(0x0F);
}

void Write_CMD_LCD(char cmd)
{
    // RS = 0 selects command register
    WRITEBIT(IOCLR0, RS, 1);

    // Send command to LCD
    Write_LCD(cmd);
}

void Write_DAT_LCD(char dat)
{
    // RS = 1 selects data register
    WRITEBIT(IOSET0, RS, 1);

    // Send data to LCD
    Write_LCD(dat);
}

void Write_LCD(char ch)
{
    // RW = 0 selects write operation
    WRITEBIT(IOCLR0, RW, 1);

    // Put command/data on LCD data bus
    WRITEBYTE(IOPIN1, LCD_DAT, ch);

    // Generate Enable pulse
    WRITEBIT(IOSET0, EN, 1);
    WRITEBIT(IOCLR0, EN, 1);

    // Allow LCD execution time
    delay_ms(2);
}

void Write_str_LCD(char *p)
{
    // Display string until NULL character
    while(*p)
        Write_DAT_LCD(*p++);
}

void Write_int_LCD(signed int n)
{
    char a[10], i = 0;

    // Handle negative numbers
    if(n < 0)
    {
        Write_DAT_LCD('-');
        n = -n;
    }

    // Extract digits and store in reverse order
    do
    {
        a[i++] = n % 10 + 48;
        n = n / 10;
    }while(n);

    // Display digits in correct order
    for(; i > 0; i--)
        Write_DAT_LCD(a[i - 1]);
}

void Write_float_LCD(float f, char i)
{
    // Extract integer part
    unsigned long int n = f;

    // Display integer part
    Write_int_LCD(n);

    // Display decimal point
    Write_DAT_LCD('.');

    // Display digits after decimal point
    for(; i > 0; i--)
    {
        f = f * 10;
        n = f;
        Write_DAT_LCD(n % 10 + 48);
    }
}

void LCD_SetCursor(unsigned int row, unsigned char col)
{
    unsigned char pos;

    // Calculate DDRAM address based on row and column
    switch(row)
    {
        case 0:
            pos = 0x80 + col;   // First row
            break;

        case 1:
            pos = 0xC0 + col;   // Second row
            break;

        case 2:
            pos = 0x94 + col;   // Third row (20x4 LCD)
            break;

        case 3:
            pos = 0xD4 + col;   // Fourth row (20x4 LCD)
            break;

        default:
            pos = 0x80;         // Default position
    }

    // Move cursor to desired location
    Write_CMD_LCD(pos);
}