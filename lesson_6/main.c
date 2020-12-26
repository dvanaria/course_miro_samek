#include "tm4c123gh6pm.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main() {  
  
    unsigned int a = 0x5A5A5A5A;
    unsigned int b = 0xDEADBEEF;
    unsigned int c;
    
    c = a | b;
    c = a & b;
    c = a ^ b;
    c = ~b;
    c = b >> 1;
    c = b << 3;
    
    int x = 1024;
    int y = -1024;
    int z;
    
    z = x >> 3;
    z = y >> 3;
    
    SYSCTL_RCGCGPIO_R = (1U << 5);    // enable the LED hardware area (GPIO F)
    GPIO_PORTF_DIR_R  = (LED_RED | LED_BLUE | LED_GREEN);   // 00001110 sets all three pins (RGB) to OUTPUT mode
    GPIO_PORTF_DEN_R  = (LED_RED | LED_BLUE | LED_GREEN);   // 00001110 sets all to Digital mode
    
    int volatile counter = 0;
 
    // keep the blue LED on throughout the program
    GPIO_PORTF_DATA_R = LED_BLUE;  
             
    //toggle the red LED on and off without disturbing the blue LED
    while(1) {
      
         counter = 0;
         GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_RED;  
         while( counter < 1000000 ) {
             ++counter;
         }
      
         counter = 0;
         GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & ~LED_RED;  
         while( counter < 1000000 ) {
             ++counter;
         }
    }

    return 0;
}