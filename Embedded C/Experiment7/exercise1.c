//Write an Embedded C programming language for generating a delay of 4 seconds using a 3MHz crystal frequency and toggle RED LED at P1.0.
#include "msp.h"
uint32_t ClockFrequency = 3000000;
void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1ms(uint32_t n)
{
while(n)
  {
    delay(ClockFrequency/3000);  
        n--;
  }
}
int main(void)
{
 volatile uint32_t i;
 WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // Stop watchdog timer
  P1->DIR |= BIT0;

    while(1)
    {
        P1->OUT ^= BIT0;
        Clock_Delay1ms(4000);
    }
}
