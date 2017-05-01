/**
   @author    Supachai Vorapojpisut
   @brief     Demo #3 for Energia MT: AT command
*/
#include "platform.h"


// Shared variables
int cmdState = IDLE;
Event_Handle hEvt;


// Local functions
int parseCommand(char* cmdTxt);


/**
   @brief     Initialize Serial hardware
*/
void setup() {
  Serial.begin(9600);
  Error_Block eb;
  Error_init(&eb);
  hEvt = Event_create(NULL, &eb);
}


/**
   @brief     Get and parse commands from Serial buffer
*/
void loop() {
  static int idx = 0;
  static char cmdTxt[20];

  while (Serial.available()) {
    char ch = Serial.read();
    switch (cmdState) {
      case IDLE: // wait for AT
        switch (idx) {
          case 0:
            if ((ch == 'a') || (ch == 'A')) {
              idx = 1;
            }
            break;
          case 1:
            if ((ch == 't') || (ch == 'T')) {
              cmdState = CMD;
            }
            idx = 0;
            break;
          default:
            idx = 0;
        }
        break;
      case CMD: // buffer command and argument
        if (ch == '\n') {
          cmdTxt[idx] = 0;
          parseCommand(cmdTxt);
          idx = 0;
          cmdState = IDLE;
        } else {
          cmdTxt[idx++] = ch;
          if (idx == 20) {
            idx = 0;
            cmdState = IDLE;
          }
        }
        break;
      default:
        cmdState = IDLE;
        idx = 0;
    }
  }
  delay(100);
}


/**
   @brief     Parse command
*/
int parseCommand(char* cmdTxt) {
  char cmd[5];
  char arg1[10];
  char arg2[10];

  int cnt = sscanf(cmdTxt, "%s %s %s", cmd, arg1, arg2);
  if (strcmp(cmd, "BL") == 0) {
    if (cnt == 2) {
      if (strcmp(arg1, "ON") == 0) {
        Event_post(hEvt, EVT_ON);
        Serial.println("OK");
      } else {
        if (strcmp(arg1, "OFF") == 0) {
          Event_post(hEvt, EVT_OFF);
          Serial.println("OK");
        } else {
          Serial.println("Error: ATBL ON/OFF");
        }
      }
    } else {
      Serial.println("Error: ATBL ON/OFF");
    }
  }
  return 0;
}

