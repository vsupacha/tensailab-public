/**
   @author    Supachai Vorapojpisut
   @brief     Demo #2 for Energia MT: task and ISR
*/
#include "platform.h"

int startBlink = 0;

/**
 * @brief     ISR for pushbutton
 */
void btn2Handler() {
  static uint32_t prevTime = millis();
  if (50 < (millis() - prevTime)) {
    startBlink = !startBlink;
    prevTime = millis();
  }
}


/**
   @brief     Initialize Serial hardware
*/
void setup() {
  Serial.begin(9600);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, btn2Handler, RISING);
}


/**
 * @brief     Echo Serial input
 */
void loop() {
  while (Serial.available()) {
    Serial.write(Serial.read());
  }
  delay(100);
}

