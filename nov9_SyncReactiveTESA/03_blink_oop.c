#include "mbed.h"

Serial pc(USBTX, USBRX);

// class definition
class Flasher {
    private:
        DigitalOut *_led;
        uint16_t _msec;
        Thread _thread;
        void _run();
        
    public:
        Flasher(PinName pin, float period);
        void start();
        void stop();
};

// constructor
Flasher::Flasher(PinName pin, float period)
{
    _led = new DigitalOut(pin);
    _msec = period*1000;
}

// run method
void Flasher::_run()
{
    while(true) {
        *_led = !(*_led);
        Thread::wait(this->_msec);
    }
}

// start thread
void Flasher::start() 
{
    _thread.start(callback(this, &Flasher::_run));
}

// stop thread
void Flasher::stop()
{
    _thread.terminate();
}

// main thread
int main() 
{
    Flasher flasher(LED1, 1);
    while(true) {
        flasher.start();
        pc.printf("Thread started\n");
        Thread::wait(5000);
        flasher.stop();
        pc.printf("Thread stopped\n");
        Thread::wait(5000);
    }
}
