#include "platform.h"

void setupBlue() {
  pinMode(BLUE_LED, OUTPUT);
  delay(100);
}

void loopBlue() {
  Semaphore_pend(hSem, BIOS_WAIT_FOREVER);
  digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
}

