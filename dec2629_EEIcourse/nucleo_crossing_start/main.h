#ifndef MAIN_H
#define MAIN_H

// state type definition
enum StateName {
    IDLE,
    PREPARE,
    CAR_STOP,
    CROSS_OK,
    CROSS_STOP,
    LAMP_ERROR
};
typedef enum StateName state_t;

#endif // end main.h