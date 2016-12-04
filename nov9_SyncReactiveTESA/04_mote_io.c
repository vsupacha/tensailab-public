#include "mbed.h"
#include "mote_common.h"
#include "mote_io.h"

// private variables
Thread io_thread;
void io_thread_cb(void);

// initialize IO module
void io_init() 
{
    io_thread.start(&io_thread_cb);
} 

// thread callback for IO handler
void io_thread_cb()
{
    while(true) {
        osEvent evt = Thread::signal_wait(FLAG_IO_TRIGGER);
        if (evt.status == osEventSignal) {
            pc.printf("IO Thread: %p\n", Thread::gettid());
        }
        evt = Thread::signal_wait(FLAG_IO_ENABLE, 0);
        if (evt.status == osEventSignal) {
            pc.printf("IO Thread: Enabled\n");
        } else {
            pc.printf("IO Thread: Disabled\n");
        }
    }
}
