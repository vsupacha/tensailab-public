#ifndef LAMP_H
#define LAMP_H

// lamp type definition
enum LampName {
    BLANK,
    CAR_RED,
    CAR_YELLOW,
    CAR_GREEN,
    WALK_STOP
    WALK_GO,
};
typedef enum LampName lamp_t;

// public function
void lamp_init(void);
void lamp_set(lamp_t lamp);

#endif // end lamp.h
