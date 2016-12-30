#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);

int main() {
    char txt[10];
    
    // setup
    
    while(1) {
        //loop
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        pc.scanf("%s", txt);
        pc.printf("hello\n");
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}
