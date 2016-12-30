#include "mbed.h"

DigitalOut myled(LED1);
Serial test(PA_9, PA_10);

int main() {
    // setup
    
    while(1) {
        // loop
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
        test.printf("Hi\n");
    }
}
