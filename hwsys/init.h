
#ifndef INIT_H
#define INIT_H

#include "conf.h"
#include "xpc56el.h"
#include "siu.h"
#include "pit.h"
#include "osal.h"

int main();

void peripheralsInit(void);
void systemFunction(void);

void PIT_Channel_1(void);
void PIT_Channel_2(void);

void can_receive(void);

#endif
