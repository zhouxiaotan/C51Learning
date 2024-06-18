#include "UART.h"
#include "regx52.h"

void UART_Init(void)
{
    SCON = 0x50;
    PCON = 0x80;
    IE   =
    
    TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF3;		    //设定定时初值
	TH1 = 0xF3;		    //设定定时器重装值
	ET1 = 0;		    //禁止定时器1中断
    TR1 = 1;		    //启动定时器1
    ES  = 1;
    EA  = 1; 
}

void UART_SendByte(unsigned char byte)
{
    SBUF = byte;
    while(TI == 0);
    TI = 0;    
}

void UART_Routine() interrupt 4
{
    if(RI == 1)
    {
        P2 = ~SBUF;
        UART_SendByte(SBUF);
        RI = 0;
    }
    
    
}