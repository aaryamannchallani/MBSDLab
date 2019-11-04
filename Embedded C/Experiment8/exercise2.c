#include "msp.h"
int main(void)
{
    P1->DIR&=~0x12;
    P1->DIR|=BIT0;
    P1->REN=BIT1|BIT4;
    P1->OUT=BIT1|BIT4;
    while(1){
        if((!(P1->IN & BIT4))&(!(P1->IN & BIT1)))        
            P1->OUT^=0x01;     
    }
}
