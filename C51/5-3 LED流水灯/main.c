#include "regx52.h"

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
			i = 12;
			j = 169;
			do
			{
				while (--j);
			} while (--i);
	}	
}

void main()
{
	unsigned int delay = 100;
	while(1){
			P2 = 0xFE;
			Delay(delay*2);
			P2 = 0xFD;
			Delay(delay);
			P2 = 0xFB;
			Delay(delay*2);
			P2 = 0xF7;
			Delay(delay);
			P2 = 0xEF;
			Delay(delay*2);
			P2 = 0xDF;
			Delay(delay);
			P2 = 0xBF;
			Delay(delay*2);
			P2 =  0x7F;
			Delay(delay);
	}
}