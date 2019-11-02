//Write an assembly language program to toggle RGB LED’s individually. Set a visible frequency. 
#include "msp.h"
void main()
{
    WDT_A->CTL=WDT_A_CTL_PW|WDT_A_CTL_HOLD;
    P2->DIR|=0x07;
    while(1)
    {
        P2->OUT^=BIT0;
        for(int i=10000;i>0;i--);
        P2->OUT^=BIT1;
        for(int i=10000;i>0;i--);
        P2->OUT^=BIT2;
        for(int i=10000;i>0;i--);
    }
    
}
