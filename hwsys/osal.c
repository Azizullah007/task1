/**
* HLE layer for the OSAL
* of the vECU
**/

#include "osal.h"
#include <windows.h>

void osalThreadDelaySeconds(uint32_t sec)
{
    Sleep(sec*1000);
}

void osalThreadDelayMilliseconds(uint32_t msec)
{
    Sleep(msec);
}

void osalThreadDelayMicroseconds(uint32_t usec)
{
    Sleep(usec / 1000);
}
