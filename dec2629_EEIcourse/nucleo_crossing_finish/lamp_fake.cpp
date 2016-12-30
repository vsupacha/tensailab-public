#include "mbed.h"
#include "lamp.h"

void lamp_init(void) {
}

void lamp_set(lamp_t lamp) {
    switch (lamp) {
        case BLANK:
            printf("Blank\n");
            break;
        case CAR_RED:
            printf("Car red\n");        
            break;
        case CAR_YELLOW:
            printf("Car yellow\n");
            break;
        case CAR_GREEN:
            printf("Car green\n");
            break;
        case WALK_STOP:
            printf("Walk stop\n");
            break;
        case WALK_GO:
            printf("Walk go\n");
            break;
        default:
            break;
    }
}
