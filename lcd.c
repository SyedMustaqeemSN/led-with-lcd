#include<REGX51.H>
sfr LCD=0XA0;
sbit RS=P3^0;
sbit RW=P3^1;
sbit EN=P3^2;
void delay(unsigned int t)
{
	unsigned int i;
	while(t--)
	for(i=0;i<1257;i++);
}
void lcd_cmd(unsigned char ch)
{
	LCD=ch;
	RS=0;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcd_data(unsigned char ch)
{
	LCD=ch;
	RS=1;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcd_init()
{
	lcd_cmd(0X38);
	lcd_cmd(0X06);
	lcd_cmd(0X0C);
	lcd_cmd(0X01);
	lcd_cmd(0X80);
}
void lcd_print(unsigned char*str)
{
	while(*str)
	{
		lcd_data(*str);
		str++;
	}
}
void main()
{
	while(1)
	{
		P0_0=0;
		P0_1=0;
		lcd_init();
	lcd_cmd(0X83);
	P0_0=1;
	lcd_print("Green color");
	delay(100);
	lcd_cmd(0X01);
	P0_0=0;
	delay(100);
	lcd_cmd(0XC0);
	lcd_cmd(0X81);
	P0_1=1;
	lcd_print("yellow color");
	delay(100);
	lcd_cmd(0X01);
	P0_1=0;
	delay(100);
}
	}
	