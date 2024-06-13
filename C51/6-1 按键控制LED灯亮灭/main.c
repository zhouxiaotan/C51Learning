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
	while(1){
			if(P1_0 == 0)
			{
					P2_0 = 0;
			}
			else 
			{
					P2_0 = 1;
			}
	}
}