void delay_ms(unsigned int dlyMS)
{
    // Convert milliseconds to loop count
    dlyMS *= 12000;

    // Software delay loop
    while(dlyMS--);
}

void delay_us(unsigned int dlyUS)
{
    // Convert microseconds to loop count
    dlyUS *= 12;

    // Software delay loop
    while(dlyUS--);
}