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
	P2_1 = 0;
	while(1){
			P2_0 = 0;
			Delay(100);
			P2_0 = 1;
			Delay(100);
	}
}