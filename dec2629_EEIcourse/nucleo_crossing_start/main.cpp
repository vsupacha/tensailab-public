#include "mbed.h"
#include "main.h"
#include "events.h"
#include "lamp.h"
 
DigitalOut led(LED1);
state_t state = IDLE;
 
int main() {
    // setup
    
    while(1) {
        // loop
        
        switch (state) {
            case IDLE:
                break;
            case PREPARE:
                break;
            case CROSS_OK:
                break;
            case CROSS_STOP:
                break;
            case LAMP_ERROR:
                break;
            default:
                state = IDLE;
        }
        wait(0.5);
    }
}
 