#include "regx52.h"

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}	
}

void main()
{
	while(1)
    {
        if(P1_0 == 0)
        {
            Delay(10);
            while(P1_0 ==0);
            Delay(10);
            P2_0 = !P2_0;
        }
	}
}