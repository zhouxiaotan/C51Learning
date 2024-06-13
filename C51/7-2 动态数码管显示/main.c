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

unsigned int smg_value[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void Nixie(unsigned int id)
{
    switch(id)
    {
        case 1: P3_6 = 1; P3_5 = 0; P3_4 = 0; break;
        case 2: P3_6 = 1; P3_5 = 0; P3_4 = 1; break;
        case 3: P3_6 = 1; P3_5 = 1; P3_4 = 0; break;
        case 4: P3_6 = 1; P3_5 = 1; P3_4 = 1; break;
        case 5: P3_6 = 0; P3_5 = 0; P3_4 = 0; break;
        case 6: P3_6 = 0; P3_5 = 0; P3_4 = 1; break;
        case 7: P3_6 = 0; P3_5 = 1; P3_4 = 0; break;
        case 8: P3_6 = 0; P3_5 = 1; P3_4 = 1; break;
        default: break;
    }
}

void main()
{
    unsigned int i,j;
	while(1)
    {
        for(j = 0; j < 10000; j++)
        {
            for(i = 1;i<50;i++)
            {
                Nixie(4);
                P0 = j > 1000 ? smg_value[j/1000%10] : 0x00;
                Delay(1);
                P0 = 0x00;
                
                Nixie(3);
                P0 = j > 100 ? smg_value[j/100%10] : 0x00;
                Delay(1);
                P0 = 0x00;

                Nixie(2);
                P0 = j > 10 ? smg_value[j/10%10] : 0x00;
                Delay(1);
                P0 = 0x00;
            
                Nixie(1);
                P0 = smg_value[j%10];        
                Delay(1);
                P0 = 0x00;
            }
        }
	}
}




//#define HC_A P3_4
//#define HC_B P3_5
//#define HC_C P3_6

//unsigned int smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
//					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//??0~F??


//void delayus(unsigned int i)    // 10*i us
//{
//	while(i--);	
//}

//void Select(unsigned int Pos)  // ??,?????????
//{
//	switch(Pos)	 
//    {
//        case(1):
//            HC_A=0;HC_B=0;HC_C=1; break;
//        case(2):
//            HC_A=1;HC_B=0;HC_C=1; break;
//        case(3):
//            HC_A=0;HC_B=1;HC_C=1; break;
//        case(4):
//            HC_A=1;HC_B=1;HC_C=1; break;
//        case(5):
//            HC_A=0;HC_B=0;HC_C=0; break;
//        case(6):
//            HC_A=1;HC_B=0;HC_C=0; break;
//        case(7):
//            HC_A=0;HC_B=1;HC_C=0; break;
//        case(8):
//            HC_A=1;HC_B=1;HC_C=0; break;
//    }
//		
//}

//void show_two(unsigned long num)
//{		
//    // 数字越大显示的越慢
//    unsigned int j = 0;
//    for(j = 0; j<100;j++)
//    {    
//        if(num >= 10000000)
//        {
//            Nixie(8);
//            P0=smgduan[num/10000000%10];
//            delayus(100); 
//            P0=0x00;
//        }
//        
//        if(num >= 1000000)
//        {
//            Nixie(7);
//            P0=smgduan[num/1000000%10];
//            delayus(100); 
//            P0=0x00;
//        }
//        
//        if(num >= 100000)
//        {
//            Nixie(6);
//            P0=smgduan[num/100000%10];
//            delayus(100); 
//            P0=0x00;
//        }

//        if(num >= 10000)
//        {
//            Nixie(5);
//            P0=smgduan[num/10000%10];
//            delayus(100); 
//            P0=0x00;
//        }

//        if(num >= 1000)
//        {
//            Nixie(4);
//            P0=smgduan[num/1000%10];
//            delayus(100); 
//            P0=0x00;
//        }


//        if(num >= 100)
//        {
//            Nixie(3);
//            P0=smgduan[(num/100)%10];
//            delayus(100); 
//            P0=0x00;
//        }

//        if(num >= 10)
//        {
//            Nixie(2);
//            P0=smgduan[(num/10)%10];
//            delayus(100); 
//            P0=0x00;
//        }

//        Nixie(1);
//        P0=smgduan[num%10];
//        delayus(100); 
//        P0=0x00;
//    }
//}

//void main()
//{
//    unsigned long i = 0, j = 0;
//    while(1)
//    {
//        for(i = 0; i<100000000;i++)
//        {
//            show_two(i);
//        }
//    }

//}
