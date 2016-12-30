#include "mbed.h"
#include "lamp.h"

DigitalOut carRed(D3);
DigitalOut carYellow(D4);
DigitalOut carGreen(D5);
DigitalOut walkStop(D6);
DigitalOut walkGo(D7);

void lamp_init(void) {
}

void lamp_set(lamp_t lamp) {
    switch (lamp) {
        case BLANK:
            carRed = 0;
            carYellow = 0;
            carGreen = 0;
            walkStop = 0;
            walkGo = 0;
            break;
        case CAR_RED:
            carRed = 1;
            carYellow = 0;
            carGreen = 0;
            break;
        case CAR_YELLOW:
            carRed = 0;
            carYellow = 1;
            carGreen = 0;
            break;
        case CAR_GREEN:
            carRed = 0;
            carYellow = 0;
            carGreen = 1;
            break;
        case WALK_STOP:
            walkStop = 1;
            walkGo = 0;
            break;
        case WALK_GO:
            walkStop = 0;
            walkGo = 1;
            break;
        default:
            break;
    }
}
