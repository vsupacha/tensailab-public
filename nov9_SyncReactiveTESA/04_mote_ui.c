#include "mbed.h"
#include "mote_common.h"
#include "mote_ui.h"

// private variables
Thread ui_thread;
void ui_thread_cb(void);

// initialize UI module
void ui_init() 
{
    ui_thread.start(&ui_thread_cb);
} 

// thread callback for UI handler
void ui_thread_cb()
{
    while(true) {
        osEvent evt = Thread::signal_wait(FLAG_UI_TRIGGER);
        if (evt.status == osEventSignal) {
            pc.printf("UI Thread: %p\n", Thread::gettid());
        }
        
    }
}
