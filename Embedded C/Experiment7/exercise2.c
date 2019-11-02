//Write an Embedded C programming language for switching RED LED, GREEN LED, BLUE LED each individually ON after 2 seconds of delay simultaneously use 12MHz clock for scaling.
#include "msp.h"
uint32_t ClockFrequency = 12000000;
void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1ms(uint32_t n)
{
while(n)
  {
    delay(ClockFrequency/12000);   
        n--;
  }
}
int main(void)
{
 volatile uint32_t i;
 WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // Stop watchdog timer
  P2->DIR |= 0x07;

    while(1)
    {
        P2->OUT ^= BIT0;
        Clock_Delay1ms(2000);
        P2->OUT ^= BIT1;
        Clock_Delay1ms(2000);
        P2->OUT ^= BIT2;
        Clock_Delay1ms(2000);
    }
}
