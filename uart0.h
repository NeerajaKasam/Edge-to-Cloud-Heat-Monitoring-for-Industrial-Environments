#ifndef _UART0_H_
#define _UART0_H_

// Enable UART Interrupts
#define UART_INT_ENABLE 1

// Baud Rate Calculation
#define FOSC      12000000      // Oscillator Frequency
#define CCLK      5*FOSC        // CPU Clock Frequency
#define PCLK      CCLK/4        // Peripheral Clock Frequency
#define BAUD      9600          // Required Baud Rate
#define DIVISOR   (PCLK/(16 * BAUD)) // Baud Rate Divisor

// Initialize UART0
void InitUART0(void);

// Transmit one character
void UART0_Tx(char ch);

// Receive one character
char UART0_Rx(void);

// Transmit string
void UART0_Str(char *);

// Transmit integer value
void UART0_Int(unsigned int);

// Transmit floating-point value
void UART0_Float(float);

#endif