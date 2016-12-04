#include "mbed.h"
#include "mote_common.h"
#include "mote_ui.h"
#include "mote_io.h"
#include "mote_comm.h"

// shared variables
Serial pc(USBTX, USBRX);

// private variables
Ticker dispatcher;
Thread main_thread;
DigitalOut led(LED1);
volatile int state = 0;

// private functions
void dispatcher_cb()
{
    led = !led;
    main_thread.signal_set(FLAG_MAIN_TRIGGER);
    io_thread.signal_set(FLAG_IO_TRIGGER);
    ui_thread.signal_set(FLAG_UI_TRIGGER);
}

void main_thread_cb() 
{
    while(true) {
        osEvent evt = Thread::signal_wait(FLAG_MAIN_TRIGGER);
        if (evt.status == osEventSignal) {
            pc.printf("Main Thread: %p\n", Thread::gettid());
        }
        switch(state) {
            case 0:
            case 1:
            case 2:
                break;
            default:
                state = 0;
        }
    }
}

// main program
int main() 
{       
    io_init();
    ui_init();

    pc.printf("Starting app\n");
    main_thread.start(&main_thread_cb);
    dispatcher.attach(&dispatcher_cb, 1.0);    
    
    while(true) {
        io_thread.signal_set(FLAG_IO_ENABLE);
        Thread::wait(2000);
    }
    //Thread::wait(osWaitForever);
}
