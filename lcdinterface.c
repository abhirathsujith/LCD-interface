#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void main()
{
	P2=0x00;
	while(1)
	{
		lcdcmd(0X38);
		delay();
		lcdcmd(0X01);
		delay();
		lcdcmd(0X10);
		delay();
		lcdcmd(0X0c);
		delay();
		lcdcmd(0X81);
		delay();
		lcddat('M');
		delay();
		lcddat('A');
		delay();
		lcddat('N');
		delay();
		lcddat('D');
		delay();
		lcddat('E');
		delay();
		lcddat('E');
		delay();
		lcddat('P');
		delay();
	}
}
void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char val)
{
	P2=val;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void delay()
{
	unsigned int i;
	for(i=0;i<12000;i++);
}
