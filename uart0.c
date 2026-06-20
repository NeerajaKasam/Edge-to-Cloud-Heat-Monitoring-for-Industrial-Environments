#include <LPC21xx.H>  /* LPC214x Register Definitions */

#include "uart0.h"

char buff[200] = "hello", dummy;
unsigned char i = 0, ch, r_flag;

// UART0 Interrupt Service Routine
void UART0_isr(void) __irq
{
    // Check for Receive Interrupt
    if(U0IIR & 0x04)
    {
        // Read received character and clear interrupt
        ch = U0RBR;

        // Store received data in buffer
        if(i < 200)
            buff[i++] = ch;
    }
    else
    {
        // Read IIR to clear transmit interrupt
        dummy = U0IIR;
    }

    // Inform VIC that ISR execution is complete
    VICVectAddr = 0;
}

// UART0 Initialization
void InitUART0(void)
{
    // Configure P0.0 as RXD0 and P0.1 as TXD0
    PINSEL0 |= 0x00000005;

    // 8-bit data, No parity, 1 stop bit, DLAB = 1
    U0LCR = 0x83;

    // Load baud rate divisor
    U0DLL = DIVISOR;
    U0DLM = DIVISOR >> 8;

    // Disable DLAB
    U0LCR = 0x03;

#if UART_INT_ENABLE > 0

    // Configure UART0 interrupt in VIC
    VICIntSelect = 0x00000000;
    VICVectAddr0 = (unsigned)UART0_isr;
    VICVectCntl0 = 0x20 | 6;
    VICIntEnable = 1 << 6;

    // Enable RX and THRE interrupts
    U0IER = 0x03;

#endif
}

// Transmit one character
void UART0_Tx(char ch)
{
    // Wait until transmitter is ready
    while(!(U0LSR & 0x20));

    // Send character
    U0THR = ch;
}

// Receive one character
char UART0_Rx(void)
{
    // Wait until data is received
    while(!(U0LSR & 0x01));

    return U0RBR;
}

// Transmit string
void UART0_Str(char *s)
{
    while(*s)
        UART0_Tx(*s++);
}

// Transmit integer value
void UART0_Int(unsigned int n)
{
    unsigned char a[10] = {0};
    int i = 0;

    // Special case for zero
    if(n == 0)
    {
        UART0_Tx('0');
        return;
    }

    // Convert integer to ASCII digits
    while(n > 0)
    {
        a[i++] = (n % 10) + 48;
        n = n / 10;
    }

    // Send digits in correct order
    --i;
    for(; i >= 0; i--)
    {
        UART0_Tx(a[i]);
    }
}

// Transmit floating point value
void UART0_Float(float f)
{
    int x;
    float temp;

    // Extract integer part
    x = f;
    UART0_Int(x);

    // Print decimal point
    UART0_Tx('.');

    // Extract two digits after decimal point
    temp = (f - x) * 100;
    x = temp;

    UART0_Int(x);
}