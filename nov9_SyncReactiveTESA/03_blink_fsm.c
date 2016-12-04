#include "mbed.h"

Serial pc(USBTX, USBRX);

// class definition
class Blinker {
    private:
        DigitalOut *_led;
        Thread _thread;
        uint16_t _state;
        void _run(void);
        
    public:
        Blinker(PinName pin);
        void trigger(void);
        uint16_t get_state(void);
};

// constructor
Blinker::Blinker(PinName pin)
{
    _led = new DigitalOut(pin);
    *_led = 1;
    _state = 0;
    _thread.start(callback(this, &Blinker::_run));
}

// finite state machine (timed)
void Blinker::_run() 
{
    int count;
    
    while(true) {
        osEvent evt = Thread::signal_wait(0x01, 0); // timeout = 0 msec
        count = 0;
        switch(_state) {
            case 0:
                if (evt.status == osEventSignal) {
                    count = 1;
                    _state = 1;
                }
                break;
            case 1:
                if (evt.status == osEventSignal) {
                    count = 2;
                    _state = 2;
                }
                break;
            case 2:
                if (evt.status == osEventSignal) {
                    count = 3;
                    _state = 0;
                }
                break;
            default:
                _state = 0;
        }
        for (int i = 0; i < count; i++) {
            *_led = 0;
            Thread::wait(100);
            *_led = 1;
            Thread::wait(100);
        }
        Thread::wait(1000 - count*200);
    }
}

// event trigger
void Blinker::trigger() 
{
    _thread.signal_set(0x01);
}

// current state
uint16_t Blinker::get_state() 
{
    return _state;
}

// main thread
int main()
{
    Blinker blinker(LED1);
    pc.printf("Starting app\n");
    while(true) {
        blinker.trigger();
        pc.printf("State %d\n", blinker.get_state());        
        Thread::wait(3000);
    }
}
