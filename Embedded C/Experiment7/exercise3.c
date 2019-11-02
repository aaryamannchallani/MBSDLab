//Write an Embedded C programming language to 2 LED’s with different clocks 12MHz and 48MHz simultaneously. Condition: Both the LED’s should be scaled to 1sec delay of toggle. 
#include "msp.h"
uint32_t ClockFrequency = 12000000;
uint32_t ClockFrequency2 = 48000000;
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
void Clock_Delay1ms2(uint32_t n)
{
while(n)
  {
    delay(ClockFrequency2/48000);   
        n--;
  }
}
int main(void)
{
 volatile uint32_t i;
 WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // Stop watchdog timer
  P2->DIR |= BIT0;
  P1->DIR |= BIT0;

    while(1)
    {
        P2->OUT ^= BIT0;
        
        Clock_Delay1ms(1000);
        P1->OUT ^= BIT0;
        Clock_Delay1ms2(1000);
    }
}
