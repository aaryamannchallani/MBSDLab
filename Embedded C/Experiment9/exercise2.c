#include "msp.h"
void delayMs(int n);
int main(void)
{
    P1->DIR |= BIT0;
    P2->DIR |= 0x07;	
    while (1) {
        P1->OUT ^= BIT0;
        P2->OUT^=0x07;       
        delayMs(1000);
    }
}
void delayMs(int n)
{
    int i;
    TIMER32_1->LOAD = 3000 - 1;
    TIMER32_1->CONTROL = 0xC2;
    for(i = 0; i < n; i++) {
        while((TIMER32_1->RIS & 1) == 0);
        TIMER32_1->INTCLR = 0;
    }
}

---------------------------------------------OR------------------------------------------------------

#include "msp.h"
void delayMs(int n);
int main(void)
{
    P1->DIR |= BIT0;
    P2->DIR |= 0x07;
    while (1) {
        P1->OUT ^= BIT0;   
	P2->OUT^=0x07;   
        delayMs(1000);
    }
}
void delayMs(int n)
{
    int i;
    TIMER32_1->LOAD = 3000 - 1;
    NVIC->ISER[0]=BIT25;
    TIMER32_1->CONTROL = 0xC2;
    for(i = 0; i < n; i++) {
        while((TIMER32_1->INTCLR & 0) == 0);
    }
}
void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR |= BIT0;
}
