#include "mbed.h"

DigitalOut led(LED1);
Serial pc(USBTX, USBRX);

// callback function 
void blink_thread(void const *data) {
    led = !led;
}

// main thread
int main() {
    int sec = 0;
    RtosTimer blink_timer(&blink_thread, osTimerPeriodic, (void *)0);
    
    blink_timer.start(500);
    while (true) {
        pc.printf("Second: %d\n", sec++);
        Thread::wait(1000);
    }
}
