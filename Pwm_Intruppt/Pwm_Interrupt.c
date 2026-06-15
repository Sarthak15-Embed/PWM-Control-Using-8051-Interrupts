#include<reg51.h>
void timer_delay(int);
void delay(int);
sbit IN1=P0^0;
sbit IN2=P0^1;
sbit En=P0^2;// PWM
char count=0;
// bit flag=0;
void ISR_Speed(void)interrupt 0
{
		if(count<5)
		count++;
		if(count==5)
		 count=1;
}
void ISR_Direct(void)interrupt 2
{
	IN1=~IN1;
	IN2=~IN2;
}
void main()
{
	TMOD=0x01;
	IN1=0;
	IN2=1;
	EA=1;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	while(1)
	{
		if(count==1)//25% delay
		{
			P1=0x01;
			En=1;
			timer_delay(1);//5ms
			En=0;
			timer_delay(3);//15ms
		}
		else if(count==2)//50% delay
		{	
			P1=0x02;
			En=1;
			timer_delay(2);//10ms
			En=0;
			timer_delay(2);//10ms
		}
		else if(count==3)//75% delay
		{	
			P1=0x04;
			En=1;
			timer_delay(3);//15ms
			En=0;
			timer_delay(1);//5ms
		}
		else if(count==4)
		{
			P1=0x08;
			En=1;
		}
	}
}

void timer_delay(int time)
{
	char i;
	for(i=0; i<time; i++)
	TH0=0xEE;//Load
	TL0=0x00;//Load
	TR0=1;  //start Timer 0
	while(TF0==0);
	TR0=0;
	TF0=0;
}
void delay(int time)
{
	int i,j;
	for(i=0; i<time; i++)
		for(j=0; j<1000; j++);
}