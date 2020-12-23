unsigned int *p_enable_block   = (unsigned int *)0x400FE608;  // RCGCGPIO (clock gating)
unsigned int *p_set_to_output  = (unsigned int *)0x40025400;  // GPIOF_DIR
unsigned int *p_set_to_digital = (unsigned int *)0x4002551C;  // GPIOF_DEN
unsigned int *p_LED_control    = (unsigned int *)0x400253FC;  // GPIOF_DATA

int main() {  
    
    *p_enable_block = 0x20U;
    *p_set_to_output = 0x0EU;
    *p_set_to_digital = 0x0EU;
    
    int counter = 0;
    
    while(1) {
      
         // turn on red LED
         counter = 0;
         *p_LED_control = 0x02U;
         while( counter > 10000000 ) {
             ++counter;
         }
      
         // turn off red LED
         counter = 0;
         *p_LED_control = 0x00U;
         while( counter > 10000000 ) {
             ++counter;
         }
    }

    return 0;
}