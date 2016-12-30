#include "mbed.h"
#include "main.h"
#include "events.h"
#include "lamp.h"
 
DigitalOut led(LED1);
AnalogIn sensor(A0);
state_t state = IDLE;
 
int main() { 
    // setup
    lamp_init();
    event_init();
    led = 0;
    
    while(1) {
        // loop
        switch (state) {
            case IDLE:
                lamp_set(CAR_GREEN);
                lamp_set(WALK_STOP);
                if (event_status() == BUTTON) {
                    state = PREPARE;
                }
                if (sensor.read() < 0.1) {
                    state = LAMP_ERROR;
                }
                break;
            case PREPARE:
                for (int i = 0; i < 2; i++) {
                    lamp_set(BLANK);                    
                    wait(1.0);
                    lamp_set(CAR_GREEN);
                    lamp_set(WALK_STOP);
                    wait(1.0);
                }
                lamp_set(CAR_YELLOW);
                alarm_set(2); 
                while (event_status() != TIMER) {
                    // do something 
                }
                state = CROSS_OK;
                break;
            case CROSS_OK:
                lamp_set(CAR_RED);
                lamp_set(WALK_GO);
                alarm_set(20);
                while (event_status() != TIMER) {
                    // do something
                }
                state = CROSS_STOP;
                break;
            case CROSS_STOP:
                for (int i = 0; i < 2; i++) {
                    lamp_set(BLANK);                    
                    wait(1.0);
                    lamp_set(CAR_RED);
                    lamp_set(WALK_GO);
                    wait(1.0);
                }
                state = IDLE;
                break;
            case LAMP_ERROR:
                led = 1;
                lamp_set(BLANK);                    
                wait(1.0);
                lamp_set(CAR_RED);
                lamp_set(WALK_STOP);
                wait(1.0);
                break;
            default:
                state = IDLE;
        }
        wait(1);
    }
}
 