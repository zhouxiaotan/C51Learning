#include "regx52.h"
#include "MatrixKey.h"
#include "Nixie.h"

unsigned char KeyNum = 0;

void main()
{
    NiXie_init();
    while(1)
    {
        KeyNum = MatrixKey();
        if(KeyNum != 0) 
        {
            NiXie(1,KeyNum);
        }
    }
}    