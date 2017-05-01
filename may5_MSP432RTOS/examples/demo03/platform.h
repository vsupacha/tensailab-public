#ifndef PLATFORM_H
#define PLATFORM_H

#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/hal/Timer.h>
#include <stdio.h>

// Shared variables
extern Event_Handle hEvt;

// Command state
#define IDLE      0
#define CMD       1

// Event definition
#define EVT_NONE  Event_Id_NONE
#define EVT_ON    Event_Id_00
#define EVT_OFF   Event_Id_01


#endif
