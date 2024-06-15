#include "NiXie.h"
#include "regx52.h"
#include "Delay.h"

unsigned int smg_value[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,

 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};


void NiXie_init()
{
	P0 = 0x00;
}

void NiXie(unsigned char id,unsigned char value)
{
	if (value > 15)
	{
		value = 0;
	}
	switch (id)
	{
		case 1:P3_6 = 1, P3_5 = 0; P3_4 = 0;  break;
		case 2:P3_6 = 1, P3_5 = 0; P3_4 = 1;  break;
		case 3:P3_6 = 1, P3_5 = 1; P3_4 = 0;  break;
		case 4:P3_6 = 1, P3_5 = 1; P3_4 = 1;  break;
		case 5:P3_6 = 0, P3_5 = 0; P3_4 = 0;  break;
		case 6:P3_6 = 0, P3_5 = 0; P3_4 = 1;  break;
		case 7:P3_6 = 0, P3_5 = 1; P3_4 = 0;  break;
		case 8:P3_6 = 0, P3_5 = 1; P3_4 = 1;  break;
		default:break;
	}
	P0 = smg_value[value];
//	Delay(20);
//	P0 = 0x00;
}
