//Write an assembly language program to switch RGB LED individually for one cycle and after RGB switch RED LED at P1.0. Repeat this cycle for 5 times and stop. 
#include "msp.h"
void main()
{
    int j=5;
    WDT_A->CTL=WDT_A_CTL_PW|WDT_A_CTL_HOLD;
    P2->DIR|=0x07;
    P1->DIR|=BIT0;
    while(j>0)
    {
        P2->OUT^=BIT0;
        for(int i=10000;i>0;i--);
        P2->OUT^=BIT1;
        for(int i=10000;i>0;i--);
        P2->OUT^=BIT2;
        for(int i=10000;i>0;i--);
        P1->OUT^=BIT0;
        for(int i=10000;i>0;i--);
        j--;
    }
    
}
