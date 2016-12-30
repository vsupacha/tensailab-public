#include "mbed.h"
#include "tester.h"

DigitalOut trigger(D2);
DigitalIn carRed(D3);
DigitalIn carYellow(D4);
DigitalIn carGreen(D5);
DigitalIn walkStop(D6);
DigitalIn walkGreen(D7);
DigitalOut sensor(D8);


void testSetup() {
    trigger = 1;
}


int testIDLE() {
    int result = 2;
    
    printf("Testing IDLE\n");
    if ( (carYellow != 0) || (carRed != 0) || (walkGreen != 0) ) {
        printf("IDLE: Y/R or Go is ON\n");        
    } else {
        result--; // pass
    }
    if ( (carGreen != 1) || (walkStop != 1) ) {
        printf("IDLE: G or Stop is OFF\n");
    } else {
        result--; // pass
    }
    return result;
}


int testButton(void) {
    int result = 1;

    printf("Testing button\n");
    trigger = 0;
    wait(0.5);
    trigger = 1;
    wait(1.5);
    for (int i = 0; i < 4; i++) {
        if ( (carGreen == 0) && (walkStop == 0) ) {
            result--; // pass
            break;
        }
    }
    if (result) {
        printf("Button: not active\n");
    }
    return result;
}


int testPREPARE() {
    int result = 1;
    return result;    
}


int testOK() {
    int result = 1;
    return result;   
}


int testSTOP() {
    int result = 1;
    return result;   
}


int testSensor() {
    int result = 1;
    return result;   
}
