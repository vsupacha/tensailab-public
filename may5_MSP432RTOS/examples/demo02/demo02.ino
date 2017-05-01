/**
   @author    Supachai Vorapojpisut
   @brief     Demo #3 for Energia MT: semaphore
*/
#include "platform.h"

Semaphore_Handle hSem;

/**
 * @brief     ISR for pushbutton
 */
void btn2Handler() {
  static uint32_t prevTime = millis();
  if (50 < (millis() - prevTime)) {
    Semaphore_post(hSem);
    prevTime = millis();
  }
}


/**
   @brief     Initialize Serial hardware
*/
void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, btn2Handler, RISING);
  // RTOS object
  Error_Block eb;
  Error_init(&eb);
  hSem = Semaphore_create(0, NULL, &eb);
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

