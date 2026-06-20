// Send command to LCD
void Write_CMD_LCD(char);

// Send data/character to LCD
void Write_DAT_LCD(char);

// Write byte to LCD
void Write_LCD(char);

// Initialize LCD
void LCD_Init(void);

// Display string on LCD
void Write_str_LCD(char *);

// Display integer on LCD
void Write_int_LCD(signed int);

// Display float on LCD
void Write_float_LCD(float f, char);

// Set cursor position on LCD
void LCD_SetCursor(unsigned int row, unsigned char col);