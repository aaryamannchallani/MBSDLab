#include "msp.h"

void delayMs();

int main(void)
{
    P2->DIR|=0x07;
    P1->DIR&=~BIT4;
    P1->REN|=BIT4;
    P1->OUT|=BIT4;
    while(1){
        if(!(P1->IN & BIT4)){
            delays;
            P2->OUT^=0x07;
        }
            
    }
}
void delays()
{
    int i;
    for(i=3000000;i>0;i--);
    
}
