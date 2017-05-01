#include "platform.h"

void setupBlink() {
  pinMode(RED_LED, OUTPUT);
}

void loopBlink() {
  if (startBlink) {
    digitalWrite(RED_LED, HIGH);
    delay(500);
    digitalWrite(RED_LED, LOW);
    delay(500);
  }
}

