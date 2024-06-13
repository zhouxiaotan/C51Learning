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
unsigned char count = 0;
void main()
{
	while(1){
        if(P1_0 == 0)
        {
            Delay(10);
            while(P1_0 == 0);
            Delay(100);
            P2 = ~(0x01 << count);
            count+=1;
            if(count > 7) count = 0;
        }
	}
}