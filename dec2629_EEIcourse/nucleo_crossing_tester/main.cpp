#include "mbed.h"
#include "main.h"
#include "tester.h"

DigitalOut status(LED1);
InterruptIn button(USER_BUTTON);
int start = false;

void button_pressed() {
    start = true;
}

int main() {
    state_t state = IDLE; 
    int count = 0;
    
    // setup
    status = 0;
    button.fall(&button_pressed);
    
    while(1) {
        // loop
        switch (state) {
            case IDLE:
                testSetup();
                if (start) {
                    state = SETUP;
                }
                break;
            case SETUP:
                status = 1;
                state = EXECUTE;
                break;
            case EXECUTE:
                count += testIDLE(); 
                count += testButton();
                count += testPREPARE();
                count += testOK();
                count += testSTOP();
                count += testSensor();     
                state = TEARDOWN;           
                break;
            case TEARDOWN:
                if (count == 0) {
                    printf("Test completed: PASS\n");
                } else {
                    printf("Test completed: NG\n");
                }
                count = 0;
                status = 0;
                start = false;
                state = IDLE;
                break;
            default:
                state = IDLE;
        }
        wait(1);
    }
}
