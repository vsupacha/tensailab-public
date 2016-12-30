#include "mbed.h"
 
AnalogIn analog_value(A0);
PwmOut led(LED1);
Serial pc(USBTX, USBRX);
Serial mcu(PA_9, PA_10); // D10, D2

int main() {
    float meas;

    // setup
    led.period_ms(10);
    led.pulsewidth_ms(0);    
    while(1) {
        //loop
        meas = analog_value.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        meas = meas * 3300; // Change the value to be in the 0 to 3300 range
        pc.printf("%f\n", meas);
        if (meas > 2000) { // If the value is greater than 2V then switch the LED on
            mcu.printf("1");
        } else {
            mcu.printf("0");
        }
        wait(0.1);
        if (mcu.readable()) {
            if (mcu.getc() == '1') {
                led.pulsewidth_ms(5); 
                pc.printf("X");
            } else {
                led.pulsewidth_ms(0);
                pc.printf("Y"); 
            }
        }
        wait(1); // 1 s
    }
}
