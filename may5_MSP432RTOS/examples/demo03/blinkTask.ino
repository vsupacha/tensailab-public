/**
   @author    Supachai Vorapojpisut
   @brief     Blink output
*/
#include "platform.h"


Timer_Handle hTmr;

void blinkFunction() {
  digitalWrite(RED_LED, !digitalRead(RED_LED));
}


/**
   @brief     Configure digital output
*/
void setupBlink() {
  pinMode(RED_LED, OUTPUT);
  delay(100);
  Timer_Params params;
  Timer_Params_init(&params);
  params.periodType = Timer_PeriodType_MICROSECS;
  params.period = 500 * 1000; // 0.5 sec
  params.startMode = Timer_StartMode_USER;
  Error_Block eb;
  Error_init(&eb);
  hTmr = Timer_create(Timer_ANY, (Timer_FuncPtr)blinkFunction, &params, &eb);
}


/**
   @brief     Blink output
*/
void loopBlink() {
  UInt evt = Event_pend(hEvt, EVT_NONE, EVT_ON + EVT_OFF, BIOS_WAIT_FOREVER);
  if (evt & EVT_ON) {
    Timer_start(hTmr);
  }
  if (evt & EVT_OFF) {
    Timer_stop(hTmr);
    digitalWrite(RED_LED, LOW);
  }
}


