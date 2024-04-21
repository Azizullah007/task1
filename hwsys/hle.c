/**
* This file contains the main interop layer
* for targeting the virtual ECU through HLE
**/

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include "hle.h"
#include "init.h"
#include "irq.h"

void* main_thread_handle = NULL;

void main_entry(void* pParams)
{
    main();

    // TODO: handle end of main?
}

vinterop uint64_t bootstrap_main(char* out_interface_version, uint8_t len)
{
    if (len < strlen(HLE_INTERFACE_VERSION))
    {
        return 0;
    }

    memcpy(out_interface_version, HLE_INTERFACE_VERSION, strlen(HLE_INTERFACE_VERSION)); // copy without null termination
    return _beginthread( main_entry, 0, NULL );
}

vinterop void v_read(VRegisters* vreg)
{
    memcpy(vreg, &VREG, sizeof(VRegisters));
}

vinterop void irq_trig(uint8_t type)
{
    switch (type)
    {
        case IRQ_PIT_CH0: if (IRQ.pit_ch0) IRQ.pit_ch0(); break;
        case IRQ_PIT_CH1: if (IRQ.pit_ch1) IRQ.pit_ch1(); break;
        case IRQ_PIT_CH2: if (IRQ.pit_ch2) IRQ.pit_ch2(); break;
        case IRQ_CAN_RX: IRQ.can_rcv(); break;
    }
}

vinterop void v_write(VRegisters* vreg)
{
    memcpy(&VREG, vreg, sizeof(VRegisters));
}
