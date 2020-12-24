#include "tm4c123gh6pm.h"


/*
#define RCGCGPIO   (*((unsigned int *)0x400FE608U))  // (clock gating register)
#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR  (*((unsigned int *)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN  (*((unsigned int *)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int *)(GPIOF_BASE + 0x3FCU)))
*/

int main() {  
    
    SYSCTL_RCGCGPIO_R = 0x20U;    // set bit 5 to enable the LED hardware area (GPIO F)
    GPIO_PORTF_DIR_R  = 0x0EU;   // 00001110 sets all three pins (RGB) to OUTPUT mode
    GPIO_PORTF_DEN_R  = 0x0EU;   // 00001110 sets all to Digital mode
    
    int volatile counter = 0;
    
    while(1) {
      
         // turn on the blue LED
         counter = 0;
         GPIO_PORTF_DATA_R = 0x04U;  
         while( counter < 1000000 ) {
             ++counter;
         }
      
         // turn off the blue LED
         counter = 0;
         GPIO_PORTF_DATA_R = 0x00U;
         while( counter < 1000000 ) {
             ++counter;
         }
    }

    return 0;
}