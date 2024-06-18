#include "regx52.h"
#include "Timer.h"
#include "INTRINS.H"
#include "key.h"


unsigned char Count = 0;
unsigned char led_mode  = 0;
unsigned char key_num = 0;
void Timer0_Rountine(void) interrupt 1
{
    TL0   = 0x18; 
    TH0   = 0xFC;
    if(Count > 100)
    {
        Count = 0;
        P2 = led_mode == 0 ? _crol_(P2,1) : _cror_(P2,1);
    }
    Count++;
}

void main()
{
    Timer0_init();
    P2 = 0xFE;
    
    while(1)
    {
        key_num = key();
        if(key_num == 1)
        {
            led_mode++;
            led_mode = led_mode % 2;
        }
        
    }
}