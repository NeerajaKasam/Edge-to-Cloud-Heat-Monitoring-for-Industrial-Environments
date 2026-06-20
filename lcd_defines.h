#ifndef _LCD_DEFINES_H
#define _LCD_DEFINES_H

// HD44780 LCD Commands

#define CLEAR_LCD           0x01    // Clear display
#define RET_CUR_HOME        0x02    // Return cursor to home

#define SHIFT_CUR_RIGHT     0x06    // Cursor right
#define SHIFT_CUR_LEFT      0x10    // Cursor left

#define DSP_OFF             0x08    // Display OFF
#define DSP_ON_CUR_OFF      0x0C    // Display ON, Cursor OFF
#define DSP_ON_CUR_ON       0x0E    // Display ON, Cursor ON
#define DSP_ON_CUR_BLINK    0x0F    // Display ON, Blinking Cursor

#define SHIFT_DISP_LEFT     0x10    // Shift display left
#define SHIFT_DISP_RIGHT    0x14    // Shift display right

#define MODE_8BIT_1LINE     0x30    // 8-bit, 1-line mode
#define MODE_4BIT_1LINE     0x20    // 4-bit, 1-line mode
#define MODE_8BIT_2LINE     0x38    // 8-bit, 2-line mode
#define MODE_4BIT_2LINE     0x28    // 4-bit, 2-line mode

#define GOTO_LINE1_POS0     0x80    // Line 1, Position 0
#define GOTO_LINE2_POS0     0xC0    // Line 2, Position 0
#define GOTO_LINE3_POS0     0x94    // Line 3, Position 0
#define GOTO_LINE4_POS0     0xD4    // Line 4, Position 0

#define GOTO_CGRAM_START    0x40    // CGRAM start address

// LCD Data Pins
#define LCD_DATA            8       // P0.8 - P0.15

// LCD Control Pins
#define LCD_RS              16      // Register Select
#define LCD_RW              17      // Read/Write
#define LCD_EN              18      // Enable

#endif