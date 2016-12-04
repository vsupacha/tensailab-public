#include "mbed.h"

DigitalOut led(LED1);
AnalogIn ain(A0);
Serial pc(USBTX, USBRX);
Ticker sampler;

// data structure 
typedef struct {
    uint32_t timestamp;
    float volt;
} message_t;
Queue<message_t, 1> queue;
message_t msg;

// timer callback
void timer_isr()
{
    led = !led;
    msg.volt = ain;
    msg.timestamp = clock(); 
    queue.put(&msg);
}

// printing thread
void print_thread() 
{    
    message_t *pmsg;
    while(true) {
        osEvent evt = queue.get();
        if (evt.status == osEventMessage) {
            pmsg = (message_t*)evt.value.p;
            pc.printf("Data: %f, %d\n", pmsg->volt, pmsg->timestamp);
        }
    }
}

// main thread
int main()
{
    Thread thread;
    osStatus err = thread.start(&print_thread);
    if (err) {
        pc.printf("Error creating thread\n");
    }
    sampler.attach(&timer_isr, 1.0);
    pc.printf("Start app\n");
    while(true) {
        pc.printf("Clock: %d\n", clock());
        Thread::wait(1000);
    }
}
