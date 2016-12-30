#include "mbed.h"
#include "lamp.h"

void lamp_init(void) {
}

void lamp_set(lamp_t lamp) {
    switch (lamp) {
        case BLANK:
            break;
        case CAR_RED:
            break;
        case CAR_YELLOW:
            break;
        case CAR_GREEN:
            break;
        case WALK_STOP:
            break;
        case WALK_GO:
            break;
        default:
            break;
    }
}
