#include "mbed.h"
#include "events.h"

InterruptIn button(USER_BUTTON);
Timeout alarm;
event_t detected_event = NONE;

// private functions
void button_pressed() {
}

void button_released() {
    detected_event = BUTTON;
}

void alarm_fired() {
    detected_event = TIMER;
}

// private 
void event_init(void) {
    button.fall(&button_pressed);
    button.rise(&button_released);
}

event_t event_status(void) {
    event_t last_event = detected_event;
    detected_event = NONE;
    return last_event;
}

void alarm_set(float t) {
    alarm.attach(&alarm_fired, t);
}
