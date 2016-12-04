#include "mbed.h"

DigitalOut led(LED1);
Serial pc(USBTX, USBRX);

// callback function 
void blink_thread() {
    while(true) {
        led = !led;
        Thread::wait(500);
    }
}

// main thread
int main() {
    Thread thread;
    int sec = 0;
    
    // register thread callback
    osStatus err = thread.start(&blink_thread);
    if (err) {
        pc.printf("Error\n");
    }
    
    // main loop
    while(true) {
        pc.printf("Second: %d\n", sec++);
        Thread::wait(1000);
    }
}
