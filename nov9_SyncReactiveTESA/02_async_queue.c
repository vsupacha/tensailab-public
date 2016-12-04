#include "mbed.h"

DigitalOut led(LED1);
InterruptIn button(USER_BUTTON);
Serial pc(USBTX, USBRX);

// data structure 
typedef struct {
    uint32_t timestamp;
    uint32_t count;
} message_t;
Queue<message_t, 1> queue;
message_t msg;

// edge-detecing ISR
void button_isr()
{
    static uint32_t count = 0;
    static uint32_t timestamp = 0;

    led = !led;
    count++;
    if (clock() > timestamp + CLOCKS_PER_SEC) {
        timestamp = clock();
        msg.count = count;
        msg.timestamp = timestamp; 
        queue.put(&msg);
    }
}

// printing thread
void print_thread() 
{    
    message_t *pmsg;
    while(true) {
        osEvent evt = queue.get();
        if (evt.status == osEventMessage) {
            pmsg = (message_t*)evt.value.p;
            pc.printf("Data: %d, %d\n", pmsg->count, pmsg->timestamp);
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
    button.rise(&button_isr);
    button.fall(&button_isr);
    pc.printf("Start app\n");
    while(true) {
        pc.printf("Clock: %d\n", clock());
        Thread::wait(1000);
    }
}
