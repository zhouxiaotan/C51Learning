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
unsigned char count;
void main()
{
    count = 0;
	while(1){
        if(P1_0 == 0)
        {
            
            Delay(10);
            while(P1_0 == 0);
            count+=1;
            Delay(100);
            P2 = ~count;
        }
	}
}