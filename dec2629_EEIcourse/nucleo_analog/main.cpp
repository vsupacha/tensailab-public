#include "mbed.h"
 
AnalogIn analog_value(A0);
PwmOut led(LED1);
Serial pc(USBTX, USBRX);

int main() {
    float meas;
    char cmd;
    
    //setup
    pc.printf("\nAnalogIn example\n");
    led.period_ms(10);
    led.pulsewidth_ms(0);
    while(1) {
        // loop
        meas = analog_value.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        meas = meas * 3300; // Change the value to be in the 0 to 3300 range
        pc.printf("measure = %.0f mV\n", meas);
        if (pc.readable()) {
            cmd = pc.getc();
            switch(cmd) {
                case '0':
                    led.pulsewidth_ms(0);
                    break;
                case '1':
                    led.pulsewidth_ms(1);
                    break;
                case '2':
                    led.pulsewidth_ms(2);
                    break;
                case '3':
                    led.pulsewidth_ms(3);
                    break;
                default:
                    led.pulsewidth_ms(0);         
            }
            //if (pc.getc() == 'a') { // If the value is greater than 2V then switch the LED on
            //    led = 1;
            //} else {
            //    led = 0;
            //}
        }
        wait(0.2); // 200 ms
    }
}
