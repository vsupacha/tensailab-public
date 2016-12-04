# Synchronous Reactive for Sensor Node Platform
A mini-workshop about how to realize Synchronous Reactive model via mbed platform and RTOS. This is the first mini-workshop about computing models to be formulated as programming templates. The event was hosted by NIA and TESA on November 9th, 2016 at NIA building.

The presentation material can be accessed onine by [this Prezi link](https://prezi.com/cgbkvh79fw3a/syncreact-programming/). 

## Requirements
* STM32 Nucleo board + USB cable.
* Account on [mbed developer site](https://developer.mbed.org/).

## Examples
1. **01_blink_wait.c** and **01_blink_timer.c** two examples of executing timely operations.
2. **02_async_queue.c** and **02_periodic_queue.c** two examples on passing data between thread and ISR.
3. **03_blink_fsm.c** and **03_blink_oop.c** examples on programming finite state machine and OOP.
4. **04_mote_xxx.c** template code for implementing synchronous reactive.

## References
* [System Design, Modeling, and Simulation using Ptolemy II book](http://ptolemy.eecs.berkeley.edu/books/Systems/).
* [Real-Time Concepts for Embedded Systems](https://www.amazon.com/Real-Time-Concepts-Embedded-Systems-Qing/dp/1578201241).
* [CMSIS RTOS](https://developer.mbed.org/handbook/CMSIS-RTOS).
