#ifndef PLATFORM_H
#define PLATFORM_H

#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>


// Shared variables
extern Semaphore_Handle hSem;

#endif
