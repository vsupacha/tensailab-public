#ifndef MAIN_H
#define MAIN_H

// State type definition
enum StateName {
    IDLE,
    SETUP,
    EXECUTE,
    TEARDOWN
};
typedef enum StateName state_t;

#endif // end main.h
