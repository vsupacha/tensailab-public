/**
   @author    Supachai Vorapojpisut
   @brief     Demo #1 for Energia MT: new task
*/
#include "platform.h"

/**
   @brief     Initialize Serial hardware
*/
void setup() {
  Serial.begin(9600);
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

