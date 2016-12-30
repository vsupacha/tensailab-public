#ifndef EVENTS_H
#define EVENTS_H

// event type definition
enum EventName {
    NONE,
    BUTTON,
    TIMER,
};
typedef enum EventName event_t;

// public functions
void event_init(void);
event_t event_status(void);
void alarm_set(float t);

#endif // end events.h