#include "platform.h"

void setupRed() {
  pinMode(RED_LED, OUTPUT);
  delay(100);
}

void loopRed() {
  Semaphore_pend(hSem, BIOS_WAIT_FOREVER);
  digitalWrite(RED_LED, !digitalRead(RED_LED));
}

