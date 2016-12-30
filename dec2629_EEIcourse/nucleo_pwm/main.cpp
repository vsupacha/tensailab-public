#include "mbed.h"

PwmOut myled(LED1);

int main() {
    int i = 1;
    
    // setup
    myled.period_ms(10);
    myled.pulsewidth_ms(1);
      
    while(1) {
        // loop
        myled.pulsewidth_ms( (i++)%10 );
        wait(1.0);    
    }
}
